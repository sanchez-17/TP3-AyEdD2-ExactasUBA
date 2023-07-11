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
    void encolar(alpha tupla);

    // Desencola el próximo elemento de la cola.
    // PRE: Hay al menos un elemento en la cola.
    //void desencolar();

    // Decide si la cola esta vacía o no.
    // bool vacia();

    //PRE: la tupla1 ya fue encolada antes. la tupla 2 no.
    //tupla1 tendria q ser el <gasto,persona> viejo. tupla2 es el <gasto,persona> nuevo.
    void cambiarPrioridad(alpha tupla1, alpha tupla2);

private:
    map<alpha, bool> _cola; //el bool es basura
};
#include "colaPriorA.hpp"
#endif // COLA_H