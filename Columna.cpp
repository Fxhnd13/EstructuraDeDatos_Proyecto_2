#include <iostream>
#include "Columna.h"
#include <string.h>

char* Columna::getNombre(){
    return this->nombre;
}

void Columna::setNombre(char valor[]){
    strcpy(this->nombre, valor);
}

int Columna::getTipo(){
    return this->tipo;
}

void Columna::setTipo(int valor){
    this->tipo = valor;
}

Columna*& Columna::getAnt(){
    return this->ant;
}

void Columna::setAnt(Columna* valor){
    this->ant = valor;
}

Columna*& Columna::getSig(){
    return this->sig;
}

void Columna::setSig(Columna* valor){
    this->sig = valor;
}

ListAVL*& Columna::getTablaHash(){
    return this->tablaHash;
}

void Columna::setTablaHash(ListAVL* valor){
    this->tablaHash = valor;
}

int Columna::getEspaciosOcupados(){
    return this->espaciosOcupados;
}

int Columna::getEspaciosTotales(){
    return this->espaciosTotales;
}

void Columna::setEspaciosOcupados(int valor){
    this->espaciosOcupados = valor;
}

void Columna::setEspaciosTotales(int valor){
    this->espaciosTotales = valor;
}

void Columna::agregarEspacios(int cantidad){
    this->espaciosTotales = cantidad;
    for (int i = 0; i < cantidad; i++){
        ListAVL *avl = new ListAVL();
        this->agregarArbol(avl);
    }
}

void Columna::limpiarTodo(){
    last();
    while(tablaHash){
        ListAVL *aux = this->tablaHash;
        if(aux->getAnt()){
            if(this->tablaHash->getAVL()){
                this->tablaHash->getAVL()->limpiarDatos();
            }
            this->tablaHash = aux->getAnt();
            aux->getAnt()->setSig(NULL);
            aux->setAnt(NULL);
        }else{
            this->tablaHash = NULL;
        }
        delete aux;
    }
}

void Columna::limpiarListaDatos(){
    while(this->listDatos && this->listDatos->getSig()){
        this->listDatos = this->listDatos->getSig();
    }
    while(listDatos){
        ListDatos *aux = this->listDatos;
        if(aux->getAnt()){
            this->listDatos = aux->getAnt();
            aux->getAnt()->setSig(NULL);
            aux->setAnt(NULL);
        }else{
            this->listDatos = NULL;
        }
        delete aux;
    }
}

void Columna::listarDatos(){
    for (int i = 0; i < this->espaciosTotales; i++){
        this->getAt(i)->listarDatos(this->listDatos);
    }
}

void Columna::insertar(Dato dato){
    int indice = dato.funcionHash(this->espaciosTotales);
    AVL *arbol = this->getAt(indice);
    bool aumento;
    insert(dato, aumento, arbol);
}

void Columna::insert(Dato dato, bool &aumento, AVL* &arbol){
    if(arbol == NULL){
        arbol = new AVL();
        arbol->setDato(dato);
        arbol->setFb(0);
        arbol->setIzq(NULL);
        arbol->setDer(NULL);
        aumento = true;
        arbol->setBorrado(false);
    }else{
        if(dato.getValorNumerico() < arbol->getDato().getValorNumerico()){
            insert(dato, aumento, arbol->getIzq());
            if(aumento){
                switch(arbol->getFb()){
                    case -1:{
                        arbol->setFb(0);
                        aumento = false;
                        break;
                    }
                    case 0:{
                        arbol->setFb(1);
                        aumento = false;
                        break;
                    }
                    case 1:{
                        if(arbol->getIzq()->getFb() == 1){
                            rotarLL(arbol);
                        }else{
                            rotarLR(arbol);
                        }
                        aumento = false;
                        break;
                    }
                }
            }
        }else{
            insert(dato, aumento, arbol);
            if(aumento){
                switch(arbol->getFb()){
                    case -1:{
                        if(arbol->getDer()->getFb()==1){
                            rotarRL(arbol);
                        }else{
                            rotarRR(arbol);
                        }
                        aumento = false;
                        break;
                    }
                    case 0: {
                        arbol->setFb(-1);
                        aumento = false;
                        break;
                    }
                    case 1:{
                        arbol->setFb(0);
                        aumento = false;
                        break;
                    }
                }
            }
        }
    }
}

void Columna::rotarLL(AVL* &arbol){
    AVL* aux = arbol->getIzq()->getDer();
    arbol->getIzq()->setDer(arbol);
    arbol->getIzq()->setFb(0);
    AVL* aux2 = arbol->getIzq();
    arbol->setIzq(aux);
    arbol->setFb(0);
    arbol = aux2;
}

