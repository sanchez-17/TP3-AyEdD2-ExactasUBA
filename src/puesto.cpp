#include "puesto.h"

//puesto::puesto() = default;
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
        vector<Nat> arr (stockItem+1,0); //vector<Nat>(stockItem+1);
        map<Nat, Nat> promosPorCant = it->second;
        map<Nat, Nat>::iterator itCantXPrm = promosPorCant.begin();//primera clave es la minima
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
        promociones[it->first] = arr;
    }
    return puesto(menu,stock,promociones);
}

void puesto::vender(Persona per, Producto producto, Nat cant) {
    Nat descuento = this->descuento(producto,cant);
    //Calculamos el gasto a realizar con el descuento correspondiente
    Nat precio = this->precio(producto);
    Nat nuevoGasto = floor(precio * cant * (100 - descuento) / 100);
    //Actualizamos el stock del item en el puesto
    _stock[producto] = stock(producto) - cant;
    //Actualizamos el gasto acumulado de la persona
    if (_gastosDe.count(per) == 1) { nuevoGasto += this->_gastosDe.at(per); }
    this->_gastosDe[per] = nuevoGasto; //se rompe
    _ventas[per].push_back(make_pair(producto,cant));
    if(descuento == 0){
        list<tuple<Producto,Nat>>::iterator itVenta = --_ventas[per].end();
        _ventasSinDesc[per][producto].push_back(itVenta);
    }
}

set<Producto> puesto::menu()const{
    set<Producto> conjMenu;
    for (Menu::const_iterator it = _menu.begin(); it != _menu.end(); ++it) {
        conjMenu.insert(it->first);
    }
    return conjMenu;
}
Nat puesto::precio(Producto producto)const{
    return _menu.at(producto);
}

Nat puesto::stock(Producto producto)const{
    if(_stock.count(producto) > 0){
        return _stock.at(producto);
    }else{
        return 0;
    }
}

Nat puesto::descuento(Producto producto, Nat cant){
    if(_descuentos.count(producto)>0){
        return _descuentos.at(producto)[cant];
    }else{
        return 0;
    }
}

Nat puesto::gastosDe(Persona per){
    if(_gastosDe.count(per)==1){
        return _gastosDe[per];
    } else {
        return 0;
    }
}

//funcion que se realiza al hackear un lolla
bool puesto::reponerItem(Producto producto, Persona per){
    bool dejaDeSerHackeable = false;
    // creo un puntero¿ a la lista de iteradores
    ventasDeProd* listaVentas = &_ventasSinDesc[per][producto];
    // creo un iterador a la lista de ventas
    ventasDeProd::iterator itListaVentas = listaVentas->begin();
    // me guardo el primer iterador de la lista
    itLista itVenta = *itListaVentas;
    // si la cantidad comprada NO es 1
    if ( std::get<1>(*itVenta) != 1){
        //Cambio la tupla a traves del iterador
        //*itVenta = tuple<Persona,Nat>(per,  std::get<1>(*itVenta) - 1); //aca en vez de per no es producto?
        *itVenta = tuple<Persona,Nat>(producto,  std::get<1>(*itVenta) - 1);
    }else{
        //Elimino la venta
        _ventas[per].erase(itVenta);
        if(listaVentas->size() == 1){
            _ventasSinDesc[per][producto] = ventasDeProd();
            dejaDeSerHackeable = true;
        }
        _ventasSinDesc[per][producto].erase(itListaVentas);
    }
    _stock[producto] += 1; //ojo we
    _gastosDe[per] -= _menu.at(producto);
    return dejaDeSerHackeable;
}
