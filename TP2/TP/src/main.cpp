#include "../include/estruturas.hpp"
#include "../include/sort.hpp"
#include <iostream>
#include <ostream>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>


void ImprimeA(Vertice* a, int nver){
        for(int i=0;i<nver;i++){
            std::cout<<a[i].indice<<" ";
        }
        std::cout<<std::endl;
    }


int main(){
  char opescolhida;
  int nver;
  std::cin>>opescolhida>>nver;
  Grafo *g= new Grafo(nver);
  int nviz=0;
  

  for(int i=0;i<nver;i++){
    std::cin>>nviz;
    std::cin.ignore();
    ListaArranjo *viz= new ListaArranjo(nviz);
    for(int a=0;a<nviz;a++){
      int aux;
      std::cin>>aux;
      std::cin.ignore();
      viz->InsereFinal(aux);
    }
    g->AdicionaVertice(viz);
  }
  int cor;
  for(int i=0;i<nver;i++){
    std::cin>>cor;
    g->Colore(i,cor);
  }



  if(g->CheckGuloso()==0)
    std::cout<<"0\n";
  else {
    Sort s;
    Vertice* aux = g->GetGrafo();
    std::cout<<"1 ";
    switch(opescolhida) {
        case 'b' :
          s.Bolha(aux,nver);
          ImprimeA(aux, nver);
          break;

        case 's' :
          s.Selecao(aux, nver);
          ImprimeA(aux, nver);
          break;
        
        case 'i' :
          s.Insercao(aux, nver);
          ImprimeA(aux, nver);
          break;
        
        case 'q' :
          s.QuickSort(aux, nver);
          ImprimeA(aux, nver);
          break;

        case 'm' :
          s.MergeSort(0, nver, aux);
          ImprimeA(aux, nver);
          break;
        
        case 'p' :
          s.Heapsort(aux, nver);
          ImprimeA(aux, nver);
          break;
        
        case 'y' :
          s.MySort(aux, nver);
          ImprimeA(aux, nver);
          break;

    }
  }
  
  delete g;

  return 0;
}