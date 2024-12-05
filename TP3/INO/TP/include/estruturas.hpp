#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

#include <string>
#include <iostream>
#include <cstddef>

/*
    Struct que armazena as coordenadas de um ponto
*/
typedef struct{
    long long int x_;
    long long int y_;
} Ponto;


/*
    Classe que armazena o conteudo de uma matriz 2x2 e suas operações
*/
class Matriz{
    public:
        /*
            Inicializa uma matriz como identidade
        */
        Matriz();
        /*
            Destrutor
        */
        ~Matriz(){}

        /*
            Atualiza os valores de uma matriz
        */
        void AtualizaMatriz(long long int  a, long long int b, long long int c, long long int d);
        /* 
            Multiplica a matriz por uma matriz m
        */
        Matriz MultiplicaMatriz(Matriz m);

        /*
            Multiplica o ponto por um ponto P
        */
        Ponto MultiplicaPonto(Ponto p);
    private:
        long long int a_, b_, c_, d_;
        //A matriz tem o seguinte formato
        // a b
        // c d
};


class SegTree{
    public:
        /*
            Inicializa um vetor de tipo Matriz de tamanho 4*size
        */
        SegTree(int size);
        /*
            Destrutor
        */
        ~SegTree();

        /*
            Faz a operação de update na SegTree
        */
        Matriz Update(int pos,Matriz m, int p, int l, int r);
        /*
            Faz a operação de query na SegTree
        */
        Matriz Query(int a, int b, int p, int l, int r);
    private:
        Matriz* Matrizes;

};


#endif