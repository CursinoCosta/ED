#ifndef LISTA_ENCAD_H
#define LISTA_ENCAD_H


#include <iostream>
#include "lista.hpp"
#include "tipocelula.hpp"





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

class TipoCelulaAdj : public TipoCelula
{
    public:
        TipoCelulaAdj();

    private:
        TipoItem item;
        TipoCelulaAdj *prox;
        ListaEncadeada *lista;

    friend class ListaAdjacencia;
};



#endif