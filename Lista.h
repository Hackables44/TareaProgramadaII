
#ifndef LISTA_H
#define LISTA_H

class Lista{
  class Celda;
  private:
    Celda * primera;
    Celda * ultima;

    class Celda{
      public:
        char* texto[1024];
        Celda * siguiente;
        Celda(char*);
       ~Celda();
    };

  public:
     Lista();
    ~Lista();
    void agregarAlInicio(char*);
    void agregarAlFinal(char*);


};
#endif
