#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {
	char info;
	int fator;
	struct arvore* esq;
	struct arvore* dir;
} Arvore;

Arvore* cria_arvore_vazia(void) {
	return NULL;
}

void arvore_libera(Arvore* a) {
	if (a != NULL) {
		arvore_libera(a->esq);
		arvore_libera(a->dir);
		free(a);
	}
}

int vazia(Arvore* a) {
	return a == NULL;
}

void print_2D(Arvore* a, int tabs) {
	int i;
	if (a != NULL) {
		tabs++;

		print_2D(a->dir, tabs);

		for (i = 1; i < tabs; i++) printf("\t");
		printf("%c (%d)\n", a->info, a->fator);

		print_2D(a->esq, tabs);
	}
}

void pre_ordem(Arvore *a) {
   if (!vazia(a)) {
      printf("%c, ", a->info);
      pre_ordem(a->esq);
      pre_ordem(a->dir);
   }
}

int calcula_altura_arvore (Arvore *a) {
   if (vazia(a))
      return -1;

   if (vazia(a->esq) && vazia(a->dir))
      return 0;

   int alturaEsq = 1 + calcula_altura_arvore(a->esq);
   int alturaDir = 1 + calcula_altura_arvore(a->dir);

   return alturaEsq > alturaDir ? alturaEsq : alturaDir;
}

void calcular_fator(Arvore *a) {
	if (vazia(a)) return;
	a->fator = calcula_altura_arvore(a->dir) - calcula_altura_arvore(a->esq);
}

void rotacionar_esquerda(Arvore* no) {
	Arvore* filho = no->dir;
	no->dir = filho->esq;
	filho->esq = no;
}

void rotacionar_direita(Arvore* no) {
	Arvore* filho = no->esq;
	no->esq = filho->dir;
	filho->dir = no;
}

Arvore* balancear(Arvore *no) {
	// checagem de segurança
	if (vazia(no)) return no;

	// calcula o valor inicial do fator do nó
	calcular_fator(no);

	// se já estiver balanceado, retorna o no
	if (no->fator >= -1 && no->fator <= 1) return no;

	Arvore* filho = no;

	// direita maior, rotação à esquerda
	if (no->fator > 1) {
		filho = no->dir;

		// no caso dos sinais serem diferentes, realiza-se uma rotação extra
		// para o filho na direção oposta
		if (filho->fator < 0) {
			rotacionar_direita(filho);
		}

		rotacionar_esquerda(no); // rotação simples
		calcular_fator(filho);	 // recalcula o fator do filho após balancear
	}

	// esquerda maior, rotação à direita
	else if (no->fator < -1) {
		filho = no->esq;
		
		if (filho->fator > 0) {
			rotacionar_esquerda(filho);
		}

		rotacionar_direita(no);
		calcular_fator(filho);
	}

	// recalcula o fator após balancear
	calcular_fator(no);

	// ao balancear, o filho se torna a nova raiz
	return filho;
}

Arvore* inserir(Arvore* a, char v) {
	if (vazia(a)) {
		a = (Arvore*)malloc(sizeof(Arvore));
		a->info = v;
		a->fator = 0;
		a->esq = NULL;
		a->dir = NULL;
	}
	else if (v <= a->info) {
		a->esq = inserir(a->esq, v);
	}
	else {
		a->dir = inserir(a->dir, v);
	}

	return balancear(a);
}

Arvore* remover(Arvore* a, char v) {
	if (vazia(a)) return NULL;

	// encontramos o nó a remover
	if (v == a->info) {
		// se não possuir filhos
		if (vazia(a->esq) && vazia(a->dir)) {
			free(a);
			a = NULL;
		}
		else {
			if (vazia(a->dir)) {
				Arvore* tmp = a;
				a = a->esq;
				free(tmp);
			}
			else if (vazia(a->esq)) {
				Arvore* tmp = a;
				a = a->dir;
				free(tmp);
			}
			else {
				Arvore* tmp = a->esq;
				while (tmp->dir != NULL)
					tmp = tmp->dir;

				a->info = tmp->info;
				tmp->info = v;
				a->esq = remover(a->esq, v);
			}
		}
	
		return a;
	} else {
		if (v < a->info)
			a->esq = remover(a->esq, v);
		else
			a->dir = remover(a->dir, v);

		return balancear(a);
	}
}

int buscar(Arvore* a, char v) {
	if (vazia(a)) return 0;

	if (v < a->info) {
		return buscar(a->esq, v);
	}
	else if (v > a->info) {
		return buscar(a->dir, v);
	}

	return 1;
}


#define TAM 8

int main() {

	int i;

	Arvore* a = cria_arvore_vazia();
	a = inserir(a, 'Q');
	a = inserir(a, 'Z');
	a = inserir(a, 'B');
	a = inserir(a, 'Y');
	a = inserir(a, 'T');
	a = inserir(a, 'M');
	a = inserir(a, 'E');
	a = inserir(a, 'W');
	a = inserir(a, 'X');
	a = inserir(a, 'S');
	a = inserir(a, 'F');
	a = inserir(a, 'G');
	a = inserir(a, 'A');
	a = inserir(a, 'H');
	a = inserir(a, 'N');
	a = inserir(a, 'O');
	a = inserir(a, 'P');
	a = inserir(a, 'R');


	printf("Árvore inicial:\n");
	print_2D(a, 0);
	printf("-----------------------------------------------\n");


	char itens[TAM] = { 'A', 'H', 'E', 'W', 'G', 'N', 'P', 'O' };

	for ( i = 0; i < TAM; i++) {
		printf("Removido [%c]:\n", itens[i]);
		a = remover(a, itens[i]);
		print_2D(a, 0);
		printf("-----------------------------------------------\n");
	}
	
	free(a);

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


