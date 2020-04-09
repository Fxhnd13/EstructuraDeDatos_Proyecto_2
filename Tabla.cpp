#include <iostream>
#include <string.h>
#include "Tabla.h"

using namespace std;

    Columna*& Tabla::getColumnas(){
        return this->columnas;
    }

    void Tabla::setColumnas(Columna *valor){
        this->columnas = valor;
    }

    Tabla*& Tabla::getAnt(){
        return this->ant;
    }

    void Tabla::setAnt(Tabla *valor){
        this->ant = valor;
    }

    Tabla*& Tabla::getSig(){
        return this->sig;
    }

    void Tabla::setSig(Tabla *valor){
        this->sig = valor;
    }

    char* Tabla::getNombre(){
        return this->nombre;
    }

    void Tabla::setNombre(char valor[]){
        strcpy(this->nombre, valor);
    }

    void Tabla::first(){
        while(this->columnas && this->columnas->getAnt()){
            this->columnas = this->columnas->getAnt();
        }
    }

    void Tabla::last(){
        while (this->columnas && this->columnas->getSig()){
            this->columnas = this->columnas->getSig();
        }
    }

    void Tabla::agregarColumna(Columna * &columna){
        cout<<"Por favor ingrese el tipo de dato que desea guardar en la columna"<<endl;
        cout<<"1) Entero"<<endl;
        cout<<"2) Flotante"<<endl;
        cout<<"3) String"<<endl;
        cout<<"4) Char"<<endl;
        int tipo;
        cin>>tipo;
        columna->setTipo(tipo);
        cout<<"Ingrese el nombre que desea tenga la columna"<<endl;
        char nombre[100];
        cin.getline(nombre, 100, '\n');
        cin.getline(nombre, 100, '\n');
        columna->setNombre(nombre);
        columna->agregarEspacios(5);
        last();
        if(this->columnas==NULL){
            columna->setSig(NULL);
            columna->setAnt(NULL);
            this->columnas = columna;
        }else{
            columna->setSig(NULL);
            columna->setAnt(this->columnas);
            this->columnas->setSig(columna);
            this->columnas = columna;
        }
    }
    
    Columna*& Tabla::getAt(int indice){
        first();
        if(indice==0){
            return this->columnas;
        }else{
            for (int i = 0; i < indice; i++){
                if(this->columnas->getSig()){
                    this->columnas = columnas->getSig();
                }
            }
            return this->columnas;
        }
    }