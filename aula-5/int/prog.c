#include "avl_int.h"

int main () {
   Arvore_i* AVLi = NULL;
   
   int i;
   for (i = 1; i <= 40; i++) {
      if (i == 9 || i == 17 || i == 23 || i == 24 || i == 25 || i == 26 || i == 27)
         continue;

      AVLi = inserir(AVLi, i);
   }

   imprimir_in_order_2D (AVLi, 0);

   AVLi = remover(AVLi, 1);

   printf("Removendo a chave 1\n");

   imprimir_in_order_2D (AVLi, 0);

   return 0;
}
