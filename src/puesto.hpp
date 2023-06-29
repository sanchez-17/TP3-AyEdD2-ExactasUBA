#include "puesto.h"

puesto puesto::crearPuesto(Menu menu, Stock stock, Promociones promos){
    _descuentos = map<Producto, vector<Nat>>();
    for (Promociones::iterator it = promos.begin(); it != promos.end(); ++it){
        Nat stockInicial = stock[it->first];
        vector<Nat> arr = vector<Nat>(stockInicial);
        
    }
    return puesto();
}

void puesto::vender(Persona per, Producto p, Nat cant) {

}