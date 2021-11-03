#include "avl_str.h"

int main() {

	Arvore_s* AVL = NULL;

	AVL = inserir(AVL, "Pedro");
	AVL = inserir(AVL, "Joaquim");
	AVL = inserir(AVL, "Sandra");
	AVL = inserir(AVL, "Daniele");
	AVL = inserir(AVL, "Jhony");
	AVL = inserir(AVL, "Bruna");
	AVL = inserir(AVL, "Roberto");
	AVL = inserir(AVL, "Ricardo");
	AVL = inserir(AVL, "Rafael");
	AVL = inserir(AVL, "Hayana");
	AVL = inserir(AVL, "Lorena");
	AVL = inserir(AVL, "Mariana");
	AVL = inserir(AVL, "Marina");
	AVL = inserir(AVL, "Roberta");
	AVL = inserir(AVL, "Chayene");
	AVL = inserir(AVL, "Edmundo");

	imprimir_in_order_2D(AVL, 0);

	return 0;
}
