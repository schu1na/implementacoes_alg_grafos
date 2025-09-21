#ifndef REMOCOES_HPP
#define REMOCOES_HPP
#include "grafos.hpp"

// Função de remoção de arestas em um grafo direcionado
Vizinho * remover_aresta_direcionado(Grafo * g, int v1, int v2);

// Função de remoção de arestas em um grafo não direcionado
void remover_aresta_nao_direcionado(Grafo * g, int v1, int v2);

// Funçao de remoção de um vértice com id x no grafo g
Grafo * remover_vertice(Grafo * g, int x);

#endif