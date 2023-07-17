
#include "tuplaPersona.h"

template<class alpha, class beta>
tuplaPersona<alpha,beta>::tuplaPersona(){}

template<class alpha, class beta>
tuplaPersona<alpha,beta>::tuplaPersona(alpha a,beta b) : _a(a),_b(b)
{}

template<class alpha, class beta>
tuplaPersona<alpha, beta>& tuplaPersona<alpha, beta>::operator=(const tuplaPersona &aCopiar) {
    this->_a = aCopiar.getGastoPersona();
    this->_b = aCopiar.getPersona();
    return *this;
}

template<class alpha, class beta>
bool tuplaPersona<alpha, beta>::operator>(const tuplaPersona& t) const{
    return (this->getGastoPersona() > t.getGastoPersona()) || (this->getGastoPersona() == t.getGastoPersona() && this->getPersona() > t.getPersona());
}

template<class alpha, class beta>
bool tuplaPersona<alpha, beta>::operator<(const tuplaPersona& t) const{
    return (this->getGastoPersona() < t.getGastoPersona()) || (this->getGastoPersona() == t.getGastoPersona() && this->getPersona() < t.getPersona());
}

template<class alpha, class beta>
alpha tuplaPersona<alpha, beta>::getGastoPersona() const {
    return _a;
}

template<class alpha, class beta>
beta tuplaPersona<alpha, beta>::getPersona() const {
    return _b;
}

template<class alpha, class beta>
bool tuplaPersona<alpha, beta>::operator==(tuplaPersona t) const{
    return (this->getGastoPersona() == t.getGastoPersona() && this->getPersona() == t.getPersona());
}

template<class alpha, class beta>
bool tuplaPersona<alpha, beta>::operator!=(tuplaPersona t) const{
    return (this->getGastoPersona() != t.getGastoPersona() || this->getPersona() != t.getPersona());
}
