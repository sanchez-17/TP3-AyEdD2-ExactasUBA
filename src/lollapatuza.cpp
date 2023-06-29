#include "lollapatuza.h"

lollapatuza::lollapatuza(map<IdPuesto, puesto> puestos, set<Persona> personas) :
_personas(personas),
_punterosAGastos(),
_gastosPersona(colaPriorA<Nat, Persona>(personas.size())),
_puestos(puestos),
_hackeables()
{}

lollapatuza lollapatuza::crearLolla(map<IdPuesto, puesto> puestos, set<Persona> personas){

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

}

set<Persona> lollapatuza::personas(){

}

void lollapatuza::hackear(Persona per, Producto producto){

}

Nat lollapatuza::gastoTotal(Persona per){

}

Persona lollapatuza::quienGastoMas(){

}

IdPuesto lollapatuza::menorStock(Producto producto){

}