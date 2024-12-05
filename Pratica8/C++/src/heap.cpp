#include "../include/heap.hpp"    
#include <iostream>
    
    
    
    
    Heap::Heap(int maxsize){
        data =new Aresta[maxsize];
        tamanho=0;
        for(int i=0;i<maxsize;i++){
            data[i].custo=100000;
        }
    }

    Heap::~Heap(){
        while((tamanho)!=0){
            Remover();
        }
        delete data;
    }
    
    
    void Heap::Inserir(int x, int v1, int v2){
        int i=tamanho;
        int p =(i - 1)/2;

        data[i].u=v1;
        data[i].v=v2;
        data[i].custo=x;

        if(data[i].custo<data[p].custo && p<tamanho && (data[p].custo!=0)){
            HeapifyPorBaixo(i);
        }
        tamanho++;
    }
    Aresta Heap::Remover(){
        int s;
        Aresta out = data[0];
        data[0]=data[tamanho-1];
        tamanho--;
        if(data[1].custo>data[2].custo)
            s=data[2].custo;
        else s=data[1].custo;
        if(data[0].custo>s){
            HeapifyPorCima(0);
        }
        return out;
    }

    bool Heap::Vazio(){
        if (tamanho==0)
            return 1;
        else return 0;
    }
    Aresta Heap::GetAncestral(int posicao){
        return data[(posicao-1)/2];
    }
    Aresta Heap::GetSucessorEsq(int posicao){
        return data[(2 * posicao + 1)];
    }
    Aresta Heap::GetSucessorDir(int posicao){
        return data[(2 * posicao + 2)];
    }

    void Heap::HeapifyPorBaixo(int posicao){
        int i=posicao;
        int p =(i - 1)/2;
        int h =(p - 1)/2;
        Aresta aux;

        aux = data[p];
        data[p]=data[i];
        data[i]=aux;
        
        if(data[p].custo<data[h].custo){
            HeapifyPorBaixo(p);
        }

    }
    void Heap::HeapifyPorCima(int posicao){
        int esq = GetSucessorEsq(posicao).custo;
        int dir = GetSucessorDir(posicao).custo;
        int i=posicao,s,p;
        Aresta aux;

        if(esq<dir){
            s=esq;
            p=2 * posicao + 1;
        }
        else {
            s=dir;
            p=2 * posicao + 2;
        }
        aux=data[i];
        data[i].custo=s;
        data[p]=aux;
        if(data[p].custo<GetSucessorDir(p).custo || data[p].custo<GetSucessorEsq(p).custo)
            HeapifyPorCima(p);

    }