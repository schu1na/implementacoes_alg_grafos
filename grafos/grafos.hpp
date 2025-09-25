#ifndef GRAFOS_HPP
#define GRAFOS_HPP

#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <limits>

// constantes que serão utilizadas no BFS e DFS
#define INFINITO std::numeric_limits<int>::max()
#define BRANCO 0
#define CINZA -1
#define PRETO 1

// estrutura que representará os vértices
typedef struct Vertice{
    int id;
    std::unordered_map<int, struct Vertice *> Adj;   // lista de adjacencias do vértice
    
    // atributos para as Buscas (BFS e DFS)
    int d;
    int f;
    Vertice * pi;
    int cor;

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

    // Método que realiza busca em largura (Breadth-first search) no grafo a partir do vértice s
    void bfs(int s);

    // Método que realiza busca em largura (Breadth-first search) no grafo inteiro
    std::unordered_set<int> bfs();

    // Método que imprime o caminho mínimo entre s e v após a realização de uma busca em largura
    // Note que s necessariamente precisa ser uma raiz na busca em largura, senão a função apresenta
    // saídas incorretas
    void print_path(int s, int v);

    // Método que realiza busca em profundidade (Depth-First Search) no grafo a partir do vértice s
    void dfs(Vertice * s);

    // Método que realiza busca em profundidade (Depth-First Search) no grafo inteiro
    void dfs();

    // Função auxiliar que realiza os passeios ao longo do grafo. Método utilizada no método dfs()
    void dfs_visit(Vertice * u);

    // Função que retorna o grafo predecessor após uma busca em profundidade
    Grafo * grafo_predecessor(std::unordered_set<int> raizes);

} Grafo;

#endif