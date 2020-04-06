#include <iostream>
#include <string.h>

using namespace std;

class Dato{
    
    int tipo;
    int datoEntero;
    float datoFloat;
    string datoString;
    char datoChar;

    public : 

        Dato(){}

        ~Dato(){}

        //Aquí irán todos los métodos restantes
        int getTipoDato();
        
        int getDatoEntero();
        float getDatoFlotante();
        string getDatoString();
        char getDatoChar();

        void setDatoEntero(int);
        void setDatoFlotante(float);
        void setDatoString(string);
        void setDatoChar(char );
};