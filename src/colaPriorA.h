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
    // Constructor. Genera una cola vacía de cota posiciones.
    colaPriorA(int cota);

    // Obtiene una referencia constante al próximo elemento.
    const pair<alpha,beta>& proximo(colaPriorA& cola);

    // Encola un elemento en la cola.
    // PRE: No hay "cota" cantidad de elementos en la cola.
    alpha* encolar(colaPriorA& cola, pair<alpha, beta> tupla);

    // Desencola el próximo elemento de la cola.
    // PRE: Hay al menos un elemento en la cola.
    void desencolar(colaPriorA& cola);

    // Decide si la cola esta vacía o no.
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

//Funciones para tuplaPersona

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
    return (_tupla.first > t.first) || (_tupla.first == t.first && _tupla.second > t.second);
}

#endif // COLA_H