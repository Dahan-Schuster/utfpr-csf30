#include <stdio.h>
#include <stdlib.h>
#include "util.c"

void max_heapify (int V[], int size, int i) {
   int esq = esquerda(i);
   int dir = direita(i);
   int maior = i;

   if (esq < size && V[esq] > V[i])
      maior = esq;

   if (dir < size && V[dir] > V[maior])
      maior = dir;

   if (maior != i) {
      trocar(V, maior, i);
      max_heapify(V, size, maior);
   }
}

void heap_decrease_key (int v[], int i, int chave, int size) {
   if (v[i] < chave) {
      printf("erro: chave maior que atual");
      return;
   }

   v[i] = chave;
   max_heapify(v, size, i);
}

int main () {

   int size = 12;

   int v[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

   imprimir (v, size);

   /*Modificando a chave da posição 0 para o valor 1!*/   
   heap_decrease_key (v, 0, 1, size);
   
   printf ("After decrease-key: \n");
   imprimir (v, size);

   return 0;
}
