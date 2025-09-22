#include <iostream>
#include "grafos.hpp"

// Construtor de Vertice
Vertice::Vertice(int id) : id(id){}

// Construtor de Aresta
Aresta::Aresta(Vertice * v1, Vertice * v2) : v1(v1), v2(v2){}

// Construtor de Grafo 
Grafo::Grafo(){}

// Método de busca de um vértice
Vertice * Grafo::buscar_vertice(int x){
    auto loc = V.find(x); //O(1)
    if(loc != V.end()){   // Verifica se encontrou o vértice
        return loc->second;
    }
    return nullptr;
}

std::size_t PairHash::operator()(const std::pair<int,int>& p) const{
    return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
}

// Método de busca de uma aresta
Aresta * Grafo::buscar_aresta(int v1, int v2){ //Estamos buscando pela aresta v1 -> v2
    Vertice * pv1 = buscar_vertice(v1);   //O(1)
    Vertice * pv2 = buscar_vertice(v2);   //O(1)

    Aresta * resp = nullptr;
    // apenas procuramos a aresta se ambos os vértices existirem
    if(pv1 != nullptr && pv2 != nullptr){  
        auto loc = E.find({v1,v2}); // utilizamos o hash da chave dupla para encontrar a aresta
        if(loc != E.end()){
            resp = loc->second;
            return resp;
        }
    }
    return resp;
}

// Método para imprimir o grafo 
void Grafo::imprimir_grafo(){
    for(auto v : V){
        std::cout << v.second->id; 
        for(auto u : v.second->Adj){
            std::cout << "->" << u.second->id;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}