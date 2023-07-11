template<class alpha>
colaPriorA<alpha>::colaPriorA():_cola(map<alpha, bool>()){}

template<class alpha>
const alpha colaPriorA<alpha>::proximo()const{
    // aca seria el iterador al ultimo
    auto it = --_cola.end();
    return (*it).first;
}
template<class alpha>
void colaPriorA<alpha>::encolar(alpha tupla){
    //simplemente encolo
    _cola[tupla] = false; //bool basura
}

template<class alpha>
void colaPriorA<alpha>::cambiarPrioridad(alpha tupla1, alpha tupla2){
    //me dan el anterior y lo borro y agrego este nuevo.
    //nunca va a haber repetidos pq las claves son unicas
    _cola.erase(tupla1);
    _cola[tupla2] = false; //bool basura
}

template<class alpha>
bool colaPriorA<alpha>::vacia(){
    return _cola.empty();
}

template<class alpha>
void colaPriorA<alpha>::desencolar(){
    auto it = --_cola.end();
    alpha proximo = (*it).first;
    _cola.erase(proximo);
}