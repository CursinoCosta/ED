#include "../include/heap.hpp"    
    
    
    
    
    Heap::Heap(int maxsize){
        int array[maxsize];
        tamanho=0;
        data = array;
        for(int i=0;i<maxsize;i++){
            *(data+i)=0;
        }
    }

    Heap::~Heap(){
        while(tamanho!=0){
            Remover();
        }
    }
    
    
    void Heap::Inserir(int x){
        int i=tamanho;
        int p =(i - 1)/2;

        *(data+i)=x;

        if(*(data+i)<*(data+p)){
            HeapifyPorBaixo(i);
        }
        tamanho++;
    }
    int Heap::Remover(){
        int s;
        int out = *data;
        *data=*(data+tamanho);
        tamanho--;
        if(*(data+1)>*(data+2))
            s=*(data+2);
        else s=*(data+1);
        if(*(data)>s){
            HeapifyPorCima(0);
        }
        return out;
    }

    bool Heap::Vazio(){
        if (tamanho==0)
            return 1;
        else return 0;
    }
    int Heap::GetAncestral(int posicao){
        return *(data+((posicao-1)/2));
    }
    int Heap::GetSucessorEsq(int posicao){
        return *(data+(2 * posicao + 1));
    }
    int Heap::GetSucessorDir(int posicao){
        return *(data+(2 * posicao + 2));
    }

    void Heap::HeapifyPorBaixo(int posicao){
        int i=posicao;
        int p =(i - 1)/2;
        int h =(p - 1)/2;
        int aux;

        aux = *(data+p);
        *(data+p)=*(data+i);
        *(data+i)=aux;
        
        if(*(data+p)<*(data+h)){
            HeapifyPorBaixo(p);
        }

    }
    void Heap::HeapifyPorCima(int posicao){
        int esq = GetSucessorEsq(posicao);
        int dir = GetSucessorDir(posicao);
        int i=posicao,s,p,aux;

        if(esq<dir){
            s=esq;
            p=2 * posicao + 1;
        }
        else {
            s=dir;
            p=2 * posicao + 2;
        }
        aux=*(data+i);
        *(data+i)=s;
        *(data+p)=aux;
        if(*(data+p)<GetSucessorDir(p) || *(data+p)<GetSucessorEsq(p))
            HeapifyPorCima(p);

    }