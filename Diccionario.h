
#include <fstream>
#include <iostream>
#include "Palabra.h"
#include "StringVector.h"
#include <string>
using namespace std;

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

class Diccionario {
public:
    Diccionario();
    Diccionario(ifstream& archivo);
    Diccionario(const Diccionario& orig);
    ~Diccionario();

    void operator+=(char*);
    void operator+=(Palabra&);
    bool operator[](char*);
    bool operator[](Palabra&);


private:

    class Nodo {
    public:
        Nodo* arregloNodos[34];
        Nodo();
        ~Nodo();
        void agregarPalabra(StringVector&, int);
        bool buscarPalabra(StringVector&, int);
        string asignarLetra(int);
        string asignarMayuscula(int);
    };


    Nodo* raiz;
    //static string letras[34];//{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "á", "é", "í", "ó", "ú", "ü", "ñ", "$"};
    //static string mayuscula[34];//{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "$"};
};

#endif /* DICCIONARIO_H */
