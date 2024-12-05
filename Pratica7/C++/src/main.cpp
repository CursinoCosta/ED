#include  "../include/heap.hpp"    
#include <iostream>





int main(){
    int tamanho, no, out;

    std::cin>>tamanho;
    Heap heap(tamanho);
    int aux[tamanho];
    for(int i=0;i<tamanho;i++){
        std::cin>>no;
        aux[i]=no;
    }
    for(int i=0;i<tamanho;i++){
        no=aux[i];
        heap.Inserir(no);
    }
    while(!(heap.Vazio())){
        out=heap.Remover();
        std::cout<<out<<"\n";
    }



    return 0;
}