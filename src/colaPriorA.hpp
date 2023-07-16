template<class alpha, class beta>
colaPriorA<alpha, beta>::colaPriorA():_cola(){}

template<class alpha, class beta>
const alpha colaPriorA<alpha, beta>::proximo()const{
    //Iterador al maximo
    auto it = _cola.rbegin();
    return (*it).first.getPersona();
}
template<class alpha, class beta>
void colaPriorA<alpha, beta>::encolar(tuplaPersona<alpha, beta> tupla){
    _cola[tupla] = false;
}

template<class alpha, class beta>
void colaPriorA<alpha, beta>::actualizarOrden(tuplaPersona<alpha, beta> tupla1, tuplaPersona<alpha, beta> tupla2){
    _cola.erase(tupla1);
    _cola[tupla2] = false;
}

template<class alpha, class beta>
bool colaPriorA<alpha, beta>::vacia() const{
    return _cola.empty();
}

template<class alpha, class beta>
void colaPriorA<alpha, beta>::desencolar(){
    auto it = _cola.rbegin();
    auto proximo = (*it).first;
    _cola.erase(proximo);
}