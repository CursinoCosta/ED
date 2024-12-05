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






TipoCelula::TipoCelula()
{
    item.SetChave(-1);
    prox = NULL;
}


TipoCelulaS::TipoCelulaS()
{
    item.SetChave("-1");
    prox = NULL;
}






PilhaEncadeada::PilhaEncadeada() : Pilha()
{
    topo = NULL;
}

PilhaEncadeada::~PilhaEncadeada()
{
    Limpa();
}

void PilhaEncadeada::Empilha(TipoItem item){
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};

TipoItem PilhaEncadeada::Desempilha(){
    TipoCelula* p;
    TipoItem aux;

    if(tamanho == 0)
        throw "A pilha está vazia!";

    aux = topo->item;
    p = topo;
    topo = topo->prox;
    delete p;
    tamanho--;

    return aux;
};

void PilhaEncadeada::Limpa(){
    while(!Vazia())
        Desempilha();
}





ListaEncadeada::ListaEncadeada() : Lista() {
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada()
{
    Limpa();
    delete primeiro;
}

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes=false){
    TipoCelula *p; int i;

    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";

    // Posiciona na célula anterior a desejada
    p = primeiro;
    for(i=1; i<pos; i++){
        p = p->prox;
    }
    // vai para a próxima 
    // se antes for false
    if(!antes)
        p = p->prox;

    return p;
}

TipoItem ListaEncadeada::GetItem(int pos){
    TipoCelula *p;

    p = Posiciona(pos);
    return p->item;
}

void ListaEncadeada::SetItem(TipoItem item, int pos){
    TipoCelula *p;

    p = Posiciona(pos);
    p->item = item;
}

void ListaEncadeada::InsereInicio(TipoItem item) {
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    tamanho++;

 	if(nova->prox == NULL)
        ultimo = nova;
};

void ListaEncadeada::InsereFinal(TipoItem item) {
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;

};

void ListaEncadeada::InserePosicao(TipoItem item, int pos) {
    TipoCelula *p, *nova;

    p = Posiciona(pos,true); // posiciona na célula anterior

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;

    if(nova->prox == NULL)
        ultimo = nova;
};

TipoItem ListaEncadeada::RemoveInicio() {;
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if(primeiro->prox == NULL)
        ultimo = primeiro;
    aux = p->item;
    delete p;

    return aux;
}

TipoItem ListaEncadeada::RemoveFinal() {
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);

    p->prox = NULL;
    tamanho--;
    aux = ultimo->item;
    delete ultimo;
    ultimo = p;

    return aux;
}

TipoItem ListaEncadeada::RemovePosicao(int pos) {;
    TipoItem aux;
    TipoCelula *p, *q;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if(p->prox == NULL)
        ultimo = p;
    return aux;
}

TipoItem  ListaEncadeada::Pesquisa(TipoChave c) {
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    p = primeiro->prox;
    aux.SetChave(-1);
    while (p!=NULL) {
        if (p->item.GetChave() == c) {
            aux = p->item;
            break;
        }
        p = p->prox;
    }

    return aux;
 };

 void ListaEncadeada::Imprime() {
    TipoCelula *p;

    p = primeiro->prox;
    while (p!=NULL) {
        p->item.Imprime();
        p = p->prox;
    }

    printf("\n");
};

void ListaEncadeada::Limpa() {
    TipoCelula *p;

    p = primeiro->prox;
    while (p!=NULL) {
        primeiro->prox = p->prox;
        p = primeiro->prox;
    }
    delete p;
    ultimo = primeiro;
    tamanho = 0;
};









TipoItemS::TipoItemS()
{
    chave = "-1"; // indica um item vazio
}

TipoItemS::TipoItemS(TipoString c)
{
    chave = c;
}

void TipoItemS::SetChave(TipoString c)
{
    chave = c;
}

std::string TipoItemS::GetChave()
{
    return chave;
}

void TipoItemS::Imprime()
{
    std::cout<<chave;
}



TipoNo::TipoNo()
{
    item.SetChave("-1");
    esq = NULL;
    dir = NULL;
}

TipoItemS TipoNo::GetItem(){
    return item;
}




Arvore::Arvore()
{
    raiz = NULL;
}


Arvore::~Arvore()
{
    Limpa();
}

void Arvore::Limpa(){
    ApagaRecursivo(raiz);
}


void Arvore::Insere(int lado,TipoNo* &p,TipoItemS item){
    if(raiz==NULL){
        raiz = new TipoNo();
        raiz->item = item;
    }
    else if(lado==esquerda) InsereEsquerda(p,item);
    else if(lado==direita) InsereDireita(p,item);
}



void Arvore::CriaArvoreRecursivo(TipoNo* &p, std::string expressao, std::string vars, int profundidade){
    std::string sesq=expressao, sdir=expressao,aux;
    int check=0;
    char c=vars[profundidade];
    if(profundidade==(vars.size()-1))
        check=1;

    if(p==NULL){
        p = new TipoNo();
        p->item.SetChave(expressao);
    }
    for(unsigned int h=0;h<sesq.size();h++){
        char a=sesq[h];
        if(a==c){
            sesq[h]='0';
            break;
        }
    }
    if(check!=1)
     CriaArvoreRecursivo(p->esq, sesq,vars,profundidade+1);
    else{
        Insere(esquerda,p,sesq);
    }
    

    for(unsigned int h=0;h<sdir.size();h++){
        char a=sdir[h];
        if(a==c){
            sdir[h]='1';
            break;
        }
    }
    if(check!=1)
        CriaArvoreRecursivo(p->dir,sdir,vars,profundidade+1);
    else{ 
        Insere(direita,p,sdir);
    }
}



void Arvore::InsereEsquerda(TipoNo* &p,TipoItemS item){
        TipoNo* q;
        q = new TipoNo();
        q->item = item;
        p->esq = q;
}

void Arvore::InsereDireita(TipoNo* &p,TipoItemS item){

        TipoNo* q;
        q = new TipoNo();
        q->item = item;
        p->dir = q;
}

std::string Arvore::toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}


TipoNo* Arvore::CaminhaPos(std::pair<int,int> pos){
    std::string bit="0";
    TipoNo* p;
    int tamanho=1;
    if(pos.first==0){
        return raiz;
    }

    else{
        if(pos.second!=0){
            bit=toBinary(pos.second);
        }
        tamanho=bit.size();
        while(tamanho<pos.first){
            bit="0"+bit;
            tamanho=bit.size();
        }
        p=raiz;

        for(unsigned int a=0;a<bit.size();a++){
            char c=bit[a];
            if(c=='0')
                p=p->esq;
            else if(c=='1')
                p=p->dir;
        }
    }

    return p;
}

void Arvore::ApagaRecursivo(TipoNo* p){
    if(p!=NULL){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}


TipoNo* Arvore::GetFilho(TipoNo* pai,int direcao){
    if(direcao==esquerda)
        return pai->esq;
    else if(direcao==direita)
        return pai->dir;
    else return NULL;
}

