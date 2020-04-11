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

        int getValorNumerico();
        void escribirDato();
        
        int funcionHash(int);
};