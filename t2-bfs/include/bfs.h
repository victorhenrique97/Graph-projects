#ifndef _BFS_H_
#define _BFS_H_

#include <stdio.h>
#include <stdlib.h>
#include <TADgrafo-l.h>
#include <TADfila.h>

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
	int *dist;
	int *pred;
};

struct FIELD{
	int *track;
	int len;
}; 

CHECK *create_check(int n_vertex);
FIELD *bfs(GRAFO_L *grafo_l, int s_index, int d_index);
void destroy_fila(FILA *fila);
void destroy_field(FIELD *field);

#endif