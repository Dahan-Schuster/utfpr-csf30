#include "avl_int.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior(int esq, int dir) {
   return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura(Arvore_i* a) {
   return (a == NULL ? -1 : a->altura);
}

int atualizar_altura(Arvore_i* a) {
   return (maior(altura(a->esq), altura(a->dir)) + 1);
}

/*----------------------*/
int balanceamento(Arvore_i* a) {
   return (altura(a->dir) - altura(a->esq));
}

/*----------------------*/
Arvore_i* rotacao_simples_esq(Arvore_i* a) {
   No_i* filho = a->dir;
   a->dir = filho->esq;
   filho->esq = a;
   a->altura = atualizar_altura(a);
   filho->altura = atualizar_altura(filho);
   return filho;
}

/*----------------------*/
Arvore_i* rotacao_simples_dir(Arvore_i* a) {
   No_i* filho = a->esq;
   a->esq = filho->dir;
   filho->dir = a;
   a->altura = atualizar_altura(a);
   filho->altura = atualizar_altura(filho);
   return filho;
}

/*----------------------*/
Arvore_i* rotacao_dupla_esq(Arvore_i* a) {
   a->dir = rotacao_simples_dir(a->dir);
   return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore_i* rotacao_dupla_dir(Arvore_i* a) {
   a->esq = rotacao_simples_esq(a->esq);
   return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore_i* atualizar_fb_dir(Arvore_i* a) {
   a->altura = atualizar_altura(a);
   if (balanceamento(a) == 2) {
      if (balanceamento(a->dir) >= 0) {
         a = rotacao_simples_esq(a);
      }
      else {
         a = rotacao_dupla_esq(a);
      }
   }
   return a;
}

/*----------------------*/
Arvore_i* atualizar_fb_esq(Arvore_i* a) {
   a->altura = atualizar_altura(a);
   if (balanceamento(a) == -2) {
      if (balanceamento(a->esq) <= 0) {
         a = rotacao_simples_dir(a);
      }
      else {
         a = rotacao_dupla_dir(a);
      }
   }
   return a;
}

/*----------------------*/
Arvore_i* inserir(Arvore_i* a, int chave) {
   if (a == NULL) {
      a = (No_i*)malloc(sizeof(No_i));
      a->chave = chave;
      a->altura = 0;
      a->esq = a->dir = NULL;
   }
   else if (chave < a->chave) {
      a->esq = inserir(a->esq, chave);
      a = atualizar_fb_esq(a);
   }
   else {
      a->dir = inserir(a->dir, chave);
      a = atualizar_fb_dir(a);
   }
   return a;
}

/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore_i* remover(Arvore_i* a, int chave) {
   if (a == NULL) {
      return NULL;
   }
   else {
      if (chave < a->chave) {
         a->esq = remover(a->esq, chave);
         a = atualizar_fb_dir(a);
      }
      else if (chave > a->chave) {
         a->dir = remover(a->dir, chave);
         a = atualizar_fb_esq(a);
      }
      else {
         if ((a->esq == NULL) && (a->dir == NULL)) {
            free(a);
            a = NULL;
         }
         else if (a->esq == NULL) {
            No_i* tmp = a;
            a = a->dir;
            free(tmp);
         }
         else if (a->dir == NULL) {
            No_i* tmp = a;
            a = a->esq;
            free(tmp);
         }
         else {
            No_i* tmp = a->esq;
            while (tmp->dir != NULL) {
               tmp = tmp->dir;
            }
            a->chave = tmp->chave;
            tmp->chave = chave;
            a->esq = remover(a->esq, chave);
            a = atualizar_fb_dir(a);
         }
      }
      return a;
   }
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order(Arvore_i* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      printf("Chave: %d (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
      imprimir_in_order(a->esq, nivel + 1);
      imprimir_in_order(a->dir, nivel + 1);
   }
}

void imprimir_in_order_2D(Arvore_i* a, int tabs) {
	int i;
	if (a != NULL) {
		tabs++;

		imprimir_in_order_2D(a->dir, tabs);

		for (i = 1; i < tabs; i++) printf("\t");
		printf("%d (%d)\n", a->chave, a->altura);

		imprimir_in_order_2D(a->esq, tabs);
	}
}