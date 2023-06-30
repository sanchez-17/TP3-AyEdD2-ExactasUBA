#ifndef TUPLA_PERSONA
#define TUPLA_PERSONA
#include <tuple>
#include <map>

template<class alpha, class beta>
class tuplaPersona{
public:
    //tuplaPersona(pair<alpha, typename map<beta,Nat>::iterator> tuplaPer);
    tuplaPersona(alpha gastoPersona, beta persona);

    bool operator>(tuplaPersona h);
    alpha getGastoPersona() const;
    beta getPersona() const;
    tuplaPersona& operator=(const tuplaPersona& aCopiar);


private:
    //std::tuple<alpha,beta> _tupla;
    //Nat aerr = 0;
    alpha _a;
    beta _b;

};

#include "tuplaPersona.hpp"

#endif