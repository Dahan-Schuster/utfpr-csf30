#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {  
   int info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

int vazia(Arvore *a) {
    return a == NULL;
}


//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
   if (vazia(a))  {
     a = (Arvore*)malloc(sizeof(Arvore));
     a->info = v;
     a->esq = NULL;
     a->dir = NULL;
   } else if (v <= a->info) {
     a->esq = inserir(a->esq, v);
   } else {
     a->dir = inserir(a->dir, v);
   }

   return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
    if (vazia(a)) return NULL;
    if (v < a->info)
        a->esq = remover(a->esq, v);
    else if (v > a->info)
        a->dir = remover(a->dir, v);

    // encontramos o nó a remover
    else {
        // se não possuir filhos
        if (vazia(a->esq) && vazia(a->dir)) {
            free(a);
            a = NULL;
        }
        else {
            if (vazia(a->dir)) {
                Arvore *tmp = a;
                a = a->esq;
                free(tmp);
            } else if (vazia(a->esq)) {
                Arvore *tmp = a;
                a = a->dir;
                free(tmp);
            } else {
                Arvore *tmp = a->esq;
                while (tmp->dir != NULL)
                    tmp = tmp->dir;

                a->info = tmp->info;
                tmp->info = v;
                a->esq = remover(a->esq, v);
            }
        }
    }

    return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
  if (vazia(a)) return 0;

  if (v < a->info) {
    return buscar(a->esq, v);
  } else if (v > a->info) {
    return buscar(a->dir, v);
  }

  return 1;   
}


//========= Q2 - max =====
int max (Arvore *a) {
    while (a->dir != NULL)
        a = a->dir;
    printf("%d\n", a->info);
    return a->info;
}

//========= Q2 - min =====
int min (Arvore *a) {
    while (a->esq != NULL)
        a = a->esq;
    printf("%d\n", a->info);
    return a->info;
}


//========= Q4 - imprime_decrescent =====
void desc_order (Arvore* a) {
    if (a != NULL) {
        desc_order (a->dir);
        printf("%d ", a->info);
        desc_order (a->esq);
    }
}

void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () {

    int i;
    
    Arvore *a = cria_arvore_vazia ();
    a = inserir (a, 50);
    a = inserir (a, 30);
    a = inserir (a, 90);
    a = inserir (a, 20);
    a = inserir (a, 40);
    a = inserir (a, 95);
    a = inserir (a, 10);
    a = inserir (a, 35);
    a = inserir (a, 45);


    printf("\nPré-order: ");
    pre_order (a);	
    printf("\n");
    
    printf("\nDesc-order: ");
    desc_order (a);	
    printf("\n");


    min(a);
    max(a);

    free(a);
    
    
    // ====== Q3 ====
    
    /*
    srand(time(NULL));

    Arvore *ordenada = cria_arvore_vazia();
    Arvore *randomica = cria_arvore_vazia();
    int tamanho = 99999;

    printf("Preenchendo árvores...\n");
    for (i = 0; i < tamanho; i++) {
        ordenada = inserir(ordenada, i);
        randomica = inserir(randomica, rand() % (tamanho+1));
    }
    
    printf("Árvores preenchidas.\n");
    
    clock_t start, end;
    double elapsed_time;
   
    int q = 1000000;
    
    start = clock();
    buscar (ordenada, q);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (ordenada): %f\n", elapsed_time); // 0.002971 s
 
    start = clock();
    buscar (randomica, q);
    end = clock();
    elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
    printf("Tempo de execução (randômica): %f\n", elapsed_time); // 0.000004 s
    
    
     // Ao inserir elementos em ordem na árvore sem fazer um balanceamento,
     // sua estrutura final será degenerada, tornando seu tamanho muito
     // maior que o necessário e, portanto, aumento consideravelmente a
     // complexidade de processamento

    free(ordenada);
    free(randomica);
    */

    return 0;
}


