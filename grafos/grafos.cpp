#include <iostream>
#include "grafos.hpp"

// Construtor de Vizinho
Vizinho::Vizinho(int id_vizinho) : id_vizinho(id_vizinho){
        prox = nullptr;
}

// Construtor de Grafo inicializando com um vértice
Grafo::Grafo(int id_vertice) : id_vertice(id_vertice) {
    prox_vizinho = nullptr;
    prox_vertice = nullptr;
}

// Construtor de Grafo sem vértice inicial
Grafo::Grafo(){
    id_vertice = INFINITO;
    prox_vizinho = nullptr;
    prox_vertice = nullptr;
}

// Método de busca de um vértice
Grafo * Grafo::buscar_vertice(int x){
    Grafo * g = this;
    while(g != nullptr && g->id_vertice != x){ //O(V) porque podemos ter que olhar todos os vértices
        g = g->prox_vertice;
    }
    return g;
}

// Método de busca de uma aresta
Vizinho * Grafo::buscar_aresta(int v1, int v2){ //Estamos buscando pela aresta v1 -> v2
    Grafo * pv1 = buscar_vertice(v1);   //O(V)
    Grafo * pv2 = buscar_vertice(v2);   //O(V)
    Vizinho * resp = nullptr;
    if(pv1 != nullptr && pv2 != nullptr){
        resp = pv1->prox_vizinho;
        while(resp != nullptr && resp->id_vizinho != v2){  //O(deg(v1)) grau do vértice v1
            resp = resp->prox;                             //que no pior dos casos é O(V)
        }
    }
    return resp;
}

// Método para imprimir o grafo (INCOMPLETO: falta imprimir arestas)
void Grafo::imprimir_grafo(){
    Grafo * g = this;
    while(g != nullptr){   //O(V) porque imprimimos todos os vértices
        std::cout << g->id_vertice;
        Vizinho * v = g->prox_vizinho;
        while(v != nullptr){   //O(deg(v))
            std::cout << " -> " << v->id_vizinho;
            v = v->prox;
        }
        std::cout << std::endl;
        g = g->prox_vertice;
    }
    std::cout << std::endl;
}