# Estrutura de Dados II | UTFPR

## Lista de exercícios - aula 4

## Aluno: Dahan Schuster (2701792)

**OBS:** Professora, eu faltei a aula passada e estudei o assunto pelo slide. Por causa disso, não fiquei sabendo que
a lista de exercícios era só em PDF (percebi só na hora de enviar que arquivos .c não eram aceitos). Por isso, acabei
implementando uma AVL a partir das explicações do slide. As respostas desse arquivo foram feitas usando o resultado
da própria implementação.

O formato da resposta com a árvore "deitada" foi produzido por um algorítimo de impressão de árvores em 2D, implementado manualmente

**Legenda:** Nó (fator)

### Questão 1

```text
			Z (0)
		Y (0)
			X (0)
	W (0)
			T (0)
		S (0)
			R (0)
Q (0)
			P (0)
		O (0)
			N (0)
	M (0)
			H (0)
		B (0)
			A (0)
```

### Questão 2

```text
Árvore inicial:
			Z (0)
		Y (0)
			X (0)
	W (0)
			T (0)
		S (0)
			R (0)
Q (0)
			P (0)
		O (0)
			N (0)
	M (0)
			H (0)
		B (0)
			A (0)
-----------------------------------------------
Removido [A]:
			Z (0)
		Y (0)
			X (0)
	W (0)
			T (0)
		S (0)
			R (0)
Q (0)
			P (0)
		O (0)
			N (0)
	M (0)
			H (0)
		B (1)
-----------------------------------------------
Removido [H]:
			Z (0)
		Y (0)
			X (0)
	W (0)
			T (0)
		S (0)
			R (0)
Q (0)
			P (0)
		O (0)
			N (0)
	M (1)
		B (0)
-----------------------------------------------
Removido [E]:
			Z (0)
		Y (0)
			X (0)
	W (0)
			T (0)
		S (0)
			R (0)
Q (0)
			P (0)
		O (0)
			N (0)
	M (1)
		B (0)
-----------------------------------------------
Removido [W]:
			Z (0)
		Y (0)
			X (0)
	T (0)
		S (-1)
			R (0)
Q (0)
			P (0)
		O (0)
			N (0)
	M (1)
		B (0)
-----------------------------------------------
Removido [G]:
			Z (0)
		Y (0)
			X (0)
	T (0)
		S (-1)
			R (0)
Q (0)
			P (0)
		O (0)
			N (0)
	M (1)
		B (0)
-----------------------------------------------
Removido [N]:
			Z (0)
		Y (0)
			X (0)
	T (0)
		S (-1)
			R (0)
Q (0)
			P (0)
		O (1)
	M (1)
		B (0)
-----------------------------------------------
Removido [P]:
			Z (0)
		Y (0)
			X (0)
	T (0)
		S (-1)
			R (0)
Q (1)
		O (0)
	M (0)
		B (0)
-----------------------------------------------
Removido [O]:
			Z (0)
		Y (0)
			X (0)
	T (0)
		S (-1)
			R (0)
Q (1)
	M (-1)
		B (0)
```

### Questão 3

```text
Removido [1]:
				40 (0)
			39 (0)
		38 (0)
					37 (0)
				36 (0)
			35 (0)
				34 (0)
	33 (0)
				32 (0)
			31 (0)
		30 (0)
			29 (0)
28 (0)
					22 (0)
				21 (0)
			20 (0)
				19 (0)
		18 (0)
				16 (0)
			15 (0)
	14 (0)
					13 (0)
				12 (0)
			11 (0)
				10 (0)
		8 (0)
					7 (0)
				6 (0)
			5 (0)
					4 (0)
				3 (0)
					2 (0)
```