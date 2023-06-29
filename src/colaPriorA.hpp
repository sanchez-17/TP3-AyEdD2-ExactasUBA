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
alpha* colaPriorA<alpha,beta>::encolar(colaPriorA& cola, pair<alpha, beta> tupla){
    Nat index;
    if(_indices.contains(tupla.second)){
        int i = _indices[tupla.second];
        pair<alpha, beta> iesimo = make_pair(tupla.first, _indices[tupla.second]);
        if(tupla > iesimo){
            index = heapifyUp(cola, i);
        } else {
            index = heapifyDown(cola, i);
        }
    }else{
        _longitud++;
        typename map<beta,Nat>::iterator it = (_indices.emplace(std::make_pair(tupla.second, _longitud - 1))).first;
        _heap[_longitud - 1] = make_pair(tupla.first, it);
        index = heapifyUp(cola, _longitud - 1);
    }
    alpha* res = &_heap[index].first;
    return res;
}

template<class alpha, class beta>
void colaPriorA<alpha,beta>::desencolar(colaPriorA& cola){
    int n = _heap.size() - 1;
    _heap[0] = _heap[n];
    _longitud--;
    _heap = heapifyDown(_heap,0);
}

template<class alpha, class beta>
bool colaPriorA<alpha,beta>::vacia(colaPriorA cola){
    return _longitud == 0;
}

template<class alpha, class beta>
Nat colaPriorA<alpha,beta>::heapifyUp(colaPriorA cola, Nat index){
    if(index>0){
        //pair<alpha,beta> tuplaIndex= obtenerTupla(_heap[index]);
        tuplaPersona<alpha,beta> tuplaIndex(_heap[index]);
        int indexPadre = floor((index-1)/2);
        tuplaPersona<alpha,beta> tuplaPadre(_heap[indexPadre]);
        //pair<alpha,beta> tuplaPadre= obtenerTupla(_heap[indexPadre]);

        while (tuplaIndex > tuplaPadre){
            indexPadre = floor((index-1)/2);
            tuplaPersona<alpha,beta> tuplaPadre(_heap[indexPadre]);

            pair<alpha,beta> temp = tuplaIndex;
            tuplaIndex = tuplaPadre;
            tuplaPadre = temp;

            index = indexPadre;
            _heap[index].second->second = index;
            _heap[indexPadre].second->second = indexPadre;
        }

        return index;
    }
}

template<class alpha, class beta>
Nat colaPriorA<alpha,beta>::heapifyDown(colaPriorA cola, Nat index) {
    Nat largo = _longitud;
    Nat iMaximo = index;
    while (index < largo) {
        Nat iHijoIzq = 2 * index + 1;
        Nat iHijoDer = 2 * index + 2;
        Nat iMaximo = index;

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
        if (iMaximo != index) {
            pair<alpha, typename map<beta,Nat>::iterator> temp = _heap[index];
            _heap[index] = _heap[iMaximo];
            _heap[iMaximo] = temp;
            index = iMaximo;
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