void Columna::rotarRR(AVL* &arbol){
    AVL* aux = arbol->getDer()->getIzq();
    arbol->getDer()->setIzq(arbol);
    arbol->getDer()->setFb(0);
    AVL* aux2 = arbol->getDer();
    arbol->setDer(aux);
    arbol->setFb(0);
    arbol = aux2;
}

void Columna::rotarLR(AVL* &arbol){
    rotarRR(arbol->getIzq());
    rotarLL(arbol);
}

void Columna::rotarRL(AVL* &arbol){
    rotarLL(arbol->getDer());
    rotarRR(arbol);
}

void Columna::cantidadDeRegistros(int &cantidad){
    this->first();
    if(this->tablaHash) this->tablaHash->getAVL()->cantidadDeRegistros(cantidad);
    while(tablaHash->getSig()){
        this->tablaHash = this->tablaHash->getSig();
        this->tablaHash->getAVL()->cantidadDeRegistros(cantidad);
    }
    this->first();
}

void Columna::getDatoByNoRegistro(int noRegistro, Dato &dato, bool &encontrado){
    this->first();
    if(this->tablaHash){
        this->tablaHash->getAVL()->getDatoByNoRegistro(noRegistro, dato, encontrado);
        while(tablaHash->getSig() && (!encontrado)){
            this->tablaHash = this->tablaHash->getSig();
            this->tablaHash->getAVL()->getDatoByNoRegistro(noRegistro, dato, encontrado);
        }
    }else{
        cout<<"No se enconro el dato en la tabla hash."<<endl;
    }
}

void Columna::getListNoRegistroByDato(ListNoRegistro* &listNoRegistro, Dato dato){
    int indice = dato.funcionHash(this->espaciosTotales);
    if(this->tablaHash){
        if(this->getAt(indice)){
            this->getAt(indice)->getListNoRegistroByDato(listNoRegistro, dato);
        }
    }
}

void Columna::getNoRegistroByDato(int &noRegistro, Dato dato){
    int indice = dato.funcionHash(this->espaciosTotales);
    if(this->tablaHash){
        if(this->getAt(indice)){
            this->getAt(indice)->getNoRegistroByDato(dato, noRegistro);
        }
    }
}

void Columna::agregarArbol(ListAVL* &avl){
    last();
    if(this->tablaHash==NULL){
        avl->setSig(NULL);
        avl->setAnt(NULL);
        this->tablaHash = avl;
    }else{
        avl->setSig(NULL);
        avl->setAnt(this->tablaHash);
        this->tablaHash->setSig(avl);
        this->tablaHash = avl;
    }
}

void Columna::last(){
    if(this->tablaHash && this->tablaHash->getSig()){
        this->tablaHash = this->tablaHash->getSig();
    }
}

void Columna::first(){
    if(this->tablaHash && this->tablaHash->getAnt()){
        this->tablaHash = this->tablaHash->getAnt();
    }
}

AVL*& Columna::getAt(int indice){
    this->first();
    if(indice==0){
        return this->tablaHash->getAVL();
    }else{
        for (int i = 0; i < indice; i++){
            if(this->tablaHash->getSig()){
                this->tablaHash = this->tablaHash->getSig();
            }
        }
        return this->tablaHash->getAVL();
    }
}

Dato Columna::getDatoAt(int indice){
    while(this->listDatos && this->listDatos->getAnt()){
        this->listDatos = listDatos->getAnt();
    }
    if(indice==0){
        return this->listDatos->getDato();
    }else{
        for (int i = 0; i < indice; i++){
            if(this->listDatos->getSig()){
                this->listDatos = this->listDatos->getSig();
            }
        }
        return this->listDatos->getDato();
    }
}

    int Columna::sizeListaDatos(){
        int cantidad = 0;
        this->first();
        ListDatos* aux = this->listDatos;
        if(aux) cantidad++;
        while(aux && aux->getSig()){
            cantidad++;
            aux = aux->getSig();
        }
        return cantidad;
    }

    void Columna::escribirEstructura(string &cadena, int &noEstructura, int noEstructuraPadre){
        cadena += "\n     node"+to_string(noEstructuraPadre)+" -> node"+to_string(noEstructura)+";";
        cadena += "\n     node"+to_string(noEstructura)+" [label=\""+this->getNombre()+"\", shape=record, height.1];";
        noEstructuraPadre = noEstructura;
        noEstructura++;
        for (int i = 0; i < this->sizeArboles(); i++){
            this->getAt(i)->escribirEstructura(cadena, noEstructura, noEstructuraPadre);
        }
    }

    int Columna::sizeArboles(){
        int cantidad = 0;
        this->first();
        ListAVL* aux = this->tablaHash;
        if(aux) cantidad++;
        while(aux && aux->getSig()){
            cantidad++;
            aux = aux->getSig();
        }
        return cantidad;
    }