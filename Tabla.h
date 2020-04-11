#include <iostream>
#include <string.h>
#include "Columna.cpp"

using namespace std;

class Tabla{
    
    char nombre[100];
    Columna *columnas;
    Tabla *ant, *sig;
    
    public:

        Tabla(){}

        ~Tabla(){}

        //Aqui irán todos los métodos restantes        
        
        Columna*& getColumnas();
        void setColumnas(Columna* );

        Tabla*& getAnt();
        void setAnt(Tabla* );

        Tabla*& getSig();
        void setSig(Tabla* );

        char* getNombre();
        void setNombre(char[]);
        
        Columna*& getAt(int);

        int getByName(char nombre[]);

        void first();

        void last();

        void agregarColumna(Columna* &);
        int sizeColumnas();

        void mostrarDatos();

        void mostrarDatosPorBusqueda(int, int, Dato);

        void insertar(int, int, Dato);
};