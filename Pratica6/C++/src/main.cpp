#include "../include/graph.hpp"
#include <ostream>
#include <getopt.h>

#include <stdio.h>
#include <stdlib.h>

#define avisoAssert(e,m) ((void) ((e)?0: __avisoassert (#e,__FILE__,__LINE__,m)))
#define __avisoassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Aviso: '%s' - %s\n",file,line,e,m),0)
#define erroAssert(e,m) ((void) ((e)?0: __erroassert (#e,__FILE__,__LINE__,m)))
#define __erroassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Erro '%s' - %s\n",file,line,e,m), abort(),0)

static int opescolhida;
char outnome[100];
int optx, opty;

#define D 1
#define N 2
#define K 3


void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty
{
     // variaveis externas do getopt
     extern char * optarg;
     extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opescolhida = -1;
     optx = -1;
     opty = -1;
     outnome[0] = 0;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "dnk")) != EOF){
       switch(c) {
         case 'd':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = D;
                  break;
         case 'n':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = N;
                  break;
         case 'k':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = K;
                  break;

         default:
                  exit(1);

       }
     }
}

int main(int argc, char **argv){
    int nver, nviz, item;
    parse_args(argc,argv);
    Grafo grafo;
    std::cin>>nver;
    for(int i=0;i<nver;i++){
        grafo.InsereVertice();
    }
    for(int i=0;i<nver;i++){      
        std::cin>>nviz;  
        for(int a=0;a<nviz;a++){
            std::cin>>item;
            grafo.InsereAresta(i,item);
        }
    }


    switch(opescolhida){
        case D:
            std::cout<<grafo.QuantidadeVertices()<<std::endl;
            std::cout<<grafo.QuantidadeArestas()<<std::endl;
            std::cout<<grafo.GrauMinimo()<<std::endl;
            std::cout<<grafo.GrauMaximo()<<std::endl;
            break;

        case N:
            for(int z=0;z<nver;z++){
                grafo.ImprimeVizinhos(z);
            }
            break;

        case K:
            int var= (grafo.QuantidadeArestas()*(grafo.QuantidadeArestas()-1)/2);
            if(grafo.QuantidadeVertices()==var)
                std::cout<<1<<std::endl;
            else std::cout<<0<<std::endl;
            break;


    }

    return 0;
}