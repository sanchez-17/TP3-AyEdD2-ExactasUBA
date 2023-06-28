template<class alpha, class beta>
colaPriorA<alpha,beta>::colaPriorA(int cota):_cota(cota),_longitud(0),_indices({{}}){} //preguntar

template<class alpha, class beta>
pair<alpha,beta> colaPriorA<alpha,beta>::proximo(colaPriorA& cola){
    pair<alpha, typename map<beta,Nat>::iterator> tuplaProx = heap[0];
    alpha primeroProx = tuplaProx.first;
    it = tuplaProx.second;
    beta segundoProx = it.first;
    return make_pair<primeroProx,segundoProx>;
}

template<class alpha, class beta>
alpha* colaPriorA<alpha,beta>::encolar(colaPriorA& cola, pair<alpha, beta> tupla){
    if(indices.contains(tupla.second)){
        int i = indices[tupla.second];
        pair<alpha, beta> iesimo = make_pair(tupla.first, _indices[tupla.second]);
        if(tupla > iesimo){
            index = heapifyUp(cola, i);
        } else {
            index = heapifyDown(c, i);
        }
    }else{
        _longitud = _longitud + 1;
        map<beta,Nat>::iterator it = (_indices.emplace(std::make_pair(beta, _longitud - 1))).first;
        heap[_longitud - 1] = make_pair(tupla.first, it);
        index = heapifyUp(cola, _longitud - 1);
    }
    alpha* res = &heap[index].first;
    return res;
}

template<class alpha, class beta>
void desencolar(colaPriorA& cola){
    n = _heap.size() - 1;
    _heap[0] = _heap[n];
    _longitud--;
    _heap = HeapifyDown(_heap,0);
}

template<class alpha, class beta>
bool colaPriorA<alpha,beta>::vacia(colaPriorA cola){
    return _longitud == 0;
}

template<class alpha, class beta>
colaPriorA& colaPriorA<alpha,beta>::heapifyUp(colaPriorA cola, int index){
    if(indice>0){
        alpha primeroIndex = _heap[index].first();
        beta segundoIndex = _heap[index].second().first();
        pair<alpha,beta> tuplaIndex= <primeroIndex,segundoIndex>;

        int indexPadre = floor((indice-1)/2);
        alpha primeroPadre = _heap[indexPadre].first();
        beta segundoPadre = _heap[indexPadre].second().first();
        pair<alpha,beta> tuplaPadre= <primeroPadre,segundoPadre>;

        while (tuplaIndex > tuplaPadre){
            
        }
    }
}

template<class alpha, class beta>
colaPriorA& colaPriorA<alpha,beta>::heapifyDown(colaPriorA cola, int indice){
    largo = _longitud;
    while(indice < largo){
        hijoIzq = 2*indice + 1;
        hijoDer = 2*indice + 2;
        maximo = i;
        if(hijoIzq < largo && heap[hijoIzq] > heap){

        }
    }
}
