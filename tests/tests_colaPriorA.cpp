//
// Created by aquil on 29/6/2023.
//
#include "../src/colaPriorA.h"
#include "../src/tuplaPersona.h"
#include "gtest-1.8.1/gtest.h"



TEST(colaPriorATest, test_general) {
    colaPriorA<Persona,Nat> c(3);
    EXPECT_TRUE(c.vacia());
    tuplaPersona<Persona, Nat> per1(1,1);
    tuplaPersona<Persona, Nat> per2(2,3);
    tuplaPersona<Persona, Nat> per3(3,2);

    c.encolar(per3);
    EXPECT_FALSE(c.vacia());

    c.encolar(per1);
    c.encolar(per2);
    //La persona que mas gasto es per2 con gasto:3
    EXPECT_EQ(c.proximo().getGastoPersona(),3);
    EXPECT_EQ(c.proximo().getPersona(),2);
    c.desencolar();
    //Ahora la persona que mas gasto es per3 con gasto:2
    EXPECT_EQ(c.proximo().getGastoPersona(),2);
    EXPECT_EQ(c.proximo().getPersona(),3);
    c.desencolar();
    //Ahora la persona que mas gasto es per1 con gasto:1
    EXPECT_EQ(c.proximo().getGastoPersona(),1);
    EXPECT_EQ(c.proximo().getPersona(),1);
    c.desencolar();
    EXPECT_TRUE(c.vacia());

}

TEST(ColaPrior, vacio) {
    colaPriorA<Persona,Nat> q;
    ASSERT_TRUE(q.vacia());
}

TEST(ColaPrior, encolarUno) {
    colaPriorA<Persona,Nat> q;
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Persona, Nat> per10(100,10);
    q.encolar(per10);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 10 && q.proximo().getGastoPersona()==100);
}

TEST(ColaPrior, encolarMenor) {
    colaPriorA<Persona,Nat> q;
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Persona, Nat> per1(100,1);
    q.encolar(per1);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);
    tuplaPersona<Persona, Nat> per2(50,2);
    q.encolar(per2);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);
    tuplaPersona<Persona, Nat> per3(50,2);
    q.encolar(per3);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);
}

TEST(ColaPrior, encolarMayor) {
    colaPriorA<Persona,Nat> q;
    ASSERT_TRUE(q.vacia());

    tuplaPersona<Persona, Nat> per1(100,1);
    q.encolar(per1);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);

    tuplaPersona<Persona, Nat> per2(200,2);
    q.encolar(per2);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 2 && q.proximo().getGastoPersona()==200);

    tuplaPersona<Persona, Nat> per3(300,3);
    q.encolar(per3);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 3 && q.proximo().getGastoPersona()==300);
}

TEST(ColaPrior, desencolarMenor) {
    colaPriorA<Persona,Nat> q;
    ASSERT_TRUE(q.vacia());
    q.encolar(51);
    q.encolar(42);
    q.encolar(33);
    q.encolar(24);
    q.encolar(15);
    ASSERT_EQ(q.proximo(), 51);
    ASSERT_EQ(q.tam(), 5);
    q.desencolar();
    ASSERT_EQ(q.proximo(), 42);
    ASSERT_EQ(q.tam(), 4);
    q.desencolar();
    ASSERT_EQ(q.proximo(), 33);
    ASSERT_EQ(q.tam(), 3);
    q.desencolar();
    ASSERT_EQ(q.proximo(), 24);
    ASSERT_EQ(q.tam(), 2);
    q.desencolar();
    ASSERT_EQ(q.proximo(), 15);
    ASSERT_EQ(q.tam(), 1);
    q.desencolar();
    ASSERT_EQ(q.tam(), 0);
}

TEST(ColaPrior, desencolarMayor) {
    colaPriorA<Persona,Nat> q;
    ASSERT_TRUE(q.vacia());
    q.encolar(15);
    q.encolar(24);
    q.encolar(33);
    q.encolar(42);
    q.encolar(51);
    ASSERT_EQ(q.proximo(), 51);
    ASSERT_EQ(q.tam(), 5);
    q.desencolar();
    ASSERT_EQ(q.proximo(), 42);
    ASSERT_EQ(q.tam(), 4);
    q.desencolar();
    ASSERT_EQ(q.proximo(), 33);
    ASSERT_EQ(q.tam(), 3);
    q.desencolar();
    ASSERT_EQ(q.proximo(), 24);
    ASSERT_EQ(q.tam(), 2);
    q.desencolar();
    ASSERT_EQ(q.proximo(), 15);
    ASSERT_EQ(q.tam(), 1);
    q.desencolar();
    ASSERT_TRUE(q.vacia());
}