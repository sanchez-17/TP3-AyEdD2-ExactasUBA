
#ifndef TP_LOLLA_LOLLAPATUZA_H
#define TP_LOLLA_LOLLAPATUZA_H

#include "tipos.h"
#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <cmath>
#include "puesto.h"
#include "colaPriorA.h"

class lollapatuza{
public:
    lollapatuza(map<IdPuesto, puesto> puestos, set<Persona> personas);
    lollapatuza crearLolla(map<IdPuesto, puesto> puestos, set<Persona> personas);
    void vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant);
    map<IdPuesto, puesto> puestos();
    set<Persona> personas();
    void hackear(Persona per, Producto producto);
    Nat gastoTotal(Persona per);
    Persona quienGastoMas();
    IdPuesto menorStock(Producto producto);

private:
    set<Persona> _personas;
    map<Persona, Nat*> _punterosAGastos;
    map<Persona,Nat> _gastosDe;
    colaPriorA<Nat, Persona> _gastosPersona;
    map<IdPuesto, puesto> _puestos;
    map<Persona,map<Producto,map<IdPuesto, puesto*>>>  _hackeables;
};

#include "lollapatuza.cpp"



#endif //TP_LOLLA_LOLLAPATUZA_H
