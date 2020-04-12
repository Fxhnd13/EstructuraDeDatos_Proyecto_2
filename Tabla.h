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
        
        //Retorna la columna en el indice indicado
        Columna*& getAt(int);

        //Retorna el indice de la columan con el nombre indicado
        int getByName(char nombre[]);

        //Coloca el puntero de la lista de columnas en el indice 0
        void first();
        //Coloca el puntero de la lista de columnas en el indice final
        void last();

        //Sirve para agregar una nueva columna a la lista de columnas
        void agregarColumna(Columna* &);

        //Retorna la cantidad de columnas que posee la tabla
        int sizeColumnas();

        //Metodos para mostrar los datos
        void mostrarDatos();
        
        //Metodo para mostrar los datos de una busqueda especifica
        void mostrarDatosPorBusqueda(int, Dato);

        //Inserta el dato en la columna correspondiente
        void insertar(int, Dato);

        //Escribre en una cadena la estructura correspondiente de la tabla
        void escribirEstructura(string&, int&, int);
};