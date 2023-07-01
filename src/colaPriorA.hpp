template<class alpha, class beta>
colaPriorA<alpha,beta>::colaPriorA(int cota):_heap(vector<pair<alpha, typename map<beta,Nat>::iterator>>(cota)),_cota(cota),_longitud(0),_indices(map<beta, Nat>()){}

template<class alpha, class beta>
const tuplaPersona<alpha, beta> colaPriorA<alpha,beta>::proximo()const{
    tuplaPersona<alpha,beta> res(_heap[0].first,_heap[0].second->first);
    return res;
}

template<class alpha, class beta>
alpha* colaPriorA<alpha,beta>::encolar(tuplaPersona<alpha, beta> tupla){
    Nat index;
    if(_indices.count(tupla.getPersona()) > 0){
        Nat i = _indices[tupla.getPersona()];
        tuplaPersona<alpha, beta> iesimo(_heap[i].first,_heap[i].second->first);
        if(tupla > iesimo){
            index = heapifyUp(i);
        } else {
            index = heapifyDown(i);
        }
    }else{
        _longitud++;
        pair<typename map<beta,Nat>::iterator,bool> it = _indices.insert(pair<Persona,Nat>(tupla.getPersona(),_longitud-1));
        _heap[_longitud - 1] = make_pair(tupla.getGastoPersona(), it.first);
        index = heapifyUp( _longitud - 1);
    }
    alpha* res = &_heap[index].first;
    //_heap[index].second->second = index;
    return res;
}

template<class alpha, class beta>
void colaPriorA<alpha,beta>::desencolar(){
    swap(_heap[0], _heap[_longitud-1]);
    //Actualizamos indices
    _heap[0].second->second = 0;
    _heap[_longitud-1].second->second = _longitud-1;
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
        tuplaPersona<alpha,beta> tuplaI(_heap[i].first,_heap[i].second->first);
        Nat indexPadre = floor((i-1)/2);
        tuplaPersona<alpha,beta> tuplaPadre(_heap[indexPadre].first,_heap[indexPadre].second->first);

        while (tuplaI > tuplaPadre && i!=0){
            indexPadre = floor((i-1)/2);
            tuplaPadre = tuplaPersona<alpha,beta>(_heap[indexPadre].first,_heap[indexPadre].second->first);
            swap(_heap[i], _heap[indexPadre]);

            swap(i,indexPadre);
            //i = indexPadre;
            _heap[i].second->second = i;
            _heap[indexPadre].second->second = indexPadre;
        }
    }
    return i;
}

template<class alpha, class beta>
Nat colaPriorA<alpha,beta>::heapifyDown(Nat i) {
    /*Nat left = 2*i + 1;
    Nat right = 2*i + 2;
    Nat indiceMayorHijo = i;
    tuplaPersona<alpha,beta> tuplaLeft(_heap[left].first,_heap[left].second->first);
    tuplaPersona<alpha,beta> tuplaRight(_heap[right].first,_heap[right].second->first);
    tuplaPersona<alpha,beta> tuplaMax(_heap[indiceMayorHijo].first,_heap[indiceMayorHijo].second->first);

    if (left < _longitud && tuplaMax < tuplaLeft) {
        _heap[indiceMayorHijo].second->second = left;
        _heap[right].second->second = indiceMayorHijo;
        indiceMayorHijo = left;
    }
    if (right < _longitud && tuplaMax < tuplaRight) {
        _heap[indiceMayorHijo].second->second = right;
        _heap[right].second->second = indiceMayorHijo;
        indiceMayorHijo = right;
    }

    if (indiceMayorHijo != i) {
        swap(_heap[i], _heap[indiceMayorHijo]);
        heapifyDown(indiceMayorHijo);
    }*/
    //***********************
    Nat largo = _longitud;
    Nat iMayorHijo = i;
    while (i < largo) {
        Nat iHijoIzq = 2 * i + 1;
        Nat iHijoDer = 2 * i + 2;
        iMayorHijo = i;

        tuplaPersona<alpha, beta> tuplaIzq;
        tuplaPersona<alpha, beta> tuplaDer;
        if(iHijoIzq<largo) {
            tuplaIzq = tuplaPersona<alpha, beta>(_heap[iHijoIzq].first, _heap[iHijoIzq].second->first);
        }
        if(iHijoDer<largo) {
            tuplaDer = tuplaPersona<alpha, beta>(_heap[iHijoDer].first, _heap[iHijoDer].second->first);
        }
        tuplaPersona<alpha,beta> tuplaMax(_heap[iMayorHijo].first,_heap[iMayorHijo].second->first);

        if (iHijoIzq < largo) {
            if(tuplaIzq > tuplaMax){
                iMayorHijo = iHijoIzq;
                tuplaMax = tuplaPersona<alpha,beta>(_heap[iMayorHijo].first,_heap[iMayorHijo].second->first);
            }

        }
        if(iHijoDer < largo){
            if(tuplaDer > tuplaMax){
                iMayorHijo = iHijoDer;
            }
        }

        if (iMayorHijo != i) {
            _heap[i].second->second = iMayorHijo;
            _heap[iMayorHijo].second->second = i;
            swap(_heap[i], _heap[iMayorHijo]);
            i = iMayorHijo;
        } else {
            break;
        }
    }
    return iMayorHijo;
}

template<class alpha, class beta>
pair<alpha, beta> colaPriorA<alpha, beta>::obtenerTupla(pair<alpha,typename map<beta, Nat>::iterator> t) {
    pair<alpha, beta> iesimo = make_pair(t.first, t.second->first);
    return iesimo;
}