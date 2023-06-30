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

    EXPECT_EQ(c.proximo().getGastoPersona(),per1.getGastoPersona());
    EXPECT_EQ(c.proximo().getPersona(),per1.getPersona());
    c.desencolar();
    EXPECT_EQ(c.proximo().getGastoPersona(),per2.getGastoPersona());
    EXPECT_EQ(c.proximo().getPersona(),per2.getPersona());
    c.desencolar();
    EXPECT_EQ(c.proximo().getGastoPersona(),per3.getGastoPersona());
    EXPECT_EQ(c.proximo().getPersona(),per3.getPersona());
    c.desencolar();
    EXPECT_TRUE(c.vacia());

}
