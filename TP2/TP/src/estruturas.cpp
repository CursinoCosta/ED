#include <cerrno>
#include <cstddef>
#include <math.h>
#include <stdio.h>
#define esquerda 0
#define direita 1


#include "../include/estruturas.hpp"
#include <iostream>

TipoItem::TipoItem()
{
    chave = -1; // indica um item vazio
}

TipoItem::TipoItem(TipoChave c)
{
    chave = c;
}

void TipoItem::SetChave(TipoChave c)
{
    chave = c;
}

TipoChave TipoItem::GetChave()
{
    return chave;
}

void TipoItem::Imprime()
{
    std::cout<<chave;
}


ListaArranjo::ListaArranjo(int maxtam):Lista(){ 
     MAXTAM=maxtam;
     itens = new TipoItem[maxtam];
}

ListaArranjo::ListaArranjo():Lista(){ 
     MAXTAM=100;
     itens = new TipoItem[100];
}

ListaArranjo::~ListaArranjo(){
    delete []itens;
}


TipoItem ListaArranjo::GetItem(int pos){
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";

    return itens[pos-1];
}

void ListaArranjo::SetItem(TipoItem item, int pos){
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";

   itens[pos-1] = item;
}

void ListaArranjo::InsereInicio(TipoItem item) {
    int i;
    if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";

    tamanho++;
    for(i=tamanho-1;i>0;i--)
        itens[i] = itens[i-1];

    itens[0] = item;
};

void ListaArranjo::InsereFinal(TipoItem item) {
    if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";

    itens[tamanho] = item;
    tamanho++;
};

void ListaArranjo::InserePosicao(TipoItem item, int pos) {
    int i;
	if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";

    pos--; // posição no vetor = pos-1 (vetor começa em 0)
    for(i=tamanho;i>pos;i--)
        itens[i] = itens[i-1];

    itens[pos] = item;
    tamanho++;
};

TipoItem ListaArranjo::RemoveInicio() {
    int i;
    TipoItem aux;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    aux = itens[0];
    for(i=0;i<tamanho;i++)
        itens[i] = itens[i+1];

    tamanho--;
    return aux;
}

TipoItem ListaArranjo::RemoveFinal() {
    TipoItem aux;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    tamanho--;
    aux = itens[tamanho];
    return aux;
}

TipoItem ListaArranjo::RemovePosicao(int pos) {
    int i; TipoItem aux;
   
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";

    pos--;  // posição no vetor = pos-1 (vetor começa em 0)
    aux = itens[pos];
    for(i=pos;i<tamanho;i++)
        itens[i] = itens[i+1];
    tamanho--;
    return aux;
}

TipoItem  ListaArranjo::Pesquisa(TipoChave c) {
    int i; TipoItem aux;


	aux.SetChave(-1); // indica pesquisa sem sucesso
    for(i=0;i<tamanho;i++)
        if(itens[i].GetChave() == c) {
            aux = itens[i];
            break;
        }

    return aux;
 };

void ListaArranjo::Imprime() {
    int i=0;
    for(i=0;i<tamanho;i++){
        itens[i].Imprime();
        std::cout<<" ";
        }

    printf("\n");
};

void ListaArranjo::Limpa() {
    tamanho = 0;
};


