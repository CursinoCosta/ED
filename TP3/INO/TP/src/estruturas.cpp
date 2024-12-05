

#include "../include/estruturas.hpp"
#include <iostream>

Matriz::Matriz(){
    a_=1;
    b_=0;
    c_=0;
    d_=1;
}



void Matriz::AtualizaMatriz(long long int a, long long int b, long long int c, long long int d){
    a_=a;
    b_=b;
    c_=c;
    d_=d;
}

Matriz Matriz::MultiplicaMatriz(Matriz m){
    int mod = 1e8;
    Matriz out;
    out.AtualizaMatriz(((m.a_*a_)%mod +(m.c_*b_)%mod)%mod,
            ((m.b_*a_)%mod+(m.d_*b_)%mod)%mod,
            ((m.a_*c_)%mod+(m.c_*d_)%mod)%mod,
            ((m.b_*c_)%mod+(m.d_*d_)%mod)%mod);
    return out;
}

Ponto Matriz::MultiplicaPonto(Ponto p){
    Ponto out;
    int mod = 1e8;
    out.x_=((a_*p.x_)% mod+(b_*p.y_)% mod) % mod;
    out.y_=((c_*p.x_)% mod+(d_*p.y_)% mod) % mod;
    return out;
}



SegTree::SegTree(int size){
    Matrizes= new Matriz[size];
}

SegTree::~SegTree(){
    delete []Matrizes;
}

Matriz SegTree::Update(int i,Matriz x, int p, int l, int r){
    return Matrizes[p] = x;
}

Matriz SegTree::Query(int a, int b, int p, int l, int r){
    Matriz out;
    for(int i=0;i<r;i++){
        out = out.MultiplicaMatriz(Matrizes[i]);
    }
    return out;
}
