template<class alpha>
colaPriorA<alpha>::colaPriorA():_cola(){}

template<class alpha>
const alpha colaPriorA<alpha>::proximo()const{
    // el iterador al ultimo
    auto it = _cola.rbegin();
    return (*it).first;
}
template<class alpha>
void colaPriorA<alpha>::encolar(alpha tupla){
    _cola[tupla] = false;
}

template<class alpha>
void colaPriorA<alpha>::cambiarPrioridad(alpha tupla1, alpha tupla2){
    // recibe el anterior y lo borra y agrega el nuevo.
    // nunca va a haber repetidos pq las claves son unicas
    _cola.erase(tupla1);
    _cola[tupla2] = false;
}

template<class alpha>
bool colaPriorA<alpha>::vacia() const{
    return _cola.empty();
}

template<class alpha>
void colaPriorA<alpha>::desencolar(){
    auto it = _cola.rbegin();
    alpha proximo = (*it).first;
    _cola.erase(proximo);
}