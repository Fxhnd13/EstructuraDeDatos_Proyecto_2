#include <iostream>
#include "Columna.h"
#include <string.h>

template <class TipoDato>
string Columna<TipoDato>::getNombre(){
    return this->nombre;
}

template <class TipoDato>
void Columna<TipoDato>::setNombre(string valor){
    this->nombre = valor;
}

template <class TipoDato>
int Columna<TipoDato>::getTipo(){
    return this->tipo;
}

template <class TipoDato>
void Columna<TipoDato>::setTipo(int valor){
    this->tipo = valor;
}

template <class TipoDato>
Columna<TipoDato>*& Columna<TipoDato>::getAnt(){
    return this->ant;
}

template <class TipoDato>
void Columna<TipoDato>::setAnt(Columna<TipoDato> *&valor){
    this->ant = valor;
}

template <class TipoDato>
Columna<TipoDato>*& Columna<TipoDato>::getSig(){
    return this->sig;
}

template <class TipoDato>
void Columna<TipoDato>::setSig(Columna<TipoDato> *&valor){
    this->sig = valor;
}

template <class TipoDato>
AVL<TipoDato>*& Columna<TipoDato>::getTablaHash(){
    return this->tablaHash;
}

template <class TipoDato>
void Columna<TipoDato>::setTablaHash(AVL<TipoDato> *&valor){
    this->tablaHash = valor;
}