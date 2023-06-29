#ifndef COLA_H
#define COLA_H
#include "tipos.h"
#include "tuplaPersona.h"
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
#include "colaPriorA.hpp"
#endif // COLA_H