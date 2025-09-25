#include "grafos.hpp"
#include <queue>
#include <unordered_set>
#include <iostream>

int time = 0;

// Método que realiza busca em largura (Breadth-first search) no grafo a partir do vértice s
void Grafo::bfs(int s){
    // Verificamos se o vértice de id igual a s está presente no grafo
    Vertice * ps = buscar_vertice(s);
    if(ps == nullptr){
        std::cout << "Vértice " << s << " nao encontrado no grafo." << std::endl;
        return; 
    }
    // Inicializamos o grafo do zero
    for(auto v : V){            //O(V)
        v.second->d = INFINITO;
        v.second->pi = nullptr;
        v.second->cor = BRANCO;
    }
    // Inicializamos o vértice s
    ps->d = 0;
    ps->cor = CINZA;

    // Inicializamos a fila 
    std::queue<Vertice *> Q;
    Q.push(ps);

    while(!Q.empty()){          //O(V+E)
        Vertice * u = Q.front();
        Q.pop();
        for(auto v : u->Adj){
            if(v.second->cor == BRANCO){
                v.second->d = u->d + 1;
                v.second->cor = CINZA;
                v.second->pi = u;
                Q.push(v.second);
            }
        }
        u->cor = PRETO;
    }
};

// Método que realiza a busca em largura em todo o grafo
std::unordered_set<int> Grafo::bfs(){
    // Inicializamos o grafo do zero
    for(auto v : V){            //O(V)
        v.second->d = INFINITO;
        v.second->pi = nullptr;
        v.second->cor = BRANCO;
    }

    // Conjunto das raizes
    std::unordered_set<int> raizes;

    // Inicializamos a fila 
    std::queue<Vertice *> Q;

    // Faremos a busca em largura para todas as componentes, ou seja, 
    // para todo vértice branco 
    for(auto u : V){
        if(u.second->cor == BRANCO){
            // Adicionamos a lista de raízes
            raizes.emplace(u.second->id);

            u.second->d = 0;
            u.second->cor = CINZA;
            // Enfileiramos u
            Q.push(u.second);

            while(!Q.empty()){
                Vertice * v = Q.front();
                Q.pop();
                for(auto s : v->Adj){
                    if(s.second->cor == BRANCO){
                        s.second->d = v->d + 1;
                        s.second->cor = CINZA;
                        s.second->pi = v;
                        Q.push(s.second);
                    }
                }
                v->cor = PRETO;
            }
        }
        
    }
    return raizes;
}

// Método que obtém o grafo predecessor após uma busca em largura. Recebe
// a(s) raiz(es) da busca realizada
Grafo * Grafo::grafo_predecessor(std::unordered_set<int> raizes){
    // Verificamos se existe o vértice de id igual a s no grafo
    for(int r : raizes){
        Vertice * pr = buscar_vertice(r);
        if(pr == nullptr){
            return nullptr;
        }
    }
    // Criamos o grafo predecessor se existir o vértice s
    Grafo * Gp = new Grafo();

    // Construindo o conjunto Vpi
    for(auto v : V){
        // Vpi é o conjunto dos vértices de V que tem v.pi != nullptr
        // união a "raiz" s.
        if(v.second->pi != nullptr || raizes.find(v.second->id) != raizes.end()){
            Gp->inserir_vertice(v.second->id);          
        }
    }

    // Construindo o conjunto Epi
    for(auto v : V){
        if(v.second->pi != nullptr){
            Gp->inserir_aresta_direcionado(v.second->pi->id, v.second->id);
        }
    }
    return Gp;
}

// Método que imprime o caminho mínimo entre s e v após a realização de uma busca
// em largura com origem em s. 
void Grafo::print_path(int s, int v){
    Vertice * pts = buscar_vertice(s);
    Vertice * ptv = buscar_vertice(v);
    
    if(pts == nullptr || ptv == nullptr){
        std::cout << "Um dos dois vertices nao pertence ao grafo" << std::endl;
        return;
    } 
    if(ptv->id == pts->id){
        std::cout << pts->id;
    }
    else if(ptv->pi == nullptr){
        std::cout << "Nao existe caminho\n";
    }
    else{
        print_path(s, ptv->pi->id);
        std::cout << " -> " << ptv->id; 
    }
};

// Método que realiza busca em profundidade (Depth-First Search) no grafo a partir do vértice s
// void Grafo::dfs(Vertice * s){

// }

// Função auxiliar que realiza os passeios ao longo do grafo. Método utilizada
// no método dfs()
// void Grafo::dfs_visit(Vertice * u){
//     time++;
//     // Definimos o tempo de chegada e marcamos u de CINZA
//     u->d = time;
//     u->cor = CINZA;
//     // VIsitamos cada vértice BRANCO nas adjacencias de u
//     for(auto v : u->Adj){
//         if(v.second->cor == BRANCO){
//             v.second->pi = u;
//             // Fazemos uso da recursão para empilhar os vértices
//             dfs_visit(v.second);
//         }
//     }
//     time++;
//     // Definimos o tempo de saída após olhar todos os vértices
//     // da adjacencia de u e pintamos u de PRETO
//     u->f = time;
//     u->cor = PRETO;
// }

// Método que realiza busca em profundidade (Depth-First Search) no grafo inteiro
// void Grafo::dfs(){
//     // Inicializamos o grafo com os pais nulos e cores brancas
//     for(auto v : V){
//         v.second->cor = BRANCO;
//         v.second->pi = nullptr;
//     }
//     // Zeramos o tempo
//     time = 0;
//     // Aplicamos o DFS para todo vértice u pertencente a V
//     // que seja branco.
//     for(auto u : V){
//         if(u.second->cor == BRANCO){
//             dfs_visit(u.second);
//         }
//     }
// };

