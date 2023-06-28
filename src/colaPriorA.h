#ifndef COLA_H
#define COLA_H
#include "tipos.h"
#include <string>
#include <map>
#include <vector>

template<class alpha, class beta>
class colaPriorA{
public:
    colaPriorA(int cota); //constructor
    const pair<alpha,beta>& proximo(colaPriorA& cola);
    alpha* encolar(colaPriorA& cola, pair<alpha, beta> tupla);
    void desencolar(colaPriorA& cola);
    bool vacia(colaPriorA cola);

private:
    vector<pair<alpha, typename map<beta,Nat>::iterator>> heap;
    map<beta, Nat> _indices;
    Nat _longitud;
    Nat _cota;

    Nat heapifyUp(colaPriorA cola,int index);
    Nat heapifyDown(colaPriorA cola,int index);
    pair<alpha, beta> obtenerTupla(pair<alpha, typename map<beta,Nat>::iterator> t)
};

template<class alpha, class beta>
bool pair<alpha, beta>::operator>(typename pair<alpha, beta> t) {
    return (this.first > t.first) || (this.first == t.first && this.second == t.second)
}

#include "colaPriorA.hpp"

#endif // COLA_H