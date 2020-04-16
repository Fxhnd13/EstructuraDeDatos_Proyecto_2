#include <iostream>
#include "Tabla.cpp"
#include <fstream>

using namespace std;

Tabla *tablas;
int option = 0;

Tabla*& getAt(int);
int getByName(string);
void first();
void last();
void agregarTabla(Tabla *&);
int sizeTablas();

void crearTabla();
void hacerConsulta();
void insertarDatos();
void verGrafico();
void reportes();

int main(){
    do{
        cout<<"\n\nBienvenido a las bases de datos"<<endl;
        cout<<""<<endl;
        cout<<"0) Limpiar pantalla"<<endl;
        cout<<"1) Crear tabla"<<endl;
        cout<<"2) Hacer consulta"<<endl;
        cout<<"3) Insertar datos"<<endl;
        cout<<"4) Ver grafico"<<endl;
        cout<<"5) Reportes"<<endl;
        cout<<"6) Salir"<<endl;
        cin>>option;
        switch(option){
            case 0:{
                system("clear");
                break;
            }
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
            case 5:{
                reportes();
                break;
            }
        }
    }while(option!=6);
    for (int i = 0; i < sizeTablas(); i++){
        for (int j = 0; j < getAt(i)->sizeColumnas(); j++){
            getAt(i)->getAt(j)->limpiarTodo();
            getAt(i)->getAt(j)->~Columna();
        }
        getAt(i)->~Tabla();
    }
    
    return 0;
}

void crearTabla(){
    Tabla *nuevaTabla = new Tabla();
    char nombre[100];
    system("clear");
    cout<<"Por favor ingrese el nombre de la tabla"<<endl;
    cin.getline(nombre, 100, '\n');
    cin.getline(nombre, 100, '\n');
    nuevaTabla->setNombre(nombre);
    cout<<"\nPor favor ingrese la cantidad de columnas que tendrá su tabla: ";
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
    system("clear");
    cout<<"Por favor ingrese el nombre de la tabla en la que desea hacer la busqueda: "<<endl;
    char nombreTabla[100];
    cin.getline(nombreTabla, 100, '\n');
    cin.getline(nombreTabla, 100, '\n');
    if(getByName(nombreTabla)!=(-1)){
        cout<<"\n¿Desea hacer una busqueda precisa?"<<endl;
        cout<<"1) Si"<<endl; cout<<"2) No"<<endl; cout<<"\nPor favor ingrese el número de su decisión"<<endl;
        int busqueda; 
        cin>>busqueda;
        switch(busqueda){
            case 1:{
                Tabla* tabla = getAt(getByName(nombreTabla));
                cout<<"\nEliga una columna para realizar la busqueda: "<<endl;
                for (int i = 0; i < tabla->sizeColumnas(); i++){
                    cout<<(i+1)<<") "<<tabla->getAt(i)->getNombre()<<endl;
                }
                int columna = -1;
                cout<<"\nPor favor ingrese el numero de la opción que desea: "<<endl;
                cin>>columna;
                columna--;
                if(tabla->sizeColumnas() > columna){
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
                    dato.setTipoDato(tabla->getAt(columna)->getTipo());
                    cout<<"\nResultados de la consulta de la tabla "<<getAt(getByName(nombreTabla))->getNombre()<<": "<<endl;
                    getAt(getByName(nombreTabla))->mostrarDatosPorBusqueda(columna, dato);
                }else{
                    cout<<"\nNo existe una tabla en el indice indicado."<<endl;
                }
                break;
            }
            case 2:{
                cout<<"\nResultados de la consulta de la tabla "<<getAt(getByName(nombreTabla))->getNombre()<<": "<<endl;
                getAt(getByName(nombreTabla))->mostrarDatos();
                break;
            }
            default:{
                cout<<"\nPor favor ingrese un valor válido."<<endl;
            }
        }
    }else{
        cout<<"No existe una tabla con el nombre ingresado."<<endl;
    }
}

