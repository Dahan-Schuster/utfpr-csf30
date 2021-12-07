#include <stdio.h>
#include <stdlib.h>

/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   return G;
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   NoA *aux;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         while (G->Adj[v] != NULL) {
            aux = G->Adj[v]->next;
            free(G->Adj[v]);
            G->Adj[v] = aux;
         }
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}

NoA* enqueue(NoA *lista, int id) {
   NoA* new = (NoA*) malloc (sizeof(NoA));
   new->id = id;
   new->next = NULL;

   if (lista == NULL) {
      lista = new;
   } else {
      NoA* end = lista;
      while (end->next != NULL) {
         end = end->next;
      }
      end->next = new;
   }

   return lista;
}

void inserir_arestas_adj_arr (
   GrafoA *G, int origem, int *arestas, int qteArestas
) {
   if (origem < 0 || origem >= G->V) {
      printf("erro: vértice inexistente");
      return;
   }

   int i;
   for (i = 0; i < qteArestas; i++) {
      int destino = arestas[i];
      if (origem < 0 || origem >= G->V) {
         printf("erro: vértice inexistente");
         return;
      }

      G->Adj[origem] = enqueue(G->Adj[origem], destino);
      G->Adj[destino] = enqueue(G->Adj[destino], origem);
   }
}

void inserir_arestas_adj (GrafoA *G, int origem, int destino) {
   if (origem < 0 || origem >= G->V || destino < 0 || destino >= G->V) {
      printf("erro: um ou mais vértices inexistentes");
      return;
   }
   
   G->Adj[origem] = enqueue(G->Adj[origem], destino);
   G->Adj[destino] = enqueue(G->Adj[destino], origem);
}

void inserir_arestas_mat (GrafoM *G, int origem, int destino) {
   if (origem < 0 || origem >= G->V || destino < 0 || destino >= G->V) {
      printf("erro: um ou mais vértices inexistentes");
      return;
   }

   G->Mat[origem][destino] = 1;
   G->Mat[destino][origem] = 1;
}

void imprimir_grafo_adj (GrafoA *G) {
   NoA *e; /*var. para percorrer a lista*/
   int v;
   for (v = 0; v < G->V; v++) {
      printf("%d -> ", v);
      if (G->Adj[v] != NULL) {
         for (e = G->Adj[v]; e != NULL; e = e->next) {
            printf("%d ", e->id);
         }
      }
      printf("\n");
   }
   printf("\n");
}

void imprimir_grafo_mat (GrafoM *G) {
   int i, j;
   
   printf("    ");
   for (i = 0; i < G->V; i++)
      printf("%d ", i);
   printf("\n\n");

   for (i = 0; i < G->V; i++) {
      printf("%d   ", i);
      for (j = 0; j < G->V; j++) {
         printf("%d ", G->Mat[i][j]);
      }
      printf("\n");  
   }
   printf("\n");
}

void limpar_grafo_adj (GrafoA *G) {
   int v;
   NoA *aux;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         while (G->Adj[v] != NULL) {
            aux = G->Adj[v]->next;
            free(G->Adj[v]);
            G->Adj[v] = aux;
         }

         G->Adj[v] = NULL;
      }
   }
}

void limpar_grafo_mat (GrafoM *G) {
   int i, j;
   
   for (i = 0; i < G->V; i++) {
      for (j = 0; j < G->V; j++) {
         G->Mat[i][j] = 0;
      }
   }
}

/* */
int main () {

   int Va = 6; /*Número de vértices*/

   GrafoA* Ga = criar_grafo_adj (Va);

   int Vm = 6; /*Número de vértices*/

   GrafoM* Gm = criar_grafo_mat (Vm);


   // Q1 ==================================

   // Lista
   int e0[] = {1, 2, 5};
   inserir_arestas_adj_arr(Ga, 0, e0, 3);

   int e1[] = {2, 3};
   inserir_arestas_adj_arr(Ga, 1, e1, 2);
   
   int e2[] = {3, 4};
   inserir_arestas_adj_arr(Ga, 2, e2, 2);
   
   inserir_arestas_adj(Ga, 3, 4);
   inserir_arestas_adj(Ga, 4, 5);

   printf("\nGrafo (lista adjacência):\n");
   imprimir_grafo_adj (Ga);
   limpar_grafo_adj (Ga);


   // Matriz
   inserir_arestas_mat(Gm, 0, 1);
   inserir_arestas_mat(Gm, 0, 2);
   inserir_arestas_mat(Gm, 0, 5);
   inserir_arestas_mat(Gm, 1, 2);
   inserir_arestas_mat(Gm, 1, 3);
   inserir_arestas_mat(Gm, 2, 3);
   inserir_arestas_mat(Gm, 2, 4);
   inserir_arestas_mat(Gm, 3, 4);
   inserir_arestas_mat(Gm, 4, 5);

   printf("\nGrafo (matriz adjacência):\n");
   imprimir_grafo_mat (Gm);
   limpar_grafo_mat (Gm);

   // =====================================

   liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);

   return 0;
}

