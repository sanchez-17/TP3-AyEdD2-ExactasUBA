#include "../src/puesto.h"
#include "gtest-1.8.1/gtest.h"

Menu menu = {{3, 500}, {4, 1000}, {5, 2500}, {7, 2000}};
Stock stock2 = {{3, 10}, {4, 5}, {5, 30}, {7, 10}};
Promociones descuentos2 = {{7, {{3, 20}, {6, 25}}}};
Persona per2 = 2;
Persona per4 = 4;
Persona per9 = 9;


TEST(puestoTest, descuento) {
    puesto p(menu,stock2,descuentos2);

    EXPECT_EQ(p.descuento(7,0),0);
    EXPECT_EQ(p.descuento(7,2),0);
    EXPECT_EQ(p.descuento(7,3),20);
    EXPECT_EQ(p.descuento(7,4),20);
    EXPECT_EQ(p.descuento(7,5),20);
    EXPECT_EQ(p.descuento(7,6),25);
    EXPECT_EQ(p.descuento(7,7),25);
    EXPECT_EQ(p.descuento(7,10),25);
    //FUNCIONA, entonces algo pasa cuando se obtiene el puesto por referencia
}

TEST(puestoTest, vender) {
    puesto p(menu,stock2,descuentos2);

    p.vender(per2,3,5);
    EXPECT_EQ(p.gastosDe(per2),2500);
    p.vender(per2,4,2);
    EXPECT_EQ(p.gastosDe(per2),4500);
    p.vender(per4,5,1);
    EXPECT_EQ(p.gastosDe(per4),2500);
}

TEST(puestoTest, vender_con_desc) {
    puesto p(menu,stock2,descuentos2);

    p.vender(per2,7,6);
    EXPECT_EQ(p.gastosDe(per2),9000);
    p.vender(per4,7,3);
    EXPECT_EQ(p.gastosDe(per4),4800);
    p.vender(per9,7,10);
    EXPECT_EQ(p.gastosDe(per9),15000);
}