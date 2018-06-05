
#include "Palabra.h"
#include <iostream>
#include <string.h> //libreria para poder utilizar los strings
#include <stdio.h>
#include <fstream>
using namespace std;

//Constructor de la clase Palabra
		Palabra::Palabra(){
			palabra = new char[1];
			palabra[0] = '\0';
			longitud = 0;
			cout << "se entro al constructor por omision" << endl;
		}

		//Constructor por parametro de la clase Palabra
		Palabra::Palabra(const char* palabra){
			this->setPalabra(palabra);
			cout << "se entro al constructor por parametro" << endl;
		}

		//Constructor por copia de la clase Palabra
		Palabra::Palabra(const Palabra& otro){
			this->setPalabra(otro.palabra);
			cout << "se entro al constructor por copia" << endl;
		}

		//Destructor de la clase Palabra
		Palabra::~Palabra(){
			cout << "Se va a morir: " << this->palabra << endl;
		}

		//Sobrecarga del operador == para ver si la palabra ya existe o no, 0 es false y cualquier otro numero es true
		int Palabra::operator==(const Palabra& otro){
			int result = 0;
			if(strcmp(palabra,otro.palabra) != 0){
				cout << "son diferentes" << endl;
			}
			else{
				cout << "son iguales" << endl;
			}
			return result;
		}

		//Sobrecarga del operador + que en este caso lo usaremos para concatenar Palabras
		Palabra Palabra::operator+(Palabra& otro){
			int newLongitud = this->getLongitud() + otro.getLongitud() + 2;
			char* newPalabra = new char[newLongitud];
			int i = 0;
			while(this->palabra[i]){
				newPalabra[i] = this->palabra[i];
				++i;
			}
			newPalabra[i] = ',';
			++i;
			newPalabra[i] = ' ';
			++i;
			int s = 0;
			while(otro.palabra[s]){
				newPalabra[i] = otro.palabra[s];
				++i;
				++s;
			}
			newPalabra[i] = '\0';
			Palabra palabra(newPalabra);
			return palabra;
		}

		//Sobrecarga del operador = para asignar una palabra a otra
		Palabra& Palabra::operator=(const Palabra& otro){
			this->setPalabra(otro.palabra);
			return *this;

		}

		Palabra& Palabra::operator+=(istream& entrada){
			Palabra palabra;
			char* local = (char*)entrada;
			palabra.setPalabra(local);
			return palabra;
		}

		void Palabra::setPalabra(const char* palabra){
			this->palabra = new char [99];
			int i = 0;
			while(i < 99 && palabra[i]){
				this->palabra[i] = palabra[i];
				++i;
			}
			this->palabra[i] = '\0';
			this->longitud = i;
		}

		char* Palabra::getPalabra(){
			return palabra;
		}

		int Palabra::getLongitud(){

			return longitud;
		}

		ostream& operator<<(ostream& salida, Palabra& palabra){
			palabra.imprimir(salida);
			return salida;
		}

		std::ostream& Palabra::imprimir(std::ostream& salida){
			for(int i = 0; i < longitud; ++i){
				salida << palabra[i] << endl;
			}
			return salida;
		}

		std::istream& Palabra::cargar(std::istream& entrada){
			entrada >> longitud;
			setPalabra((char*)entrada);
			for(int i=0; i < longitud; ++i){
				entrada >> this->palabra[i];
			}
			return entrada;
		}

		std::istream& operator>>(std::istream&, Palabra palabra&){
			palabra.cargar(entrada);
			return entrada;
		}
