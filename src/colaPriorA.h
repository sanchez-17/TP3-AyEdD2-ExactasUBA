#include "tipos.h"
#include <string>
#include <map>

template<class alpha, class beta>
class colaPriorA{
public:
    colaPriorA(int cota);
    alpha proximo(colaPriorA& cola);
    alpha& encolar(colaPriorA& cola, pair<alpha, beta> tupla);
    void desencolar(colaPriorA& cola);
    bool vacia(colaPriorA cola);

private:
    heap 

};