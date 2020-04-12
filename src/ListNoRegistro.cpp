#include <iostream>
#include <string.h>

using namespace std;

class ListNoRegistro{
    int noRegistro;
    ListNoRegistro *sig, *ant;

    public:

        ListNoRegistro(){}

        ~ListNoRegistro(){}

        int& getNoRegistro();
        void setNoRegistro(int);

        ListNoRegistro*& getSig();
        ListNoRegistro*& getAnt();
        void setSig(ListNoRegistro* );
        void setAnt(ListNoRegistro* );
};

int& ListNoRegistro::getNoRegistro(){
    return this->noRegistro;
}

ListNoRegistro*& ListNoRegistro::getSig(){
    return this->sig;
}

ListNoRegistro*& ListNoRegistro::getAnt(){
    return this->ant;
}

void ListNoRegistro::setNoRegistro(int valor){
    this->noRegistro = valor;
}

void ListNoRegistro::setSig(ListNoRegistro* valor){
    this->sig = valor;
}

void ListNoRegistro::setAnt(ListNoRegistro* valor){
    this->ant = valor;
}