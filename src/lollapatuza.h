#ifndef TP_LOLLA_LOLLAPATUZA_H
#define TP_LOLLA_LOLLAPATUZA_H

#include "puesto.h"
#include "colaPriorA.h"

class lollapatuza{
public:
/*    lollapatuza(map<IdPuesto, puesto> puestos,
                set<Persona> personas,
                map<Persona, Nat*> punterosAGastos,
                colaPriorA<Nat, Persona> gastosPersona);*/
    lollapatuza();
    void crearLolla(map<IdPuesto, puesto> puestos, set<Persona> personas);
    void vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant);
    map<IdPuesto, puesto> puestos() const;
    const set<Persona>& personas() const;
    void hackear(Persona per, Producto producto);
    Nat gastoTotal(Persona per) const;
    Persona quienGastoMas() const;
    IdPuesto menorStock(Producto producto) const;

private:
    set<Persona> _personas;
    map<Persona, Nat*> _punterosAGastos;
    colaPriorA<Nat, Persona> _gastosPersona;
    map<IdPuesto, puesto> _puestos;
    map<Persona,map<Producto,map<IdPuesto, puesto*>>>  _hackeables;
};

#endif //TP_LOLLA_LOLLAPATUZA_H
