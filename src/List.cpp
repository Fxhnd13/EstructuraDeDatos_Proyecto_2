#include <iostream>
#include <string.h>
#include "List.h"

using namespace std;

    template <class TipoDato>
    void List<TipoDato>::setAnt(TipoDato* valor){
        this->ant = valor;
    }

    template <class TipoDato>
    void List<TipoDato>::setSig(TipoDato* valor){
        this->sig = valor;
    }

    template <class TipoDato>
    void List<TipoDato>::setObjeto(TipoDato valor){
        this->objeto = valor;
    }

    template <class TipoDato>
    TipoDato*& List<TipoDato>::getAnt(){
        return this->ant;
    }

    template <class TipoDato>
    TipoDato*& List<TipoDato>::getSig(){
        return this->sig;
    }

    template <class TipoDato>
    TipoDato List<TipoDato>::getObjeto(){
        return this->objeto;
    }