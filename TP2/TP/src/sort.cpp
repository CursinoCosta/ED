#include "../include/sort.hpp"


//Funcao que faz a troca de dois indices do vetor de Vertices
void Sort::Troca(int i1, int i2,Vertice *a){
        Vertice aux;
        aux=a[i1];
        a[i1]=a[i2];
        a[i2]=aux;
    }


void Sort::Bolha (Vertice *v, int n) 
{
	int i, j;

  for(i = 0; i < n-1; i++)
    for(j = 1; j < n-i; j++)
      if (v[j] < v[j-1]) 
        Troca(j-1, j, v);
}


void Sort::Selecao (Vertice *v, int n){ 
  int i, j, Min;

  for (i = 0; i < n - 1; i++){ 
    Min = i;
    for (j = i + 1 ; j < n; j++){
      if (v[j]< v[Min]) 
        Min = j;
    }
    if(Min!=i)
      Troca(i, Min, v);
  }
}


void Sort::Insercao(Vertice *v, int n) {
int i,j;
Vertice aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while (( j >= 0 ) && (aux < v[j])) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
  }

}


void Sort::merge(int e_esq, int e_dir, int med, Vertice* a) {
  Vertice *aux = new Vertice[e_dir-e_esq+1];
  int i = e_esq;
  int j = med;
  int k = 0;
  while (i < med && j < e_dir) {
    if (a[i] <= a[j]) {
      aux[k] = a[i];
      i++;
    } else {
      aux[k] = a[j];
      j++;
    }
    k++;
  }
  while(i < med){
    aux[k] = a[i];
    i++;
    k++;
  }
  while(j < e_dir){
    aux[k] = a[j];
    j++;
    k++;
  }
  for(i = e_esq; i<e_dir;i++)
    a[i] = aux[i-e_esq];
  delete []aux;
}



void Sort::MergeSort(int e,int d, Vertice* a)
{
  if (e < d-1 )
  {
     int meio = (e+d)/2;
     MergeSort(e, meio, a);
     MergeSort(meio, d, a);
     merge(e, d, meio, a);
  }
}



void Sort::Particao(int Esq, int Dir, 
			  int *i, int *j, Vertice *A)
{ 
  Vertice x, w;
  *i = Esq; *j = Dir;
  x = A[(*i + *j)/2]; /* obtem o pivo x */
  do
  { 
    while (x > A[*i]) (*i)++;
    while (x < A[*j]) (*j)--;
    if (*i <= *j)
    { 
		w = A[*i]; A[*i] = A[*j]; A[*j] = w;
      (*i)++; (*j)--;
    }
  } while (*i <= *j);
}


void Sort::Ordena(int Esq, int Dir, Vertice *A)
{ int i, j;
  Particao(Esq, Dir, &i, &j, A);
  if (Esq < j) Ordena(Esq, j, A);
  if (i < Dir) Ordena(i, Dir, A);
}

void Sort::QuickSort(Vertice *A, int n)
{ 
  Ordena(0, n-1, A); 
}



void  Sort::Refaz(int Esq, int Dir, Vertice *A){
  int i, j; 
  Vertice x;
  i = Esq;
  j = i * 2;
  x = A[i];
  while (j <= Dir){
    if (j < Dir)
       if (A[j] < A[j+1]) j++;
    if (x >= A[j]) break;
    A[i] = A[j];
    i = j; 
    j = i *2;
  }
  A[i] = x;
}


void Sort::Constroi(Vertice *A, int n) {
  int Esq;
  
  Esq = n / 2 + 1;
  while (Esq > 0) { 
    Esq--;
    Refaz(Esq, n, A);
  }
}

void Sort::Heapsort(Vertice *A, int n) {
  int Esq, Dir;
  Vertice x;
  Constroi(A, n); /* constroi o heap */
  Esq = 0; Dir = n-1;
  while (Dir > 0){ /* ordena o vetor */
    x = A[0]; 
    A[0] = A[Dir]; 
    A[Dir] = x; 
    Dir--;
    Refaz(Esq, Dir, A);
  }
}


// baseado no gnome sort
void Sort::MySort(Vertice *A, int n){
    int aux = 0; 
  
    while (aux < n) { 
        if (aux == 0) 
            aux++; 
        if (A[aux] >= A[aux - 1]) 
            aux++; 
        else { 
            Troca(aux, aux - 1, A); 
            aux--; 
        } 
    } 
    return; 
}




