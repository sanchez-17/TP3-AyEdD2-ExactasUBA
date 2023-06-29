//
// Created by aquil on 29/6/2023.
//
#include "../src/tuplaPersona.h"
#include "gtest-1.8.1/gtest.h"

TEST(tuplaPersonaTest, testBasico){
    tuplaPersona<Nat, Persona> miTupla(10, 45);
    EXPECT_EQ(miTupla.getGastoPersona(),10);
    EXPECT_EQ(miTupla.getPersona(),45);
}

