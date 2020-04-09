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

void Columna::agregarEspacios(int cantidad){
    this->espaciosTotales = cantidad;
    for (int i = 0; i < cantidad; i++){
        ListAVL *avl = new ListAVL();
        this->agregarArbol(avl);
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
    first();
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

void Columna::insertar(AVL* &arbol, Dato dato){
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

int Columna::cantidadDeRegistros(AVL* arbol, int &cantidad){
    if(arbol){
        cantidad++;
        cantidadDeRegistros(arbol->getDer(), cantidad);
        cantidadDeRegistros(arbol->getIzq(), cantidad);
    }
    return cantidad;
}