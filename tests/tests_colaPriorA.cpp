#include "../src/colaPriorA.h"
#include "gtest-1.8.1/gtest.h"


TEST(colaPriorATest, test_general) {
    colaPriorA<Nat,Persona> c(3);
    EXPECT_TRUE(c.vacia());
    tuplaPersona<Nat, Persona> per1(1,1);
    tuplaPersona<Nat, Persona> per2(2,3);
    tuplaPersona<Nat, Persona> per3(3,2);

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
    colaPriorA<Nat,Persona> q(0);
    ASSERT_TRUE(q.vacia());
}

TEST(colaPriorATest, encolarUno) {
    colaPriorA<Nat,Persona> q(1);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per10(100,10);
    q.encolar(per10);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 10 && q.proximo().getGastoPersona()==100);
}

TEST(colaPriorATest, encolarMenor){
    colaPriorA<Nat,Persona> q(3);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per1(100,1);
    q.encolar(per1);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);
    tuplaPersona<Nat, Persona> per2(50,2);
    q.encolar(per2);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);
    tuplaPersona<Nat, Persona> per3(51,2);
    q.encolar(per3);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);
}

TEST(colaPriorATest, encolarMayor) {
    colaPriorA<Nat,Persona> q(3);
    ASSERT_TRUE(q.vacia());

    tuplaPersona<Nat, Persona> per1(100,1);
    q.encolar(per1);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 1 && q.proximo().getGastoPersona()==100);

    tuplaPersona<Nat, Persona> per2(200,2);
    q.encolar(per2);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 2);
    ASSERT_TRUE(q.proximo().getGastoPersona()==200);
    //ASSERT_TRUE(q.proximo().getPersona() == 2 && q.proximo().getGastoPersona()==200);

    tuplaPersona<Nat, Persona> per3(300,3);
    q.encolar(per3);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 3 && q.proximo().getGastoPersona()==300);
}

