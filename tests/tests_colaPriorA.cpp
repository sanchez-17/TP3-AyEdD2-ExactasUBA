//
// Created by aquil on 29/6/2023.
//
#include "../src/colaPriorA.h"
#include "gtest-1.8.1/gtest.h"



TEST(colaPriorATest, test_general) {
    ColaPriorA c(3);
    pair<Nat,Nat> third = <1,1>;
    pair<Nat,Nat> second = <2,1>;
    pair<Nat,Nat> first = <2,2>;

    c.encolar(third);
    EXPECT_FALSE(c.vacia)

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


TEST(colaPriorATest, test_insertar_un_valor) {
    Conjunto<int> c;
    c.insertar(5);
    EXPECT_EQ(c.cardinal(), 1);
}


TEST(colaPriorATest, test_insertar_cinco_valores) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.cardinal(), 5);
}

TEST(colaPriorATest, test_pertenece) {
    Conjunto<int> c;

    for (int i = 0; i < 5; i++) {
        EXPECT_FALSE(c.pertenece(i));
    }

    // Agrego el 3
    c.insertar(3);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(c.pertenece(i), i == 3);
    }

    // Agrego el 3
    c.insertar(5);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(c.pertenece(i), i == 3);
    }
    EXPECT_TRUE(c.pertenece(5));

}

TEST(colaPriorATest, test_insertar_remover_un_valor) {
    Conjunto<int> c;
    c.insertar(5);
    c.remover(5);
    EXPECT_EQ(c.cardinal(), 0);
    c.insertar(5);
    EXPECT_EQ(c.cardinal(), 1);
}

TEST(colaPriorATest, test_minimo) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.minimo(), 4);
}

TEST(colaPriorATest, test_maximo) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    EXPECT_EQ(c.maximo(), 8);
}

TEST(colaPriorATest, test_remover_caso_un_hijo) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(6);
    c.insertar(7);
    c.remover(6);
    EXPECT_EQ(c.cardinal(), 2);
}

TEST(colaPriorATest, test_remover_caso_dos_hijos_simple) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    c.remover(7);
    EXPECT_EQ(c.cardinal(), 4);
}

TEST(colaPriorATest, test_remover_caso_dos_hijos_raiz) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(7);
    c.insertar(6);
    c.insertar(8);
    c.remover(5);
    EXPECT_EQ(c.cardinal(), 4);
}


TEST(colaPriorATest, test_remover_caso_dos_hijos_doble) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(20);
    c.insertar(15);
    c.insertar(12);
    c.insertar(16);
    c.insertar(24);
    c.insertar(22);
    c.insertar(25);
    c.remover(20);
    EXPECT_EQ(c.cardinal(), 8);
}

TEST(colaPriorATest, test_siguiente_inorder) {
    Conjunto<int> c;
    c.insertar(5);
    c.insertar(4);
    c.insertar(20);
    c.insertar(15);
    c.insertar(12);
    c.insertar(16);
    c.insertar(24);
    c.insertar(22);
    c.insertar(25);

    EXPECT_EQ(c.siguiente(20), 22);
    EXPECT_EQ(c.siguiente(4), 5);
    EXPECT_EQ(c.siguiente(15), 16);
}

const int NCLAVES = 1000;

int clave(int i) {
    return NCLAVES * ((i * i - 100 * i) % NCLAVES) + i;
}

TEST(colaPriorATest, mini_stress) {
    Conjunto<int> c;
    c.insertar(1);
    c.insertar(-2);
    c.insertar(3);
    c.insertar(-4);
    c.insertar(5);
    c.insertar(2);

    c.remover(-2);
    ASSERT_FALSE(c.pertenece(-2));
    c.remover(-4);
    ASSERT_FALSE(c.pertenece(-4));
    c.remover(2);
    ASSERT_FALSE(c.pertenece(2));

    c.insertar(4);

    c.remover(3);
    ASSERT_FALSE(c.pertenece(3));
    c.remover(1);
    ASSERT_FALSE(c.pertenece(1));
    c.remover(5);
    ASSERT_FALSE(c.pertenece(5));

    ASSERT_TRUE(c.pertenece(4));
    c.remover(4);
    ASSERT_FALSE(c.pertenece(4));
    ASSERT_EQ(c.cardinal(),0);
}

TEST(colaPriorATest, test_stress) {
    Conjunto<int> c;

    // Insertar
    for (int i = 0; i < NCLAVES; i++) {
        int k = clave(i);
        ASSERT_EQ(c.cardinal(), i);
        ASSERT_FALSE(c.pertenece(k));
        c.insertar(k);
        ASSERT_TRUE(c.pertenece(k));
    }
    ASSERT_EQ(c.cardinal(), NCLAVES);

    // Insertar de nuevo
    for (int i = 0; i < NCLAVES; i++) {
        int k = clave(i);
        ASSERT_TRUE(c.pertenece(k));
        c.insertar(k);
        ASSERT_TRUE(c.pertenece(k));
        ASSERT_EQ(c.cardinal(), NCLAVES);
    }

    // Eliminar los valores para i par
    for (int i = 0; i < NCLAVES; i++) {
        int k = clave(i);
        ASSERT_TRUE(c.pertenece(k));
        if (i % 2 == 0) {
            c.remover(k);
            ASSERT_FALSE(c.pertenece(k));
        }
    }
    ASSERT_EQ(c.cardinal(), NCLAVES / 2);

    // Eliminar los valores para i impar
    for (int i = 0; i < NCLAVES; i++) {
        int k = clave(i);
        if (i % 2 == 0) {
            ASSERT_FALSE(c.pertenece(k));
        } else {
            ASSERT_TRUE(c.pertenece(k));
            c.remover(k);
            ASSERT_FALSE(c.pertenece(k));
        }
    }
    ASSERT_EQ(c.cardinal(), 0);

    // Verificar que no haya valores
    for (int i = 0; i < NCLAVES; i++) {
        int k = clave(i);
        ASSERT_FALSE(c.pertenece(k));
    }
}