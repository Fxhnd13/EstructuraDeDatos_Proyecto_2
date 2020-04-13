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
        cout<<"Ingrese el nombre que desea tenga la columna: "<<endl;
        char nombre[100];
        cin.getline(nombre, 100, '\n');
        cin.getline(nombre, 100, '\n');
        columna->setNombre(nombre);
        cout<<"\nPor favor ingrese el tipo de dato que desea guardar en la columna "<<nombre<<endl;
        cout<<"1) Entero"<<endl;
        cout<<"2) Flotante"<<endl;
        cout<<"3) String"<<endl;
        cout<<"4) Char"<<endl;
        int tipo;
        cin>>tipo;
        columna->setTipo(tipo);
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
                    this->columnas = this->columnas->getSig();
                }
            }
            return this->columnas;
        }
    }

    int Tabla::sizeColumnas(){
        int cantidad = 0;
        first();
        Columna* aux = this->columnas;
        if(aux) cantidad++;
        while(aux && aux->getSig()){
            cantidad++;
            aux = aux->getSig();
        }
        return cantidad;
    }

    void Tabla::mostrarDatos(){
        if(this->getAt(0)){
            int cantidadRegistros = 0;
            this->getAt(0)->cantidadDeRegistros(cantidadRegistros);
            if(cantidadRegistros == 0){
                cout<<"No hay registros en la tabla seleccionada."<<endl;
            }else{
                for (int i = 0; i < cantidadRegistros; i++){       
                    for (int j = 0; j < this->sizeColumnas(); j++){
                        Dato dato;
                        bool encontrado = false;
                        this->getAt(j)->getDatoByNoRegistro(i, dato, encontrado);
                        if(encontrado){
                            cout<<this->getAt(j)->getNombre()<<": ";
                            dato.escribirDato();
                            if((j+1) < this->sizeColumnas())cout<<"---";
                        }
                    }
                }
            }
        }else{
            cout<<"No hay tablas ingresadas."<<endl;
        }
    }

    void Tabla::mostrarDatosPorBusqueda(int columna, Dato dato){
        if(this->getAt(columna)){
            ListNoRegistro *listNoRegistro = new ListNoRegistro();
            this->getAt(columna)->getListNoRegistroByDato(listNoRegistro, dato);
            if(sizeListNoRegistro(listNoRegistro)==0){
                cout<<"No hay registros en la tabla con el dato ingresado"<<endl;
            }else{
                for (int i = 0; i < sizeListNoRegistro(listNoRegistro); i++){
                    for (int j = 0; j < this->sizeColumnas(); j++){
                        Dato aux;  
                        bool encontrado = false;
                        this->getAt(j)->getDatoByNoRegistro(getAtListNoRegistro(listNoRegistro, i), aux, encontrado);
                        cout<<this->getAt(j)->getNombre()<<": ";
                        aux.escribirDato();
                        if((j+1) < this->sizeColumnas())cout<<"---";
                    }
                }
                
            }
        }
    }

    int Tabla::sizeListNoRegistro(ListNoRegistro *listNoRegistro){
        int cantidad = 0;
        while(listNoRegistro && listNoRegistro->getAnt()){
            listNoRegistro = listNoRegistro->getAnt();
        }
        ListNoRegistro *aux = listNoRegistro;
        if(aux) cantidad++;
        while(aux && aux->getSig()){
            cantidad++;
            aux = aux->getSig();
        }
        return cantidad;
    }

    int Tabla::getAtListNoRegistro(ListNoRegistro* listNoRegistro, int indice){
        while(listNoRegistro && listNoRegistro->getAnt()){
            listNoRegistro = listNoRegistro->getAnt();
        }
        if(indice==0){
            return listNoRegistro->getNoRegistro();
        }else{
            for (int i = 0; i < indice; i++){
                if(listNoRegistro->getSig()){
                    listNoRegistro = listNoRegistro->getSig();
                }
            }
            return listNoRegistro->getNoRegistro();
        }
    }

    void Tabla::insertar(int columna, Dato dato){
        //Insertamos el dato en la columna correspondiente
        this->getAt(columna)->insertar(dato);
        //Cambiamos la cantidad de espacios ocupados que hay en la columna
        this->getAt(columna)->setEspaciosOcupados(this->getAt(columna)->getEspaciosOcupados()+1);
    }

    void Tabla::escribirEstructura(string &cadena, int &noEstructura, int noEstructuraPadre){
        cadena += "\n     node"+to_string(noEstructuraPadre)+" -> node"+to_string(noEstructura)+";";
        cadena += "\n     node"+to_string(noEstructura)+" [label=\""+this->getNombre()+"\", shape=record, height=.1];";
        noEstructuraPadre = noEstructura;
        noEstructura++;
        for (int i = 0; i < this->sizeColumnas(); i++){
            if(this->getAt(i)) this->getAt(i)->escribirEstructura(cadena, noEstructura, noEstructuraPadre);
        }
    }