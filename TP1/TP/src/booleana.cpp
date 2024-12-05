#include <cstddef>
#define esquerda 0
#define direita 1

#include "../include/estruturas.hpp"
#include "../include/booleana.hpp"
#include <iostream>
#include <string>
#include <math.h>




std::string OpBooleana::PreparaExpressao(std::string expressao, std::string variaveis){
    //Substitui as variaveis numericas (ex: 1, 2, 27, 43) por variaveis binaras ou valoradas (ex: 0, 1, a, e) na expressao
    int auxi=0;
    std::string auxs="", out="";
    char aux=' ';
    char b='0';

    for(unsigned int a=0;a<expressao.size();a++){
        if(a>0) b=expressao[a-1];
        char c=expressao[a];
        char d=expressao[a+1];
        if(c>='0' && c<='9'){
            if(d>='0' && d<='9'){
                auxs=auxs+c;
                auxs=auxs+d;
                auxi=stoi(auxs);
                out=out + variaveis[auxi];
            }
            else if(!(b>='0' && b<='9')){
                auxs=c;
                auxi=stoi(auxs);
                out=out + variaveis[auxi];
            }
        }
        else out=out+c;

        auxs="";

    }
    return out;

}

char OpBooleana::Operador(char entr1, char oper, char entr2){
    //faz as operações lógicas entre valores
    int e1 = entr1-'0';
    int e2 = entr2-'0';
    switch (oper) {
        case '|':
            return ((e1||e2)+'0');
        case '&' :
            return ((e1&&e2)+'0');
        case '~' :
            return ((!e1)+'0');
        default:
            return (e1+'0');
    
    }
}

int OpBooleana::Comparador(char op1, char op2){
    //compara a ordem de prioridade entre deois operadoes, retorna 1 pra op2<=op1 e 0 para op2>op1
        if(op1=='|'){
            return 0;
        }
        if(op1=='&'){
            if(op2=='|')
                return 1;
            else return 0;
        }
        if(op1=='~'){
            if(op2=='~')
                return 0;
            else return 1;
        }
        else return 3;
}

ListaEncadeada* OpBooleana::Posfix(std::string expressao){
    //coloca as variaveis e operadores de uma expressao numa pilha em sua ordem posfixa
    PilhaEncadeada aux;
    ListaEncadeada* out=new ListaEncadeada();
    char aux1;
    int check=0;


    for(unsigned int z=0;z<expressao.size();z++){
        char c = expressao[z];
        if(c==' ') {}

        else if(c=='0' || c=='1')
            out->InsereFinal(c);

        else if(c=='(' || c==')'){
            if(c=='(') aux.Empilha(c);
            if(c==')'){
                aux1=aux.Desempilha().GetChave();
                while(aux1!='('){
                    out->InsereFinal(aux1);
                    aux1=aux.Desempilha().GetChave();
                }
            }
        }

        else if(c=='|' || c=='&' || c=='~'){
            int inserido = 0;
            while(inserido!=1){
                if(c=='~' && expressao[z+2]=='~'){
                    inserido=1;
                    check=1;
                    break;
                }
                else if(c=='~' && check==1){
                    inserido=1;
                    check=0;
                    break;
                }
                else if(aux.Vazia()){
                    aux.Empilha(c);
                    inserido=1;
                    break;
                }
                aux1=aux.Desempilha().GetChave();
                if(aux1=='('){
                    aux.Empilha(aux1);
                    aux.Empilha(c);
                    inserido=1;
                }
                else if(Comparador(c,aux1)==1){
                    aux.Empilha(aux1);
                    aux.Empilha(c);
                    inserido=1;
                }
                else if(Comparador(c,aux1)==0)
                    out->InsereFinal(aux1);
            }
        }
    }
    while(aux.GetTamanho()>0){
        out->InsereFinal(aux.Desempilha());
    }
    return out;
}

char OpBooleana::Resolve(ListaEncadeada* posfix){
    //dada uma lista com uma ordem posfixa retorna o valor resultante da resoluçao da expressao
    PilhaEncadeada aux;
    char aux1=' ', aux2=' ', var1=' ', var2=' ';

    while(posfix->GetTamanho()>0){
        aux1=posfix->RemoveInicio().GetChave();
        if(aux1=='1' || aux1=='0'){
            aux.Empilha(aux1);
           }
        else if(aux1=='|' || aux1=='&'){
            var1=aux.Desempilha().GetChave();
            var2=aux.Desempilha().GetChave();
            aux1=Operador(var1,aux1,var2);
            aux.Empilha(aux1);
        }
        else if(aux1=='~'){
            if(aux.Vazia()){
                aux2=posfix->RemoveInicio().GetChave();
                aux.Empilha(aux2);
            }

            var1=aux.Desempilha().GetChave();
            aux1=Operador(var1,aux1);
            aux.Empilha(aux1);
        }
    }
    delete posfix;
    aux1 = aux.Desempilha().GetChave();
    return aux1;
}



int OpBooleana::ResolveExpressao(std::string expressao, std::string variaveis){
    //chama as funçoes necessarias para resolver uma expressao tendo suas variaveis, resoluçao do problema 1 do tp
    std::string expr = PreparaExpressao(expressao,variaveis);

    ListaEncadeada* l = Posfix(expr);

    char out = Resolve(l);

    if(out=='1') return 1;
    else return 0;
}


