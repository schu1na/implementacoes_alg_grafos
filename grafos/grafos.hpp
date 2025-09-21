#ifndef GRAFOS_HPP
#define GRAFOS_HPP

#include <limits>
#define INFINITO std::numeric_limits<int>::max()

//Estrutura que representará as arestas do meu grafo através
//de uma lista de adjacências
typedef struct Vizinho {
    int id_vizinho;
    int peso;
    struct Vizinho * prox;

    // Construtor
    Vizinho(int id_vizinho);

} Vizinho;

//Estrutura principal que representará um grafo
typedef struct Grafo {
    int id_vertice;
    Vizinho * prox_vizinho;
    struct Grafo * prox_vertice;

    // Construtor inicializando com 1 vértice
    Grafo(int id_vertice);

    // Construtor sem vértice inicial
    Grafo();

    // Método de busca de um vértice
    Grafo * buscar_vertice(int x);

    // Método de busca de uma aresta
    Vizinho * buscar_aresta(int v1, int v2);

    // Método para imprimir o grafo 
    void imprimir_grafo();

} Grafo;

#endif