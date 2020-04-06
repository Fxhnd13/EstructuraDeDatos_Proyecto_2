#include <iostream>
#include <string.h>
#include "BaseDeDatos.h"

using namespace std;

Columna*& BaseDeDatos::getColumnas(){
    return this->columnas;
}

void BaseDeDatos::setColumnas(Columna *&valor){
    this->columnas = valor;
}

BaseDeDatos*& BaseDeDatos::getAnt(){
    return this->ant;
}

void BaseDeDatos::setAnt(BaseDeDatos *&valor){
    this->ant = valor;
}

BaseDeDatos*& BaseDeDatos::getSig(){
    return this->sig;
}

void BaseDeDatos::setSig(BaseDeDatos *&valor){
    this->sig = valor;
}

string BaseDeDatos::getNombre(){
    return this->nombre;
}

void BaseDeDatos::setNombre(string valor){
    this->nombre = valor;
}