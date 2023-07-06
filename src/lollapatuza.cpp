#include "lollapatuza.h"

lollapatuza::lollapatuza():
_personas(),
_punterosAGastos(),
_gastosPersona(colaPriorA<Nat, Persona>(0)),
_puestos(),
_hackeables(){}


void lollapatuza::crearLolla(map<IdPuesto, puesto> puestos, set<Persona> personas){
    colaPriorA<Nat, Persona> gastosPersona(personas.size());
    map<Persona, Nat> punterosAGastos;
    for(Persona per:personas){
        tuplaPersona<Nat,Persona> tuplaPersona(0,per);
        Nat gastoActualizado = gastosPersona.encolar(tuplaPersona);
        punterosAGastos[per] = gastoActualizado;
    }
    _personas = personas;
    _puestos = puestos;
    _punterosAGastos = punterosAGastos;
    _gastosPersona = gastosPersona;
}


void lollapatuza::vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant){
    //Accedo al puesto en cuestion
    puesto* puesto = &_puestos[idPuesto];
    Nat precioProducto = puesto->precio(producto);
    //Defino el descuento/promo
    Nat descuento = puesto->descuento(producto,cant);
    //Registro la venta en el puesto
    //puesto->vender(per,producto,cant);
    Nat gastoVenta = floor(cant * ((precioProducto  * (100-descuento)) / 100) );
    //Si la venta no tuvo descuento y el puesto no era hackeable, añadir a _hackeables
    if(descuento == 0 && _hackeables[per][producto].count(idPuesto) == 0){
        _hackeables[per][producto][idPuesto] = puesto;
    }
    //Actualizo el gasto total de la persona en el lollapatuza
    Nat punteroAGasto = _punterosAGastos.at(per);
    Nat gastoActualizado = punteroAGasto + gastoVenta;
    tuplaPersona<Nat,Persona> gastoPer(gastoActualizado,per);
    //pair<Nat,Persona> gastoPer = make_pair(gastoActualizado,per);
    Nat punteroDinero = _gastosPersona.encolar(gastoPer);
    //Actualizo el puntero del gasto de la persona
    _punterosAGastos[per] = punteroDinero;
    puesto->vender(per,producto,cant);
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
    Nat gastoAnterior = _punterosAGastos[per];
    Nat precioItem = puesto->precio(producto);
    tuplaPersona<Nat,Persona> gastoPer(gastoAnterior-precioItem,per); // no es solo por el precio del prod, es por la cant comprada tmb. igual parece q da bien
    Nat gastoActual = _gastosPersona.encolar(gastoPer);
    _punterosAGastos[per] = gastoActual;


}

Nat lollapatuza::gastoTotal(Persona per)const{
    return _punterosAGastos.at(per);
}

Persona lollapatuza::quienGastoMas()const{
    Persona per = _gastosPersona.proximo().getPersona();
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