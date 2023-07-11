#ifndef TUPLA_PERSONA
#define TUPLA_PERSONA
#include <tuple>
#include <map>

template<class alpha, class beta>
class tuplaPersona{
public:
    tuplaPersona();
    tuplaPersona(alpha gastoPersona, beta persona);

    bool operator>(const tuplaPersona& h) const;
    bool operator<(const tuplaPersona& h) const;
    bool operator == (tuplaPersona h);
    alpha getGastoPersona() const;
    beta getPersona() const;
    tuplaPersona& operator=(const tuplaPersona& aCopiar);
    bool operator != (tuplaPersona h);

private:
    alpha _a;
    beta _b;

};



#include "tuplaPersona.hpp"

#endif