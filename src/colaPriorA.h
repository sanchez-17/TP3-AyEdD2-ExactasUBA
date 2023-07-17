#ifndef COLA_H
#define COLA_H
#include "tuplaPersona.h"
#include "tipos.h"
#include <vector>
#include <cmath>

template<class alpha, class beta>
class colaPriorA{
public:
    colaPriorA();
    // Constructor. Genera una cola vacía de cota posiciones.
    colaPriorA(int cota);

    // Obtiene una el siguiente elemento beta de la cola de prioridad.
    const beta proximo() const;

    // Encola un elemento en la cola.
    // PRE: No hay "cota" cantidad de elementos en la cola.
    alpha encolar(tuplaPersona<alpha, beta> gastoActualizado);

    // Desencola el próximo elemento de la cola.
    // PRE: Hay al menos un elemento en la cola.
    void desencolar();

    // Decide si la cola esta vacía o no.
    bool vacia() const;
private:
    std::vector<pair<alpha,typename map<beta, Nat>::iterator>*> _heap;
    std::vector<pair<alpha,typename map<beta, Nat>::iterator> > _tuplas;
    map<beta, Nat> _indices;
    Nat _longitud;
    Nat _cota;
    //Funciones privadas
    Nat heapifyUp(Nat i);
    Nat heapifyDown(Nat i);
};
#include "colaPriorA.hpp"
#endif // COLA_H