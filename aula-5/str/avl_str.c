#include <string.h>
#include "avl_str.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior(int esq, int dir) {
   return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura(Arvore_s* a) {
   return (a == NULL ? -1 : a->altura);
}

int atualizar_altura(Arvore_s* a) {
   return (maior(altura(a->esq), altura(a->dir)) + 1);
}

/*----------------------*/
int balanceamento(Arvore_s* a) {
   return (altura(a->dir) - altura(a->esq));
}

/*----------------------*/
Arvore_s* rotacao_simples_esq(Arvore_s* a) {
   No_s* filho = a->dir;
   a->dir = filho->esq;
   filho->esq = a;
   a->altura = atualizar_altura(a);
   filho->altura = atualizar_altura(filho);
   return filho;
}

/*----------------------*/
Arvore_s* rotacao_simples_dir(Arvore_s* a) {
   No_s* filho = a->esq;
   a->esq = filho->dir;
   filho->dir = a;
   a->altura = atualizar_altura(a);
   filho->altura = atualizar_altura(filho);
   return filho;
}

/*----------------------*/
Arvore_s* rotacao_dupla_esq(Arvore_s* a) {
   a->dir = rotacao_simples_dir(a->dir);
   return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore_s* rotacao_dupla_dir(Arvore_s* a) {
   a->esq = rotacao_simples_esq(a->esq);
   return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore_s* atualizar_fb_dir(Arvore_s* a) {
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
Arvore_s* atualizar_fb_esq(Arvore_s* a) {
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
Arvore_s* inserir(Arvore_s* a, char* chave) {
   if (a == NULL) {
      a = (No_s*)malloc(sizeof(No_s));
      a->altura = 0;
      a->esq = a->dir = NULL;

      a->chave = strdup(chave);
   }
   else if (strcmp(chave, a->chave) < 0) {
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
Arvore_s* remover(Arvore_s* a, char* chave) {
   if (a == NULL) {
      return NULL;
   }
   else {
      int str_cmp = strcmp(chave, a->chave);

      if (str_cmp < 0) {
         a->esq = remover(a->esq, chave);
         a = atualizar_fb_dir(a);
      }
      else if (str_cmp > 0) {
         a->dir = remover(a->dir, chave);
         a = atualizar_fb_esq(a);
      }
      else {
         if ((a->esq == NULL) && (a->dir == NULL)) {
            free(a);
            a = NULL;
         }
         else if (a->esq == NULL) {
            No_s* tmp = a;
            a = a->dir;
            free(tmp);
         }
         else if (a->dir == NULL) {
            No_s* tmp = a;
            a = a->esq;
            free(tmp);
         }
         else {
            No_s* tmp = a->esq;
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
void imprimir_in_order(Arvore_s* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      printf("Chave: %s (altura: %d, fb: %+d) no nível: %d\n", a->chave, a->altura, balanceamento(a), nivel);
      imprimir_in_order(a->esq, nivel + 1);
      imprimir_in_order(a->dir, nivel + 1);
   }
}

void imprimir_in_order_2D(Arvore_s* a, int tabs) {
	int i;
	if (a != NULL) {
		tabs++;

		imprimir_in_order_2D(a->dir, tabs);

		for (i = 1; i < tabs; i++) printf("\t");
		printf("%s (%d)\n", a->chave, a->altura);

		imprimir_in_order_2D(a->esq, tabs);
	}
}