#include "../include/grafo.hpp"



    Grafo::Grafo(int numvertices){
        Vertices = new Vertice[numvertices];
        tamanho=0;
    }
    Grafo::~Grafo(){
        delete []Vertices;
    }


    void Grafo::AdicionaVertice(ListaArranjo *vizinhos){
        Vertices[tamanho].vizinhos=vizinhos;
        Vertices[tamanho].indice=tamanho;
        tamanho++;
    }
    void Grafo::Colore(int pos, int cor){
        Vertices[pos].cor=cor;
    }
    bool Grafo::CheckGuloso(){
        for(int i=0;i<tamanho;i++){
            ListaArranjo coresvizinhas(Vertices[i].vizinhos->GetTamanho());
            for(int a=0;a<Vertices[i].vizinhos->GetTamanho();a++){
                int posviz = Vertices[i].vizinhos->GetItem(a+1).GetChave();
                coresvizinhas.InsereFinal(Vertices[posviz].cor);
            }
            for(int z=1;z<Vertices[i].cor;z++){
                if(coresvizinhas.Pesquisa(z).GetChave()==-1)
                    return 0;
            }      
        }
        return 1;
    }
    Vertice* Grafo::GetGrafo(){
        return Vertices;
    }

    void Grafo::Imprime(){
        for(int i=0;i<tamanho;i++){
            std::cout<<"vertice "<<i<<" vizinhos: ";
            Vertices[i].vizinhos->Imprime();
            std::cout<<"de cor "<<Vertices[i].cor<<"\n";
        }
    }


