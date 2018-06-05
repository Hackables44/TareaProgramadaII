#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;

Lista::Celda::Celda(char* texto){
}
Lista::Celda::~Celda(){
  if (siguiente) {
    delete siguiente;
    siguiente = 0;
  }
}

Lista::Lista(){
}

Lista::~Lista(){
  if (primera) {
    delete primera;
    primera = 0;
  }
    ultima = 0;
}

void Lista::agregarAlInicio(char* texto){
  Celda * nueva = new Celda (texto);
  nueva->siguiente = this->primera;
  if (ultima==0) {
    this->ultima = nueva;
  }
}

void Lista::agregarAlFinal(char* texto){
  Celda * nueva = new Celda (texto);
  if (this->primera==0) {
    this->agregarAlInicio(texto);
  }
  this->ultima->siguiente = nueva;
  //this->ultima->nueva;
}
