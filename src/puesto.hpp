#include "puesto.h"

puesto::puesto(Menu menu,Stock stock,map<Producto, vector<Nat>> promos):
_menu(menu),
_stock(stock),
_descuentos(promos),
_ventasSinDesc(),
_ventas()
{}

map<Producto, map<Nat, Nat>>;
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

void puesto::vender(Persona per, Producto p, Nat cant) {

}

