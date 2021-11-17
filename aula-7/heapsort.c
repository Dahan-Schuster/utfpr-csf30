#include <stdio.h>

int pai(int i) {
   return (i - 1) / 2;
}

int esquerda(int i) {
   return i * 2 + 1;
}

int direita(int i) {
   return i * 2 + 2;
}

void trocar(int V[], int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir(int V[], int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");
}

void max_heapify(int V[], int size, int i) {
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

void build_max_heap(int V[], int size) {
   int i;
   for (i = size/2 - 1; i >= 0; i--)
      max_heapify(V, size, i);
}

void heap_sort(int V[], int size) {
   build_max_heap(V, size);
   int i;
   for (i = size - 1; i > 0; i--) {
      trocar(V, 0, i);
      max_heapify(V, --size, 0);
   }
}

int main()
{
   int size = 10;

   int V[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
   int B[] = { 5, 13, 2, 25, 7, 17, 20, 8, 4 };

   printf("Vetor inicial : ");
   imprimir(V, size);

   heap_sort(V, size);

   printf("Vetor ordenado: ");
   imprimir(V, size);


   printf("Max Heap B: ");
   build_max_heap(B, 9);
   imprimir(B, 9);

   return 0;
}