TEST(colaPriorATest, desencolarMenor) {
    colaPriorA<Nat,Persona> q(5);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per1(100,1);
    tuplaPersona<Nat, Persona> per2(200,2);
    tuplaPersona<Nat, Persona> per3(300,3);
    tuplaPersona<Nat, Persona> per4(400,4);
    tuplaPersona<Nat, Persona> per5(500,5);
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
    colaPriorA<Nat,Persona> q(5);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per1(100,1);
    tuplaPersona<Nat, Persona> per2(200,2);
    tuplaPersona<Nat, Persona> per3(300,3);
    tuplaPersona<Nat, Persona> per4(400,4);
    tuplaPersona<Nat, Persona> per5(500,5);
    q.encolar(per5);
    q.encolar(per4);
    q.encolar(per3);
    q.encolar(per2);
    q.encolar(per1);
    ASSERT_TRUE(q.proximo().getGastoPersona()==500);
    ASSERT_TRUE(q.proximo().getPersona() == 5);
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

TEST(colaPriorATest,desencolarRandom){
    colaPriorA<Nat,Persona> q(5);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per1(100,1);
    tuplaPersona<Nat, Persona> per2(200,2);
    tuplaPersona<Nat, Persona> per3(300,3);
    tuplaPersona<Nat, Persona> per4(400,4);
    tuplaPersona<Nat, Persona> per5(500,5);
    q.encolar(per3);
    q.encolar(per1);
    q.encolar(per5);
    q.encolar(per2);
    q.encolar(per4);
    ASSERT_TRUE(q.proximo().getGastoPersona()==500);
    ASSERT_TRUE(q.proximo().getPersona() == 5);
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

TEST(colaPriorATest,desencolarUno){
    colaPriorA<Nat,Persona> q(1);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per10(100,10);
    q.encolar(per10);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 10 && q.proximo().getGastoPersona()==100);
    q.desencolar();
    ASSERT_TRUE(q.vacia());
}

TEST(colaPriorATest, punterosCorrectos) {
    colaPriorA<Nat,Persona> q(5);
    ASSERT_TRUE(q.vacia());
    /*tuplaPersona<Nat, Persona> per1(100,1);
    tuplaPersona<Nat, Persona> per2(200,7);
    tuplaPersona<Nat, Persona> per3(300,3);
    tuplaPersona<Nat, Persona> per4(400,4);
    tuplaPersona<Nat, Persona> per5(500,5);
    Nat* puntero = q.encolar(per5);
    Nat* puntero4 = q.encolar(per4);
    Nat* puntero2 = q.encolar(per2);
    Nat* puntero3 = q.encolar(per3);
    Nat* puntero1 = q.encolar(per1);
    EXPECT_EQ(*puntero, 500);
    EXPECT_EQ(*puntero4, 400);
    EXPECT_EQ(*puntero2, 200);
    EXPECT_EQ(*puntero3, 300);
    EXPECT_EQ(*puntero1, 100);*/
}

TEST(colaPriorATest, punterosCorrectos_valores_modificados) {
    map<Persona, Nat*> _punterosAGastos;
    //Todas las personas compran 2 veces(aumentan sus gastos acumulados)
    colaPriorA<Nat, Persona> q(5);
    ASSERT_TRUE(q.vacia());
    //encolo todas las personas
    /*tuplaPersona<Nat, Persona> per1(100,1);
    tuplaPersona<Nat, Persona> per2(200,7);
    tuplaPersona<Nat, Persona> per3(300,3);
    tuplaPersona<Nat, Persona> per4(500,4);
    tuplaPersona<Nat, Persona> per5(700,5);
    Nat* puntero5 = q.encolar(per5);
    _punterosAGastos[5] = puntero5;
    Nat* puntero4 = q.encolar(per4);
    _punterosAGastos[4] = puntero4;
    Nat* puntero2 = q.encolar(per2);
    _punterosAGastos[2] = puntero2;
    Nat* puntero3 = q.encolar(per3);
    _punterosAGastos[3] = puntero3;
    Nat* puntero1 = q.encolar(per1);
    _punterosAGastos[1] = puntero1;
    EXPECT_EQ(*puntero1, 100);
    EXPECT_EQ(*puntero4, 500);
    EXPECT_EQ(*puntero2, 200);
    EXPECT_EQ(*puntero3, 300);
    EXPECT_EQ(*puntero5, 700);
    //Actualizo el gasto de per5 a 1500
    per5 = tuplaPersona<Nat, Persona>(1500,5);
    EXPECT_EQ(*_punterosAGastos[5], 1500);
    q.encolar(per5);
    //
    tuplaPersona<Nat, Persona> per10(700,1);
    tuplaPersona<Nat, Persona> per20(300,7);
    tuplaPersona<Nat, Persona> per30(400,3);
    tuplaPersona<Nat, Persona> per40(600,4);
    tuplaPersona<Nat, Persona> per50(800,5);
    Nat* puntero10 = q.encolar(per10);
    Nat* puntero20 = q.encolar(per20);
    Nat* puntero30 = q.encolar(per30);
    Nat* puntero40 = q.encolar(per40);
    Nat* puntero50 = q.encolar(per50);
    EXPECT_EQ(*puntero10, 700);
    EXPECT_EQ(*puntero20, 300);
    EXPECT_EQ(*puntero30, 400);
    EXPECT_EQ(*puntero40, 600);
    EXPECT_EQ(*puntero50, 800);*/
}

TEST(colaPriorATest,punteroA2gastos){
    map<Persona, Nat> _punterosAGastos;
    colaPriorA<Nat, Persona> q(2);
    tuplaPersona<Nat, Persona> per1(500,1);
    tuplaPersona<Nat, Persona> per2(400,7);
    Nat puntero1 = q.encolar(per1);
    _punterosAGastos[1] = puntero1;
    Nat puntero2 = q.encolar(per2);
    _punterosAGastos[2] = puntero2;
    EXPECT_EQ(_punterosAGastos[1], 500);
    EXPECT_EQ(_punterosAGastos[2], 400);
    //Actualizo el gasto per2 a 600, las tuplas dentro de heap swapean,
    //Los punteros deberian seguir apuntando al gasto de la tupla original
    per2 = tuplaPersona<Nat, Persona>(800,2);
    puntero2 = q.encolar(per2);
    _punterosAGastos[2] = puntero2;
    EXPECT_EQ(_punterosAGastos[1], 500);
    EXPECT_EQ(_punterosAGastos[2], 800);
    //tira error:El puntero sigue apuntando a heap[0]
}