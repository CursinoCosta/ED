#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <string>
#include <iostream>
#include <cstddef>


typedef char TipoChave; // TipoChave é um char
class TipoItem
{
    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();

    private:
        TipoChave chave;
};

class Lista{
    public:
        Lista() {tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};

        virtual TipoItem GetItem(int pos) = 0;
        virtual void SetItem(TipoItem item, int pos) = 0;
        virtual void InsereInicio(TipoItem item) = 0;
        virtual void InsereFinal(TipoItem item) = 0;
        virtual void InserePosicao(TipoItem item, int pos) = 0;
        virtual TipoItem RemoveInicio() = 0;
        virtual TipoItem RemoveFinal() = 0;
        virtual TipoItem RemovePosicao(int pos) = 0;
        virtual TipoItem Pesquisa(TipoChave c) = 0;
        virtual void Imprime() = 0;
        virtual void Limpa() = 0;
    protected:
        int tamanho;
};


typedef std::string TipoString; // TipoString é uma string
class TipoItemS
{
    public:
        TipoItemS();
        TipoItemS(::TipoString c);
        void SetChave(::TipoString c);
        TipoString GetChave();
        void Imprime();

    private:
        ::TipoString chave;
};



class TipoCelula
{
    public:
        TipoCelula();

    private:
        TipoItem item;
        TipoCelula *prox;

    friend class ListaEncadeada;
    friend class PilhaEncadeada;
};



class TipoCelulaS
{
    public:
        TipoCelulaS();

    private:
        TipoItemS item;
        TipoCelulaS *prox;

    friend class ListaEncadeadaS;
    friend class PilhaEncadeada;
};



class Pilha
{
    public:
        Pilha(){tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};

        virtual void Empilha(TipoItem item) = 0;
        virtual TipoItem Desempilha() = 0;
        virtual void Limpa() = 0;

    protected:
        int tamanho;
};


class PilhaEncadeada : public Pilha
{
    public:
        PilhaEncadeada();
        virtual ~PilhaEncadeada();

        void Empilha(TipoItem item);
        TipoItem Desempilha();
        void Limpa();

    private:
        TipoCelula* topo;

};



class ListaEncadeada : public Lista {
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        TipoItem RemovePosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
};






class TipoNo
{
    public:
        TipoNo();
        TipoItemS GetItem();
    private:
        TipoItemS item;
        TipoNo *esq;
        TipoNo *dir;

    friend class Arvore;
    friend class FilaArranjo;
    friend class OpBooleana;
};



class Arvore
{
    public:
        Arvore();
        ~Arvore();

        std::string toBinary(int n);
        void Insere(int lado,TipoNo* &p,TipoItemS item);
        TipoNo* CaminhaPos(std::pair<int,int> pos);
        void Limpa();
        TipoNo* GetFilho(TipoNo* pai,int direcao);
        void CriaArvoreRecursivo(TipoNo* &p, std::string expressao, std::string vars, int profundidade=0);

    private:
        void InsereEsquerda(TipoNo* &p,TipoItemS item);
        void InsereDireita(TipoNo* &p,TipoItemS item);
        void ApagaRecursivo(TipoNo* p);
        
        TipoNo *raiz;

    friend class OpBooleana;
};


#endif