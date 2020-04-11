#include <iostream>
#include <string.h>
#include "ListDatos.cpp"

using namespace std;

class AVL{

    Dato dato;
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
        
        int getFb();
        void setFb(int);

        bool getBorrado();
        void setBorrado(bool);

        void getNoRegistroByDato(Dato ,int &);

        void getDatoByNoRegistro(int , Dato &, bool &);

        void cantidadDeRegistros(int &);
};