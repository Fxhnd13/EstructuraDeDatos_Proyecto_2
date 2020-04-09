#include <iostream>
#include <string.h>
#include "Utilidades.cpp"
#include "Dato.cpp"

using namespace std;

class AVL{

    Dato dato;
    int noRegistro;
    int fb;
    bool borrado;
    AVL *izq,*der;

    public :

        AVL(){}

        ~AVL(){}

        //Aquí irán todos los métodos restantes
        AVL*& getIzq();
        void setIzq(AVL * );
        
        AVL*& getDer();
        void setDer(AVL * );
    
        Dato getDato();
        void setDato(Dato);
        
        int getNoRegistro();
        void setNoRegistro(int);
        
        int getFb();
        void setFb(int);

        bool getBorrado();
        void setBorrado(bool);

};