//
// Created by aquil on 29/6/2023.
//
#include "../src/colaPriorA.h"
#include "gtest-1.8.1/gtest.h"



TEST(colaPriorATest, test_general) {
    ColaPriorA c(3);
    EXPECT_TRUE(c.vacia);
    pair<Nat,Nat> third = <1,1>;
    pair<Nat,Nat> second = <2,1>;
    pair<Nat,Nat> first = <2,2>;

    c.encolar(third);
    EXPECT_FALSE(c.vacia);

    c.encolar(first);
    c.encolar(second);

    EXPECT_EQ(c.proximo(),first);
    c.desencolar();
    EXPECT_EQ(c.proximo(),second);
    c.desencolar();
    EXPECT_EQ(c.proximo(),third);
    c.desencolar();
    EXPECT_TRUE(c.vacia);

}
