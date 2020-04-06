#include <iostream>
#include <string.h>
#include "Dato.cpp"

using namespace std;

class AVL{

    Dato dato;
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

        Dato getDato();
        void setDato(Dato);
        
        int getFb();
        void setFb(int);

        bool getBorrado();
        void setBorrado(bool);

};