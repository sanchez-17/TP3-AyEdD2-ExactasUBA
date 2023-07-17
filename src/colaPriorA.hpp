template<class alpha, class beta>
colaPriorA<alpha,beta>::colaPriorA() = default;

template<class alpha, class beta>
colaPriorA<alpha,beta>::colaPriorA(int cota):
_heap(vector<pair<alpha,typename map<beta, Nat>::iterator>*>(cota)),
_cota(cota),
_longitud(0),
_tuplas(vector<pair<alpha,typename map<beta, Nat>::iterator> >(cota)),
_indices(){}

template<class alpha, class beta>
const beta colaPriorA<alpha,beta>::proximo()const{
    return (*_heap[0]).second->first;
}

template<class alpha, class beta>
alpha colaPriorA<alpha,beta>::encolar(tuplaPersona<alpha, beta> gastoActualizado){
    Nat index;
    if(_indices.count(gastoActualizado.getPersona()) == 1){
        Nat i = _indices[gastoActualizado.getPersona()];
        Nat gastoAnterior = (*_heap[i]).first;
        //Actualizamos el gasto, y mantenemos el invariante de colaPriorA
        (*_heap[i]).first = gastoActualizado.getGastoPersona();
        if(gastoActualizado.getGastoPersona() > gastoAnterior){
            index = heapifyUp(i);
        } else {
            index = heapifyDown(i);
        }
    }else{
        auto iterador = _indices.insert({gastoActualizado.getPersona(), _longitud}).first;
        //_indices[gastoActualizado.getPersona()] = _longitud;
        //Nat* it = &_indices.at(gastoActualizado.getPersona());
        _tuplas[_longitud] = make_pair(gastoActualizado.getGastoPersona(), iterador);
        auto puntero = &_tuplas[_longitud];
        _heap[_longitud] = puntero;
        index = heapifyUp( _longitud);
        _longitud++;
    }
    return (*_heap[index]).first;
}

template<class alpha, class beta>
void colaPriorA<alpha,beta>::desencolar(){
    swap(_heap[0], _heap[_longitud-1]);
    //Actualizamos indices
    (*_heap[0]).second->second = 0;
    (*_heap[_longitud-1]).second->second = _longitud-1;
    _longitud--;
    heapifyDown(0);
}

template<class alpha, class beta>
bool colaPriorA<alpha,beta>::vacia(){
    return _longitud == 0;
}

template<class alpha, class beta>
Nat colaPriorA<alpha,beta>::heapifyUp(Nat i) {
    if(i>0){
        tuplaPersona<alpha,beta> tuplaI((*_heap[i]).first,(*_heap[i]).second->first);
        Nat indexPadre = floor((i-1)/2);
        tuplaPersona<alpha,beta> tuplaPadre((*_heap[indexPadre]).first,(*_heap[indexPadre]).second->first);

        while (tuplaI > tuplaPadre && i!=0){
            //indexPadre = floor((i-1)/2);
            //Intercambiamos indices, y luego las tuplas con los indices correspondientes.
            (*_heap[i]).second->second = indexPadre;
            (*_heap[indexPadre]).second->second = i;
            swap(_heap[i], _heap[indexPadre]);
            i = indexPadre; //ahora yo soy mi padre
            if(indexPadre != 0){ //es necesario este if? yo pq capaz la cuenta se rompe
                indexPadre = floor((i-1)/2); //quiero mi nuevo padre
                //y me creo a la tupla padre, ahora con el indice correcto
                tuplaPadre = tuplaPersona<alpha,beta>((*_heap[indexPadre]).first,(*_heap[indexPadre]).second->first);
            }
            //else: ya no quiero q hagas nada, ya estoy en el 0
            //pero esto deberia detectarlo la guarda del while

            //tuplaPadre = tuplaPersona<alpha,beta>(_heap[indexPadre].first,_heap[indexPadre].second->first);
            //i = indexPadre;
        }
    }
    return i;
}

template<class alpha, class beta>
Nat colaPriorA<alpha,beta>::heapifyDown(Nat i) {
    Nat largo = _longitud;
    Nat iMayorHijo = i;
    while (i < largo) {
        Nat iHijoIzq = 2 * i + 1;
        Nat iHijoDer = 2 * i + 2;
        iMayorHijo = i;

        tuplaPersona<alpha, beta> tuplaIzq;
        tuplaPersona<alpha, beta> tuplaDer;
        if(iHijoIzq<largo) {
            tuplaIzq = tuplaPersona<alpha, beta>((*_heap[iHijoIzq]).first, (*_heap[iHijoIzq]).second->first);
        }
        if(iHijoDer<largo) {
            tuplaDer = tuplaPersona<alpha, beta>((*_heap[iHijoDer]).first, (*_heap[iHijoDer]).second->first);
        }
        tuplaPersona<alpha,beta> tuplaMax((*_heap[iMayorHijo]).first,(*_heap[iMayorHijo]).second->first);

        if (iHijoIzq < largo) {
            if(tuplaIzq > tuplaMax){
                iMayorHijo = iHijoIzq;
                tuplaMax = tuplaPersona<alpha,beta>((*_heap[iMayorHijo]).first,(*_heap[iMayorHijo]).second->first);
            }

        }
        if(iHijoDer < largo){
            if(tuplaDer > tuplaMax){
                iMayorHijo = iHijoDer;
            }
        }

        if (iMayorHijo != i) {
            (*_heap[i]).second->second = iMayorHijo;
            (*_heap[iMayorHijo]).second->second = i;
            swap(_heap[i], _heap[iMayorHijo]);
            i = iMayorHijo;
        } else {
            break;
        }
    }
    return iMayorHijo;
}
