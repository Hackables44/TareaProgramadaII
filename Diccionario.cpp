/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.cpp
 * Author: John
 * 
 * Created on 23 de abril de 2018, 03:51 PM
 */

#include "Diccionario.h"

Diccionario::Nodo::Nodo() {
    for (int i = 0; i < 34; ++i) {
        arregloNodos[i] = 0;
    }
}

Diccionario::Nodo::~Nodo() {
    for (int i = 0; i < 34; ++i) {
        if (arregloNodos[i]) {
            delete arregloNodos[i];
        }
    }
}

void Diccionario::Nodo::agregarPalabra(StringVector& vector, int cont) {

    string letra;
    string mayuscula;
    string bandera = vector.get(cont);
    int pos;
    if (bandera.compare("$")) { //condicion de parada del llamado recursivo

        for (int i = 0; i < 34; ++i) {
            letra = asignarLetra(i);
            mayuscula = asignarMayuscula(i);
            if (!(letra.compare(bandera)) || !(mayuscula.compare(bandera))) {
                pos = i;
            }
        }

        if (arregloNodos[pos]) {
            arregloNodos[pos]->agregarPalabra(vector, ++cont);
        } else {
            arregloNodos[pos] = new Nodo();
            arregloNodos[pos]->agregarPalabra(vector, ++cont);
        }
    } else {
        arregloNodos[33] = this;
    }
}

bool Diccionario::Nodo::buscarPalabra(StringVector& vector, int cont) {
    bool esta = false;
    string bandera = vector.get(cont);
    string letra;
    string mayuscula;
    int pos;

    for (int i = 0; i < 34; ++i) {
        letra = asignarLetra(i);
        mayuscula = asignarMayuscula(i);
        if (!(bandera.compare(letra)) || !(bandera.compare(mayuscula))) {
            pos = i;
        }
    }

    if (arregloNodos[pos] != 0 && bandera.compare("$")) {
        esta = arregloNodos[pos]->buscarPalabra(vector, ++cont);
    } else {
        if (!bandera.compare("$")) {
            if (arregloNodos[33] != 0) {
                esta = true;
            }
        }
    }

    return esta;
}

Diccionario::Diccionario() {
    raiz = 0;
}

Diccionario::Diccionario(const Diccionario & orig) {

}

Diccionario::Diccionario(ifstream & archivo) {

    StringVector vector;
    int cont = 0;
    string agrego;
    char finLinea = ' ';
    raiz = new Nodo();
    while (!archivo.eof()) {
        while (!archivo.eof() && (finLinea != 10)) {
            agrego = archivo.get();
            vector.agregar(agrego, cont);
            finLinea = archivo.peek();
            ++cont;
        }
        finLinea = archivo.peek();
        vector.agregar("$", cont); // coloca fin de palabra al final del buffer
        raiz->agregarPalabra(vector, 0);
        cont = 0;
        archivo.get();
        finLinea = archivo.peek();
    }
}

Diccionario::~Diccionario() {
    if (raiz) {
        delete raiz;
    }
}

void Diccionario::operator+=(char* palabra) {

    string agregar;
    if (palabra != 0) {//condicion de entrada si la palabra esta vacia
        if (!raiz) {
            raiz = new Nodo();
        }
        StringVector vector;
        int cont = 0;

        while (palabra[cont] != '\0') {
            agregar = palabra[cont];
            vector.agregar(agregar, cont);
            ++cont;
        }


        raiz->agregarPalabra(vector, 0);
    }
}

/*
void Diccionario::operator+=(Palabra& palabra) {

    string agregar;
    char* palabra2 = palabra.getPalabra();

    if (palabra2 != '\0') {//condicion de entrada si la palabra esta vacia
        if (!raiz) {
            raiz = new Nodo();
        }
        StringVector vector;
        int cont = 0;

        while (palabra2[cont] != '\0') {
            agregar = palabra2[cont];
            vector.agregar(agregar, cont);
            ++cont;
        }


        raiz->agregarPalabra(vector, 0);
    }
}
*/

