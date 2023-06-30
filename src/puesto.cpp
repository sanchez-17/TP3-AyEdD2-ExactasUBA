#include "puesto.h"

puesto::puesto(){}

puesto::puesto(Menu menu,Stock stock,map<Producto, vector<Nat>> promos):
_menu(menu),
_stock(stock),
_descuentos(promos),
_ventasSinDesc(),
_ventas(),
_gastosDe()
{}

puesto puesto::crearPuesto(Menu menu, Stock stock, Promociones promos){
    map<Producto, vector<Nat>> promociones;
    for (Promociones::iterator it = promos.begin(); it != promos.end(); ++it){
        Nat stockItem = stock[it->first];
        vector<Nat> arr = vector<Nat>(stockItem+1);
        map<Nat, Nat> promosPorCant = it->second;
        map<Nat, Nat>::iterator itCantXPrm = promosPorCant.begin();//primera clave es la minima
        Nat cant = 1;
        Nat minPromo = itCantXPrm->second;
        Nat ultCant = minPromo;//ver
        while(cant<=stockItem) {
            //El array son todos ceros hasta hallar alguna promo para alguna cant i.
            if(cant < minPromo){
                arr[cant] = 0;
            }else {
                if (promosPorCant.count(cant) == 1) {
                    arr[cant] = promosPorCant[cant];
                    ultCant = cant;
                } else {
                    arr[cant] = promosPorCant[ultCant];
                }
            }
            cant++;
        }
        _descuentos[it->first] = arr;
    }
    return puesto(menu,stock,promociones);
}

void puesto::vender(Persona per, Producto producto, Nat cant) {
    Nat nuevoGasto = floor(_menu[producto] * (100 - _descuentos[producto][cant]) / 100);
    if (_gastosDe.count(per) == 1) { nuevoGasto += _gastosDe[per]; }
    _gastosDe[per] = nuevoGasto;
    _ventas[per].push_back(make_pair(producto,cant));
    if(_descuentos[producto][cant] == 0){
        list<tuple<Producto,Nat>>::iterator itVenta = _ventas[per].end()--;
        _ventasSinDesc[per][producto].push_back(itVenta);
    }
}

set<Producto> puesto::menu() {
    set<Producto> conjMenu;
    for (Menu::iterator it = _menu.begin(); it != _menu.end(); ++it) {
        conjMenu.insert(it->first);
    }
    return conjMenu;
}
Nat puesto::precio(Producto producto){
    return _menu[producto];
}

Nat puesto::stock(Producto producto){
    if(_stock.count(producto) > 0){
        return _stock[producto];
    }else{
        return 0;
    }
}

Nat puesto::descuento(Producto producto, Nat cant){
    if(_descuentos.count(producto)>0){
        return _descuentos[producto][cant];
    }else{
        return 0;
    }
}

Nat puesto::gastosDe(Persona per){
    return _gastosDe[per];
}

//funcion que se realiza al hackear un lolla
bool puesto::reponerItem(Producto producto, Persona per){
    bool dejaDeSerHackeable = false;
    ventasDeProd* listaVentas = &_ventasSinDesc[per][producto];
    ventasDeProd::iterator itListaVentas = listaVentas->begin();
    itLista itVenta = *itListaVentas;
    if ( std::get<1>(*itVenta) != 1){
        //Cambio la tupla a traves del iterador
        *itVenta = tuple<Persona,Nat>(per,  std::get<1>(*itVenta) - 1);
    }else{
        //Elimino la venta
        _ventas[per].erase(itVenta);
        if(listaVentas->size() == 1){
            _ventasSinDesc[per][producto] = ventasDeProd();
            dejaDeSerHackeable = true;
        }
        _ventasSinDesc[per][producto].erase(itListaVentas);
    }
    _stock[producto] += 1;
    _gastosDe[per] -= _menu[producto];
    return dejaDeSerHackeable;
}
