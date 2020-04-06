#include <iostream>
#include <string.h>
#include "Columna.cpp"

using namespace std;

class BaseDeDatos{
    
    string nombre;
    Columna *columnas;
    BaseDeDatos *ant, *sig;
    
    public:

        BaseDeDatos(){}

        ~BaseDeDatos(){}

        //Aqui irán todos los métodos restantes        
        
        Columna*& getColumnas();
        void setColumnas(Columna *&);

        BaseDeDatos*& getAnt();
        void setAnt(BaseDeDatos *&);

        BaseDeDatos*& getSig();
        void setSig(BaseDeDatos *&);

        string getNombre();
        void setNombre(string);
        
};