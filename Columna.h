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

        //Método que crea la cantidad de espacios que tendrá la tabla hash
        void agregarEspacios(int);

        //Metodo que limpia todos los arboles AVL que se encuentran listados para la tabla hash
        void limpiarTodo();

        //metodo que limpia la lista de datos utilizada para hacer el rehashing
        void limpiarListaDatos();

        //metodo que agrega un arbol a la lista de arboles que conforman la tabla hash
        void agregarArbol(ListAVL *&);

        //metodo que lista todos los datos registrados en la tabla hash de la columna para hacer el rehashing
        void listarDatos();

        //coloca el puntero de la lista de arboles en el ultimo indice
        void last();

        //coloca el puntero de la lista de arboles en el primer indice
        void first();

        //metodo que nos permite acceder a un arbol en una posicion especifica
        AVL*& getAt(int);

        //metodo que nos sirve para insertar un dato
        void insertar(Dato dato);

        //metodo que inserta el dato en el arbol correspondiente
        void insert(Dato dato, bool &, AVL* &);

        //metodo para una rotacion izquierda izquierda
        void rotarLL(AVL* &);
        //metodo para una rotacion derecha derecha
        void rotarRR(AVL* &);
        //metodo para una rotacion izquierda derecha
        void rotarLR(AVL* &);
        //metodo para una rotacion derecha izquierda
        void rotarRL(AVL* &);

        //metodo que nos lista la cantida de registros que hay en una tabla hash
        void cantidadDeRegistros(int &);

        //metodo que nos permite acceder a un dato especifico de la lista de datos al hacer rehashing
        Dato getDatoAt(int);

        //metodo que nos retorna la cantidad de datos que hay en la lista de datos al hacer rehashing
        int sizeListaDatos();

        //metodo que nos retorna un dato por el no de registro de este
        void getDatoByNoRegistro(int, Dato &, bool &);

        //metodo que nos retorna el numero de registro de un dato 
        void getNoRegistroByDato(int &, Dato);

        //metodo para escribir en una cadena la estructura de la columna
        void escribirEstructura(string &, int &, int);
};