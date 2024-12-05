#ifndef HEAP_HPP
#define HEAP_HPP

#include "unionFind.hpp" 

class Heap{

    public:
        Heap(int maxsize);
        ~Heap();

        void Inserir(int x, int v1, int v2);
        Aresta Remover();

        //Retorna true caso o heap esteja vazio, false caso contrário.
        bool Vazio();

    private:
        Aresta GetAncestral(int posicao);
        Aresta GetSucessorEsq(int posicao);
        Aresta GetSucessorDir(int posicao);

        int tamanho;
        Aresta* data;

        /* Funções necessárias para implementar o Heapify recursivo
         * Você pode apagar elas caso decida implementar o Heapify iterativo
         */
        void HeapifyPorBaixo(int posicao);
        void HeapifyPorCima(int posicao);
};


#endif