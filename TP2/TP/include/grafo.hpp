// grafo contem um array de listas arranjo em que o indice do array é o indice do vertice e o conteudo da lista sao os vertices vizinhos.
// Alem disso há tambem um array de int em que o indice do array é o indice do vertice respectivo e o conteudo sua coloração
//sera comparado a coloraçao comparando cada vértice (grafo[i] para todo i pertencente ao grafo) com todos os vizinhos da lista buscando todos as cores menores que cor[i]
//isso resolve a parte do grafo de coloraçao gulosa

//o sort da saida deve ser feito ordenando por indice de vertici depois por cor para metodos estaveis e 
// para metodos instaveis é necessario repartir o vetor de vertices em vetores de vertices da mesma cor, depois ordenar esses vetores de coloridos por indice
//armazenar a maior cor ajuda no segundo caso
//isso resolve o tp todo 

#include "estruturas.hpp"

//struct que representa um vertice do grafo, possui suas proprias comparaçoes
struct Vertice{
    int cor;
    int indice;
    ListaArranjo *vizinhos;

    bool operator<(const Vertice &a) const{
        if(cor==a.cor)
            return indice<a.indice;
        else
            return cor<a.cor;
    }

    bool operator<=(const Vertice &a) const{
        if(cor==a.cor)
            return indice<=a.indice;
        else
            return cor<=a.cor;
    }

    bool operator>(const Vertice &a) const{
        if(cor==a.cor)
            return indice>a.indice;
        else
            return cor>a.cor;
    }

    bool operator>=(const Vertice &a) const{
        if(cor==a.cor)
            return indice>=a.indice;
        else
            return cor>=a.cor;
    }

    bool operator==(const Vertice &a) const{
        if(cor==a.cor)
            return indice==a.indice;
        else
            return cor==a.cor;
    }
    bool operator!=(const Vertice &a) const{
        if(cor==a.cor)
            return indice!=a.indice;
        else
            return cor!=a.cor;
    }
    
};



class Grafo{
    public:
        Grafo(int numVertices);
        ~Grafo();

        /*
        Cria um novo vértice para o grafo
        */
        void AdicionaVertice(ListaArranjo *vizinhos);

        /*
        Associa uma cor a um vértice do grafo
        */
        void Colore(int pos, int cor);

        /*
        Compara os vizinhos ao vertice e retorna se a coloracao 
        é gulosa ou nao
        */
        bool CheckGuloso();

        /*
        Retorna o array de vertices contido no grafo
        */
        Vertice* GetGrafo();

        /*
        Imprime todos vertices seus vizinhos e sua cor, usado para debugaçao
        */
        void Imprime();


    private:
        Vertice *Vertices;
        int tamanho;
};