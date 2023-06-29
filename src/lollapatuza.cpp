#include "lollapatuza.h"

lollapatuza::lollapatuza(map<IdPuesto, puesto> puestos, set<Persona> personas) :
_personas(personas),
_punterosAGastos(),
_gastosPersona(colaPriorA<Nat, Persona>(personas.size())),
_puestos(puestos),
_hackeables()
{}

lollapatuza lollapatuza::crearLolla(map<IdPuesto, puesto> puestos, set<Persona> personas){

}

void lollapatuza::vender(IdPuesto idPuesto, Persona per, Producto producto, Nat cant){

}

map<IdPuesto, puesto> lollapatuza::puestos(){

}

set<Persona> lollapatuza::personas(){

}

void lollapatuza::hackear(Persona per, Producto producto){

}

Nat lollapatuza::gastoTotal(Persona per){

}

Persona lollapatuza::quienGastoMas(){

}

IdPuesto lollapatuza::menorStock(Producto producto){

}