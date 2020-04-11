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
    ListDatos *listDatos;

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

        int getEspaciosTotales();
        void setEspaciosTotales(int );

        int getEspaciosOcupados();
        void setEspaciosOcupados(int );

        //Método que ubica el puntero de esta clase tablaHash en la primer posicion
        void primeraPosicionTablaHash();

        //Método para agregar un dato de cualquier tipo a la tabla hash en el indice indicado
        void agregarDatoEn(int, Dato);

        //Método que crea la cantidad de espacios que tendrá la tabla hash
        void agregarEspacios(int);
        void limpiarTodo();
        void limpiarListaDatos();
        void agregarArbol(ListAVL *&);

        void listarDatos();
        void last();
        void first();

        AVL*& getAt(int);

        void insertar(int, Dato dato);
        void insert(Dato dato, bool &, AVL* &);

        void rotarLL(AVL* &);
        void rotarRR(AVL* &);
        void rotarLR(AVL* &);
        void rotarRL(AVL* &);

        void cantidadDeRegistros(int &);
        void getDatoByNoRegistro(int, Dato &, bool &);
        void getNoRegistroByDato(int &, Dato);
};