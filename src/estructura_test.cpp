#include "estructura_test.h"

EstructuraTest::EstructuraTest(colaPriorA<Nat, Persona> cola) : _cola(cola), _gastosDe() {

}

void EstructuraTest::venderCola(Nat gasto, Persona per) {
    _gastosDe[per] = gasto;
    tuplaPersona<Nat,Persona> gastoPer(gasto,per);
    _cola.encolar(gastoPer);
}

Nat EstructuraTest::dameGasto(Persona per){
    return _gastosDe.at(per);
}
