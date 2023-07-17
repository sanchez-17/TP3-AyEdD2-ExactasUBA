#ifndef PUESTO_H
#define PUESTO_H
#include "tipos.h"
#include <map>
#include <vector>
#include <list>
#include <set>
#include <cmath>

class puesto{
public:
    puesto();
    puesto(Menu& menu,Stock& stock,Promociones& prms);
    pair<bool,Nat> vender(Persona per, Producto producto, Nat cant);
    set<Producto> menu()const;
    Nat precio(Producto producto)const;
    Nat stock(Producto producto)const;
    Nat descuento(Producto producto, Nat cant)const ;
    const Nat gastosDe(Persona per)const ;
    bool reponerItem(Producto producto, Persona persona);

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


#endif //PUESTO_H