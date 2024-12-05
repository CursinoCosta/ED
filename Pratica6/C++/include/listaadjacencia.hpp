#ifndef LISTA_ADJ_H
#define LISTA_ADJ_H

#include "listaencad.hpp"
#include "tipocelula.hpp"

class ListaAdjacencia: public Lista{
    public:
        ListaAdjacencia();
        ~ListaAdjacencia();

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

        void InsereInterno(TipoItem item, int pos);
        ListaEncadeada GetListaItem(int pos);
        int GetTam();
        int GetGrauMax();
        int GetGrauMin();
        void AtualizaGrauMinimo();

    private:
        int graumax;
        int graumin;
        TipoCelulaAdj* primeiro;
        TipoCelulaAdj* ultimo;
        TipoCelulaAdj* Posiciona(int pos, bool antes);

};

#endif