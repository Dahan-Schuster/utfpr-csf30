#ifndef _AVL_INT_H
#define _AVL_INT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_i {
   int chave;
   int altura;
   struct node_i* esq;
   struct node_i* dir;
} No_i, Arvore_i;

int maior (int esq, int dir);

int altura (Arvore_i* a);

int atualizar_altura (Arvore_i *a);

int balanceamento (Arvore_i *a);

Arvore_i* rotacao_simples_esq (Arvore_i* a);

Arvore_i* rotacao_simples_dir (Arvore_i* a);

Arvore_i* rotacao_dupla_esq (Arvore_i* a);

Arvore_i* rotacao_dupla_dir (Arvore_i* a);

Arvore_i* atualizar_fb_dir (Arvore_i *a);

Arvore_i* atualizar_fb_esq (Arvore_i *a);

Arvore_i* inserir (Arvore_i *a, int chave);

Arvore_i* remover (Arvore_i *a, int chave);

void imprimir_in_order (Arvore_i* a, int nivel);

void imprimir_in_order_2D (Arvore_i* a, int tabs);

#endif
