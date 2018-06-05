
//#include "Diccionario.h"
#include <iostream>
#include <fstream>
#include "Lista.h"
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
  string hashtag;
  Lista lista;

  fstream hashtagsDoc("hashtags.csv");

  while (programOn) {
    cout << "******************** MENU *********************\n";
    cout << " 1 - Cargar documento para extraer #Hashtags.\n";
    cout << " 2 - Cargar diccionario.\n";
    cout << " 3 - Guardar hashtags y sus posibles divisiones.\n";
    cout << " 4 - Guardar la mejor division de hashtags.\n";
    cout << " 5 - Ver palabra en diccionario.\n";
    cout << " 6 - Salir.\n";
    cout << " Escoge tu opción y apreta enter: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      cout << "Cargando documento para extraer #Hashtags.\n";

      if(!hashtagsDoc.is_open()) std::cout << "Error: File Open" << '\n';

      while (hashtagsDoc.good()) {
        getline(hashtagsDoc,hashtag,'\n');
        cout << hashtag << '\n';

        std::string texto = hashtag;
        char *vHashtag = new char[texto.length() + 1];
        std::strcpy(vHashtag, texto.c_str());

        lista.agregarAlInicio(vHashtag);

        delete[] vHashtag;
      }
      hashtagsDoc.close();
    break;
    case 2:
      cout << "Cargando diccionario.\n";
    break;
    case 3:
      cout << "Guardando hashtags y sus posibles divisiones.\n";
    break;
    case 4:
      cout << "Guardando mejor division de hashtags.\n";
    break;
    case 5:
      cout << "Ingrese la palabara que desea buscar.\n";
      //cin>>palabra;
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
