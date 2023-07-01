#include "../src/puesto.h"
#include "gtest-1.8.1/gtest.h"

Menu menu = {{3, 500}, {4, 1000}, {5, 2500}, {7, 2000}};
Stock stock2 = {{3, 10}, {4, 5}, {5, 30}, {7, 10}};
Promociones descuentos2 = {{7, {{3, 20}, {6, 25}}}};


TEST(puestoTest, descuento) {
    puesto nuevoPuesto;
    puesto p = nuevoPuesto.crearPuesto(menu,stock2,descuentos2);

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
