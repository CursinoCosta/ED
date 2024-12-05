#include "../include/estruturas.hpp"
#include "../include/booleana.hpp"
#include <iostream>
#include <ostream>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>



#define avisoAssert(e,m) ((void) ((e)?0: __avisoassert (#e,__FILE__,__LINE__,m)))
#define __avisoassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Aviso: '%s' - %s\n",file,line,e,m),0)
#define erroAssert(e,m) ((void) ((e)?0: __erroassert (#e,__FILE__,__LINE__,m)))
#define __erroassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Erro '%s' - %s\n",file,line,e,m), abort(),0)

#define A 1
#define S 2


static int opescolhida;

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


     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "as")) != EOF){
       switch(c) {
         case 'a':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = A;
                  break;
         case 's':
		  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
	          opescolhida = S;
                  break;
         default:
                  exit(1);

       }
     }
}


int main(int argc, char ** argv){
  // tem que lembrar de dar erro na restiçao de tamanho
  parse_args(argc,argv);

  std::string aux1=argv[2], aux2=argv[3],auxs;
  OpBooleana op;
  
  if(aux1.size() > 10e6 || aux2.size() > 100){
    std::cout<<"tamanho de entrada invalido";
    return 1;
  }

  switch(opescolhida) {
      case A :
          std::cout<<op.ResolveExpressao(aux1,aux2)<<"\n";
          break;


      case S :
        auxs=op.AvaliaSatisf(aux1,aux2);
        if(auxs=="0")
          std::cout<<auxs<<"\n";
        else std::cout<<auxs<<" "<<op.caso<<"\n";
        break;
  }

  return 0;
}