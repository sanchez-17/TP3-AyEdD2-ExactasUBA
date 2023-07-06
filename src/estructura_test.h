#ifndef TP_LOLLA_ESTRUCTURA_TEST_H
#define TP_LOLLA_ESTRUCTURA_TEST_H


#include "colaPriorA.h"

class EstructuraTest {
public:
    EstructuraTest(colaPriorA<Nat,Persona> cola);
    void venderCola(Nat gasto,Persona per);
    Nat dameGasto(Persona per);

private:
    colaPriorA<Nat,Persona> _cola;
    map<Persona,Nat> _gastosDe;


};

//#include "estructura_test.cpp"
#endif //TP_LOLLA_ESTRUCTURA_TEST_H
