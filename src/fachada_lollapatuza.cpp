#include "fachada_lollapatuza.h"
FachadaLollapatuza::FachadaLollapatuza(const set<Persona> &personas, const map<IdPuesto, aed2_Puesto> &infoPuestos){
    //por cada clave de infoPuestos hay q crear un puesto
    map<IdPuesto, puesto> puestos;
    //puesto nuevoPuesto;
    for(auto it:infoPuestos){
        Menu menu = it.second.menu;
        Stock stock = it.second.stock;
        Promociones promos = it.second.promociones;

        //Generamos el tipo correcto para las promociones
        map<Producto, vector<Nat>> promociones;
        for (auto it: promos){
            Nat stockItem = stock[it.first];
            vector<Nat> arr (stockItem+1,0); //vector<Nat>(stockItem+1);
            map<Nat, Nat> promosPorCant = it.second;
            auto itCantXPrm = promosPorCant.begin();//primera clave es la minima
            vector<Nat> cantidades;
            while(itCantXPrm != promosPorCant.end()){
                arr[itCantXPrm->first] = itCantXPrm->second;
                cantidades.push_back(itCantXPrm->first);
                ++itCantXPrm;
            }
            Nat j = 0;
            Nat ultCant = cantidades[0];
            Nat ultDesc = arr[cantidades[0]];
            while(ultCant < arr.size()){
                arr[ultCant]=ultDesc;
                if(ultCant+1==cantidades[j+1]){
                    j++;
                    ultDesc=arr[cantidades[j]];
                }
                ultCant++;
            }
            promociones[it.first] = arr;
        }
        //Ahora generamos el puesto correspondiente
        puesto puesto(menu,stock,promociones);
        puestos.insert(make_pair(it.first, puesto));

    }
    _lolla.crearLolla(puestos, personas);
}

void FachadaLollapatuza::registrarCompra(Persona persona, Producto producto, Nat cant, IdPuesto idPuesto) {
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
    const puesto* p = &_lolla.puestos().at(idPuesto);
    return p->stock(producto);
}

Nat FachadaLollapatuza::descuentoEnPuesto(IdPuesto idPuesto, const Producto &producto, Nat cantidad) const {
    const puesto* p = &_lolla.puestos().at(idPuesto);
    //return (_lolla.puestos().at(idPuesto)).descuento(producto, cantidad);
    return p->descuento(producto,cantidad);
}

const Nat FachadaLollapatuza::gastoEnPuesto(IdPuesto idPuesto, Persona persona) const {
    const puesto *p = &_lolla.puestos().at(idPuesto);
    return p->gastosDe(persona);
}

set<IdPuesto> FachadaLollapatuza::idsDePuestos() const {
    set<IdPuesto> keys;
    for(auto puesto:_lolla.puestos()){
        keys.insert(puesto.first);
    }
    return keys;
}

