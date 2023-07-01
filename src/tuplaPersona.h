#ifndef TUPLA_PERSONA
#define TUPLA_PERSONA
#include <tuple>
#include <map>

template<class alpha, class beta>
class tuplaPersona{
public:
    tuplaPersona();
    tuplaPersona(alpha gastoPersona, beta persona);

    const bool operator>(const tuplaPersona h);
    const bool operator<(const tuplaPersona h);
    alpha getGastoPersona() const;
    beta getPersona() const;
    tuplaPersona& operator=(const tuplaPersona& aCopiar);


private:
    alpha _a;
    beta _b;

};



#include "tuplaPersona.hpp"

#endif