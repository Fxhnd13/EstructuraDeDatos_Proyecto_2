#include <iostream>
#include <string.h>
#include "AVL.h"

using namespace std;

AVL*& AVL::getIzq(){
    return this->izq;
}

  
void AVL::setIzq(AVL* valor){
    this->izq = valor;
}
        
  
AVL*& AVL::getDer(){
    return this->der;
}

  
void AVL::setDer(AVL* valor){
    this->der = valor;
}

  
Dato AVL::getDato(){
    return this->dato;
}

  
void AVL::setDato(Dato dato){
    this->dato = dato;
}

   
int AVL::getFb(){
    return this->fb;
}

  
void AVL::setFb(int valor){
    this->fb = valor;
}

  
bool AVL::getBorrado(){
    return this->borrado;
}

  
void AVL::setBorrado(bool valor){
    this->borrado = valor;
}

void AVL::getListNoRegistroByDato(ListNoRegistro* &listNoRegistro, Dato dato){
    if(this){
        if(this->getDato().getValorNumerico() == dato.getValorNumerico()){
            agregarNoRegistro(listNoRegistro, this->getDato().getNoRegistro());
        }
        if(this->getDer()) this->getDer()->getListNoRegistroByDato(listNoRegistro, dato);
        if(this->getIzq()) this->getIzq()->getListNoRegistroByDato(listNoRegistro, dato);
    }
}

void AVL::getNoRegistroByDato(Dato dato, int &noRegistro){
    if(this){
        if(this->getDato().getValorNumerico() == dato.getValorNumerico()){
            noRegistro = this->getDato().getNoRegistro();
        }else{
            if(noRegistro == (-1)){
                if(this->getDato().getValorNumerico() < dato.getValorNumerico()){
                    if(this->getDer()) this->getDer()->getNoRegistroByDato(dato, noRegistro);
                }else{
                    if(this->getIzq()) this->getIzq()->getNoRegistroByDato(dato, noRegistro);
                }
            }
        }
    }
}

void AVL::getDatoByNoRegistro(int noRegistro, Dato &dato, bool &encontrado){
    if(this){
        if(this->getDato().getNoRegistro() == noRegistro){
            dato = this->getDato();
            encontrado = true;
        }else{
            if(!encontrado){
                if(this->getDer()) this->getDer()->getDatoByNoRegistro(noRegistro, dato, encontrado);
                if(!encontrado){
                    if(this->getIzq()) this->getIzq()->getDatoByNoRegistro(noRegistro, dato, encontrado);
                }
            }
        }
    }
}

void AVL::cantidadDeRegistros(int &cantidad){
    if(this){
        cantidad++;
        if(this->getDer()) this->getDer()->cantidadDeRegistros(cantidad);
        if(this->getIzq()) this->getIzq()->cantidadDeRegistros(cantidad);
    }
}

void AVL::limpiarDatos(){
    if((this->getDer()) || (this->getIzq())){
        if(this->getDer()) this->getDer()->limpiarDatos();
        if(this->getIzq()) this->getDer()->limpiarDatos();
    }
    if(!(this->getDer()) && !(this->getIzq())) this->~AVL();
}

void AVL::listarDatos(ListDatos* &listDatos){
    if(this){
        agregarDato(listDatos, this->getDato());
        if(this->getDer()) this->getDer()->listarDatos(listDatos);
        if(this->getIzq()) this->getIzq()->listarDatos(listDatos);
    }
}

void AVL::agregarNoRegistro(ListNoRegistro*& listNoRegistro, int noRegistro){
    ListNoRegistro *nuevoRegistro = new ListNoRegistro();
    if(listNoRegistro==NULL){
        nuevoRegistro->setAnt(NULL);
        nuevoRegistro->setSig(NULL);
        listNoRegistro = nuevoRegistro;
    }else{
        nuevoRegistro->setSig(NULL);
        nuevoRegistro->setAnt(listNoRegistro);
        listNoRegistro->setSig(nuevoRegistro);
        listNoRegistro = nuevoRegistro;
    }
}

void AVL::agregarDato(ListDatos* &listDatos, Dato dato){
    while(listDatos && listDatos->getSig()){
        listDatos = listDatos->getSig();
    }
    ListDatos *nuevoDato = new ListDatos();
    nuevoDato->setDato(dato);
    if(listDatos==NULL){
        nuevoDato->setAnt(NULL);
        nuevoDato->setSig(NULL);
        listDatos = nuevoDato;
    }else{
        nuevoDato->setSig(NULL);
        nuevoDato->setAnt(listDatos);
        listDatos->setSig(nuevoDato);
        listDatos = nuevoDato;
    }
}

void AVL::escribirEstructura(string &cadena, int &noEstructura, int noEstructuraPadre){
    if(this){
        cadena += "\n     node"+to_string(noEstructuraPadre)+" -> node"+to_string(noEstructura)+";";
        cadena += "\n     node"+to_string(noEstructura)+" [label=\""+this->getDato().getCadenaDato()+"\"];";
        noEstructuraPadre = noEstructura;
        noEstructura++;
        if(this->getDer()) this->getDer()->escribirEstructura(cadena, noEstructura, noEstructuraPadre);
        if(this->getIzq()) this->getIzq()->escribirEstructura(cadena, noEstructura, noEstructuraPadre);
    }
}
