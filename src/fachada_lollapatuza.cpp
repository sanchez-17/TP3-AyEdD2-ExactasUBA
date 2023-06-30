#include "fachada_lollapatuza.h"
#include "puesto.h"
#include "lollapatuza.h"

FachadaLollapatuza::FachadaLollapatuza(const set<Persona> &personas, const map<IdPuesto, aed2_Puesto> &infoPuestos){
    //por cada clave de infoPuestos hay q crear un puesto
    map<IdPuesto, puesto> puestos;
    puesto nuevoPuesto; //necesitamos un constructor de puesto vacío? si,está hecho.
    for(map<IdPuesto, aed2_Puesto>::const_iterator it = infoPuestos.begin(); it != infoPuestos.end(); ++it){
        Menu menu = it->second.menu;
        Stock stock = it->second.stock;
        Promociones promos = it->second.promociones;
        puestos.insert(make_pair(it->first, nuevoPuesto.crearPuesto(menu, stock, promos)));
    }
    _lolla.crearLolla(puestos, personas);
}

void FachadaLollapatuza::registrarCompra(Persona persona, Producto producto, Nat cant, IdPuesto idPuesto) {
    // TODO: Completar
    //void vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant)
    _lolla.vender(idPuesto, persona, producto, cant);
}

void FachadaLollapatuza::hackear(Persona persona, Producto producto) {
    // TODO: Completar
    _lolla.hackear(persona, producto);
}

Nat FachadaLollapatuza::gastoTotal(Persona persona) const {
    // TODO: Completar
    _lolla.gastoTotal(persona);
}

Persona FachadaLollapatuza::mayorGastador() const {
    // TODO: Completar
    _lolla.quienGastoMas();
}

IdPuesto FachadaLollapatuza::menorStock(Producto producto) const {
   // TODO: Completar
   _lolla.menorStock(producto);
}

const set<Persona> &FachadaLollapatuza::personas() const {
    // TODO: Completar
    _lolla.personas();
}

Nat FachadaLollapatuza::stockEnPuesto(IdPuesto idPuesto, const Producto &producto) const {
    puesto p;
    p = _lolla.puestos()[idPuesto];
    p.stock(producto);
}

Nat FachadaLollapatuza::descuentoEnPuesto(IdPuesto idPuesto, const Producto &producto, Nat cantidad) const {
    puesto p =_lolla.puestos()[idPuesto];
    p.descuento(producto, cantidad);
}

Nat FachadaLollapatuza::gastoEnPuesto(IdPuesto idPuesto, Persona persona) const {
    puesto p =_lolla.puestos()[idPuesto];
    p.gastosDe(persona);
}

set<IdPuesto> FachadaLollapatuza::idsDePuestos() const {
    set<IdPuesto> keys;
    for (map<IdPuesto, puesto>::iterator it = _lolla.puestos().begin(); it != _lolla.puestos().end(); ++it) {
        keys.insert(it->first);
    }
    return keys;
}

