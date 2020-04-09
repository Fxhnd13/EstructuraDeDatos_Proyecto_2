#include <iostream>
#include <string.h>
#include "ListAVL.cpp"

using namespace std;

class Columna{

    char nombre[100];
    int tipo; 
    int espaciosTotales, espaciosOcupados=0;
    Columna *ant, *sig;
    ListAVL *tablaHash;

    public :

        Columna(){}

        ~Columna(){}

        //Aquí irán todos los métodos restantes
        char* getNombre();
        void setNombre(char*);

        int getTipo();
        void setTipo(int);

        Columna*& getAnt();
        void setAnt(Columna *);

        Columna*& getSig();
        void setSig(Columna * );

        ListAVL*& getTablaHash();
        void setTablaHash(ListAVL * );

        //Método que ubica el puntero de esta clase tablaHash en la primer posicion
        void primeraPosicionTablaHash();

        //Método para agregar un dato de cualquier tipo a la tabla hash en el indice indicado
        void agregarDatoEn(int, Dato);

        //Método que crea la cantidad de espacios que tendrá la tabla hash
        void agregarEspacios(int);

        void agregarArbol(ListAVL *&);

        void last();
        void first();

        AVL*& getAt(int);

        void insertar(AVL* &, Dato dato);
        void insert(Dato dato, bool &, AVL* &);

        void rotarLL(AVL* &);
        void rotarRR(AVL* &);
        void rotarLR(AVL* &);
        void rotarRL(AVL* &);

        int cantidadDeRegistros(AVL*, int &);
};