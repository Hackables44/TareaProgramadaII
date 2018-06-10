
//#include "Diccionario.h"
#include <iostream>
#include "Svg.h"
#include <fstream>
#include "Diccionario.h"
#include "Texto.h"
#include <cstring>
#include <string>
//
using namespace std;
/*
 *
 */
int main() {

  int opcion;
  bool programOn = true;
  Texto texto;
  string hashtag;
	Svg svg;
  ifstream archivo("pruebaEntradaDiccionario.txt", ios::in);
  Diccionario diccionario(archivo);
  fstream hashtagsDoc("hashtags.csv");

  while (programOn) {
    cout << "******************** MENU *********************\n";
    cout << " 1 - Cargar documento para extraer #Hashtags.\n";
    cout << " 2 - Cargar diccionario.\n";
    cout << " 3 - Guardar hashtags y sus posibles divisiones.\n";
    cout << " 4 - Guardar la mejor division de hashtags.\n";
    cout << " 5 - Ver palabra en diccionario.\n";
    cout << " 6 - Salir.\n";
    cout << " Escoge tu opcion y apreta enter: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      cout << "Cargando documento para extraer #Hashtags.\n";

      if(!hashtagsDoc.is_open()) std::cout << "Error: File Open" << '\n';
        while (hashtagsDoc.good()) {
          getline(hashtagsDoc,hashtag,'\n');
          cout << hashtag << '\n';
          std::string textoo = hashtag;
          texto.splitHashtag(textoo);
        }
      hashtagsDoc.close();

    break;

    case 2:
      cout << "Cargado.\n";
    break;

    case 3:
      cout << "Guardando hashtags y sus posibles divisiones.\n";
    break;

    case 4:
      cout << "Guardando mejor division de hashtags.\n";
	  /*
	  if(!hashtagsDoc.is_open()) std::cout << "Error: File Open" << '\n';
        while (hashtagsDoc.good()) {
          getline(hashtagsDoc,hashtag,'\n');
          cout << hashtag << '\n';
          std::string textoo = hashtag;
          texto.splitHashtag(textoo);
        }
      hashtagsDoc.close();*/
	  texto.splitHashtag("holamundos");
    break;

    case 5:
      cout << "Ingrese la palabara que desea buscar.\n";
      svg.crearSvg();
    break;

    case 6:
    cout << "Fin del programa.\n";
    programOn= 0;
    break;

    default:
    cout << "Opción inválida. \n"
    << "Escoge de nuevo.\n";
    cin >> opcion;
    break;
    }
  }
    return 0;
}
