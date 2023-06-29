#include "tuplaPersona.h"
template<class alpha, class beta>
tuplaPersona<alpha,beta>::tuplaPersona(alpha gastoPersona, beta persona):_tupla(tuple<alpha,beta>(gastoPersona,persona)){}

template<class alpha, class beta>
bool tuplaPersona<alpha, beta>::operator>(tuplaPersona t) {
    return (_tupla.first > t.first) || (_tupla.first == t.first && _tupla.second > t.second);
}

template<class alpha, class beta>
alpha tuplaPersona<alpha, beta>::getGastoPersona() const {
    return std::get<0>(_tupla);
}

template<class alpha, class beta>
beta tuplaPersona<alpha, beta>::getPersona() const {
    return std::get<1>(_tupla);
}