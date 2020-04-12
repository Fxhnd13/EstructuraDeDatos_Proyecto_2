#include <iostream>
#include "List.cpp"
#include <string.h>

using namespace std;

class Dato{
    
    int tipo, noRegistro;
    int datoEntero;
    float datoFloat;
    char datoString[300];
    char datoChar;

    public : 

        Dato(){}

        ~Dato(){}

        //Aquí irán todos los métodos restantes
        int getTipoDato();
        void setTipoDato(int);
        
        int getDatoEntero();
        float getDatoFlotante();
        char* getDatoString();
        char getDatoChar();

        int getNoRegistro();
        void setNoRegistro(int);
        
        void setDatoEntero(int);
        void setDatoFlotante(float);
        void setDatoString(char*);
        void setDatoChar(char );

        //retorna el valor numerico que el dato posee, independientemente del tipo que este sea
        int getValorNumerico();

        //escribe el valor del dato
        void escribirDato();
        
        //retorna el indice donde debería insertarse el valor dependiendo de la cantidad de espacios totales que se envien de parametro
        int funcionHash(int);
};