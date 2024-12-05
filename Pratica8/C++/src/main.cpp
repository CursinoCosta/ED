
#include <iostream>
#include "../include/heap.hpp"

int main(){
    int n, m;
    std::cin>>n>>m;
    UnionFind uf(n);
    Heap h(m);
    for(int i=0;i<n;i++){
        uf.Make(i);
    }
    for(int a=0;a<m;a++){
        int u,v,c;
        std::cin>>u>>v>>c;
        h.Inserir(c,u,v);
    }
    int conex=0,sum=0;
    Aresta aux;
    while(conex<n-1){
        aux=h.Remover();
        if(uf.Find(aux.u) != uf.Find(aux.v)){
            uf.Union(aux.u,aux.v);
            conex++;
            sum+=aux.custo;
        }
    }
    std::cout<<sum<<"\n";
    return 0;
}