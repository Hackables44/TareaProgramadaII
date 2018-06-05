#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H
#include <string>
using namespace std;

class StringVector {
public:
    StringVector();
    StringVector(const StringVector& orig);
    ~StringVector();
    void agregar(string, int);
    string get(int);

private:
    string buffer[30];
};

#endif /* STRINGVECTOR_H */
