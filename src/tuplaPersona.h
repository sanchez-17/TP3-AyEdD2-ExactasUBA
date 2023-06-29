#ifndef TUPLA_PERSONA
#define TUPLA_PERSONA
#include "tipos.h"
#include <tuple>

template<class alpha, class beta>
class tuplaPersona{
public:
    tuplaPersona(pair<alpha, typename map<beta,Nat>::iterator> tuplaPer);
    //tuplaPersona(alpha gastoPersona, beta persona);
    bool operator>(tuplaPersona h);
    alpha getGastoPersona() const;
    beta getPersona() const;

private:
    std::tuple<alpha,beta> _tupla;
};

#include "tuplaPersona.hpp"

#endif