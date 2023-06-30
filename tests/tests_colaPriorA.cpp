#include "../src/colaPriorA.h"
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

TEST(colaPriorATest, vacio) {
    colaPriorA<Persona,Nat> q(0);
    ASSERT_TRUE(q.vacia());
}

TEST(colaPriorATest, encolarUno) {
    colaPriorA<Persona,Nat> q(1);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Persona, Nat> per10(100,10);
    q.encolar(per10);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 10 && q.proximo().getGastoPersona()==100);
}

TEST(colaPriorATest, encolarMenor) {
    colaPriorA<Persona,Nat> q(3);
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

TEST(colaPriorATest, encolarMayor) {
    colaPriorA<Persona,Nat> q(3);
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

TEST(colaPriorATest, desencolarMenor) {
    colaPriorA<Persona,Nat> q(5);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Persona, Nat> per1(100,1);
    tuplaPersona<Persona, Nat> per2(200,2);
    tuplaPersona<Persona, Nat> per3(300,3);
    tuplaPersona<Persona, Nat> per4(400,4);
    tuplaPersona<Persona, Nat> per5(500,5);
    q.encolar(per5);
    q.encolar(per4);
    q.encolar(per2);
    q.encolar(per3);
    q.encolar(per1);
    ASSERT_TRUE(q.proximo().getPersona() == 5 && q.proximo().getGastoPersona()==500);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.proximo().getPersona() == 4 && q.proximo().getGastoPersona()==400);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.proximo().getPersona() == 3 && q.proximo().getGastoPersona()==300);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.proximo().getPersona() == 2 && q.proximo().getGastoPersona()==200);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.vacia());
}

TEST(colaPriorATest, desencolarMayor) {
    colaPriorA<Persona,Nat> q(5);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Persona, Nat> per1(100,1);
    tuplaPersona<Persona, Nat> per2(200,2);
    tuplaPersona<Persona, Nat> per3(300,3);
    tuplaPersona<Persona, Nat> per4(400,4);
    tuplaPersona<Persona, Nat> per5(500,5);
    q.encolar(per1);
    q.encolar(per3);
    q.encolar(per2);
    q.encolar(per4);
    q.encolar(per5);
    ASSERT_TRUE(q.proximo().getPersona() == 5 && q.proximo().getGastoPersona()==500);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.proximo().getPersona() == 4 && q.proximo().getGastoPersona()==400);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.proximo().getPersona() == 3 && q.proximo().getGastoPersona()==300);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.proximo().getPersona() == 2 && q.proximo().getGastoPersona()==200);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);
    ASSERT_FALSE(q.vacia());
    q.desencolar();
    ASSERT_TRUE(q.vacia());
}