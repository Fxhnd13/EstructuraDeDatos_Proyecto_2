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

char* Dato::getDatoString(){
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

void Dato::setDatoString(char valor[]){
    strcpy(this->datoString, valor);
}

int Dato::getValorNumerico(){
    int valor = 0;
    switch(this->tipo){
        case 1:{
            valor = this->datoEntero;
            break;
        }
        case 2:{
            valor = (int) this->datoFloat;
            break;
        }
        case 3:{
            for (int i = 0; i < strlen(this->getDatoString()); i++){
                valor += this->datoString[i];
            }
            break;
        }
        case 4:{
            valor = this->datoChar;
            break;
        }
    }
    return valor;
}