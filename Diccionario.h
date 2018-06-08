/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.h
 * Author: John
 *
 * Created on 23 de abril de 2018, 03:51 PM
 */

#include <fstream>
#include <iostream>
//#include "Palabra.h"
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
//    void operator+=(Palabra&);
    bool operator[](char*);
//    bool operator[](Palabra&);


private:

    class Nodo {
    public:
        Nodo* arregloNodos[34];
        Nodo();
        ~Nodo();
        
        //Recibe un string y su longitud 
        //Agrega la palabra, una letra en cada iteracion del arbol 
        void agregarPalabra(StringVector&, int); 
        
        //Recibe un string y su longitud
        //Busca la palabra siguiendo el camino señalado por cada posicion del string
        bool buscarPalabra(StringVector&, int);
        
        
        string asignarLetra(int);
        
        
        string asignarMayuscula(int);
    };


    Nodo* raiz;
    //static string letras[34];//{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "Ã¡", "Ã©", "Ã­", "Ã³", "Ãº", "Ã¼", "Ã±", "$"};
    //static string mayuscula[34];//{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Ã", "Ã‰", "Ã", "Ã“", "Ãš", "Ãœ", "Ã‘", "$"};
};

#endif /* DICCIONARIO_H */

