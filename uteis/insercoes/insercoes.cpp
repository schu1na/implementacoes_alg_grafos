#include <iostream>
#include "grafos/grafos.hpp"
#include "insercoes.hpp"

// Funçao de inserção de um vértice com id x no grafo g
Grafo * inserir_vertice(Grafo * g, int x){
    if(g->id_vertice == INFINITO){      // caso o id seja infinito, não há vértices no grafo ainda
        g->id_vertice = x;
        return g;
    }

    Grafo * v = g->buscar_vertice(x);       //O(V) devido ao busca_vertice
    if(v == NULL){
        v = new Grafo(x);
        v->prox_vertice = g;
        g = v;
    }
    return g;
}

// Função de inserção de arestas em um grafo direcionado
Vizinho * inserir_aresta_direcionado(Grafo * g, int v1, int v2){
    Grafo * pv1 = g->buscar_vertice(v1);    // O(V)
    Grafo * pv2 = g->buscar_vertice(v2);    // O(V)
    if(pv1 != NULL && pv2 != NULL){
        Vizinho * p = new Vizinho(v2);
        p->prox = pv1->prox_vizinho;
        pv1->prox_vizinho = p;
        return p;
    }
    return NULL; // Retorna NULL quando pelo menos 1 dos vértices não existir no grafo
}

// Função de inserção de arestas em um grafo não direcionado
void inserir_aresta_nao_direcionado(Grafo * g, int v1, int v2){
    if(v1 == v2){
        inserir_aresta_direcionado(g, v1, v2);   //O(V)
        return;
    }
    inserir_aresta_direcionado(g, v1, v2);   //O(V)
    inserir_aresta_direcionado(g, v2, v1);   //O(V)
}