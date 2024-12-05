#include <stdio.h>
#include <stdlib.h>

int actual_calc(int a, int b){
  return a/b;
}

int calc(){
  int a;
  int b;
  a=14;
  b=2;
  return actual_calc(a, b);}

int main(){
  printf("%d \n",calc());
  return 0;
}
