

#ifndef PALABRA_H
#define PALABRA_H
#include <iostream>
#include <fstream>

class Palabra {
  friend std::ostream& operator<<(std::ostream&, Palabra&);
	friend std::istream& operator>>(std::istream&, Palabra&);

	private:
		char* palabra;
		int longitud;

	public:
		//Constructor de la clase Palabra
		Palabra();

		//Constructor por parametro de la clase Palabra
		Palabra(const char*);

		//Constructor por copia de la clase Palabra
		Palabra(const Palabra&);

		//Destructor de la clase Palabra
		~Palabra();

		//Sobrecarga del operador == para ver si la palabra ya existe o no, 0 es false y cualquier otro numero es true
		int operator==(const Palabra&);

		//Sobrecarga del operador + que en este caso lo usaremos para concatenar Palabras
		Palabra operator+(Palabra&);

		//Sobrecarga del operador = para asignar una palabra a otra
		Palabra& operator=(const Palabra&);

		//Sobrecarga del operador += para ir agregando palabras a la clase diccionario
		Palabra& operator+=(std::istream&);

		//Retorna el atributo palabra de la clase Palabra
		 char* getPalabra();

		//Asigna un nuevo valor al atributo palabra de la clase Palabra
		void setPalabra(const char*);

		//Metodo que me devuelve la longitud de la palabra en la clase Palabra
		int getLongitud();

		std::ostream& imprimir(std::ostream&);

		std::istream& cargar(std::istream&);

};

#endif /* PALABRA_H */
