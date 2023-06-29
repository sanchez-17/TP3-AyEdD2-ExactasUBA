#ifndef PUESTO_H
#define PUESTO_H
#include "tipos.h"
#include <string>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <cmath>

class puesto{
public:
    puesto(Menu menu,Stock stock,map<Producto, vector<Nat>> promos);
    puesto crearPuesto(Menu m,Stock s,Promociones prms);
    void vender(Persona per, Producto p, Nat cant);
    set<Producto> menu();
    Nat precio(Producto p);
    Nat stock(Producto p);
    Nat descuento(Producto p, Nat cant);
    Nat gastosDe(Persona per);

private:
    using itLista = list<tuple<Producto,Nat>>::iterator;
    using ventasDeProd =  list<itLista>;
    Menu _menu;
    Stock _stock;
    map<Persona,Nat> _gastosDe;
    map<Producto, vector<Nat>> _descuentos;
    map<Persona,map<Producto,ventasDeProd>>  _ventasSinDesc;
    map<Persona,list<tuple<Producto,Nat>>> _ventas;
    Menu menuPuesto();
};

//#include "puesto.hpp"

#endif //PUESTO_H