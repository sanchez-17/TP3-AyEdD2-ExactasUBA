#include "fachada_lollapatuza.h"
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
    //void vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant)
    _lolla.vender(idPuesto, persona, producto, cant);
}

void FachadaLollapatuza::hackear(Persona persona, Producto producto) {
    _lolla.hackear(persona, producto);
}

Nat FachadaLollapatuza::gastoTotal(Persona persona) const {
    return _lolla.gastoTotal(persona);
}

Persona FachadaLollapatuza::mayorGastador() const {
    return _lolla.quienGastoMas();
}

IdPuesto FachadaLollapatuza::menorStock(Producto producto) const {
   return _lolla.menorStock(producto);
}

const set<Persona> &FachadaLollapatuza::personas() const {
    return _lolla.personas();
}

Nat FachadaLollapatuza::stockEnPuesto(IdPuesto idPuesto, const Producto &producto) const {
    puesto* p = &_lolla.puestos()[idPuesto];
    return p->stock(producto);
}

Nat FachadaLollapatuza::descuentoEnPuesto(IdPuesto idPuesto, const Producto &producto, Nat cantidad) const {
    puesto* p = &_lolla.puestos()[idPuesto];
    return p->descuento(producto, cantidad);
}

Nat FachadaLollapatuza::gastoEnPuesto(IdPuesto idPuesto, Persona persona) const {
    puesto* p = &_lolla.puestos()[idPuesto];
    return p->gastosDe(persona);
}

set<IdPuesto> FachadaLollapatuza::idsDePuestos() const {
    set<IdPuesto> keys;
    for(auto puesto:_lolla.puestos()){
        keys.insert(puesto.first);
    }
    //for (map<IdPuesto, puesto>::iterator it = _lolla.puestos().begin(); it != _lolla.puestos().end(); ++it) {
    //    keys.insert(it->first);
    //}
    return keys;
}

