#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <cmath>


#define FIBONACCI_RECURSIVO 1
#define FIBONACCI_ITERATIVO 2
#define FATORIAL_RECURSIVO 3
#define FATORIAL_ITERATIVO 4

enum { NS_PER_SECOND = 1000000000 };

void sub_timespec(struct timespec t1, struct timespec t2, struct timespec *td)
{
  //calcula diferença no tempo de relogio da maquina

    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;
    if (td->tv_sec > 0 && td->tv_nsec < 0)
    {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }
    else if (td->tv_sec < 0 && td->tv_nsec > 0)
    {
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }
}

float sub_rusageU(struct rusage *start, struct rusage *end)
{
  //calcula diferença no tempo de usuario do programa 
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
           1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

float sub_rusageS(struct rusage *start, struct rusage *end)
{
  //calcula diferença no tempo de sistema do programa
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
           1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}


int fatit(int a) {
  if (a == 0) return 1;
  int ans=1;
  for(int i =1;i<=a;i++) ans*=i;
  return ans;
}

int fatrec(int n) {
  for(int i=0;i<10000;i++) std::sin(30);
  if(n > 1)
    return n * fatrec(n - 1);
  else
    return 1;
}

int fibit(int a){
  if(a==0||a==1) return 1;
  int x = 0, y = 1, z = 0;
  for (int i = 0; i < a; i++) {
    z = x + y;
    x = y;
    y = z;
  }
  return z;
}

int fibrec(int a){
  for(int i=0;i<10000;i++) std::sin(30);
  if(a==0||a==1) return 1;
  return fibrec(a-1)+fibrec(a-2);
}

int escolheop(int a, int b){
  switch(a){
    case FIBONACCI_RECURSIVO :
      return fibrec(b);
    case FIBONACCI_ITERATIVO :
      return fibit(b);
    case FATORIAL_RECURSIVO :
      return fatrec(b);
    case FATORIAL_ITERATIVO :
      return fatit(b);
    default: 
      return 0;
  }
}

void exibeop(){
  std::cout<<"Escpçha uma opcao"<<std::endl;
  std::cout<<"1- Fibonacci recursivo"<<std::endl;
  std::cout<<"2- Fibonacci iterativo"<<std::endl;
  std::cout<<"3- Fatorial recursivo"<<std::endl;
  std::cout<<"4- Fatoria iterativo"<<std::endl;
}

void recebeop(){
  int a, b;
  std::cin>>a;
  std::cout<<"De qual número"<<std::endl;
  std::cin>>b;
  if(escolheop(a, b)==0){
    std::cout<< "Opcao invalida, escolha novamente";
    recebeop();
  }
  std::cout<<"O resultado é "<<escolheop(a,b)<<std::endl;
}

void seno(){
  for(int i=0;i<10000;i++) std::sin(30);
}

int main() {
  struct timespec startSis, finishSis, deltaSis;
  struct rusage startUser, finishUser;
  getrusage(RUSAGE_SELF, &startUser);
  clock_gettime(CLOCK_MONOTONIC, &startSis);

    //exibeop();
    //recebeop();
    //escolheop(FIBONACCI_RECURSIVO,1000000000);
    fatrec(17);
    fibrec(50);
    fibit(100);
    fatit(200);
  std::cout<<fatit(30)<<" "<<fibit(30)<<" "<<fibrec(40)<<" "<<fatrec(16)<<std::endl;


  clock_gettime(CLOCK_MONOTONIC, &finishSis);
  getrusage(RUSAGE_SELF, &finishUser);
  sub_timespec(startSis, finishSis, &deltaSis);

  std::cout<<"Diferença no tempo de relogio: "<<deltaSis.tv_sec<<","<<deltaSis.tv_nsec<<" segundos"<<std::endl;
  printf("  Tempo de CPU: %.06f sec usuario e %.09f sec sistema\n",sub_rusageU(&startUser, &finishUser),sub_rusageS(&startUser, &finishUser));
  return 0; 
}