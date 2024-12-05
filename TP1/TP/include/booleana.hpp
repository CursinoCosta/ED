#ifndef BOOLEANA_H
#define BOOLEANA_H


#include "estruturas.hpp"
#include <string>

class OpBooleana {
    public:
        int ResolveExpressao(std::string expressao, std::string variaveis);
        int Comparador(char op1, char op2);
        char Operador(char entr1, char oper, char entr2=0);
        char Resolve(ListaEncadeada* posfix);
        ListaEncadeada* Posfix(std::string expressao);
        std::string PreparaExpressao(std::string expressao, std::string variaveis);
        int ResolveExpressaoPreparada(std::string expressao);

        std::string AvaliaSatisf(std::string expressao, std::string variaveis);
        std::string EncontraVariaveis(std::string expressao);
        Arvore* CriaArvore(std::string expressao,std::string vars);
        std::string ParaTodo(Arvore* a,std::pair<int,int> pos,int posvar,std::string vars);
        std::string Existe(Arvore* a,std::pair<int,int> pos,int posvar,std::string vars);
        PilhaEncadeada* GetVarsOrdem(std::string vars);

        std::string caso;
    private:
        std::string expre;
       
};



#endif