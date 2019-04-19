#ifndef _TADFILA_H
#define _TADFILA_H

#include <stdlib.h>

typedef struct FILA FILA;
typedef struct NODE_F NODE_F;

struct NODE_F{
	NODE_F *suc;
	int elem;
};

struct FILA{
	NODE_F *inicio;
	NODE_F *fim;
	int n_elem;
};

FILA *create_fila();
void insere_fila(int elem, FILA *fila);
int remove_fila(FILA *fila);
int elem_inicio(FILA *fila);
int is_empty(FILA *fila);

#endif