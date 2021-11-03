#ifndef _AVL_STR_H
#define _AVL_STR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
   char* chave;
   int altura;
   struct node_s* esq;
   struct node_s* dir;
} No_s, Arvore_s;

int maior (int esq, int dir);

int altura (Arvore_s* a);

int atualizar_altura (Arvore_s *a);

int balanceamento (Arvore_s *a);

Arvore_s* rotacao_simples_esq (Arvore_s* a);

Arvore_s* rotacao_simples_dir (Arvore_s* a);

Arvore_s* rotacao_dupla_esq (Arvore_s* a);

Arvore_s* rotacao_dupla_dir (Arvore_s* a);

Arvore_s* atualizar_fb_dir (Arvore_s *a);

Arvore_s* atualizar_fb_esq (Arvore_s *a);

Arvore_s* inserir (Arvore_s *a, char* chave);

Arvore_s* remover (Arvore_s *a, char* chave);

void imprimir_in_order (Arvore_s* a, int nivel);

void imprimir_in_order_2D (Arvore_s* a, int tabs);

#endif
