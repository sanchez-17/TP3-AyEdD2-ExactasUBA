#ifndef PUESTO_H
#define PUESTO_H
#include "tipos.h"
#include <string>
#include <map>
#include <vector>
#include <list>
template<class T>
class puesto{
public:

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