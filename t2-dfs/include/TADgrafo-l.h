#ifndef _TAD_GRAFO_L_H_
#define _TAD_GRAFO_L_H_

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct GRAFO_L GRAFO_L;
typedef struct NODE NODE;

struct GRAFO_L{
	NODE **vertice;
	int n_arestas;
	int n_vertices;
	char tipo;
};

struct NODE{
	NODE *next;
	int adjacente;
	int peso;
};

GRAFO_L *cria_grafo_l(char tipo, int n_vertices);
void insere_aresta_l(GRAFO_L *grafo_l, int origem, int destino, int peso);
void imprime_grafo_l(GRAFO_L *grafo_l);
NODE *create_node(int destino, int peso);
void imprime_grafo_l(GRAFO_L *grafo_l);
void imprime_lista(NODE *node);
void imprime_adjacentes_l(GRAFO_L *grafo_l, int pos);
NODE *obtem_adjacentes_l(GRAFO_L *grafo_l, int pos);
void imprime_lista2(NODE *node);
void remove_aresta_l(GRAFO_L *grafo_l, int origem, int destino);
GRAFO_L *gera_transposta_l(GRAFO_L *grafo_l);
void imprime_transposta_l(GRAFO_L *grafo_l);
void destroy_grafo_l(GRAFO_L *grafo_l);
void destroy_lista(NODE *node);
void imprime_menor_peso_l(GRAFO_L *grafo_l);

#endif