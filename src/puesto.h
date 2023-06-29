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
    void vender(Persona per, Producto producto, Nat cant);
    set<Producto> menu();
    Nat precio(Producto producto);
    Nat stock(Producto producto);
    Nat descuento(Producto producto, Nat cant);
    Nat gastosDe(Persona per);
    void reponerItem(Producto producto, Persona persona);

private:
    using itLista = list<tuple<Producto,Nat>>::iterator;
    using ventasDeProd =  list<itLista>;
    Menu _menu;
    Stock _stock;
    map<Persona,Nat> _gastosDe;
    map<Producto, vector<Nat>> _descuentos;
    map<Persona,map<Producto,ventasDeProd>>  _ventasSinDesc;
    map<Persona,list<tuple<Producto,Nat>>> _ventas;
};

#include "puesto.hpp"

#endif //PUESTO_H