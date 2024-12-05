#ifndef TIPO_CELULA_H
#define TIPO_CELULA_H

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


class TipoCelula
{
    public:
        TipoCelula();

    private:
        TipoItem item;
        TipoCelula *prox;

    friend class ListaEncadeada;
    friend class TipoCelulaAdj;
};



#endif