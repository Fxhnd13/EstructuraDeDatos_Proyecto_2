#include <iostream>
#include <string.h>
#include "Dato.cpp"

using namespace std;

class ListDatos{
    Dato dato;
    ListDatos *sig, *ant;

    public:

        ListDatos(){}

        ~ListDatos(){}

        Dato getDato();
        void setDato(Dato);

        ListDatos*& getSig();
        ListDatos*& getAnt();
        void setSig(ListDatos*);
        void setAnt(ListDatos*);
};

Dato ListDatos::getDato(){
    return this->dato;
}

ListDatos*& ListDatos::getSig(){
    return this->sig;
}

ListDatos*& ListDatos::getAnt(){
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