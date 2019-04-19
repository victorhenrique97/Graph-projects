#ifndef _UTIS_H_
#define _UTIS_H_

#include <stdlib.h>
#include <limits.h>
	
typedef struct FILA FILA;
typedef struct ELEM ELEM;

struct FILA{
	ELEM **elem;
	int n_elem;
};

struct ELEM{
	int peso;
	int check;
	int pred;
};

FILA *create_fila(int n);
void atualiza_peso(FILA *fila, int pos, int peso);
void atualiza_pred(FILA *fila, int pos, int atualiza_pred);
int pega_minimo(FILA *fila);
void atualiza_check(FILA *fila, int pos);
int ischeck(FILA *fila, int pos);
void destroy_fila(FILA *fila);

#endif