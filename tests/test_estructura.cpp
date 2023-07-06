//
// Created by clinux01 on 05/07/23.
//
#include "gtest-1.8.1/gtest.h"
#include "../src/tipos.h"
#include "../src/estructura_test.h"




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

TEST(estructuraTest, iteradoresADiccs){
    std::vector<pair<Nat, typename map<Persona,Nat>::iterator>> _heap(3);
    map<Persona, Nat> _indices;
    //Agrego 3 personas al heap, guardo la info en _indices
    auto it1 = _indices.insert(pair<Persona,Nat>(1,0));
    _heap[0] = make_pair(25, it1.first);
    auto it2 = _indices.insert(pair<Persona,Nat>(2,1));
    _heap[1] = make_pair(30, it2.first);
    auto it3 = _indices.insert(pair<Persona,Nat>(3,2));
    _heap[2] = make_pair(35, it3.first);
    EXPECT_EQ(_indices.at(1),0);
    EXPECT_EQ(_indices.at(2),1);
    EXPECT_EQ(_indices.at(3),2);
    //Swapeo 2 tuplas dentro de _heap, primero actualizo sus indices y luego hago el swap de tuplas en _heap
    _heap[1].second->second = 2;
    _heap[2].second->second = 1;
    swap(_heap[1], _heap[2]);
    EXPECT_EQ(_indices.at(2),2);
    EXPECT_EQ(_indices.at(3),1);
    EXPECT_EQ(_heap[2].first,30);
    EXPECT_EQ(_heap[1].first,35);
    
}