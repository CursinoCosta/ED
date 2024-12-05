#include "../include/listaadjacencia.hpp"

ListaAdjacencia::ListaAdjacencia() : Lista() {
    primeiro = new TipoCelulaAdj();
    ultimo = primeiro;
    primeiro->lista = new ListaEncadeada();
    graumin = graumax = 0;
}

ListaAdjacencia::~ListaAdjacencia()
{
    Limpa();
    delete primeiro->lista;
    delete primeiro;
}

TipoCelulaAdj* ListaAdjacencia::Posiciona(int pos, bool antes=false){
    TipoCelulaAdj *p; int i;

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

TipoItem ListaAdjacencia::GetItem(int pos){
    TipoCelulaAdj *p;

    p = Posiciona(pos);
    return p->item;
}

void ListaAdjacencia::SetItem(TipoItem item, int pos){
    TipoCelulaAdj *p;

    p = Posiciona(pos);
    p->item = item;
}

ListaEncadeada ListaAdjacencia::GetListaItem(int pos){
    TipoCelulaAdj *p;

    p = Posiciona(pos);
    return *p->lista;
}

int ListaAdjacencia::GetGrauMax(){
    return graumax;
}

int ListaAdjacencia::GetGrauMin(){
    return graumin;
}

int ListaAdjacencia::GetTam(){
    return tamanho;
}

void ListaAdjacencia::AtualizaGrauMinimo(){
    TipoCelulaAdj *p;

    p=primeiro;
    while(p!=NULL){
        if(p->lista->GetTamanho()<graumin)
            graumin=p->lista->GetTamanho();
        p=p->prox;
    }
}

void ListaAdjacencia::InsereInicio(TipoItem item) {
    TipoCelulaAdj *nova;

    nova = new TipoCelulaAdj();
    nova->item = item;
    nova->prox = primeiro->prox;
    nova->lista = new ListaEncadeada();
    primeiro->prox = nova;
    tamanho++;
    
 	if(nova->prox == NULL)
        ultimo = nova;
    AtualizaGrauMinimo();
};

void ListaAdjacencia::InsereFinal(TipoItem item) {
    TipoCelulaAdj *nova;

    nova = new TipoCelulaAdj();
    nova->item = item;
    nova->lista = new ListaEncadeada();
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
    AtualizaGrauMinimo();

};

void ListaAdjacencia::InserePosicao(TipoItem item, int pos) {
    TipoCelulaAdj *p, *nova;

    p = Posiciona(pos,true); // posiciona na célula anterior

    nova = new TipoCelulaAdj();
    nova->item = item;
    nova->lista = new ListaEncadeada();
    nova->prox = p->prox;
    p->prox = nova;
    tamanho++;

    if(nova->prox == NULL)
        ultimo = nova;
    AtualizaGrauMinimo();
};

void ListaAdjacencia::InsereInterno(TipoItem item,int pos){
    TipoCelulaAdj *p;

    p = Posiciona(pos);

    p->lista->InsereFinal(item);
    if(p->lista->GetTamanho()>GetGrauMax())
        graumax=p->lista->GetTamanho();
    AtualizaGrauMinimo();

}

TipoItem ListaAdjacencia::RemoveInicio() {
    TipoItem aux;
    TipoCelulaAdj *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    p = primeiro->prox;
    primeiro->prox = p->prox;
    tamanho--;
    if(primeiro->prox == NULL)
        ultimo = primeiro;
    aux = p->item;
    delete p->lista;
    delete p;

    AtualizaGrauMinimo();
    return aux;
}

TipoItem ListaAdjacencia::RemoveFinal() {
    TipoItem aux;
    TipoCelulaAdj *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);

    p->prox = NULL;
    tamanho--;
    aux = ultimo->item;
    delete ultimo->lista;
    delete ultimo;
    ultimo = p;

    AtualizaGrauMinimo();
    return aux;
}

TipoItem ListaAdjacencia::RemovePosicao(int pos) {;
    TipoItem aux;
    TipoCelulaAdj *p, *q;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";

    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q->lista;
    delete q;
    if(p->prox == NULL)
        ultimo = p;

    AtualizaGrauMinimo();
    return aux;
}

TipoItem  ListaAdjacencia::Pesquisa(TipoChave c) {
    TipoItem aux;
    TipoCelulaAdj *p;

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


 void ListaAdjacencia::Imprime() {
    TipoCelulaAdj *p;

    p = primeiro->prox;
    while (p!=NULL) {
       // p->item.Imprime();
       // std::cout<<" ";
        p->lista->Imprime();
        p = p->prox;
    }

    printf("\n");
};

void ListaAdjacencia::Limpa() {
    TipoCelulaAdj *p;

    p = primeiro->prox;
    while (p!=NULL) {
        primeiro->prox = p->prox;
        delete p->lista;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
    graumin = graumax = 0;
};


