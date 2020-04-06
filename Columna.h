#include <iostream>
#include <string.h>
#include "AVL.cpp"

using namespace std;

template <class TipoDato>
class Columna{

    string nombre;
    int tipo; 
    Columna *ant, *sig;
    AVL<TipoDato> *tablaHash;

    public :

        Columna(){
            for (int i = 0; i < 5; i++)
            {

            }
        }

        ~Columna(){}

        //Aquí irán todos los métodos restantes
        string getNombre();
        void setNombre(string);

        int getTipo();
        void setTipo(int);

        Columna*& getAnt();
        void setAnt(Columna *&);

        Columna*& getSig();
        void setSig(Columna *&);

        AVL<TipoDato>*& getTablaHash();
        void setTablaHash(AVL<TipoDato> *&);

        //Método que ubica el puntero de esta clase tablaHash en la primer posicion
        void primeraPosicionTablaHash();

        //Método para agregar un dato de cualquier tipo a la tabla hash en el indice indicado
        void agregarDatoEn(int, TipoDato);

        //Método que crea la cantidad de espacios que tendrá la tabla hash
        void agregarEspacios(int);
};