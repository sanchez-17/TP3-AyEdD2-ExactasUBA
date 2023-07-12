#include "lollapatuza.h"

lollapatuza::lollapatuza():
        _personas(),
        _gastosPersona(),
        _colaDeGastos(),
        _puestos(),
        _hackeables(){}


void lollapatuza::crearLolla(const map<IdPuesto, puesto>& puestos, const set<Persona>& personas){
    //colaPriorA<Nat, Persona> colaGastos();
    map<Persona, Nat> gastosXPer;
    for(Persona per:personas){
        tuplaPersona<Nat,Persona> tuplaPer(0,per);
        _colaDeGastos.encolar(tuplaPer);
        gastosXPer[per] = 0;
    }
    _personas = personas;
    _puestos = puestos;
    _gastosPersona = gastosXPer;
}


void lollapatuza::vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant){
    //Accedo al puesto en cuestion
    puesto* puesto = &_puestos[idPuesto];
    Nat precioProducto = puesto->precio(producto);
    //Defino el descuento/promo
    Nat descuento = puesto->descuento(producto,cant);
    //Registro la venta en el puesto
    puesto->vender(per,producto,cant);
    Nat gastoVenta = floor(cant * ((precioProducto  * (100-descuento)) / 100) );
    //Si la venta no tuvo descuento y el puesto no era hackeable, añadir a _hackeables
    if(descuento == 0 && _hackeables[per][producto].count(idPuesto) == 0){
        _hackeables[per][producto][idPuesto] = puesto;
    }
    //Actualizo el gasto total de la persona en el lollapatuza
    Nat gastoAnterior = _gastosPersona.at(per);
    Nat gastoActualizado = gastoAnterior + gastoVenta;
    tuplaPersona<Nat,Persona> gastoPerAnt(gastoAnterior,per);
    tuplaPersona<Nat,Persona> gastoPer(gastoActualizado,per);
    _colaDeGastos.cambiarPrioridad(gastoPerAnt, gastoPer);
    //Actualizo el puntero del gasto de la persona
    _gastosPersona[per] = gastoActualizado;
}


//pruebo con puesto por referencia en vez de punteros....
//na se sigue rompiendo
//igual es mejor  idea guardarlos x ref
/*
void lollapatuza::vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant){
    //Accedo al puesto en cuestion
    puesto& puesto = _puestos[idPuesto];
    Nat precioProducto = puesto.precio(producto);
    //Defino el descuento/promo
    Nat descuento = puesto.descuento(producto,cant);
    //Registro la venta en el puesto
    puesto.vender(per,producto,cant);
    Nat gastoVenta = floor(cant * ((precioProducto  * (100-descuento)) / 100) );
    //Si la venta no tuvo descuento y el puesto no era hackeable, añadir a _hackeables
    if(descuento == 0 && _hackeables[per][producto].count(idPuesto) == 0){
        // si es por referencia aca deberian ser puestos en vez de punteros
        //_hackeables[per][producto][idPuesto] = puesto;
    }
    //Actualizo el gasto total de la persona en el lollapatuza
    Nat punteroAGasto = _punterosAGastos.at(per);
    Nat gastoActualizado = punteroAGasto + gastoVenta;
    tuplaPersona<Nat,Persona> gastoPer(gastoActualizado,per);
    //pair<Nat,Persona> gastoPer = make_pair(gastoActualizado,per);
    Nat punteroDinero = _gastosPersona.encolar(gastoPer);
    //Actualizo el puntero del gasto de la persona
    _punterosAGastos[per] = punteroDinero;
}
 */

map<IdPuesto, puesto> lollapatuza::puestos()const{
    return _puestos;
}

const set<Persona>& lollapatuza::personas() const{
    return _personas;
}

void lollapatuza::hackear(Persona per, Producto producto){
    //map<IdPuesto, puesto*>::iterator itPuesto = _hackeables[per][producto].begin();
    // se crea un iterador al dicc(idPuesto, *puesto) para obtener el de menor id
    map<IdPuesto, puesto*>::iterator itPuesto = _hackeables.at(per).at(producto).begin();
    //me guardo una copia del puntero al puesto de menor id
    puesto* puesto = itPuesto->second;
    bool dejaDeSerHackeable = puesto->reponerItem(producto,per);
    if(dejaDeSerHackeable){
        _hackeables[per][producto].erase(itPuesto);
    }
    Nat gastoAnterior = _gastosPersona[per];
    Nat precioItem = puesto->precio(producto);
    tuplaPersona<Nat,Persona> gastoPerAnt(gastoAnterior,per);
    tuplaPersona<Nat,Persona> gastoPer(gastoAnterior-precioItem,per);
    _colaDeGastos.cambiarPrioridad(gastoPerAnt, gastoPer);
    _gastosPersona[per] = gastoAnterior-precioItem;


}

const Nat lollapatuza::gastoTotal(Persona per)const{
    return _gastosPersona.at(per);
}

Persona lollapatuza::quienGastoMas()const{
    Persona per = _colaDeGastos.proximo().getPersona();
    return per;
}

IdPuesto lollapatuza::menorStock(Producto producto) const{
    map<IdPuesto, puesto>::const_iterator itPuestos = _puestos.begin();
    Nat minStock = itPuestos->second.stock(producto);
    IdPuesto idMinStock = itPuestos->first;
    while(itPuestos != _puestos.end()){
        Nat stockActual = itPuestos->second.stock(producto);
        IdPuesto idPuestoActual = itPuestos->first;
        if(stockActual < minStock || (stockActual == minStock && idPuestoActual < idMinStock)){
            minStock = stockActual;
            idMinStock = idPuestoActual;
        }
        ++itPuestos;
    }
    return idMinStock;
}