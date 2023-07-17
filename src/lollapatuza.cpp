#include "lollapatuza.h"
lollapatuza::lollapatuza()=default;

lollapatuza::lollapatuza(map<IdPuesto, puesto>& puestos,const set<Persona>& personas){
    _colaDeGastos = colaPriorA<Nat, Persona>(personas.size());
    for(Persona per:personas){
        tuplaPersona<Nat,Persona> tuplaPersona(0,per);
        Nat gastoActualizado = _colaDeGastos.encolar(tuplaPersona);
        _gastosPorPersona[per] = gastoActualizado;
    }
    _personas = personas;
    _puestos = puestos;
}


void lollapatuza::vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant){
    //Accedo al puesto en cuestion
    puesto* puesto = &_puestos[idPuesto];                                               //O(1)
    //Registro la venta en el puesto
    pair<bool,Nat>infoVenta = puesto->vender(per,producto,cant);                         //O(log(A)+log(I))
    //Al vender en el puesto, me da la informacion sobre el gasto de la venta y si se hizo sin descuento.
    bool eshackeable = infoVenta.first;                                                  //O(1)
    Nat gastoVentaEnPuesto = infoVenta.second;                                           //O(1)
    if(eshackeable) {
        _hackeables[per][producto][idPuesto] = puesto;                                   //O(log(A)+log(I)+log(P))
    }
    //Actualizo el gasto total de la persona en el lollapatuza
    Nat gastoAntEnLolla = _gastosPorPersona.at(per);                                   //O(1)
    Nat gastoActualizado = gastoAntEnLolla + gastoVentaEnPuesto;                         //O(1)
    tuplaPersona<Nat,Persona> gastoPer(gastoActualizado,per);                       //O(1)
    Nat gastoEnLolla = _colaDeGastos.encolar(gastoPer);                     //O(log(A))
    //Actualizo el puntero del gasto de la persona
    _gastosPorPersona[per] = gastoEnLolla;                                               //O(log(A))
}//Complejidad: O(log(A)+log(I)+log(P))

const map<IdPuesto, puesto>& lollapatuza::puestos()const{
    return _puestos;
}

const set<Persona>& lollapatuza::personas() const{
    return _personas;
}

void lollapatuza::hackear(Persona per, Producto producto){
    // se crea un iterador al dicc(idPuesto, *puesto) para obtener el de menor id
    map<IdPuesto, puesto*>::iterator itPuesto = _hackeables.at(per).at(producto).begin();
    //me guardo una copia del puntero al puesto de menor id
    puesto* puesto = itPuesto->second;
    bool dejaDeSerHackeable = puesto->reponerItem(producto,per);
    if(dejaDeSerHackeable){
        _hackeables[per][producto].erase(itPuesto);
    }
    Nat gastoAnterior = _gastosPorPersona[per];
    Nat precioItem = puesto->precio(producto);
    tuplaPersona<Nat,Persona> gastoPer(gastoAnterior-precioItem,per);
    Nat gastoActual = _colaDeGastos.encolar(gastoPer);
    _gastosPorPersona[per] = gastoActual;


}

const Nat lollapatuza::gastoTotal(Persona per)const{
    return _gastosPorPersona.at(per);
}

const Persona lollapatuza::quienGastoMas()const{
    return _colaDeGastos.proximo();
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