/*

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


//este falla
TEST(colaPriorATest, desencolarMayor) {
    colaPriorA<Nat,Persona> q(5);
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per1(100,1);
    tuplaPersona<Nat, Persona> per2(200,2);
    tuplaPersona<Nat, Persona> per3(300,3); //da este
    tuplaPersona<Nat, Persona> per4(400,4);
    tuplaPersona<Nat, Persona> per5(500,5);
    q.encolar(per1);
    q.encolar(per3);
    q.encolar(per2);
    q.encolar(per4);
    q.encolar(per5);
    EXPECT_EQ(q.proximo().getGastoPersona(), 500); //aca
    EXPECT_EQ(q.proximo().getPersona(), 5);
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
    tuplaPersona<Nat, Persona> per1(100,1);
    tuplaPersona<Nat, Persona> per2(200,7);
    tuplaPersona<Nat, Persona> per3(300,3);
    tuplaPersona<Nat, Persona> per4(400,4);
    tuplaPersona<Nat, Persona> per5(500,5);
    Nat puntero = q.encolar(per5);
    Nat puntero4 = q.encolar(per4);
    Nat puntero2 = q.encolar(per2);
    Nat puntero3 = q.encolar(per3);
    Nat puntero1 = q.encolar(per1);
    EXPECT_EQ(puntero, 500);
    EXPECT_EQ(puntero4, 400);
    EXPECT_EQ(puntero2, 200);
    EXPECT_EQ(puntero3, 300);
    EXPECT_EQ(puntero1, 100);
}

TEST(colaPriorATest, punterosCorrectos_valores_modificados) {
    colaPriorA<Nat, Persona> q(5);
    ASSERT_TRUE(q.vacia());
    //encolo todas las personas
    tuplaPersona<Nat, Persona> per1(0,1);
    tuplaPersona<Nat, Persona> per2(0,7);
    tuplaPersona<Nat, Persona> per3(0,3);
    tuplaPersona<Nat, Persona> per4(0,4);
    tuplaPersona<Nat, Persona> per5(0,5);
    Nat puntero = q.encolar(per5);
    Nat puntero4 = q.encolar(per4);
    Nat puntero2 = q.encolar(per2);
    Nat puntero3 = q.encolar(per3);
    Nat puntero1 = q.encolar(per1);
    EXPECT_EQ(puntero, 0);
    EXPECT_EQ(puntero4, 0);
    EXPECT_EQ(puntero2, 0);
    EXPECT_EQ(puntero3, 0);
    EXPECT_EQ(puntero1, 0);
    tuplaPersona<Nat, Persona> per10(100,1);
    tuplaPersona<Nat, Persona> per20(200,7);
    tuplaPersona<Nat, Persona> per30(300,3);
    tuplaPersona<Nat, Persona> per40(400,4);
    tuplaPersona<Nat, Persona> per50(500,5);
    Nat puntero10 = q.encolar(per10);
    Nat puntero20 = q.encolar(per20);
    Nat puntero30 = q.encolar(per30);
    Nat puntero40 = q.encolar(per40);
    Nat puntero50 = q.encolar(per50);
    EXPECT_EQ(puntero10, 100);
    EXPECT_EQ(puntero20, 200);
    EXPECT_EQ(puntero30, 300);
    EXPECT_EQ(puntero40, 400);
    EXPECT_EQ(puntero50, 500);
}

TEST(colaPriorATest, simulacro_hackear) {
    colaPriorA<Nat,Persona> q(4);
    ASSERT_TRUE(q.vacia());
    // todas las per ingresan sin gastos
    tuplaPersona<Nat, Persona> per2(0,2);
    tuplaPersona<Nat, Persona> per9(0,9);
    tuplaPersona<Nat, Persona> per8(0,8);
    tuplaPersona<Nat, Persona> per4(0,4);
    Nat gasto2 = q.encolar(per2);
    Nat gasto4 = q.encolar(per4);
    Nat gasto8 = q.encolar(per8);
    Nat gasto9 = q.encolar(per9);
    EXPECT_EQ(gasto2, 0);
    EXPECT_EQ(gasto4, 0);
    EXPECT_EQ(gasto8, 0);
    EXPECT_EQ(gasto9, 0);
    EXPECT_EQ(q.proximo().getGastoPersona(), 0);
    EXPECT_EQ(q.proximo().getPersona(), 9);
    // 8 compra dos veces
    // 1ra compra
    tuplaPersona<Nat, Persona> per8compra1(8000,8);
    gasto8 = q.encolar(per8compra1);
    EXPECT_EQ(gasto8, 8000);
    EXPECT_EQ(q.proximo().getGastoPersona(), 8000);
    EXPECT_EQ(q.proximo().getPersona(), 8);
    // 2da compra.
    // en vender ya calculamos cuanto seria el total. compra algo de 3500. por lo cual encolo 11500
    tuplaPersona<Nat, Persona> per8compra2(11500,8);
    gasto8 = q.encolar(per8compra2);
    EXPECT_EQ(gasto8, 11500);
    EXPECT_EQ(q.proximo().getGastoPersona(), 11500);
    EXPECT_EQ(q.proximo().getPersona(), 8);
    // hackeo los 3500. regresa a tener 8000
    tuplaPersona<Nat, Persona> per8hackeo(8000,8);
    gasto8 = q.encolar(per8hackeo);
    EXPECT_EQ(gasto8, 8000);
    EXPECT_EQ(q.proximo().getGastoPersona(), 8000);
    EXPECT_EQ(q.proximo().getPersona(), 8);
}

TEST(colaPriorATest, tres_compras) {
    colaPriorA<Nat,Persona> q(3);
    ASSERT_TRUE(q.vacia());
    // todas las personas ingresan sin gastos
    tuplaPersona<Nat, Persona> per2(0,2);
    tuplaPersona<Nat, Persona> per9(0,9);
    tuplaPersona<Nat, Persona> per4(0,4);
    Nat gasto2 = q.encolar(per2);
    Nat gasto9 = q.encolar(per9);
    Nat gasto4 = q.encolar(per4);
    EXPECT_EQ(gasto2, 0);
    EXPECT_EQ(gasto4, 0);
    EXPECT_EQ(gasto9, 0);
    EXPECT_EQ(q.proximo().getGastoPersona(), 0);
    EXPECT_EQ(q.proximo().getPersona(), 9);
    //4 compra
    tuplaPersona<Nat, Persona> per4compra1(1200,4);
    gasto4 = q.encolar(per4compra1);
    EXPECT_EQ(gasto4, 1200);
    EXPECT_EQ(q.proximo().getGastoPersona(), 1200);
    EXPECT_EQ(q.proximo().getPersona(), 4);//ver por aca cómo quedó el heap
    //2 compra, pero menos que 4
    tuplaPersona<Nat, Persona> per2compra1(100,2);
    gasto2 = q.encolar(per2compra1);
    EXPECT_EQ(gasto2, 100);
    EXPECT_EQ(q.proximo().getGastoPersona(), 1200);
    EXPECT_EQ(q.proximo().getPersona(), 4);
    //9 compra mas q todos
    tuplaPersona<Nat, Persona> per9compra1(2000,9);
    gasto9 = q.encolar(per9compra1);
    EXPECT_EQ(gasto9, 2000);
    EXPECT_EQ(q.proximo().getGastoPersona(), 2000);
    EXPECT_EQ(q.proximo().getPersona(), 9);
    //2 compra mas q todos
    tuplaPersona<Nat, Persona> per2compra2(2403,2);
    gasto2 = q.encolar(per2compra2);
    EXPECT_EQ(gasto2, 2403);
    EXPECT_EQ(q.proximo().getGastoPersona(), 2403);
    EXPECT_EQ(q.proximo().getPersona(), 2);

}

TEST(colaPriorATest, vender_2_veces_dist_personas) {
    colaPriorA<Nat,Persona> cola(4);
    ASSERT_TRUE(cola.vacia());
    // todas las personas ingresan sin gastos
    tuplaPersona<Nat, Persona> per2(0,2);
    tuplaPersona<Nat, Persona> per4(0,4);
    tuplaPersona<Nat, Persona> per8(0,8);
    tuplaPersona<Nat, Persona> per9(0,9);
    Nat gasto2 = cola.encolar(per2);
    Nat gasto4 = cola.encolar(per4);
    Nat gasto8 = cola.encolar(per8);
    Nat gasto9 = cola.encolar(per9);
    EXPECT_EQ(gasto2, 0);
    EXPECT_EQ(gasto4, 0);
    EXPECT_EQ(gasto8, 0);
    EXPECT_EQ(gasto9, 0);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 0);
    EXPECT_EQ(cola.proximo().getPersona(), 9);
    // 2 hace una compra de 7500
    tuplaPersona<Nat, Persona> per2compra(7500,2);
    gasto2 = cola.encolar(per2compra);
    EXPECT_EQ(gasto2, 7500);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 7500);
    EXPECT_EQ(cola.proximo().getPersona(), 2);
    // 4 hace una compra de 15000
    tuplaPersona<Nat, Persona> per4compra(15000,4);
    gasto4 = cola.encolar(per4compra);
    EXPECT_EQ(gasto4, 15000);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 15000);
    EXPECT_EQ(cola.proximo().getPersona(), 4);
}

TEST(colaPriorATest, vender_con_distintos_descuentos) {
    colaPriorA<Nat,Persona> cola(4);
    ASSERT_TRUE(cola.vacia());
    // todas las personas ingresan sin gastos
    tuplaPersona<Nat, Persona> per2(0,2);
    tuplaPersona<Nat, Persona> per4(0,4);
    tuplaPersona<Nat, Persona> per8(0,8);
    tuplaPersona<Nat, Persona> per9(0,9);
    Nat gasto2 = cola.encolar(per2);
    Nat gasto4 = cola.encolar(per4);
    Nat gasto8 = cola.encolar(per8);
    Nat gasto9 = cola.encolar(per9);
    EXPECT_EQ(gasto2, 0);
    EXPECT_EQ(gasto4, 0);
    EXPECT_EQ(gasto8, 0);
    EXPECT_EQ(gasto9, 0);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 0);
    EXPECT_EQ(cola.proximo().getPersona(), 9);
    // 2 hace una compra de 7500
    tuplaPersona<Nat, Persona> per2compra(7500,2);
    gasto2 = cola.encolar(per2compra);
    EXPECT_EQ(gasto2, 7500);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 7500);
    EXPECT_EQ(cola.proximo().getPersona(), 2);
    // 4 hace una compra de 15000
    tuplaPersona<Nat, Persona> per4compra(15000,4);
    gasto4 = cola.encolar(per4compra);
    EXPECT_EQ(gasto4, 15000);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 15000);
    EXPECT_EQ(cola.proximo().getPersona(), 4);
}
*/