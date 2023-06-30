//template<class alpha, class beta>
//colaPriorA<alpha,beta>::colaPriorA() = default;

template<class alpha, class beta>
colaPriorA<alpha,beta>::colaPriorA(int cota):_heap(vector<pair<alpha, typename map<beta,Nat>::iterator>>(cota)),_cota(cota),_longitud(0),_indices(map<beta, Nat>()){}

template<class alpha, class beta>
const tuplaPersona<alpha, beta> colaPriorA<alpha,beta>::proximo()const{
    //pair<alpha, typename map<beta,Nat>::iterator> tuplaProx = _heap[0];
    tuplaPersona<alpha,beta> res(_heap[0].first,_heap[0].second->first);
    //alpha primeroProx = tuplaProx.first;
    //typename map<beta,Nat>::iterator it = tuplaProx.second;
    //beta segundoProx = it->first;
    //retun make_pair<primeroProx,segundoProx>;
    return res;
}

template<class alpha, class beta>
alpha* colaPriorA<alpha,beta>::encolar(tuplaPersona<alpha, beta> tupla){
    Nat index;
    if(_indices.count(tupla.getPersona()) > 0){
        Nat i = _indices[tupla.getPersona()];
        tuplaPersona<alpha, beta> iesimo(_heap[i].first,_heap[i].second->first);
        //pair<alpha, beta> iesimo = make_pair(tupla.getGastoPersona(), _indices[tupla.getPersona()]);
        if(tupla > iesimo){
            index = heapifyUp(i);
        } else {
            index = heapifyDown(i);
        }
    }else{
        _longitud++;
        _indices[tupla.getPersona()] = _longitud - 1;
        typename map<beta,Nat>::iterator it = _indices.end()--;
        //typename map<beta,Nat>::iterator it = (_indices.emplace(make_pair(tupla.getPersona(), _longitud - 1))).first;
        _heap[_longitud - 1] = make_pair(tupla.getPersona(), it);
        index = heapifyUp( _longitud - 1);
    }
    alpha* res = &_heap[index].first;
    return res;
}

template<class alpha, class beta>
void colaPriorA<alpha,beta>::desencolar(){
    //int n = _heap.size() - 1;
    _heap[0] = _heap[_longitud-1];
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
        //pair<alpha,beta> tuplaIndex= obtenerTupla(_heap[index]);
        tuplaPersona<alpha,beta> tuplaI(_heap[i].first,_heap[i].second->first);
        Nat indexPadre = floor((i-1)/2);
        tuplaPersona<alpha,beta> tuplaPadre(_heap[indexPadre].first,_heap[indexPadre].second->first);
        //pair<alpha,beta> tuplaPadre= obtenerTupla(_heap[indexPadre]);

        while (tuplaI > tuplaPadre){
            indexPadre = floor((i-1)/2);
            tuplaPersona<alpha,beta> tuplaPadre(_heap[indexPadre].first,_heap[indexPadre].second->first);
            //pair<alpha,beta> temp = tuplaI;
            //tuplaI = tuplaPadre;
            //tuplaPadre = temp;

            pair<alpha, typename map<beta,Nat>::iterator> temp = _heap[i];
            _heap[i] = _heap[indexPadre];
            _heap[indexPadre] = temp;

            i = indexPadre;
            _heap[i].second->second = i;
            _heap[indexPadre].second->second = indexPadre;
        }
    }
    return i;
}

template<class alpha, class beta>
Nat colaPriorA<alpha,beta>::heapifyDown(Nat i) {
    Nat largo = _longitud;
    Nat iMaximo;
    while (i < largo) {
        Nat iHijoIzq = 2 * i + 1;
        Nat iHijoDer = 2 * i + 2;
        iMaximo = i;
        tuplaPersona<alpha,beta> tuplaIzq(_heap[iHijoIzq].first,_heap[iHijoIzq].second->first);
        tuplaPersona<alpha,beta> tuplaDer(_heap[iHijoDer].first,_heap[iHijoDer].second->first);
        tuplaPersona<alpha,beta> tuplaMax(_heap[iMaximo].first,_heap[iMaximo].second->first);

        //pair<alpha, beta> tuplaIzq = obtenerTupla(_heap[iHijoIzq]);
        //pair<alpha, beta> tuplaDer = obtenerTupla(_heap[iHijoDer]);
        //pair<alpha, beta> tuplaMax = obtenerTupla(_heap[iMaximo]);
        if (iHijoIzq < largo && tuplaIzq > tuplaMax) {
            _heap[iMaximo].second->second = iHijoIzq;
            _heap[iHijoDer].second->second = iMaximo;
            iMaximo = iHijoIzq;
        } else {

            if(iHijoDer < largo && tuplaDer > tuplaMax){
                _heap[iMaximo].second->second = iHijoDer;
                _heap[iHijoDer].second->second = iMaximo;
                iMaximo = iHijoDer;
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