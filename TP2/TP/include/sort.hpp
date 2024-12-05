#ifndef SORT_H
#define SORT_H

#include "grafo.hpp"


class Sort{
    public:    
        void Troca(int i1, int i2,Vertice *a);
        void Bolha (Vertice *v, int n);
        void Selecao (Vertice *v, int n);
        void Insercao(Vertice *v, int n);
        void merge(int e_esq, int e_dir, int med, Vertice* a); 
        void MergeSort(int e,int d, Vertice* a);
        void Particao(int Esq, int Dir, int *i, int *j, Vertice *A);
        void Ordena(int Esq, int Dir, Vertice *A);
        void QuickSort(Vertice *A, int n);
        void  Refaz(int Esq, int Dir, Vertice *A);
        void Constroi(Vertice *A, int n);
        void Heapsort(Vertice *A, int n); 
        void MySort(Vertice *A, int n);
    private:
};

#endif