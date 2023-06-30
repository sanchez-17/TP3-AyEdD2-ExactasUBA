#include "../src/tuplaPersona.h"
#include "gtest-1.8.1/gtest.h"
#include <map>
#include "../src/tipos.h"

TEST(tuplaPersonaTest, testBasico){
    //diccionario persona,indice en heap
    map<Persona,Nat> indicesPersona;
    //arreglo gastoPersona, itPersona en heap
    vector<pair<Nat, typename map<Persona,Nat>::iterator>> _heap;
    //Persona 10 en indice 0
    indicesPersona[10] = 0;
    map<Persona,Nat>::iterator it = indicesPersona.begin();
    //gasto de 200 para persona 10
    _heap.push_back(make_pair(200,it));
    //Persona 20 en indice 1
    indicesPersona[20] = 1;
    ++it;
    //gasto de 100 para persona 20
    _heap.push_back(make_pair(100,it));
    //tuplaPersona<Nat, Persona>* tupla1 = new tuplaPersona<Nat,Persona>(_heap[0].first,_heap[0].second->first);
    tuplaPersona<Nat, Persona>* tupla3 = new tuplaPersona<Nat,Persona>(20,5);
    EXPECT_EQ(tupla3, nullptr);
    //EXPECT_EQ(tupla3->getGastoPersona(),5);
    //EXPECT_EQ(tupla3->getPersona(),20);
    //EXPECT_EQ(tupla1->getGastoPersona(),200);
    //EXPECT_EQ(tupla1->getPersona(),10);

    /*tuplaPersona<Nat, Persona>* tupla2 = new tuplaPersona<Nat,Persona>(_heap[1].first,_heap[1].second->first);
    EXPECT_EQ(tupla2->getGastoPersona(),10);
    EXPECT_EQ(tupla2->getPersona(),45);*/

}

