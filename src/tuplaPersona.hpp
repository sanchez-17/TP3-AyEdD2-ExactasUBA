
//tuplaPersona<alpha,beta>::tuplaPersona(pair<alpha, typename map<beta,Nat>::iterator> tuplaPer):
//_tupla(tuple<alpha,beta>(tuplaPer.first,tuplaPer.second->first)){}
template<class alpha, class beta>
tuplaPersona<alpha,beta>::tuplaPersona(alpha a,beta b):
//_tupla(tuple<alpha,beta>(tuplaPer.first,tuplaPer.second)){}
_tupla(make_pair(a,b)){}

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