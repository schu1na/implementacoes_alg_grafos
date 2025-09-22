#ifndef GRAFOS_HPP
#define GRAFOS_HPP

#include <unordered_map>
#include <utility>
// #include <limits>

// #define INFINITO std::numeric_limits<int>::max()

// estrutura que representará os vértices
typedef struct Vertice{
    int id;
    std::unordered_map<int, struct Vertice *> Adj;   // lista de adjacencias do vértice
    
    // construtor
    Vertice(int id);

} Vertice;

// estrutura que representará as arestas
typedef struct Aresta{
    Vertice * v1;
    Vertice * v2;

    Aresta(Vertice * v1, Vertice * v2);

} Aresta;

// estrutura auxiliar para fazer o hash do par de 
// chaves das arestas
typedef struct PairHash {
     std::size_t operator()(const std::pair<int,int>& p) const;
} PairHash;

// estrutura principal que representará o grafo
typedef struct Grafo {
    // Conjunto de vertices
    std::unordered_map<int, Vertice *> V;
    // Conjunto de arestas
    std::unordered_map<std::pair<int, int>, Aresta *, PairHash> E;

    // Construtor
    Grafo();

    // Método de busca de um vértice
    Vertice * buscar_vertice(int chave);

    // Método de busca de uma aresta
    Aresta * buscar_aresta(int v1, int v2);

    // Método de inserção de um vértice
    void inserir_vertice(int chave);

    // Método de inserção de uma aresta em um grafo direcionado
    Aresta * inserir_aresta_direcionado(int v1, int v2);

    // Método de inserção de uma aresta em um grafo não direcionado
    void inserir_aresta_nao_direcionado(int v1, int v2);

    // Método para remover vértice
    Vertice * remover_vertice(int chave);

    // Método para remover uma aresta em um grafo direcionado
    Aresta * remover_aresta_direcionado(int v1, int v2);

    // Método para remover uma aresta em um grafo não direcionado
    void remover_aresta_nao_direcionado(int v1, int v2);

    // Método para imprimir o grafo 
    void imprimir_grafo();

} Grafo;

#endif