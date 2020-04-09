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

int AVL::getNoRegistro(){
    return this->noRegistro;
}

void AVL::setNoRegistro(int valor){
    this->noRegistro = valor;
}