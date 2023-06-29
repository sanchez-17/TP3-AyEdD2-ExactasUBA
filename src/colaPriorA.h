#ifndef COLA_H
#define COLA_H
#include "tipos.h"
#include <string>
#include <map>
#include <vector>
#include <cmath>


template<class alpha, class beta>
class colaPriorA{
public:
    colaPriorA(int cota); //constructor
    const pair<alpha,beta>& proximo(colaPriorA& cola);
    alpha* encolar(colaPriorA& cola, pair<alpha, beta> tupla);
    void desencolar(colaPriorA& cola);
    bool vacia(colaPriorA cola);

private:
    vector<pair<alpha, typename map<beta,Nat>::iterator>> _heap;
    map<beta, Nat> _indices;
    Nat _longitud;
    Nat _cota;
    //Funciones privadas
    Nat heapifyUp(colaPriorA<alpha,beta> cola,Nat index);
    Nat heapifyDown(colaPriorA<alpha,beta> cola,Nat index);
    pair<alpha, beta> obtenerTupla(pair<alpha, typename map<beta,Nat>::iterator> t);
};

template<class alpha, class beta>
class tuplaPersona{
public:
    tuplaPersona(alpha gastoPersona, beta persona);
    bool operator>(tuplaPersona h);
private:
    tuple<alpha,beta> _tupla;
};

template<class alpha, class beta>
tuplaPersona<alpha,beta>::tuplaPersona(alpha gastoPersona, beta persona){
    _tupla = make_pair(gastoPersona,persona);
}

template<class alpha, class beta>
bool tuplaPersona<alpha, beta>::operator>(tuplaPersona t) {
    return (_tupla.first > t.first) || (_tupla.first == t.first && _tupla.second == t.second);
}

#endif // COLA_H