void insertarDatos(){
    system("clear");
    cout<<"Por favor ingrese el nombre de la tabla en la que desea hacer una inserción: ";
    char nombreTabla[100];
    cin.getline(nombreTabla, 100, '\n');
    cin.getline(nombreTabla, 100, '\n');
    if(getByName(nombreTabla)!=(-1)){
        Tabla* tabla = getAt(getByName(nombreTabla));
        for (int i = 0; i < tablas->sizeColumnas(); i++){
            cout<<"\nIngrese el valor para "<<tabla->getAt(i)->getNombre()<<":";
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
        //Evaluamos si se supero el factor de datos en la tabla
        float factor = (float)tabla->getAt(0)->getEspaciosOcupados() / (float)tabla->getAt(0)->getEspaciosTotales();
        //de haberse superado
        if(factor >= 0.6){
            //por cada columna hay que hacer un listado de los datos que hay ahí
            for (int i = 0; i < tabla->sizeColumnas(); i++){
                //duplicaremos la cantidad de espacios para mejorar el rendimiento
                int cantidad = 2 * tabla->getAt(i)->getEspaciosTotales();
                //listamos los datos y limpiamos la lista de avl de la columna, y agregar la nueva cantidad de espacios
                tabla->getAt(i)->listarDatos();
                tabla->getAt(i)->limpiarTodo();
                tabla->getAt(i)->agregarEspacios(cantidad);
                tabla->getAt(i)->setEspaciosOcupados(0);
                //Por cada dato que haya en la lista tenemos que insertarlo en la nueva columna con su nueva tabla hash
                for (int j = 0; j < tabla->getAt(i)->sizeListaDatos(); j++){
                    tabla->insertar(i,tabla->getAt(i)->getDatoAt(j));
                    //tabla->getAt(i)->setEspaciosOcupados(tabla->getAt(i)->getEspaciosOcupados()+1);
                }
                //hay que limpiar la lista de datos que tenemos y proceder con la siguiente columna
                tabla->getAt(i)->limpiarListaDatos();
            }
        }
    }else{
        cout<<"\nNo existe una tabla con el nombre ingresado."<<endl;
    }
}

void verGrafico(){
    system("clear");
    int noEstructura = 0;
    int noEstructuraPadre = 0;
    string cadena = "digraph G {\n     nodesep=.1;\n     rankdir=LR;";
    cout<<"\nDesea ver toda la base de datos?"<<endl;
    cout<<"1)Sí"<<endl;
    cout<<"2)No"<<endl;
    int select = 0;
    cin>>select;
    switch(select){
        case 1:{
            cadena+="\n     node"+to_string(noEstructuraPadre)+" [label=\"Guatemala's Database\", shape=record, height=.1];";
            noEstructura++;
            for (int i = 0; i < sizeTablas(); i++){
                if(getAt(i)) getAt(i)->escribirEstructura(cadena, noEstructura, noEstructuraPadre);
            }
            break;
        }
        case 2:{
            cout<<"\nTablas registradas:"<<endl;
            for (int i = 0; i < sizeTablas(); i++){
                cout<<(i+1)<<") "<<getAt(i)->getNombre()<<endl;
            }
            cout<<"\nPor favor ingrese el numero de la tabla que desea ver: ";
            int tabla = 0;
            cin>>tabla;
            cout<<"\n¿Desea ver la tabla completa o columna especifica? "<<endl;
            cout<<"1) Completa"<<endl;
            cout<<"2) Columna especifica"<<endl;
            int select2 = 0;
            cin>>select2;
            switch(select2){
                case 1:{
                    getAt(tabla)->escribirEstructura(cadena, noEstructura, noEstructuraPadre);
                    break;
                }
                case 2:{
                    cout<<"\nColumnas registradas en la tabla "<<getAt(tabla)->getNombre()<<endl;
                    for (int i = 0; i < getAt(tabla)->sizeColumnas(); i++){
                        cout<<(i+1)<<") "<<getAt(tabla)->getAt(i)->getNombre()<<endl;
                    }
                    cout<<"\nPor favor ingrese el numero de la columna que desea ver: ";
                    int columna = 0;
                    cin>>columna;
                    getAt(tabla)->getAt(columna)->escribirEstructura(cadena, noEstructura, noEstructuraPadre);
                    break;
                }
            }
            break;
        }
    }
    cadena += "\n}";
    ofstream file;
    file.open("../Docs/Grafico.dot");
    file << cadena;
    file.close();
    system("dot -Tpng \"../Docs/Grafico.dot\" -o \"../Docs/Grafico.png\"");
    system("nohup display \"../Docs/Grafico.png\"");
}

void reportes(){
    system("clear");
    cout<<"Bienvenido al menú de Reportes"<<endl;
    cout<<"1) Cantidad de datos en todas las tablas"<<endl;
    cout<<"2) Cantidad de datos"<<endl;
    cout<<"3) Cantidad de columnas (decia filas pero pues) de un mismo tipo de dato en una tabla"<<endl;
    cout<<"4) Cantidad de todas las filas de todas las tablas"<<endl;
    cout<<"5) Cantidad de todas las columnas de todas las tablas"<<endl;
    int seleccion;
    cin>>seleccion;
    switch(seleccion){
        case 1:{
            for (int i = 0; i <  sizeTablas(); i++){
                int total = 0;
                for (int j = 0; j < getAt(i)->sizeColumnas(); j++){
                    int cantidad =0;
                    getAt(i)->getAt(j)->cantidadDeRegistros(cantidad);
                    cout<<"\nCantidad de datos en la columna "<<getAt(i)->getAt(j)->getNombre()<<" de la tabla "<<getAt(i)->getNombre()<<": "<<cantidad;
                    total += cantidad;
                }
                cout<<"\nCon un total de "<<total<<" de datos en la tabla "<<getAt(i)->getNombre();    
            }
            break;
        }
        case 2:{
            int total = 0;
            for (int i = 0; i <  sizeTablas(); i++){
                int totalDeTabla = 0;
                for (int j = 0; j < getAt(i)->sizeColumnas(); j++){
                    int cantidad =0;
                    getAt(i)->getAt(j)->cantidadDeRegistros(cantidad);
                    totalDeTabla += cantidad;
                }
                total += totalDeTabla;
            }
            cout<<"\nSe han ingresado un total de "<<total<<" datos en la base de datos"<<endl;
            break;
        }
        case 3:{
            for (int i = 0; i <  sizeTablas(); i++){
                int cantidadEntero = 0, cantidadFloat=0, cantidadString=0, cantidadChar=0;
                for (int j = 0; j < getAt(i)->sizeColumnas(); j++){
                    switch(getAt(i)->getAt(j)->getTipo()){
                        case 1:{
                            cantidadEntero++; break;
                        }
                        case 2:{
                            cantidadFloat++; break;
                        }
                        case 3:{
                            cantidadString++; break;
                        }
                        case 4:{
                            cantidadChar++; break;
                        }
                    }
                }
                cout<<"\nPara la tabla "<<getAt(i)->getNombre()<<": "<<endl;
                cout<<"Columnas tipo entero: "<<cantidadEntero<<endl;
                cout<<"Columnas tipo float: "<<cantidadFloat<<endl;
                cout<<"Columnas tipo string: "<<cantidadString<<endl;
                cout<<"Columnas tipo Char: "<<cantidadChar<<endl;
                cout<<""<<endl;
            }
            break;
        }
        case 4:{
            for (int i = 0; i <  sizeTablas(); i++){
                if(getAt(i)->getAt(0)){
                    int cantidad =0;
                    getAt(i)->getAt(0)->cantidadDeRegistros(cantidad);
                    cout<<"\nCantidad de registros/filas en la tabla "<<getAt(i)->getNombre()<<" es de: "<<cantidad;
                }
            }
            break;
        }
        case 5:{
            for (int i = 0; i <  sizeTablas(); i++){
                if(getAt(i)->getAt(0)){
                    cout<<"\nCantidad de Columnas en la tabla "<<getAt(i)->getNombre()<<" es de: "<<getAt(i)->sizeColumnas()<<endl;;
                }
            }
        }
    }
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

int getByName(string nombre){
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