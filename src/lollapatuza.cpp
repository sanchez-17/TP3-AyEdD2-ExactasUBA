#include "lollapatuza.h"

lollapatuza::lollapatuza():
        _personas(),
        _gastosPersona(),
        _colaDeGastos(),
        _puestos(),
        _hackeables(){}


void lollapatuza::crearLolla(const map<IdPuesto, puesto>& puestos, const set<Persona>& personas){
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
    //Registro la venta en el puesto
    pair<bool,Nat>infoVenta = puesto->vender(per,producto,cant);
    //Al vender en el puesto, me da la informacion sobre el gasto de la venta y si se hizo sin descuento.
    bool eshackeable = infoVenta.first;
    Nat gastoVentaEnPuesto = infoVenta.second;
    if(eshackeable) {
        _hackeables[per][producto][idPuesto] = puesto;
    }
    //Actualizo el gasto total de la persona en el lollapatuza
    Nat gastoAntEnLolla = _gastosPersona.at(per);
    Nat gastoActualizado = gastoAntEnLolla + gastoVentaEnPuesto;
    tuplaPersona<Nat,Persona> gastoPerAnt(gastoAntEnLolla,per);
    tuplaPersona<Nat,Persona> gastoPer(gastoActualizado,per);
    _colaDeGastos.actualizarOrden(gastoPerAnt, gastoPer);
    //Actualizo el puntero del gasto de la persona
    _gastosPersona[per] = gastoActualizado;

}

const map<IdPuesto, puesto> & lollapatuza::puestos() const {
    return _puestos;
}

const set<Persona>& lollapatuza::personas() const{
    return _personas;
}

void lollapatuza::hackear(Persona per, Producto producto){
    // se crea un iterador al dicc(idPuesto, *puesto) para obtener el de menor id
    map<IdPuesto, puesto*>::iterator itPuesto = _hackeables.at(per).at(producto).begin();//O(log(A)+log(I))
    //me guardo una copia del puntero al puesto de menor id
    puesto* puesto = itPuesto->second;                                          //O(1)
    bool dejaDeSerHackeable = puesto->reponerItem(producto,per);        //O(log(A)+log(I))
    if(dejaDeSerHackeable){
        _hackeables[per][producto].erase(itPuesto);                     //O(log(A)+log(I)+log(P))
    }
    Nat gastoAnterior = _gastosPersona[per];                                    //O(log(A))
    Nat precioItem = puesto->precio(producto);                                  //O(log(I))
    tuplaPersona<Nat,Persona> gastoPerAnt(gastoAnterior,per);              //O(1)
    tuplaPersona<Nat,Persona> gastoPer(gastoAnterior-precioItem,per);      //O(1)
    _colaDeGastos.actualizarOrden(gastoPerAnt, gastoPer);           //O(log(A))
    _gastosPersona[per] = gastoAnterior-precioItem;                             //O(log(A))

}

const Nat lollapatuza::gastoTotal(Persona per)const{
    return _gastosPersona.at(per);
}

Persona lollapatuza::quienGastoMas()const{
    Persona per = _colaDeGastos.proximo();
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