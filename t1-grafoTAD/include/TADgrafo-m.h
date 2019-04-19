#ifndef _TAD_GRAFO_M_H_
#define _TAD_GRAFO_M_H_

#include <stdlib.h>
#include <stdio.h>
#include <utils.h>
#include <limits.h>

typedef struct GRAFO_M GRAFO_M;
typedef struct ADJACENTES_G ADJACENTES_G;

struct GRAFO_M{
	int n_vertices;
	int n_arestas;
	int **matriz;
	char tipo;
};

struct ADJACENTES_G{
	int *adjacentes;
	int n_adjacentes;
};

GRAFO_M *cria_grafo_m(char tipo, int n_vertices, int flag);
void insere_aresta_m(GRAFO_M *grafo_m, int origem, int destino, int peso);
void remove_aresta_m(GRAFO_M *grafo_m, int origem, int destino);
void imprime_grafo_m(GRAFO_M *grafo_m);
GRAFO_M *gera_transposto_m(GRAFO_M *grafo_m);
ADJACENTES_G *retorna_adjacentes_m(GRAFO_M *grafo_m, int pos);
void imprime_menor_peso_m(GRAFO_M *grafo_m);
void destroi_grafo_m(GRAFO_M *grafo_m);
void imprime_adjacentes_m(GRAFO_M *grafo_m, int pos);
void imprime_transposto_m(GRAFO_M *grafo_m);

#endif

