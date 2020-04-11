#include <iostream>
#include <string.h>

using namespace std;

template <class TipoDato>
class List{
    TipoDato objeto;
    TipoDato *ant, *sig;

    public:

        void setAnt(TipoDato*);
        void setSig(TipoDato*);
        void setObjeto(TipoDato);

        TipoDato*& getAnt();
        TipoDato*& getSig();
        TipoDato*& getAt(int);
        TipoDato getObjeto();

        void add(TipoDato*&);
        int size();
        
};