
#include "StringVector.h"

StringVector::StringVector() {
}

StringVector::StringVector(const StringVector& orig) {
}

StringVector::~StringVector() {
}

void StringVector::agregar(string caracter, int pos){
    buffer[pos] = caracter;
}

string StringVector::get(int pos){
    return buffer[pos];
}
