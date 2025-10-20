#include <iostream>
#include "grafos.hpp"

int main(){
    Grafo * G = new Grafo();
    // Criando vértices do grafo de teste
    G->inserir_vertice(1);
    G->inserir_vertice(2);
    G->inserir_vertice(3);
    G->inserir_vertice(4);
    G->inserir_vertice(5);
    G->inserir_vertice(6);
    G->inserir_vertice(7);
    G->inserir_vertice(8);
    G->inserir_vertice(9);
    G->inserir_vertice(10);
    G->inserir_vertice(11);

    // Inserindo as arestas
    G->inserir_aresta_nao_direcionado(1, 2);
    G->inserir_aresta_nao_direcionado(1, 4);
    G->inserir_aresta_nao_direcionado(2, 3);
    G->inserir_aresta_nao_direcionado(2, 4);
    G->inserir_aresta_nao_direcionado(2, 5);
    G->inserir_aresta_nao_direcionado(4, 6);
    G->inserir_aresta_nao_direcionado(5, 6);
    G->inserir_aresta_nao_direcionado(7, 8);
    G->inserir_aresta_nao_direcionado(7, 9);
    G->inserir_aresta_nao_direcionado(8, 9);
    G->inserir_aresta_nao_direcionado(10, 11);

    G->imprimir_grafo();
    
    return 0;
}