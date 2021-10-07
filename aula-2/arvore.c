#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
   char info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 1 - pré-ordem ====
void pre_ordem(Arvore *a) {
   if (!verifica_arv_vazia(a)) {
      printf("%c, ", a->info);
      pre_ordem(a->esq);
      pre_ordem(a->dir);
   }
}


//========= Exercício 1 - in-ordem ====
void in_ordem(Arvore *a) {
   if (!verifica_arv_vazia(a)) {
      in_ordem(a->esq);
      printf("%c, ", a->info);
      in_ordem(a->dir);
   }
}

//========= Exercício 1 - pós-ordem ====
void pos_ordem(Arvore *a) {
   if (!verifica_arv_vazia(a)) {
      pos_ordem(a->esq);
      pos_ordem(a->dir);
      printf("%c, ", a->info);
   }
}

//========= Exercício 2 - pertence ====
int pertence_arv (Arvore *a, char c) {
   if (!verifica_arv_vazia(a))
      if (c == a->info || pertence_arv(a->esq, c) || pertence_arv(a->dir, c))
         return 1;

   return 0;
}

//========= Exercício 3 - conta nós ====
int conta_nos (Arvore *a) {
   if (verifica_arv_vazia(a)) return 0;

   return 1 + conta_nos(a->esq) + conta_nos(a->dir);
}

//========= Exercício 4 - calcula altura ====
int calcula_altura_arvore (Arvore *a) {
   if (verifica_arv_vazia(a))
      return -1;

   if (verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir))
      return 0;

   int alturaEsq = 1 + calcula_altura_arvore(a->esq);
   int alturaDir = 1 + calcula_altura_arvore(a->dir);

   return alturaEsq > alturaDir ? alturaEsq : alturaDir;
}


//========= Exercício 5 - conta folhas ====
int conta_nos_folha (Arvore *a) {
   if (verifica_arv_vazia(a))
      return 0;

   if (verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir))
      return 1;

   return conta_nos_folha(a->esq) + conta_nos_folha(a->dir);
}


int main (int argc, char *argv[]) {

   Arvore *a = cria_arv_vazia();
   // Arvore *a = constroi_arv ('a', cria_arv_vazia(), cria_arv_vazia());
   // Arvore *a = constroi_arv ('a',
   //       constroi_arv('b',
   //       cria_arv_vazia(),
   //       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
   //    ),
   //    constroi_arv('c',
   //       constroi_arv('e',
   //          constroi_arv('x', cria_arv_vazia(), cria_arv_vazia()),
   //          constroi_arv('y', cria_arv_vazia(), cria_arv_vazia())
   //       ),
   //       constroi_arv('f',
   //          constroi_arv('g',
   //             cria_arv_vazia(),
   //             constroi_arv('h',
   //                constroi_arv('i', cria_arv_vazia(), cria_arv_vazia()),
   //                cria_arv_vazia()
   //             )
   //          ),
   //          constroi_arv('k', cria_arv_vazia(), cria_arv_vazia())
   //       )
   //   )
   // );

   printf("Pré-ordem: ");
   pre_ordem(a);
   printf("\n");

   printf("In-ordem: ");
   in_ordem(a);
   printf("\n");

   printf("Pós-ordem: ");
   pos_ordem(a);
   printf("\n");
   
   printf("f pertence? ");
   printf(pertence_arv(a, 'f') ? "Sim!" : "Não!");
   printf("\n");
   
   printf("g pertence? ");
   printf(pertence_arv(a, 'g') ? "Sim!" : "Não!");
   printf("\n");
   
   printf("Quantidade de nós: %d\n", conta_nos(a));
   
   printf("Quantidade de folhas: %d\n", conta_nos_folha(a));

   printf("Altura: %d\n", calcula_altura_arvore(a));

   arv_libera (a);

   return 0;
}

