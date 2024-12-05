

#include "../include/unionFind.hpp"

UnionFind::UnionFind(int quantidade_subconjuntos){
    subconjuntos = new Subconjunto[quantidade_subconjuntos];
    tamanho=0;
}
UnionFind::~UnionFind(){
    delete subconjuntos;
}

void UnionFind::Make(int x){
    Subconjunto a;
    a.rank=0;
    a.representante=x;
    subconjuntos[x]=a;
    tamanho++;
}

int UnionFind::Find(int x){
    return subconjuntos[x].representante;
}

void UnionFind::Union(int x, int y){
    Subconjunto* pai, *filho;
    if (subconjuntos[x].rank <= subconjuntos[y].rank){
   	 pai = &subconjuntos[Find(x)];
   	 filho = &subconjuntos[Find(y)];
    }else{
   	 pai = &subconjuntos[Find(y)];
   	 filho = &subconjuntos[Find(x)];
    }
    filho->representante = pai->representante;
    if(pai->rank == filho->rank) pai->rank++;
}