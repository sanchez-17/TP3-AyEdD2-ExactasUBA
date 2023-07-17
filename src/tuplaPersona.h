#ifndef TUPLA_PERSONA
#define TUPLA_PERSONA
#include <tuple>
#include <map>

template<class alpha, class beta>
class tuplaPersona{
public:
    tuplaPersona();
    tuplaPersona(alpha gastoPersona, beta persona);

    bool operator>(const tuplaPersona& t) const;
    bool operator<(const tuplaPersona& t) const;
    bool operator == (tuplaPersona t) const;
    alpha getGastoPersona() const;
    beta getPersona() const;
    tuplaPersona& operator=(const tuplaPersona& aCopiar);
    bool operator != (tuplaPersona t) const;
    
private:
    alpha _a;
    beta _b;

};



#include "tuplaPersona.hpp"

#endif