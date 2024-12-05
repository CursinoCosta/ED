#include "../include/graph.hpp"

Grafo::Grafo(){
    vertices = new ListaAdjacencia(); 
}

Grafo::~Grafo(){

}

void Grafo::InsereVertice(){
    vertices->InsereFinal(vertices->GetTam());
}

void Grafo::InsereAresta(int v, int w){
    vertices->InsereInterno(w,v);
 //   vertices->InsereInterno(v,w);
}

int Grafo::QuantidadeVertices(){
    return vertices->GetTamanho();
}
int Grafo::QuantidadeArestas(){
    int sum=0;
    for(int i=0;i<=vertices->GetTamanho();i++){
        sum+=vertices->GetListaItem(i).GetTamanho();
    }

    return sum/2;
}

int Grafo::GrauMinimo(){
    return vertices->GetGrauMin();
}
int Grafo::GrauMaximo(){
    return vertices->GetGrauMax();
}

void Grafo::ImprimeVizinhos(int v){
    vertices->Imprime();
}