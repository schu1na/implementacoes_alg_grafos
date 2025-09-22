#include "grafos.hpp"

// Funçao de inserção de um vértice com id x no grafo g
void Grafo::inserir_vertice(int chave){
    if(V.empty()){
        Vertice * u = new Vertice(chave);
        V.emplace(chave, u);
        return;
    }
    Vertice * u = buscar_vertice(chave);
    if(u == nullptr){
        u = new Vertice(chave);
        V.emplace(chave, u);
        return;
    }
}

// Método de inserção de uma aresta em um grafo direcionado
Aresta * Grafo::inserir_aresta_direcionado(int v1, int v2){
    Vertice * pv1 = buscar_vertice(v1);
    Vertice * pv2 = buscar_vertice(v2);
    if(pv1 != nullptr && pv2 != nullptr){
        pv1->Adj.emplace(v2, pv2);
        Aresta * e = new Aresta(pv1, pv2);
        E.emplace(std::make_pair(v1,v2), e);
        return e;
    }
    return nullptr;
};

// Método de inserção de uma aresta em um grafo não direcionado
void Grafo::inserir_aresta_nao_direcionado(int v1, int v2){
    if(v1 == v2){
        inserir_aresta_direcionado(v1, v2);
        return;
    }
    inserir_aresta_direcionado(v1, v2);
    inserir_aresta_direcionado(v2, v1);

};
