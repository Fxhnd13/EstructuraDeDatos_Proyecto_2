#include <iostream>
#include "Tabla.cpp"

using namespace std;

Tabla *tablas;
Utilidades utilidades;
int option = 0;

Tabla*& getAt(int);
int getByName(char[]);
void first();
void last();
void agregarTabla(Tabla *&);

void crearTabla();
void hacerConsulta();
void insertarDatos();
void verGrafico();

int main(){
    do{
        cout<<"Bienvenido a las bases de datos"<<endl;
        cout<<"1) Crear tabla"<<endl;
        cout<<"2) Hacer consulta"<<endl;
        cout<<"3) Insertar datos"<<endl;
        cout<<"4) Ver grafico"<<endl;
        cout<<"5) Salir"<<endl;
        cin>>option;
        switch(option){
            case 1:{
                crearTabla();
                break;
            }
            case 2:{
                hacerConsulta();
                break;
            }
            case 3:{
                insertarDatos();
                break;
            }
            case 4:{
                verGrafico();
                break;
            }
        }
    }while(option!=5);
    return 0;
}

void crearTabla(){
    Tabla *nuevaTabla = new Tabla();
    char nombre[100];
    cout<<"Por favor ingrese el nombre de la tabla"<<endl;
    cin.getline(nombre, 100, '\n');
    cin.getline(nombre, 100, '\n');
    nuevaTabla->setNombre(nombre);
    cout<<"Por favor ingrese la cantidad de columnas que tendrá su tabla: ";
    int columnas;
    cin>>columnas;
    cout<<""<<endl;
    for (int i = 0; i < columnas; i++)
    {
        Columna *columna = new Columna();
        nuevaTabla->agregarColumna(columna);
        cout<<""<<endl;
    }
}

void hacerConsulta(){

}

void insertarDatos(){

}

void verGrafico(){

}

bool existeTablaAt(int indice){
    bool valor = true;
    if(indice == 0 ){
        if(!tablas) valor = false; 
    }else{
        for (int i = 0; i < indice; i++){
            if(tablas->getSig()){
                tablas = tablas->getSig();
            }else{
                valor = false;
            }
        }
    }
    return valor;
}

Tabla*& getAt(int indice){
    first();
    if(indice==0){
        return tablas;
    }else{
        for (int i = 0; i < indice; i++){
            if(tablas->getSig()){
                tablas = tablas->getSig();
            }
        }
        return tablas;
    }
}

int getByName(char nombre[]){
    first();
    int indice = -1;
    if(tablas->getNombre()==nombre){
        indice = 0;
    }else{
        while(tablas->getSig()){
            tablas = tablas->getSig();
            indice++;
            if(tablas->getNombre()==nombre) break;
        }
    }
    return indice;
}

void first(){
    while(tablas && tablas->getAnt()){
        tablas = tablas->getAnt();
    }
}

void last(){
    while (tablas && tablas->getSig()){
        tablas = tablas->getSig();
    }

}

void agregarTabla(Tabla *&Tabla){
    last();
        if(tablas==NULL){
            Tabla->setSig(NULL);
            Tabla->setAnt(NULL);
            tablas = Tabla;
        }else{
            Tabla->setSig(NULL);
            Tabla->setAnt(tablas);
            tablas->setSig(Tabla);
            tablas = Tabla;
        }
}