#include <iostream>
#include "grafos.hpp"

int main(){
    Grafo * G = new Grafo();
    G->inserir_vertice(1);
    G->inserir_vertice(2);
    G->inserir_vertice(3);
    G->inserir_vertice(4);
    G->inserir_vertice(1);
    
    G->imprimir_grafo();

    G->inserir_aresta_nao_direcionado(1, 4);
    G->inserir_aresta_nao_direcionado(4, 1);
    G->inserir_aresta_nao_direcionado(1, 2);
    G->inserir_aresta_nao_direcionado(1, 1);

    // G->inserir_aresta_direcionado(1, 4);
    // G->inserir_aresta_direcionado(4, 1);
    // G->inserir_aresta_direcionado(1, 2);
    // G->inserir_aresta_direcionado(1, 2);
    // G->inserir_aresta_direcionado(1, 1);

    G->imprimir_grafo();
    // G->remover_aresta_direcionado(1, 1);
    // G->remover_aresta_nao_direcionado(4, 1);
    G->remover_vertice(4);
    G->imprimir_grafo();

    return 0;
}