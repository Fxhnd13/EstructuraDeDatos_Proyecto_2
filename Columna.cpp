#include <iostream>
#include "Columna.h"
#include <string.h>

string Columna::getNombre(){
    return this->nombre;
}

void Columna::setNombre(string valor){
    this->nombre = valor;
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

void Columna::setAnt(Columna *&valor){
    this->ant = valor;
}

Columna*& Columna::getSig(){
    return this->sig;
}

void Columna::setSig(Columna *&valor){
    this->sig = valor;
}

AVL*& Columna::getTablaHash(){
    return this->tablaHash;
}

void Columna::setTablaHash(AVL *&valor){
    this->tablaHash = valor;
}