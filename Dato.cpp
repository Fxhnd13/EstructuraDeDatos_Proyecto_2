#include <iostream>
#include <string.h>
#include "Dato.h"

using namespace std;

int Dato::getTipoDato(){
    return this->tipo;
}

void Dato::setTipoDato(int valor){
    this->tipo = valor;
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

void Dato::getCadenaDato(){
    string valor;
    switch(this->tipo){
        case 1:{
            valor = this->datoEntero;
            break;
        }
        case 2:{
            valor = this->datoFloat;
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

void Dato::escribirDato(){
    switch(this->tipo){
        case 1:{
            cout<< this->datoEntero;
            break;
        }
        case 2:{
            cout<< this->datoFloat;
            break;
        }
        case 3:{
            cout<< this->datoString;
            break;
        }
        case 4:{
            cout<< this->datoChar;
            break;
        }
    }
}

int Dato::funcionHash(int cantidadEspacios){
    int indice = 0;
    indice = this->getValorNumerico() % cantidadEspacios;
    return indice;    
}


int Dato::getNoRegistro(){
    return this->noRegistro;
}

void Dato::setNoRegistro(int valor){
    this->noRegistro = valor;
}
        