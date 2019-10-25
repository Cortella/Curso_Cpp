//Respresentacao - Lista de Adjacencia
#include <iostream>
#include <list>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Grafo{
    int v_;
    list<int> *adj; //ponteiro para um aray contendo listas de adjacencia

    public:
    //Construtor
    Grafo(int v);

    //Adiciona arestas no grafo
    void addAresta(int v1,int v2);

    //Obtem o grau de saida de um dado vertice
    //grau de saida e o numero de arcos que saem de "v"
    int obterGrauDeSaida(int v);

    //verifica se v2 e vizinho de v1
    bool existeVizinho(int v1,int v2);

    Grafo::Grafo(int v){
        this->v_ = v;
        adj = new list<int>[v]; //cria as listas
    }

    void Grafo::addAresta(int v1,int v2){
        adj[v1].push_back(v2);
    }

    int Grafo::obterGrauDeSaida(int v){
        return adj[v].size();
    }

    bool Grafo::existeVizinho(int v1,int v2){
        if(find(adj[v1].begin() , adj[v1].end(),v2) != adj[v1].end())
        return true;
    return false;
    }

    int main(){
        //Criando grafo de 4 vertices
        Grafo grafo(4);
        //Add arestas
        grafo.addAresta(0,1);
        grafo.addAresta(0,3);
        grafo.addAresta(1,2);
        grafo.addAresta(3,1);
        grafo.addAresta(1,2);

        //mostra grau de saida
        cout<< "Grau de saida do vertice 1" << grafo.obterGrauDeSaida(1)<<endl;
         cout<< "Grau de saida do vertice 3" << grafo.obterGrauDeSaida(3) <<endl;

         //existe vizinhos?
         if(grafo.existeVizinho(0,1)){
             cout << "E vizinho";{
                 cout<<"nao e vizinho";
             }
         }

        system("pause");
        return 0;
    }
};