int OpBooleana::ResolveExpressaoPreparada(std::string expressao){
    //resolve uma expressao que ja teve suas variaveis substituidas

    ListaEncadeada* l = Posfix(expressao);

    char out = Resolve(l);

    if(out=='1') return 1;
    else return 0;
}

std::string OpBooleana::EncontraVariaveis(std::string expressao){
    //percorre uma expressao e retorna um string de todas suas variaveis (a ou e) em sua ordem de apariçao

    std::string out="";

    for(unsigned int z=0;z<expressao.size();z++){
        char c = expressao[z];
        if(c=='a' || c=='e'){
            out = out + c;
        }
    }

    return out;
}


PilhaEncadeada* OpBooleana::GetVarsOrdem(std::string vars){
    //retorna uma pilha com os as posiçoes das variaveis na string de entrada

    PilhaEncadeada* p=new PilhaEncadeada();

    for(unsigned int z=0;z<vars.size();z++){
        char c = vars[z];
        if(c=='a' || c=='e'){
            p->Empilha(z);
        }
    }
    return p;
}

Arvore* OpBooleana::CriaArvore(std::string expressao,std::string vars){
    //chama a funcao de criaçao de arvore baseada em uma expressao e suas variaveis

    Arvore* a = new Arvore();
    
    a->CriaArvoreRecursivo(a->raiz,expressao,vars);

    return a;

}

std::string OpBooleana::ParaTodo(Arvore* a,std::pair<int,int> pospai,int posvar,std::string vars){
    //resolve uma variavel de para todo comparando os filhos do nó que contem essa variavel

    TipoNo* p;
    std::string fesq,fdir;
    TipoItemS out;

    p=a->CaminhaPos(pospai);
    fesq=a->GetFilho(p,esquerda)->GetItem().GetChave();
    fdir=a->GetFilho(p,direita)->GetItem().GetChave();
    std::pair<int,int> resultados (0,0);

    if(((fesq=="0" || fesq=="1") && (fdir=="0" || fdir=="1"))){
         resultados.first=ResolveExpressaoPreparada(fesq);
         resultados.second=ResolveExpressaoPreparada(fdir);
    }
    else{
        resultados.first=ResolveExpressao(expre,fesq);
        resultados.second=ResolveExpressao(expre,fdir);
    }
    if(resultados.first==1 && resultados.second==1){
        vars[posvar]='a';
        out.SetChave("1");
        p->item=out;
        return vars;
    }
    else{
        out.SetChave("0");
        p->item=out;
        return "-1";
    }

}

std::string OpBooleana::Existe(Arvore* a,std::pair<int,int> pospai,int posvar,std::string vars){
    //resolve uma variavel de existe comparando os filhos do nó que contem essa variavel

    TipoNo* p;
    std::string fesq,fdir;
    TipoItemS out;
    std::pair<int,int> resultados (0,0);

    p=a->CaminhaPos(pospai);
    fesq=a->GetFilho(p,esquerda)->item.GetChave();
    fdir=a->GetFilho(p,direita)->item.GetChave();


    if((fesq=="0" || fesq=="1") && (fdir=="0" || fdir=="1")){
         resultados.first=ResolveExpressaoPreparada(fesq);
         resultados.second=ResolveExpressaoPreparada(fdir);
    }
    else{
        resultados.first=ResolveExpressao(expre,fesq);
        resultados.second=ResolveExpressao(expre,fdir);
    }

    if(resultados.first==1 && resultados.second==1){
        vars[posvar]='a';
        out.SetChave("1");
        p->item=out;
        return vars;
    }
    else if(resultados.first==1 && resultados.second==0){
        vars[posvar]='0';
        out.SetChave("1");
        p->item=out;
        return vars;
    }
    else if(resultados.first==0 && resultados.second==1){
        vars[posvar]='1';
        out.SetChave("1");
        p->item=out;
        return vars;
    }
    else{
        out.SetChave("0");
        p->item=out;
        return "-1";
    }

}

std::string OpBooleana::AvaliaSatisf(std::string expressao, std::string variaveis){
    //funcao que resolve o segundo problema do tp, ela chama o criador de arvore para o conjunto de variaveis binarias e valoradas
    // da expressao depois percorre essa arvore de baixo para cima resolvendo as variaveis valoradas ate chegar de volta a raiz com um resultado
    //enquanto armazena o caso de resultado para a expressao 

    expre=expressao;
    std::string vars = EncontraVariaveis(variaveis);
    std::string auxs;
    int profundidade = vars.size();
    

    Arvore* a;
    a =  CriaArvore(variaveis,vars);
    
    int posvar=0;
    std::string outvars = variaveis;
    PilhaEncadeada* p = GetVarsOrdem(outvars);


    for(int i=profundidade;i>0;i--){
        std::pair<int,int> pos(i-1,0);
        posvar=p->Desempilha().GetChave();
        while((pow(2,(pos.first))>(pos.second))){
            if(outvars[posvar]=='a'){
                auxs = ParaTodo(a,pos,posvar,outvars);
                if(auxs=="-1"){}
                else outvars=auxs;
            }
            else if (outvars[posvar]=='e') {
                auxs = Existe(a,pos,posvar,outvars);
                if(auxs=="-1"){}
                else outvars=auxs;
            }
            pos.second++;
        }

    }


    caso=outvars;
    delete p;
    std::pair<int,int> aux(0,0);
    std::string out=a->CaminhaPos(aux)->GetItem().GetChave();
    delete a;

    return out;
}

