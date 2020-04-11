#include <iostream>
#include <string.h>
#include "Dato.cpp"

using namespace std;

class ListDatos{
    Dato dato;
    Dato *sig, *ant;

    public:

        ListDatos(){}

        ~ListDatos(){}

        Dato getDato();
        void setDato(Dato);

        Dato*& getSig();
        Dato*& getAnt();
        void setSig(ListDatos*);
        void setAnt(ListDatos*);
};

Dato& ListDatos::getDato(){
    return this->dato;
}

Dato*& ListDatos::getSig(){
    return this->sig;
}

Dato*& ListDatos::getAnt(){
    return this->ant;
}

void ListDatos::setDato(Dato valor){
    this->dato = valor;
}

void ListDatos::setSig(ListDatos* valor){
    this->sig = valor;
}

void ListDatos::setAnt(ListDatos* valor){
    this->ant = valor;
}