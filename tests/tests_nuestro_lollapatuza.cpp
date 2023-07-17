#include "../src/puesto.h"
#include "../src/lollapatuza.h"
#include "gtest-1.8.1/gtest.h"

#include "../src/tipos.h"

Menu menu1 = {{3, 500}, {4, 1000}, {5, 2500}, {7, 2000}};
Stock stock21 = {{3, 10}, {4, 5}, {5, 30}, {7, 10}};
Promociones descuentos21 = {{7, {{3, 20}, {6, 25}}}};
Persona per21 = 2;
Persona per41 = 4;
Persona per81 = 8;
Persona per91 = 9;
set<Persona> peoples={2,4,8,9};

TEST(nuestroLollaTest, bugacho_raro) {
    puesto nuevoPuesto;
    nuevoPuesto = nuevoPuesto.crearPuesto(menu1, stock21, descuentos21);

    map<IdPuesto,puesto>  dickPuesto;
    dickPuesto[2] = nuevoPuesto;

    lollapatuza lol(dickPuesto,peoples);

    lol.vender(2,8,3,2); //1000
    EXPECT_EQ(lol.gastoTotal(8),1000);


}