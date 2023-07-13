#ifndef COLA_H
#define COLA_H
#include "tuplaPersona.h"
#include "tipos.h"
#include <vector>
#include <cmath>

template<class alpha>
class colaPriorA{
public:
    colaPriorA();

    // Obtiene una referencia constante al próximo elemento.
    const alpha proximo() const;

    // Encola un elemento en la cola.
    // PRE: La persona no fue encolada antes
    void encolar(alpha a);

    // Desencola el próximo elemento de la cola.
    // PRE: Hay al menos un elemento en la cola.
    void desencolar();

    // Decide si la cola esta vacía o no.
    bool vacia() const;

    //PRE: la a1 ya fue encolada antes. la a2 no.
    //a1 es el <gasto,persona> con el gasto anterior. a2 es el <gasto,persona> con el gasto actualizado.
    void actualizarOrden(alpha a1, alpha a2);

private:
    map<alpha, bool> _cola;
};
#include "colaPriorA.hpp"
#endif // COLA_H