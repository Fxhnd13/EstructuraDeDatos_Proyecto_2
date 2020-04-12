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

        //modifica el valor de el entero ingresado al no de registro del dato ingresado
        void getNoRegistroByDato(Dato ,int &);

        //modifica el dato ingresado al dato correspondiente al numero de registro ingresado
        void getDatoByNoRegistro(int , Dato &, bool &);

        //nos dice la cantidad de registros que hay en el arbol
        void cantidadDeRegistros(int &);

        //elimina todos los datos que hay en el arbol
        void limpiarDatos();

        //agrega a la lista enviada como parametro los datos que se encuentre en el arbol
        void listarDatos(ListDatos* &);

        //agrega el dato enviado de parametro a la lista enviada de parametro
        void agregarDato(ListDatos* &, Dato);

        void escribirEstructura(string &, int&, int);
};