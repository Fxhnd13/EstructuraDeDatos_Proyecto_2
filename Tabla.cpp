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
                    this->columnas = columnas->getSig();
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

    void Tabla::mostrarDatosPorBusqueda(int opcion, int columna, Dato dato){
        if(this->getAt(0)){
            int cantidadRegistros = 0;
            this->getAt(0)->cantidadDeRegistros(cantidadRegistros);
            if(cantidadRegistros == 0){
                cout<<"No hay registros en la tabla seleccionada."<<endl;
            }else{
                for (int i = 0; i < cantidadRegistros; i++){     
                    Dato aux;  
                    bool encontrado = false;
                    this->getAt(columna)->getDatoByNoRegistro(i, aux, encontrado);
                    switch(opcion){
                        case 0:{
                            if(aux.getValorNumerico() == dato.getValorNumerico()){
                                for (int j = 0; j < this->sizeColumnas(); j++){
                                    cout<<this->getAt(j)->getNombre()<<": ";
                                    aux.escribirDato();
                                    if((j+1) < this->sizeColumnas())cout<<"---";
                                }
                            }
                            break;
                        }
                        case 1:{
                            if(aux.getValorNumerico() > dato.getValorNumerico()){
                                for (int j = 0; j < this->sizeColumnas(); j++){
                                    cout<<this->getAt(j)->getNombre()<<": ";
                                    aux.escribirDato();
                                    if((j+1) < this->sizeColumnas()) cout<<"---";
                                }
                            }
                            break;
                        }
                        case 2:{
                            if(aux.getValorNumerico() < dato.getValorNumerico()){
                                for (int j = 0; j < this->sizeColumnas(); j++){
                                    cout<<this->getAt(j)->getNombre()<<": ";
                                    aux.escribirDato();
                                    if((j+1) < this->sizeColumnas()) cout<<"---";
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }else{
            cout<<"No hay tablas ingresadas."<<endl;
        }
    }

    void Tabla::insertar(int columna, Dato dato){
        //Insertamos el dato en la columna correspondiente
        this->getAt(columna)->insertar(dato);
        //Cambiamos la cantidad de espacios ocupados que hay en la columna
        this->getAt(columna)->setEspaciosOcupados(this->getAt(columna)->getEspaciosOcupados()+1);
        //Evaluamos si se supero el factor de datos en la tabla
        float factor = this->getAt(columna)->getEspaciosOcupados()/ this->getAt(columna)->getEspaciosTotales();
        //de haberse superado
        if(factor > 0.6){
            //por cada columna hay que hacer un listado de los datos que hay ahí
            for (int i = 0; i < this->sizeColumnas(); i++){
                //duplicaremos la cantidad de espacios para mejorar el rendimiento
                int cantidad = 2 * this->getAt(i)->getEspaciosTotales();
                //listamos los datos y limpiamos la lista de avl de la columna, y agregar la nueva cantidad de espacios
                this->getAt(i)->listarDatos();
                this->getAt(i)->limpiarTodo();
                this->getAt(i)->agregarEspacios(cantidad);
                //Por cada dato que haya en la lista tenemos que insertarlo en la nueva columna con su nueva tabla hash
                for (int j = 0; j < this->getAt(i)->sizeListaDatos(); j++){
                    this->getAt(i)->insertar(this->getAt(i)->getDatoAt(j));
                }
                //hay que limpiar la lista de datos que tenemos y proceder con la siguiente columna
                this->getAt(i)->limpiarListaDatos();
            }
        }
    }