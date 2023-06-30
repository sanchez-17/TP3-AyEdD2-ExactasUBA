#ifndef TP_LOLLA_LOLLAPATUZA_H
#define TP_LOLLA_LOLLAPATUZA_H

// ya estan los #includes en puesto.h
//#include "tipos.h"
//#include <string>
//#include <map>
//#include <vector>
//#include <list>
//#include <set>
//#include <cmath>
#include "puesto.h"
#include "colaPriorA.h"

class lollapatuza{
public:
    lollapatuza();
    lollapatuza(map<IdPuesto, puesto> puestos,
                set<Persona> personas,
                map<Persona, Nat*> punterosAGastos,
                colaPriorA<Nat, Persona> gastosPersona);

    lollapatuza crearLolla(map<IdPuesto, puesto> puestos, set<Persona> personas);
    void vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant);
    map<IdPuesto, puesto> puestos();
    set<Persona> personas() const;
    void hackear(Persona per, Producto producto);
    Nat gastoTotal(Persona per);
    Persona quienGastoMas();
    IdPuesto menorStock(Producto producto);

private:
    set<Persona> _personas;
    map<Persona, Nat*> _punterosAGastos;
    colaPriorA<Nat, Persona> _gastosPersona;
    map<IdPuesto, puesto> _puestos;
    map<Persona,map<Producto,map<IdPuesto, puesto*>>>  _hackeables;
};

#include "lollapatuza.cpp"



#endif //TP_LOLLA_LOLLAPATUZA_H
