#ifndef _TADLISTA_H_
#define _TADLISTA_H_

#include <stdlib.h>

typedef struct LISTA LISTA;
typedef struct NODE_L NODE_L;

struct NODE_L{
	NODE_L *prox;
	int elem;
};

struct LISTA{
	NODE_L *inicio;
};

int is_empty_list(LISTA *lista);
LISTA *create_list();
void insere_list(int elem, LISTA *lista);
void destroy_list(LISTA *lista);
int remove_primeiro(LISTA *lista);

#endif