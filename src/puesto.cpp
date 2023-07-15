#include "puesto.h"

puesto::puesto() = default;
//puesto::puesto(){}

puesto::puesto(Menu& menu, Stock& stock, Promociones& promos):_menu(menu),
                                                              _stock(stock){
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
    _descuentos = promociones;
}

pair<bool,Nat> puesto::vender(Persona per, Producto producto, Nat cant){
    Nat puestoHackeable = false;                                                            //O(1)
    Nat descuento = this->descuento(producto,cant);                                         //O(log(I))
    //Calculamos el gasto a realizar con el descuento correspondiente
    Nat precio = this->precio(producto);                                                    //O(log(I))
    Nat gastoVentaP = floor(precio * cant * (100 - descuento) / 100);                     //O(1)
    //Actualizamos el stock del item en el puesto
    _stock[producto] = stock(producto) - cant;                                              //O(log(I))
    //Actualizamos el gasto acumulado de la persona
    Nat gastoAcumuladoEnPuesto = gastoVentaP;
    if (_gastosDe.count(per) == 1) { gastoAcumuladoEnPuesto += _gastosDe.at(per); }
    this->_gastosDe[per] = gastoAcumuladoEnPuesto;                                                     //O(log(A))
    _ventas[per].push_back(make_pair(producto,cant));                               //O(log(A))
    if(descuento == 0){
        auto itVenta = --_ventas[per].end();                                      //O(1)
        _ventasSinDesc[per][producto].push_back(itVenta);                                 //O(log(A)+log(I))
        puestoHackeable = true;                                                             //O(1)
    }
    pair<bool,Nat> infoVenta;
    infoVenta.first = puestoHackeable;
    infoVenta.second = gastoVentaP;                                                           //O(1)
    return infoVenta;
}

set<Producto> puesto::menu()const{
    set<Producto> conjMenu;
    for(auto m:_menu){
        conjMenu.insert(m.first);
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

Nat puesto::descuento(Producto producto, Nat cant)const{
    if(_descuentos.count(producto)>0){
        return _descuentos.at(producto)[cant];
    }else{
        return 0;
    }
}

const Nat puesto::gastosDe(Persona per)const{
    if(_gastosDe.count(per)==1){
        return _gastosDe.at(per);
    } else {
        return 0;
    }
}

//funcion que se realiza al hackear un lolla
bool puesto::reponerItem(Producto producto, Persona per){
    bool dejaDeSerHackeable = false;                                                    //O(1)
    // creo un puntero¿ a la lista de iteradores
    ventasDeProd* listaVentas = &_ventasSinDesc[per][producto];                         //O(log(A)+log(I))
    // creo un iterador a la lista de ventas
    ventasDeProd::iterator itListaVentas = listaVentas->begin();                        //O(1)
    // me guardo el primer iterador de la lista
    itLista itVenta = *itListaVentas;                                                   //O(1)
    // si la cantidad comprada NO es 1
    if ( std::get<1>(*itVenta) != 1){                                               //O(1)
        //Cambio la tupla a traves del iterador
        *itVenta = tuple<Persona,Nat>(producto,  std::get<1>(*itVenta) - 1);  //O(1)
    }else{
        //Elimino la venta
        _ventas[per].erase(itVenta);                                            //O(log(A))
        if(listaVentas->size() == 1){                                                  //O(1)
            _ventasSinDesc[per][producto] = ventasDeProd();                            //O(log(A)+log(I))
            dejaDeSerHackeable = true;                                                 //O(1)
        }
        _ventasSinDesc[per][producto].erase(itListaVentas);                     //O(log(A)+log(I))
    }
    _stock[producto] += 1;                                                             //O(log(I))
    _gastosDe[per] -= _menu.at(producto);                                           //O(log(A)+log(I))
    return dejaDeSerHackeable;                                                         //O(1)
}//Complejidad: O(log(A)+log(I))
