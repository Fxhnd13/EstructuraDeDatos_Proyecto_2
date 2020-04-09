#include <iostream>
#include <string.h>

using namespace std;

class Dato{
    
    int tipo;
    int datoEntero;
    float datoFloat;
    char datoString[300];
    char datoChar;

    public : 

        Dato(){}

        ~Dato(){}

        //Aquí irán todos los métodos restantes
        int getTipoDato();
        
        int getDatoEntero();
        float getDatoFlotante();
        char* getDatoString();
        char getDatoChar();

        void setDatoEntero(int);
        void setDatoFlotante(float);
        void setDatoString(char*);
        void setDatoChar(char );

        int getValorNumerico();
};