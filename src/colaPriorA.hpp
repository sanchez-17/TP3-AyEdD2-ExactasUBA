template<class alpha, class beta>
colaPriorA<alpha,beta>::colaPriorA(int cota):_heap(vector<pair<alpha, typename map<beta,Nat>::iterator>>(cota)),_cota(cota),_longitud(0),_indices(map<beta, Nat>()){}

template<class alpha, class beta>
const pair<alpha, beta> & colaPriorA<alpha,beta>::proximo(colaPriorA& cola){
    pair<alpha, typename map<beta,Nat>::iterator> tuplaProx = _heap[0];
    alpha primeroProx = tuplaProx.first;
    typename map<beta,Nat>::iterator it = tuplaProx.second;
    beta segundoProx = it->first;
    return make_pair<primeroProx,segundoProx>;
}

template<class alpha, class beta>
alpha* colaPriorA<alpha,beta>::encolar(pair<alpha, beta> tupla){
    Nat index;
    if(_indices.count(tupla.second) > 0){
        int i = _indices[tupla.second];
        pair<alpha, beta> iesimo = make_pair(tupla.first, _indices[tupla.second]);
        if(tupla > iesimo){
            index = heapifyUp( i);
        } else {
            index = heapifyDown( i);
        }
    }else{
        _longitud++;
        typename map<beta,Nat>::iterator it = (_indices.emplace(std::make_pair(tupla.second, _longitud - 1))).first;
        _heap[_longitud - 1] = make_pair(tupla.first, it);
        index = heapifyUp( _longitud - 1);
    }
    alpha* res = &_heap[index].first;
    return res;
}

template<class alpha, class beta>
void colaPriorA<alpha,beta>::desencolar(colaPriorA& cola){
    int n = _heap.size() - 1;
    _heap[0] = _heap[n];
    _longitud--;
    heapifyDown(0);
}

template<class alpha, class beta>
bool colaPriorA<alpha,beta>::vacia(colaPriorA cola){
    return _longitud == 0;
}

template<class alpha, class beta>
Nat colaPriorA<alpha,beta>::heapifyUp(Nat i) {
    if(i>0){
        //pair<alpha,beta> tuplaIndex= obtenerTupla(_heap[index]);
        tuplaPersona<alpha,beta> tuplaIndex(_heap[i]);
        int indexPadre = floor((i-1)/2);
        tuplaPersona<alpha,beta> tuplaPadre(_heap[indexPadre]);
        //pair<alpha,beta> tuplaPadre= obtenerTupla(_heap[indexPadre]);

        while (tuplaIndex > tuplaPadre){
            indexPadre = floor((i-1)/2);
            tuplaPersona<alpha,beta> tuplaPadre(_heap[indexPadre]);

            pair<alpha,beta> temp = tuplaIndex;
            tuplaIndex = tuplaPadre;
            tuplaPadre = temp;

            i = indexPadre;
            _heap[i].second->second = i;
            _heap[indexPadre].second->second = indexPadre;
        }

        return i;
    }
}

template<class alpha, class beta>
Nat colaPriorA<alpha,beta>::heapifyDown(Nat i) {
    Nat largo = _longitud;
    Nat iMaximo = i;
    while (i < largo) {
        Nat iHijoIzq = 2 * i + 1;
        Nat iHijoDer = 2 * i + 2;
        Nat iMaximo = i;

        tuplaPersona<alpha,beta> tuplaIzq(_heap[iHijoIzq]);
        tuplaPersona<alpha,beta> tuplaDer(_heap[iHijoDer]);
        tuplaPersona<alpha,beta> tuplaMax(_heap[iMaximo]);
        //pair<alpha, beta> tuplaIzq = obtenerTupla(_heap[iHijoIzq]);
        //pair<alpha, beta> tuplaDer = obtenerTupla(_heap[iHijoDer]);
        //pair<alpha, beta> tuplaMax = obtenerTupla(_heap[iMaximo]);
        if (iHijoIzq < largo && tuplaIzq > tuplaMax) {
            _heap[iMaximo].second->second = iHijoIzq;
            _heap[iHijoDer].second->second = iMaximo;
            iMaximo = iHijoIzq;
        } else {

            if(iHijoDer < largo && tuplaDer > tuplaMax){
                _heap[iMaximo].second->second = iHijoIzq;
                _heap[iHijoDer].second->second = iMaximo;
                iMaximo = iHijoIzq;
            }
        }
        if (iMaximo != i) {
            pair<alpha, typename map<beta,Nat>::iterator> temp = _heap[i];
            _heap[i] = _heap[iMaximo];
            _heap[iMaximo] = temp;
            i = iMaximo;
        } else {
            break;
        }
    }
    return iMaximo;
}

template<class alpha, class beta>
pair<alpha, beta> colaPriorA<alpha, beta>::obtenerTupla(pair<alpha,typename map<beta, Nat>::iterator> t) {
    pair<alpha, beta> iesimo = make_pair(t.first, t.second->first);
    return iesimo;
}