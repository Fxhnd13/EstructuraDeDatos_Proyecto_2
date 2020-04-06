#include <iostream>
#include <string.h>
#include "Dato.cpp"

using namespace std;

template <class TipoDato>
class AVL{

    TipoDato dato;
    int fb;
    bool borrado;
    AVL *izq,*der, *ant,*sig;

    public :

        AVL(){}

        ~AVL(){}

        //Aquí irán todos los métodos restantes
        AVL*& getIzq();
        void setIzq(AVL *&);
        
        AVL*& getDer();
        void setDer(AVL *&);
        
        AVL*& getAnt();
        void setAnt(AVL *&);
        
        AVL*& getSig();
        void setSig(AVL *&);

        TipoDato getDato();
        void setDato(TipoDato);
        
        int getFb();
        void setFb(int);

        bool getBorrado();
        void setBorrado(bool);

};