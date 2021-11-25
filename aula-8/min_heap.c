#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "util.c"

void min_heapify (int V[], int size, int i) {
   int esq = esquerda(i);
   int dir = direita(i);
   int menor = i;

   if (esq < size && V[esq] < V[i])
      menor = esq;

   if (dir < size && V[dir] < V[menor])
      menor = dir;

   if (menor != i) {
      trocar(V, menor, i);
      min_heapify(V, size, menor);
   }
}

void build_min_heap (int V[], int size) {
   int i;
   for (i = size/2 - 1; i >= 0; i--)
      min_heapify(V, size, i);
}

int heap_extract_min (int V[], int *size) {
   if (*size < 1) {
      printf("erro: heap underflow");
      return -1;
   }

   int min = V[0];
   V[0] = V[*size - 1];
   (*size)--;
   min_heapify(V, *size, 0);
   return min;
}

int heap_extract_min_realloc(int *V, int *size) {
   if (*size < 1) {
      printf("erro: heap underflow");
      return -1;
   }

   int min = V[0];
   V[0] = V[*size - 1];
   (*size)--;

   int *pAux = (int*) realloc(V, (*size) * sizeof(int));
   if (pAux != NULL) {
      V = pAux;
   } else {
      printf("erro: não foi possível realocar o vetor");
      V[0] = min;
      (*size)++;
      return -1;
   }

   min_heapify(V, *size, 0);
   return min;
}

void heap_decrease_key (int V[], int i, int chave, int size) {
   if (V[i] < chave) {
      printf("erro: chave maior que atual");
      return;
   }

   V[i] = chave;
   while (i > 0 && V[pai(i)] > V[i]) {
      trocar(V, pai(i), i);
      i = pai(i);
   }
}

void heap_increase_key (int V[], int i, int chave, int size) {
   if (V[i] > chave) {
      printf("erro: chave menor que atual");
      return;
   }

   V[i] = chave;
   while (i > 0 && V[pai(i)] > V[i]) {
      trocar(V, pai(i), i);
      i = pai(i);
   }
}

void min_heap_insert (int V[], int chave, int *size) {
   (*size)++;
   V[*size - 1] = INT_MIN;
   heap_increase_key(V, *size - 1, chave, *size);
}

void min_heap_insert_realloc (int *V, int chave, int *size) {
   (*size)++;
   
   int *pAux = (int*) realloc(V, (*size) * sizeof(int));
   if (pAux != NULL) {
      V = pAux;
   } else {
      printf("erro: não foi possível realocar o vetor");
      (*size)++;
      return;
   }
   
   V[*size - 1] = INT_MIN;
   heap_increase_key(V, *size - 1, chave, *size);
}

int main () {

   int size = 10;

   int v[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

   imprimir (v, size);

   build_min_heap (v, size);
   
   imprimir (v, size);
   
   int min = heap_extract_min (v, &size);
   
   imprimir (v, size);
   
   /*Modificando a última chave {16} para o valor {1}!*/
   heap_decrease_key (v, size-1, 1, size);
   
   imprimir (v, size);

   /*Inserindo uma nova chave com valor {0}!*/ 
   min_heap_insert (v, 0, &size);
   
   imprimir (v, size);
   
   return 0;
}


