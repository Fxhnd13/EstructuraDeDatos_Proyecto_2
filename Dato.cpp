#include <iostream>
#include <string.h>
#include "Dato.h"

using namespace std;

int Dato::getTipoDato(){
    return this->tipo;
}

int Dato::getDatoEntero(){
    return this->datoEntero;
}

float Dato::getDatoFlotante(){
    return this->datoFloat;
}

string Dato::getDatoString(){
    return this->datoString;
}

char Dato::getDatoChar(){
    return this->datoChar;
}

void Dato::setDatoChar(char valor){
    this->datoChar = valor;
}

void Dato::setDatoEntero(int valor){
    this->datoEntero = valor;
}

void Dato::setDatoFlotante(float valor){
    this->datoFloat = valor;
}

void Dato::setDatoString(string valor){
    this->datoString = valor;
}