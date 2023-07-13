template<class alpha>
colaPriorA<alpha>::colaPriorA():_cola(){}

template<class alpha>
const alpha colaPriorA<alpha>::proximo()const{
    // el iterador al ultimo
    auto it = _cola.rbegin();
    return (*it).first;
}
template<class alpha>
void colaPriorA<alpha>::encolar(alpha a){
    _cola[a] = false;
}

template<class alpha>
void colaPriorA<alpha>::actualizarOrden(alpha a1, alpha a2){
    // recibe el anterior y lo borra y agrega el nuevo.
    // nunca va a haber repetidos pq las claves son unicas
    _cola.erase(a1);
    _cola[a2] = false;
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