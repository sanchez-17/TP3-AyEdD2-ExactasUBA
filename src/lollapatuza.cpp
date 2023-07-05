#include "lollapatuza.h"

lollapatuza::lollapatuza():
_personas(),
_punterosAGastos(),
_gastosPersona(colaPriorA<Nat, Persona>(0)),
_puestos(),
_hackeables(){}

/*lollapatuza::lollapatuza(map<IdPuesto,puesto> puestos,
                         set<Persona> personas,
                         map<Persona,Nat*> punterosAGastos,
                         colaPriorA<Nat,Persona> gastosPersona) :
_personas(personas),
_punterosAGastos(punterosAGastos),
_gastosPersona(gastosPersona),
_puestos(puestos),
_hackeables()
{}*/

void lollapatuza::crearLolla(map<IdPuesto, puesto> puestos, set<Persona> personas){
    colaPriorA<Nat, Persona> gastosPersona(personas.size());
    map<Persona, Nat*> punterosAGastos;
    for(Persona per:personas){
        tuplaPersona<Nat,Persona> tuplaPersona(0,per);
        auto* puntero = gastosPersona.encolar(tuplaPersona);
        punterosAGastos[per] = &puntero->first;
    }
    /*for (set<Persona>::iterator it = personas.begin(); it != personas.end(); ++it) {
        //pair<Nat, map<Persona,Nat>::iterator> t = make_pair(0,it);
        tuplaPersona<Nat,Persona> tuplaPersona(0,*it);
        //Nat* puntero = gastosPer.encolar(make_pair(0, *it));
        Nat* puntero = gastosPersona.encolar(tuplaPersona);
        punterosAGastos[*it] = puntero;
    }*/
    _personas = personas;
    _puestos = puestos;
    _punterosAGastos = punterosAGastos;
    _gastosPersona = gastosPersona;
}

void lollapatuza::vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant){
    //Accedo al puesto en cuestion
    puesto* puesto = &_puestos[idPuesto];
    //Nat precioProducto = puesto->precio(producto);
    //Defino el descuento/promo
    //Nat descuento = puesto->descuento(producto,cant);
    //Registro la venta en el puesto
    tuple<Nat,Nat> infoVenta = puesto->vender(per,producto,cant); //Descuento,gastoVenta
    Nat descuento = get<0>(infoVenta);
    Nat gastoVenta = get<1>(infoVenta);
    //Al vender el puesto nos dice la informacion de la compra: si fue con descuento y cuanto se gasto
    //Nat gastoVenta = floor(cant * ((precioProducto  * (100-descuento)) / 100) );
    //Si la venta no tuvo descuento y el puesto no era hackeable, añadir a _hackeables
    if(descuento == 0 && _hackeables[per][producto].count(idPuesto) == 0){
        _hackeables[per][producto][idPuesto] = puesto;
    }
    //Actualizo el gasto total de la persona en el lollapatuza
    Nat gastoAcumulado = _punterosAGastos.at(per);
    Nat gastoAcumActualizado = gastoAcumulado + gastoVenta;
    tuplaPersona<Nat,Persona> infoGastoPer(gastoAcumActualizado,per);
    //pair<Nat,Persona> gastoPer = make_pair(gastoActualizado,per);
    Nat gastoPer = _gastosPersona.encolar(infoGastoPer);
    /*
     * Si al encolar, cada vez que se intercambian tuplas del heap, tmb hay actualizar los punteros
     * Cada puntero apunta a una tupla del heap, si esta tupla1 se intercambia por otra tupla2. el puntero
     * existente apunta a tupla2. Se hizo un test para esto:testPunterosBasico
     */
    //Actualizo el puntero del gasto de la persona
    _punterosAGastos[per] = gastoPer;
}

map<IdPuesto, puesto> lollapatuza::puestos()const{
    return _puestos;
}

const set<Persona>& lollapatuza::personas() const{
    return _personas;
}

void lollapatuza::hackear(Persona per, Producto producto){
    map<IdPuesto, puesto*>::iterator itPuesto = _hackeables[per][producto].begin();
    puesto* puesto = itPuesto->second;
    bool dejaDeSerHackeable = puesto->reponerItem(producto,per);
    if(dejaDeSerHackeable){
        _hackeables[per][producto].erase(itPuesto); //Borramos por iterador, tmb puede ser por key
    }
    Nat* puntero = _punterosAGastos[per];
    Nat gastoAnterior = *puntero;
    Nat precioItem = puesto->precio(producto);
    tuplaPersona<Nat,Persona> gastoPer(gastoAnterior-precioItem,per);
    auto* punteroGastoActual = _gastosPersona.encolar(gastoPer);
    _punterosAGastos[per] = &punteroGastoActual->first;


}

Nat lollapatuza::gastoTotal(Persona per)const{
    //Nat orueba = *_punterosAGastos.at(per);
    return *_punterosAGastos.at(per);
}

Persona lollapatuza::quienGastoMas()const{
    //tuplaPersona<Nat,Persona> res = _gastosPersona.proximo();
    Persona per = _gastosPersona.proximo().getPersona();
    return per;
}

/*
 *  set<Persona> _personas;
    map<Persona, Nat*> _punterosAGastos;
    colaPriorA<Nat, Persona> _gastosPersona;
    map<IdPuesto, puesto> _puestos;
    map<Persona,map<Producto,map<IdPuesto, puesto*>>>  _hackeables;
 */
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