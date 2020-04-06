#include <iostream>
#include <string.h>
#include "AVL.h"

using namespace std;

  
AVL*& AVL::getIzq(){
    return this->izq;
}

  
void AVL::setIzq(AVL *&valor){
    this->izq = valor;
}
        
  
AVL*& AVL::getDer(){
    return this->der;
}

  
void AVL::setDer(AVL *&valor){
    this->der = valor;
}
        
  
AVL*& AVL::getAnt(){
    return this->ant;
}

  
void AVL::setAnt(AVL *&valor){
    this->ant = valor;
}

       
AVL*& AVL::getSig(){
    return this->sig;
}

  
void AVL::setSig(AVL *&valor){
    this->sig = valor;
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