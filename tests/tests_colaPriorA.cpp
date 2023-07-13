
#include "../src/colaPriorA.h"
#include "gtest-1.8.1/gtest.h"


TEST(colaPriorATest, test_general) {
    colaPriorA<tuplaPersona<Nat,Persona>> c;
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
    colaPriorA<tuplaPersona<Nat,Persona>> q;
    ASSERT_TRUE(q.vacia());
}

TEST(colaPriorATest, encolarUno) {
    colaPriorA<tuplaPersona<Nat,Persona>> q;
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per10(100,10);
    q.encolar(per10);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 10 && q.proximo().getGastoPersona()==100);
}

TEST(colaPriorATest, encolarMenor){
    colaPriorA<tuplaPersona<Nat,Persona>> q;
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
    colaPriorA<tuplaPersona<Nat,Persona>> q;
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
    colaPriorA<tuplaPersona<Nat,Persona>> q;
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
    colaPriorA<tuplaPersona<Nat,Persona>> q;
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per1(100,1);
    tuplaPersona<Nat, Persona> per2(200,2);
    tuplaPersona<Nat, Persona> per3(300,3);
    tuplaPersona<Nat, Persona> per4(400,4);
    tuplaPersona<Nat, Persona> per5(500,5);
    q.encolar(per1);
    q.encolar(per3);
    q.encolar(per2);
    q.encolar(per4);
    q.encolar(per5);
    EXPECT_EQ(q.proximo().getGastoPersona(), 500);
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
    colaPriorA<tuplaPersona<Nat,Persona>> q;
    ASSERT_TRUE(q.vacia());
    tuplaPersona<Nat, Persona> per10(100,10);
    q.encolar(per10);
    ASSERT_FALSE(q.vacia());
    ASSERT_TRUE(q.proximo().getPersona() == 10 && q.proximo().getGastoPersona()==100);
    q.desencolar();
    ASSERT_TRUE(q.vacia());
}

TEST(colaPriorATest, simulacro_hackear) {
    colaPriorA<tuplaPersona<Nat,Persona>> q;
    ASSERT_TRUE(q.vacia());
    // todas las per ingresan sin gastos
    tuplaPersona<Nat, Persona> per2(0,2);
    tuplaPersona<Nat, Persona> per9(0,9);
    tuplaPersona<Nat, Persona> per8(0,8);
    tuplaPersona<Nat, Persona> per4(0,4);
    q.encolar(per2);
    q.encolar(per4);
    q.encolar(per8);
    q.encolar(per9);
    EXPECT_EQ(q.proximo().getGastoPersona(), 0);
    EXPECT_EQ(q.proximo().getPersona(), 9);
    // 8 compra dos veces
    // 1ra compra
    tuplaPersona<Nat, Persona> per8compra1(8000,8);
    q.actualizarOrden(per8, per8compra1);
    EXPECT_EQ(q.proximo().getGastoPersona(), 8000);
    EXPECT_EQ(q.proximo().getPersona(), 8);
    // 2da compra.
    // en vender ya calculamos cuanto seria el total. compra algo de 3500. por lo cual encolo 11500
    tuplaPersona<Nat, Persona> per8compra2(11500,8);
    q.actualizarOrden(per8compra1, per8compra2);
    EXPECT_EQ(q.proximo().getGastoPersona(), 11500);
    EXPECT_EQ(q.proximo().getPersona(), 8);
    // hackeo los 3500. regresa a tener 8000
    tuplaPersona<Nat, Persona> per8hackeo(8000,8);
    q.actualizarOrden(per8compra2, per8hackeo);
    EXPECT_EQ(q.proximo().getGastoPersona(), 8000);
    EXPECT_EQ(q.proximo().getPersona(), 8);
}

TEST(colaPriorATest, tres_compras) {
    colaPriorA<tuplaPersona<Nat,Persona>> q;
    ASSERT_TRUE(q.vacia());
    // todas las personas ingresan sin gastos
    tuplaPersona<Nat, Persona> per2(0,2);
    tuplaPersona<Nat, Persona> per9(0,9);
    tuplaPersona<Nat, Persona> per4(0,4);
    q.encolar(per2);
    q.encolar(per9);
    q.encolar(per4);
    EXPECT_EQ(q.proximo().getGastoPersona(), 0);
    EXPECT_EQ(q.proximo().getPersona(), 9);
    //4 compra
    tuplaPersona<Nat, Persona> per4compra1(1200,4);
    q.actualizarOrden(per4, per4compra1);
    EXPECT_EQ(q.proximo().getGastoPersona(), 1200);
    EXPECT_EQ(q.proximo().getPersona(), 4);
    //2 compra, pero menos que 4
    tuplaPersona<Nat, Persona> per2compra1(100,2);
    q.actualizarOrden(per2, per2compra1);
    EXPECT_EQ(q.proximo().getGastoPersona(), 1200);
    EXPECT_EQ(q.proximo().getPersona(), 4);
    //9 compra mas que todos
    tuplaPersona<Nat, Persona> per9compra1(2000,9);
    q.actualizarOrden(per9, per9compra1);
    EXPECT_EQ(q.proximo().getGastoPersona(), 2000);
    EXPECT_EQ(q.proximo().getPersona(), 9);
    //2 compra mas que todos
    tuplaPersona<Nat, Persona> per2compra2(2403,2);
    q.actualizarOrden(per2compra1, per2compra2);
    EXPECT_EQ(q.proximo().getGastoPersona(), 2403);
    EXPECT_EQ(q.proximo().getPersona(), 2);
}

TEST(colaPriorATest, vender_2_veces_dist_personas) {
    colaPriorA<tuplaPersona<Nat,Persona>> cola;
    ASSERT_TRUE(cola.vacia());
    // todas las personas ingresan sin gastos
    tuplaPersona<Nat, Persona> per2(0,2);
    tuplaPersona<Nat, Persona> per4(0,4);
    tuplaPersona<Nat, Persona> per8(0,8);
    tuplaPersona<Nat, Persona> per9(0,9);
    cola.encolar(per2);
    cola.encolar(per4);
    cola.encolar(per8);
    cola.encolar(per9);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 0);
    EXPECT_EQ(cola.proximo().getPersona(), 9);
    // 2 hace una compra de 7500
    tuplaPersona<Nat, Persona> per2compra(7500,2);
    cola.actualizarOrden(per2, per2compra);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 7500);
    EXPECT_EQ(cola.proximo().getPersona(), 2);
    // 4 hace una compra de 15000
    tuplaPersona<Nat, Persona> per4compra(15000,4);
    cola.actualizarOrden(per4, per4compra);
    EXPECT_EQ(cola.proximo().getGastoPersona(), 15000);
    EXPECT_EQ(cola.proximo().getPersona(), 4);
}
