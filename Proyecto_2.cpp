#include <iostream>
#include "Tabla.cpp"

using namespace std;

Tabla *tablas;
int option = 0;

Tabla*& getAt(int);
int getByName(char[]);
void first();
void last();
void agregarTabla(Tabla *&);
int sizeTablas();

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
    agregarTabla(nuevaTabla);
}

void hacerConsulta(){
    cout<<"Por favor ingrese el nombre de la tabla en la que desea hacer la busqueda: "<<endl;
    char nombreTabla[100];
    cin.getline(nombreTabla, 100, '\n');
    if(getByName(nombreTabla)!=(-1)){
        cout<<"¿Desea hacer una busqueda precisa?"<<endl;
        cout<<"1) Si"<<endl; cout<<"2) No"<<endl; cout<<"Por favor ingrese el número de su decisión"<<endl;
        int busqueda; 
        cin>>busqueda;
        switch(busqueda){
            case 1:{
                Tabla* tabla = getAt(getByName(nombreTabla));
                cout<<"Eliga una columna para realizar la busqueda: "<<endl;
                for (int i = 0; i < tabla->sizeColumnas(); i++){
                    cout<<(i+1)<<") "<<tabla->getAt(i)->getNombre()<<endl;
                }
                int columna = -1;
                cout<<"Por favor ingrese el numero de la opción que desea: "<<endl;
                cin>>columna;
                if(columna != (-1)){
                    cout<<""<<endl;
                    cout<<"Por favor ingrese el parametro de busqueda: "<<endl;
                    Dato dato;
                    switch(tabla->getAt(columna)->getTipo()){
                        case 1:{
                            int parametro;
                            cin>>parametro;
                            dato.setDatoEntero(parametro);
                            break;
                        }
                        case 2:{
                            float parametro;
                            cin>>parametro;
                            dato.setDatoFlotante(parametro);
                            break;
                        }
                        case 3:{
                            char parametro[300];
                            cin.getline(parametro, 300, '\n');
                            cin.getline(parametro, 300, '\n');
                            dato.setDatoString(parametro);
                            break;
                        }
                        case 4:{
                            char parametro;
                            cin>>parametro;
                            dato.setDatoChar(parametro);
                            break;
                        }
                    }
                    getAt(getByName(nombreTabla))->mostrarDatosPorBusqueda(columna, dato);
                }
                break;
            }
            case 2:{
                getAt(getByName(nombreTabla))->mostrarDatos();
                break;
            }
        }
    }else{
        cout<<"No existe una tabla con el nombre ingresado."<<endl;
    }
}

void insertarDatos(){
    cout<<"\nPor favor ingrese el nombre de la tabla en la que desea hacer una inserción: ";
    char nombreTabla[100];
    cin.getline(nombreTabla, 100, '\n');
    cin.getline(nombreTabla, 100, '\n');
    if(getByName(nombreTabla)!=(-1)){
        Tabla *tabla = getAt(getByName(nombreTabla));
        for (int i = 0; i < tablas->sizeColumnas(); i++){
            cout<<"Ingrese el valor para "<<tabla->getAt(i)->getNombre()<<":";
            Dato dato;
            switch(tabla->getAt(i)->getTipo()){
                case 1:{
                    int valor; 
                    cin>>valor;
                    dato.setDatoEntero(valor);
                    dato.setTipoDato(1);
                    break;
                }
                case 2:{
                    float valor;
                    cin>>valor;
                    dato.setDatoFlotante(valor);
                    dato.setTipoDato(2);
                    break;
                }
                case 3:{
                    char valor[300];
                    cin.getline(valor, 300, '\n');
                    cin.getline(valor, 300, '\n');
                    dato.setDatoString(valor);
                    dato.setTipoDato(3);
                    break;
                }
                case 4:{
                    char valor;
                    cin>>valor;
                    dato.setDatoChar(valor);
                    dato.setTipoDato(4);
                    break;
                }
            }
            int noRegistro = 0;
            noRegistro = (tabla->getAt(i)->getEspaciosOcupados()) + 1;
            dato.setNoRegistro(noRegistro);
            tabla->insertar(i, dato);
        }
    }
}

void verGrafico(){
    int noEstructura = 0;
    int noEstructuraPadre = 0;
    string cadena = "digraph G {\n     nodesep=.1;\n     rankdir=LR;\n     node"+to_string(noEstructuraPadre)+" [label=\"Guatemala's Database\", shape=record, height=.1];";
    noEstructura++;
    for (int i = 0; i < sizeTablas(); i++){
        getAt(i)->escribirEstructura(cadena, noEstructura, noEstructuraPadre);
    }
    cadena += "\n}";
    
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
    if(tablas && tablas->getNombre()==nombre){
        indice = 0;
    }else{
        while(tablas && tablas->getSig()){
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

int sizeTablas(){
    int cantidad = 0;
    first();
    Tabla *aux = tablas;
    if(aux) cantidad++;
    while(aux && aux->getSig()){
        cantidad++;
        aux = aux->getSig();
    }
    return cantidad;
}