bool Diccionario::operator[](char* palabra) {
    bool esta;
    string agregar;
    StringVector vector;
    int cont = 0;

    while (palabra[cont] != '\0') {
        agregar = palabra[cont];
        vector.agregar(agregar, cont);
        ++cont;
    }

    esta = raiz->buscarPalabra(vector, 0);
    return esta;
}

/*
bool Diccionario::operator[](Palabra & palabra) {
    char* palabra2 = palabra.getPalabra();
    string agregar;
    bool esta;
    StringVector vector;
    int cont = 0;

    while (palabra2[cont] != '\0') {
        agregar = palabra2[cont];
        vector.agregar(agregar, cont);
        ++cont;
    }

    esta = raiz->buscarPalabra(vector, 0);
    return esta;

}
*/

string Diccionario::Nodo::asignarLetra(int num) {

    string retorno;
    switch (num) {
        case 0: retorno = "a";
            break;
        case 1: retorno = "b";
            break;
        case 2: retorno = "c";
            break;
        case 3: retorno = "d";
            break;
        case 4: retorno = "e";
            break;
        case 5: retorno = "f";
            break;
        case 6: retorno = "g";
            break;
        case 7: retorno = "h";
            break;
        case 8: retorno = "i";
            break;
        case 9: retorno = "j";
            break;
        case 10: retorno = "k";
            break;
        case 11: retorno = "l";
            break;
        case 12: retorno = "m";
            break;
        case 13: retorno = "n";
            break;
        case 14: retorno = "o";
            break;
        case 15: retorno = "p";
            break;
        case 16: retorno = "q";
            break;
        case 17: retorno = "r";
            break;
        case 18: retorno = "s";
            break;
        case 19: retorno = "t";
            break;
        case 20: retorno = "u";
            break;
        case 21: retorno = "v";
            break;
        case 22: retorno = "w";
            break;
        case 23: retorno = "x";
            break;
        case 24: retorno = "y";
            break;
        case 25: retorno = "z";
            break;
        case 26: retorno = "Ã¡";
            break;
        case 27: retorno = "Ã©";
            break;
        case 28: retorno = "Ã­";
            break;
        case 29: retorno = "Ã³";
            break;
        case 30: retorno = "Ãº";
            break;
        case 31: retorno = "Ã¼";
            break;
        case 32: retorno = "Ã±";
            break;
        case 33: retorno = "$";
            break;
    }
    return retorno;
}

string Diccionario::Nodo::asignarMayuscula(int num) {
    string retorno;
    switch (num) {
        case 0: retorno = "A";
            break;
        case 1: retorno = "B";
            break;
        case 2: retorno = "C";
            break;
        case 3: retorno = "D";
            break;
        case 4: retorno = "E";
            break;
        case 5: retorno = "F";
            break;
        case 6: retorno = "G";
            break;
        case 7: retorno = "H";
            break;
        case 8: retorno = "I";
            break;
        case 9: retorno = "J";
            break;
        case 10: retorno = "K";
            break;
        case 11: retorno = "L";
            break;
        case 12: retorno = "M";
            break;
        case 13: retorno = "N";
            break;
        case 14: retorno = "O";
            break;
        case 15: retorno = "P";
            break;
        case 16: retorno = "Q";
            break;
        case 17: retorno = "R";
            break;
        case 18: retorno = "S";
            break;
        case 19: retorno = "T";
            break;
        case 20: retorno = "U";
            break;
        case 21: retorno = "V";
            break;
        case 22: retorno = "W";
            break;
        case 23: retorno = "X";
            break;
        case 24: retorno = "Y";
            break;
        case 25: retorno = "Z";
            break;
        case 26: retorno = "Ã";
            break;
        case 27: retorno = "Ã‰";
            break;
        case 28: retorno = "Ã";
            break;
        case 29: retorno = "Ã“";
            break;
        case 30: retorno = "Ãš";
            break;
        case 31: retorno = "Ãœ";
            break;
        case 32: retorno = "Ã‘";
            break;
        case 33: retorno = "$";
            break;
    }
    return retorno;
}



