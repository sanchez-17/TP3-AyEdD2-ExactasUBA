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
    _descuentos = map<Producto, vector<Nat>>();
    for (Promociones::iterator it = promos.begin(); it != promos.end(); ++it){
        Nat stockInicial = stock[it->first];
        vector<Nat> arr = vector<Nat>(stockInicial);
        _descuentos[it->first] = arr;
        map<Nat, Nat> cantidades = it->second;
        map<Nat, Nat>::iterator itPrm = cantidades.begin();
        Nat i = 0;
        Nat ultI = i;
        Nat minPromo = itPrm->second;
        while(i<=stockInicial) {
            //El array son todos ceros hasta hallar alguna promo para alguna cant i.
            if(i < minPromo){
                arr[i] = 0;
            }else {
                if (cantidades.count(i) == 1) {
                    arr[i] = cantidades[i];
                    ultI = i;
                } else {
                    arr[i] = cantidades[ultI];
                }
            }
            i++;
        }
    }
    return puesto(menu,stock,);
}

void puesto::vender(Persona per, Producto p, Nat cant) {

}

