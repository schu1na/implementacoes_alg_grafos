#include <iostream>
#include "grafos/grafos.hpp"
#include "uteis/insercoes/insercoes.hpp"
// #include "uteis/remocoes/remocoes.hpp"

int main(){
    Grafo * G = new Grafo();
    G = inserir_vertice(G, 4);
    G = inserir_vertice(G, 23);
    G = inserir_vertice(G, 1);
    G = inserir_vertice(G, 9);

    inserir_aresta_nao_direcionado(G, 4, 23);
    inserir_aresta_nao_direcionado(G, 4, 1);
    inserir_aresta_nao_direcionado(G, 1, 9);
    inserir_aresta_nao_direcionado(G, 1, 1);

    inserir_aresta_direcionado(G, 4, 23);
    inserir_aresta_direcionado(G, 4, 1);
    inserir_aresta_direcionado(G, 1, 9);
    inserir_aresta_direcionado(G, 1, 1);

    G->imprimir_grafo();
    return 0;
}