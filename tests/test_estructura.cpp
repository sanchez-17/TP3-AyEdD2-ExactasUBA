//
// Created by clinux01 on 05/07/23.
//
#include "gtest-1.8.1/gtest.h"
#include "../src/tipos.h"
#include "../src/estructura.h"




TEST(estructuraTest, bugacho_raro) {
    colaPriorA<Nat, Persona> cola(4);
    tuplaPersona<Nat, Persona> per1(0,1);
    tuplaPersona<Nat, Persona> per2(0,2);
    tuplaPersona<Nat, Persona> per3(0,8);
    tuplaPersona<Nat, Persona> per4(0,4);

    cola.encolar(per1);
    cola.encolar(per2);
    cola.encolar(per3);
    cola.encolar(per4);

    EstructuraTest qcy = EstructuraTest(cola);
    qcy.venderCola(50,8);
    EXPECT_EQ(qcy.dameGasto(8), 50);
}