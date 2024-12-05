#ifndef MAT_H
#define MAT_H

#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "msgassert.h"

#define MAXTAM 5
// limite superior da inicializacao aleatoria
#define INITRANDOMRANGE 10
// Macro que realiza swap sem variavel auxiliar
#define ELEMSWAP(x,y) (x+=y,y=x-y,x-=y)

typedef struct mat {
  double m[MAXTAM][MAXTAM];
  int tamx, tamy;
  int id;
} mat_tipo;

#endif