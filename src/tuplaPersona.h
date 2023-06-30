#ifndef TUPLA_PERSONA
#define TUPLA_PERSONA
#include <tuple>
#include <map>

template<class alpha, class beta>
class tuplaPersona{
public:
    tuplaPersona(alpha gastoPersona, beta persona);

    bool operator>(tuplaPersona h);
    bool operator<(tuplaPersona h);
    alpha getGastoPersona() const;
    beta getPersona() const;
    tuplaPersona& operator=(const tuplaPersona& aCopiar);


private:
    alpha _a;
    beta _b;

};



#include "tuplaPersona.hpp"

#endif