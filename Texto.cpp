//Texto.cpp			Implementación de la clase Texto

#include "Texto.h" // Clase Texto
#include "Diccionario.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// constructor por omisión
Texto::Texto(){
	// inicialización de las variables de instancia (atributos)
	diccionarioPtr = 0; // puntero nulo
	cantidadPalabras = 0;
	cout << "Se construyo una instancia de Texto por Omision" << endl;
	/** se usará para simular si alguna palabra está en diccionario */
	length=5; /** length del vector */
	vPalabras = new string [length];
	vPalabras[0] = "hola";
	vPalabras[1] = "mundo";
	vPalabras[2] = "mundos";
	vPalabras[3] = "ola";
	vPalabras[4] = "s";
}

int Texto::operator[](string palabra){
	int encontrado = 0; /** se usará como banderá para saber cuando detener la búsqueda */
	int i = 0;  /** variable utilizada como índice */
	while(!encontrado && i<length && i>=0){ /** mientras no se haya encontrado, que busque la palabra, sin salirse del vector */
		if(palabra == vPalabras[i]){ /** si encuentra la palabra en la celda */
			encontrado = 1; /** indica que sí está con true (valor diferente de 0) */
		}
		++i;
	}
	
	return encontrado;
}

// constructor con parámetro, que recibe puntero del diccionario a utilizar
Texto::Texto(Diccionario * diccionarioPtr){
	this->diccionarioPtr = diccionarioPtr; // asigno el puntero
	cantidadPalabras = 0; // aun no se han analizado hashtag
	// cout << "Se construyo por copia un objeto con puntero " << this->*diccionarioPtr << endl;
}

// constructor por copia; siempre es bueno tener estos 3 constructores, pero en este caso este no se utilizará
Texto::Texto(Texto & otro){
	this->diccionarioPtr = otro.diccionarioPtr;
	this->cantidadPalabras = otro.cantidadPalabras;
}

Texto::~Texto(){
	if(diccionarioPtr){ // si el puntero es 0 (nulo), no entra al if
		delete diccionarioPtr; // invoca al destructor de la instancia
		cantidadPalabras = 0;
	}
}
/*
Palabra & Texto::operator[](int i){ // devuelve la referencia de la palabra i-enésima
	Palabra * palabraPtr = 0; // inicialización en nulo

	if( i>=0 && i<cantidadPalabras ){
		palabraPtr = ; // asigno la referencia a la palabra
	}
	else{
		cerr << "Warning: La posicion de palabra ingresada es incorrecta.\nSe devuelve un puntero nulo por omisión." << endl;
	}

	return palabraPtr; // devuelve el puntero
}
*/

int Texto::getTamanyo(){ // devuelve la cantidad de palabras que forman al hashtag
	return cantidadPalabras;
}

void Texto::splitHashtag(string hashtag/*, ofstream & salida*/){ // divide el hashtag
		cout << "splitHashtag" << endl;
		splitHashtagR(hashtag, "", "", 0/*, salida*/, 0);
		cout << "ya paso el metodo splitHashtagvR" << endl;
}

void Texto::splitHashtagR(string hashtag, string divisionesH, string fragmentoH, int indice/*, ofstream & salida*/, int iteracion){
	string divisiones = "";
	if( indice < hashtag.length() ){
		divisiones = divisionesH; // almacenará los fragmentos válidos del hashtag
		string fragmento = fragmentoH; // fragmento que enviará verificar si existe en el diccionario
		bool existeFragmento = 0; // almacena si el fragmento existe

		fragmento += hashtag.at(indice); // concatena el conjunto de caracteres por buscar
		//int n = fragmento.length()+1;
		//cout << "n: " << n << endl;
		//cout << "string: " << hashtag << endl;
		//char letrasFragmento[n];
		/* for(int i=0; i<fragmento.length(); ++i){
			letrasFragmento[i]= fragmento.at(i);
			cout << "fragmento[]: " << fragmento.at(i) << endl;
			cout << "letrasFragmento[]: " << letrasFragmento[i] << endl;
		} */
		/* letrasFragmento[n-1] = '\0'; */
		// cout << "Convertir string a char *" << endl;
		char* cadena; /** almacena el string convertido a puntero a literal */
		cadena = (char *)fragmento.c_str();
		//char * letra=(char)(fragmento);
		//cout << "letras: " << letrasFragmento << endl;
		/* Intento de conversión de string a char *
		cout << "Convertido: " << cadena << endl;
		cout << "Convertido: " << (char *)fragmento.c_str() << endl;
		*/
		// existeFragmento = (*diccionarioPtr)[cadena]; // almacena si existe el fragmento
		existeFragmento = (*this)[fragmento];
		cout << "\nFragmento: " << fragmento << endl;
		cout << "Existe o no el fregmento: " << existeFragmento << endl;
		if(existeFragmento){
			divisiones += fragmento; // si es una palabra válida, la agrega a la división
			divisiones += ", ";
			fragmento = ""; // limpia la variable para analizar el próximo fragmento
		}

		splitHashtagR(hashtag, divisiones, fragmento, ++indice/*, salida*/, ++iteracion); //
	}
	else{
		if(divisiones!=""){
			cout << hashtag << ": " << divisiones << endl; // Guarda en un archivo
		}
	}
	/** que imprima las divisiones según el nivel en el que se va */
	cout << "\nIteracion: " << iteracion << endl;
	cout << "Divisiones: { " << divisiones << " }" << endl;
}
