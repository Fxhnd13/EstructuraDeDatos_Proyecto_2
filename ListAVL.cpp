#include <iostream>
#include <string.h>
#include "AVL.cpp"

using namespace std;

class ListAVL{
    AVL *avl;
    ListAVL *sig, *ant;

    public:

        ListAVL(){}

        ~ListAVL(){}

        AVL*& getAVL();
        void setAVL(AVL* );

        ListAVL*& getSig();
        ListAVL*& getAnt();
        void setSig(ListAVL* );
        void setAnt(ListAVL* );
};

AVL*& ListAVL::getAVL(){
    return this->avl;
}

ListAVL*& ListAVL::getSig(){
    return this->sig;
}

ListAVL*& ListAVL::getAnt(){
    return this->ant;
}

void ListAVL::setAVL(AVL* valor){
    this->avl = valor;
}

void ListAVL::setSig(ListAVL* valor){
    this->sig = valor;
}

void ListAVL::setAnt(ListAVL* valor){
    this->ant = valor;
}