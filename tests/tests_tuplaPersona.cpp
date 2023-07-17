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
    tuplaPersona<Nat, Persona> tupla3(20,5);
    EXPECT_EQ(tupla3.getPersona(), 5);

}

TEST(tuplaPersonaTest,RelacionDeOrden){
    tuplaPersona<Nat, Persona> t1(20,5);
    tuplaPersona<Nat, Persona> t2(20,6);
    EXPECT_TRUE(t2>t1);

    tuplaPersona<Nat, Persona> t3(50,5);
    tuplaPersona<Nat, Persona> t4(20,6);
    EXPECT_TRUE(t4<t3);
}

TEST(tuplaPersonaTest,Diferencia){
    tuplaPersona<Nat, Persona> t1(50,5);
    tuplaPersona<Nat, Persona> t2(50,6);
    EXPECT_TRUE(t2!=t1);

    tuplaPersona<Nat, Persona> t3(50,5);
    tuplaPersona<Nat, Persona> t4(20,6);
    EXPECT_TRUE(t4!=t3);

    tuplaPersona<Nat, Persona> t5(50,6);
    tuplaPersona<Nat, Persona> t6(20,6);
    EXPECT_TRUE(t5!=t6);
}

TEST(tuplaPersonaTest,Igualdad){
    tuplaPersona<Nat, Persona> t1(20,8);
    tuplaPersona<Nat, Persona> t2(20,8);
    EXPECT_TRUE(t2==t1);

    tuplaPersona<Nat, Persona> t3(500,1);
    tuplaPersona<Nat, Persona> t4(240,1);
    EXPECT_FALSE(t4==t3);
}

TEST(tuplaPersonaTest,Gets_Correctos){
    tuplaPersona<Nat, Persona> t1(5000,2);
    tuplaPersona<Nat, Persona> t2(1750,9);
    EXPECT_EQ(5000, t1.getGastoPersona());
    EXPECT_EQ(1750, t2.getGastoPersona());
    EXPECT_EQ(2, t1.getPersona());
    EXPECT_EQ(9, t2.getPersona());

    tuplaPersona<Nat, Persona> t3(0,1);
    tuplaPersona<Nat, Persona> t4(2400,0);
    EXPECT_EQ(0, t3.getGastoPersona());
    EXPECT_EQ(2400, t4.getGastoPersona());
    EXPECT_EQ(1, t3.getPersona());
    EXPECT_EQ(0, t4.getPersona());
}