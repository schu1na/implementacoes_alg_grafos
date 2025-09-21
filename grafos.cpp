#include <iostream>
#include <limits>

#define INFINITO std::numeric_limits<int>::max()

//Estrutura que representará as arestas do meu grafo através
//de uma lista de adjacências
typedef struct Vizinho {
    int id_vizinho;
    int peso;
    struct Vizinho * prox;

    Vizinho(int id_vizinho) : id_vizinho(id_vizinho){
        prox = NULL;
    }

} Vizinho;

//Estrutura principal que representará um grafo
typedef struct Grafo {
    int id_vertice;
    Vizinho * prox_vizinho;
    struct Grafo * prox_vertice;

    // Construtor inicializando com 1 vértice
    Grafo(int id_vertice) : id_vertice(id_vertice) {
        prox_vizinho = NULL;
        prox_vertice = NULL;
    }

    Grafo(){
        id_vertice = INFINITO;
        prox_vizinho = NULL;
        prox_vertice = NULL;
    }

    // Método de busca de um vértice
    Grafo * buscar_vertice(int x){
        Grafo * g = this;
        while(g != NULL && g->id_vertice != x){ //O(V) porque podemos ter que olhar todos os vértices
            g = g->prox_vertice;
        }
        return g;
    }

    // Método de busca de uma aresta
    Vizinho * buscar_aresta(int v1, int v2){ //Estamos buscando pela aresta v1 -> v2
        Grafo * pv1 = buscar_vertice(v1);   //O(V)
        Grafo * pv2 = buscar_vertice(v2);   //O(V)
        Vizinho * resp = NULL;
        if(pv1 != NULL && pv2 != NULL){
            resp = pv1->prox_vizinho;
            while(resp != NULL && resp->id_vizinho != v2){  //O(deg(v1)) grau do vértice v1
                resp = resp->prox;                          //que no pior dos casos é O(V)
            }
        }
        return resp;
    }

    // Método para imprimir o grafo (INCOMPLETO: falta imprimir arestas)
    void imprimir_grafo(){
        Grafo * g = this;
        while(g != NULL){   //O(V) porque imprimimos todos os vértices
            std::cout << g->id_vertice;

            Vizinho * v = g->prox_vizinho;
            while(v != NULL){   //O(deg(v))
                std::cout << " -> " << v->id_vizinho;
                v = v->prox;
            }
            std::cout << std::endl;
            g = g->prox_vertice;
        }
    }

} Grafo;

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

// FunçÕa de inserção de arestas em um grafo não direcionado
void inserir_aresta_nao_direcionado(Grafo * g, int v1, int v2){
    if(v1 == v2){
        Vizinho * e1 = inserir_aresta_direcionado(g, v1, v2);   //O(V)
        return;
    }
    Vizinho * e1 = inserir_aresta_direcionado(g, v1, v2);   //O(V)
    Vizinho * e2 = inserir_aresta_direcionado(g, v2, v1);   //O(V)
}

int main(){
    Grafo * G = new Grafo();
    G = inserir_vertice(G, 4);
    G = inserir_vertice(G, 23);
    G = inserir_vertice(G, 1);
    G = inserir_vertice(G, 9);
    

    // inserir_aresta_nao_direcionado(G, 4, 23);
    // inserir_aresta_nao_direcionado(G, 4, 1);
    // inserir_aresta_nao_direcionado(G, 1, 9);
    // inserir_aresta_nao_direcionado(G, 1, 1);

    // inserir_aresta_direcionado(G, 4, 23);
    // inserir_aresta_direcionado(G, 4, 1);
    // inserir_aresta_direcionado(G, 1, 9);
    // inserir_aresta_direcionado(G, 1, 1);

    G->imprimir_grafo();
    return 0;
}