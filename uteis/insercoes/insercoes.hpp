#ifndef INSERCOES_HPP
#define INSERCOES_HPP
#include "grafos.hpp"


// Funçao de inserção de um vértice com id x no grafo g
Grafo * inserir_vertice(Grafo * g, int x);

// Função de inserção de arestas em um grafo direcionado
Vizinho * inserir_aresta_direcionado(Grafo * g, int v1, int v2);

// Função de inserção de arestas em um grafo não direcionado
void inserir_aresta_nao_direcionado(Grafo * g, int v1, int v2);

#endif