#include "lollapatuza.h"

lollapatuza::lollapatuza()=default;

lollapatuza::lollapatuza(map<IdPuesto, puesto>& puestos, const set<Persona>& personas){
    for(Persona per:personas){
        tuplaPersona<Nat,Persona> tuplaPer(0,per);
        _colaDeGastos.encolar(tuplaPer);
        _gastosPersona[per] = 0;
    }
    _personas = personas;
    _puestos = puestos;
}


void lollapatuza::vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant){
    //Accede al puesto en cuestion
    puesto* puesto = &_puestos[idPuesto];                                                       //O(1)
    //Registra la venta en el puesto
    pair<bool,Nat>infoVenta = puesto->vender(per,producto,cant);                                //O(log(A)+log(I))
    //Al vender en el puesto, da la informacion sobre el gasto de la venta y si se hizo sin descuento
    bool eshackeable = infoVenta.first;                                                         //O(1)
    Nat gastoVentaEnPuesto = infoVenta.second;                                                  //O(1)
    if(eshackeable) {                                                                           //O(1)
        _hackeables[per][producto][idPuesto] = puesto;                                          //O(log(A)+log(I)+log(P))
    }
    //Actualiza el gasto total de la persona en el lollapatuza
    Nat gastoAntEnLolla = _gastosPersona.at(per);                                            //log(A)
    Nat gastoActualizado = gastoAntEnLolla + gastoVentaEnPuesto;                                //O(1)
    tuplaPersona<Nat,Persona> gastoPerAnt(gastoAntEnLolla,per);                           //O(1)
    tuplaPersona<Nat,Persona> gastoPer(gastoActualizado,per);                             //O(1)
    _colaDeGastos.actualizarOrden(gastoPerAnt, gastoPer);                          //O(log(A))
    //Actualiza el puntero del gasto de la persona
    _gastosPersona[per] = gastoActualizado;                                                    //O(log(A))
} //Complejidad: O(log(A)+log(I)+log(P))

const map<IdPuesto, puesto> & lollapatuza::puestos() const {
    return _puestos;
}

const set<Persona>& lollapatuza::personas() const{
    return _personas;
}

void lollapatuza::hackear(Persona per, Producto producto){
    //Crea un iterador al dicc(idPuesto, *puesto) para obtener el de menor id
    map<IdPuesto, puesto*>::iterator itPuesto = _hackeables.at(per).at(producto).begin();   //O(log(A)+log(I))
    //Guarda una copia del puntero al puesto de menor id
    puesto* puesto = itPuesto->second;                                                           //O(1)
    bool dejaDeSerHackeable = puesto->reponerItem(producto,per);                         //O(log(A)+log(I))
    if(dejaDeSerHackeable){
        _hackeables[per][producto].erase(itPuesto);                                      //O(log(A)+log(I)+log(P))
    }
    Nat gastoAnterior = _gastosPersona[per];                                                    //O(log(A))
    Nat precioItem = puesto->precio(producto);                                                  //O(log(I))
    tuplaPersona<Nat,Persona> gastoPerAnt(gastoAnterior,per);                             //O(1)
    tuplaPersona<Nat,Persona> gastoPer(gastoAnterior-precioItem,per);                     //O(1)
    _colaDeGastos.actualizarOrden(gastoPerAnt, gastoPer);                          //O(log(A))
    _gastosPersona[per] = gastoAnterior-precioItem;                                            //O(log(A))
} //Complejidad: O(log(A)+log(I)+log(P))

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