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

    // Obtiene una referencia constante al próximo elemento.
    const alpha proximo() const;

    // Encola un elemento en la cola.
    // PRE: La persona no fue encolada antes
    void encolar(tuplaPersona<alpha, beta> tupla);

    // Desencola el próximo elemento de la cola.
    // PRE: Hay al menos un elemento en la cola.
    void desencolar();

    // Decide si la cola esta vacía o no.
    bool vacia() const;

    //PRE: la a1 ya fue encolada antes. la a2 no.
    //tupla1 es el <gasto,persona> con el gasto anterior. a2 es el <gasto,persona> con el gasto actualizado.
    void actualizarOrden(tuplaPersona<alpha, beta> tupla1, tuplaPersona<alpha, beta> tupla2);

private:
    map<tuplaPersona<alpha, beta>, bool> _cola;
};
#include "colaPriorA.hpp"
#endif // COLA_H