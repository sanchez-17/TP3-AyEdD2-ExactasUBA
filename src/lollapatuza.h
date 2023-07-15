#ifndef TP_LOLLA_LOLLAPATUZA_H
#define TP_LOLLA_LOLLAPATUZA_H

#include "puesto.h"
#include "colaPriorA.h"
#include "tuplaPersona.h"

class lollapatuza{
public:
    lollapatuza();
    void crearLolla(const map<IdPuesto, puesto>& puestos, const set<Persona>& personas);
    void vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant);
    const map<IdPuesto, puesto> & puestos() const;
    const set<Persona>& personas() const;
    void hackear(Persona per, Producto producto);
    const Nat gastoTotal(Persona per) const;
    Persona quienGastoMas() const;
    IdPuesto menorStock(Producto producto) const;

private:
    set<Persona> _personas;
    map<Persona, Nat> _gastosPersona;
    colaPriorA<Nat, Persona> _colaDeGastos;
    map<IdPuesto, puesto> _puestos;
    map<Persona,map<Producto,map<IdPuesto, puesto*>>>  _hackeables;
};

#endif //TP_LOLLA_LOLLAPATUZA_H

