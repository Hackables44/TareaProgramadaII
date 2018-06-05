//Texto.h		Cabecera de la clase Texto

#ifndef _TEXTO_H
#define _TEXTO_H

// clases que utilizará
#include "Diccionario.h"
#include "Palabra.h"
#include "string"


class Texto{
	private:
		Diccionario * diccionarioPtr; // puntero al diccionario que utilizará
		int cantidadPalabras; // almacenará temporalmente la cantidad de palabras que forman un hashtag
		ofstream salida("Hashtags.csv");
		
	public:
		// constructor por omisión
		Texto();
		// constructor con parámetro
		Texto(const Diccionario * diccionarioPtr);
		// constructor por copia
		Texto(const Texto & otro);
		// destructor
		~Texto();
		
		Palabra & operator[](int i); // devuelve la palabra en la posición indicada
		int getTamanyo(); // devuelve la cantidad de palabras que forman al hashtag
		void splitHashtag(string hashtag); // pasa los parámetros al métod para dividir el hashtag
		void splitHashtagR(string hashtag, string divisionesH, string fragmentoH, int indice); // // divide el hashtag
		
};

#endif