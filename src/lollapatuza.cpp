#include "lollapatuza.h"

lollapatuza::lollapatuza(map<IdPuesto, puesto> puestos, set<Persona> personas, map<Persona, Nat*> punteros, colaPriorA<Nat, Persona> gastosPer) :
_personas(personas),
_punterosAGastos(punteros),
_gastosPersona(gastosPer),
_puestos(puestos),
_hackeables()
{}

lollapatuza lollapatuza::crearLolla(map<IdPuesto, puesto> puestos, set<Persona> personas){
    colaPriorA<Nat, Persona> gastosPer = colaPriorA<Nat, Persona>(personas.size());
    map<Persona, Nat*> punteros;
    for (set<Persona>::iterator it = personas.begin(); it != personas.end(); ++it) {
        Nat* puntero = encolar(gastosPer, make_pair(0, *it));
        punteros[*it] = puntero;
    }
    return lollapatuza(puestos, personas, gastosPer, punteros);
}

void lollapatuza::vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant){
    //Accedo al puesto en cuestion
    puesto* puesto = &_puestos[idPuesto];
    Nat precioProducto = puesto->precio(producto);
    //Defino el descuento/promo
    Nat descuento = puesto->descuento(producto,cant);
    //Registro la venta en el puesto
    puesto->vender(per,producto,cant);
    Nat gastoVenta = floor(cant * precioProducto * (100-descuento) / 100 );
    //Si la venta no tuvo descuento y el puesto no era hackeable, añadir a _hackeables
    if(descuento == 0 && _hackeables[per][producto].count(idPuesto) == 0){
        _hackeables[per][producto][idPuesto] = puesto;
    }
    //Actualizo el gasto total de la persona en el lollapatuza
    Nat* punteroAGasto = _punterosAGastos[per];
    Nat gastoActualizado = *punteroAGasto + gastoVenta;
    pair<Nat,Persona> gastoPer = make_pair(gastoActualizado,per);
    Nat* punteroDinero = _gastosPersona.encolar(gastoPer);

}

map<IdPuesto, puesto> lollapatuza::puestos(){
    return _puestos;
}

set<Persona> lollapatuza::personas(){
    return _personas;
}

void lollapatuza::hackear(Persona per, Producto producto){

}

Nat lollapatuza::gastoTotal(Persona per){
    return *_punterosAGastos[per];
}

Persona lollapatuza::quienGastoMas(){
    return (proximo(_gastosPersona)).second;
}

IdPuesto lollapatuza::menorStock(Producto producto){

}