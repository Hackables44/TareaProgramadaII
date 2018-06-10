//Texto.h		Cabecera de la clase Texto

#ifndef _TEXTO_H
#define _TEXTO_H

// clases que utilizará
#include "Diccionario.h"
//#include "Palabra.h"
#include "string"
#include <fstream>

class Texto{
	private:
		Diccionario * diccionarioPtr; // puntero al diccionario que utilizará
		int cantidadPalabras; // almacenará temporalmente la cantidad de palabras que forman un hashtag
		//ofstream salida("Hashtags.csv");
		
		/** lo siguiente se usará para simular si alguna palabra está en diccionario */
		string * vPalabras;
		int length; /** length del vector */

	public:
		// constructor por omisión
		Texto();
		// constructor con parámetro
		Texto(Diccionario * diccionarioPtr);
		// constructor por copia
		Texto(Texto & otro);
		// destructor
		~Texto();

		//Palabra & operator[](int i); // devuelve la palabra en la posición indicada
		int getTamanyo(); // devuelve la cantidad de palabras que forman al hashtag
		void splitHashtag(string hashtag/*, ofstream & salida*/); // pasa los parámetros al métod para dividir el hashtag
		void splitHashtagR(string hashtag, string divisionesH, string fragmentoH, int indice/*, ofstream & salida*/, int iteracion); // // divide el hashtag

		int operator[](string palabra); /** simulador de diccionario, busca en el vector de strings las palabras */
};

#endif
