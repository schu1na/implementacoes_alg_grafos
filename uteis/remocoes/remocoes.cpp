#include "remocoes.hpp"

// Função de remoção de arestas em um grafo direcionado
Vizinho * remover_aresta_direcionado(Grafo * g, int v1, int v2){
    Grafo * pv1 = g->buscar_vertice(v1);    // O(V)
    Grafo * pv2 = g->buscar_vertice(v2);    // O(V)
    Vizinho * resp = nullptr;
    Vizinho * ant = nullptr;
    if(pv1 != nullptr && pv2 != nullptr){
        resp = pv1->prox_vizinho;
        ant = pv1->prox_vizinho;
        while(resp != nullptr && resp->id_vizinho != v2){   //O(deg(v1))
            ant = resp;
            resp = resp->prox;
        }
        
        if(resp == ant){
            pv1->prox_vizinho = resp->prox;
        }
        if(resp){
            ant->prox = resp->prox;
        }
        return resp;
    }  
}

// Função de remoção de arestas em um grafo não direcionado
void remover_aresta_nao_direcionado(Grafo * g, int v1, int v2){
    if(v1 == v2){
        remover_aresta_direcionado(g, v1, v2);
        return;
    }
    remover_aresta_direcionado(g, v1, v2);
    remover_aresta_direcionado(g, v2, v1);
}

// Funçao de inserção de um vértice com id x no grafo g
Grafo * remover_vertice(Grafo * g, int x){
    Grafo * p = g->buscar_vertice(x);       // O(V)
    if(p){
        Grafo * v = g;
        Grafo * ant = g;
        while(v != nullptr){        // removemos todas as arestas relacionados ao vértice x
            remover_aresta_direcionado(g, v->id_vertice, x); // O(V)
            v = v->prox_vertice;
        }

        v = g;
        ant = v;
        while(v->id_vertice != x){ // O(V)
            ant = v;
            v = v->prox_vertice;
        }

        if(ant == v){   // removemos o vértice x em si
            g = v->prox_vertice;
        }
        else{
            ant->prox_vertice = v->prox_vertice;
        }
        return g;
    }
}