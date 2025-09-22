#include "grafos.hpp"

// Método para remover vértice
Vertice * Grafo::remover_vertice(int chave){
    Vertice * u = buscar_vertice(chave);
    if(u){
        for(auto v : u->Adj){
            remover_aresta_direcionado(v.second->id, chave);
        }
        V.erase(chave);
        return u;
    }
    return u;
};

// Método para remover uma aresta em um grafo direcionado
Aresta * Grafo::remover_aresta_direcionado(int v1, int v2){
    Aresta * e = buscar_aresta(v1, v2); 
    // verificamos se a aresta v1 -> v2 existe
    if(e){
        // temos que remover v2 da Adj de v1
        Vertice * pv1 = buscar_vertice(v1);
        pv1->Adj.erase(v2);
        // apagamos a aresta v1->v2 do conjunto E
        E.erase(std::make_pair(v1,v2));
        return e;            
    }
    return e;        

};

// Método para remover uma aresta em um grafo não direcionado
void Grafo::remover_aresta_nao_direcionado(int v1, int v2){
    if(v1 == v2){
        remover_aresta_direcionado(v1, v2);
        return;
    }
    remover_aresta_direcionado(v1, v2);
    remover_aresta_direcionado(v2, v1);
};
