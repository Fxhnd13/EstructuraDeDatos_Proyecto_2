#include <iostream>
#include <string.h>
#include "AVL.h"

using namespace std;

template <class TipoDato>
AVL<TipoDato>*& AVL<TipoDato>::getIzq(){
    return this->izq;
}

template <class TipoDato>
void AVL<TipoDato>::setIzq(AVL<TipoDato> *&valor){
    this->izq = valor;
}
        
template <class TipoDato>
AVL<TipoDato>*& AVL<TipoDato>::getDer(){
    return this->der;
}

template <class TipoDato>
void AVL<TipoDato>::setDer(AVL<TipoDato> *&valor){
    this->der = valor;
}
        
template <class TipoDato>
AVL<TipoDato>*& AVL<TipoDato>::getAnt(){
    return this->ant;
}

template <class TipoDato>
void AVL<TipoDato>::setAnt(AVL<TipoDato> *&valor){
    this->ant = valor;
}

template <class TipoDato>     
AVL<TipoDato>*& AVL<TipoDato>::getSig(){
    return this->sig;
}

template <class TipoDato>
void AVL<TipoDato>::setSig(AVL<TipoDato> *&valor){
    this->sig = valor;
}

template <class TipoDato>
TipoDato AVL<TipoDato>::getDato(){
    return this->dato;
}

template <class TipoDato>
void AVL<TipoDato>::setDato(TipoDato dato){
    this->dato = dato;
}

template <class TipoDato> 
int AVL<TipoDato>::getFb(){
    return this->fb;
}

template <class TipoDato>
void AVL<TipoDato>::setFb(int valor){
    this->fb = valor;
}

template <class TipoDato>
bool AVL<TipoDato>::getBorrado(){
    return this->borrado;
}

template <class TipoDato>
void AVL<TipoDato>::setBorrado(bool valor){
    this->borrado = valor;
}