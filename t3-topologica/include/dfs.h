#ifndef _DFS_H_
#define _DFS_H_

#include <stdio.h>
#include <stdlib.h>
#include <TADgrafo-l.h>
#include <TADlista.h>

enum{
	WHITE,
	GRAY,
	BLACK
};

typedef struct CHECK CHECK;
typedef struct FIELD FIELD;

struct CHECK{
	int *vertex;
	int *color;
	int *time1;
	int *time2;
	int *pred;
};

struct FIELD{
	int *track;
	int len;
}; 

void destroy_field(FIELD *field);
void ordenacao_topologica(GRAFO_L *grafo_l, int n_vertex, LISTA *l);
void destroy_check(CHECK *check);
FIELD *dfs(GRAFO_L *grafo_l, int s, int d);

#endif