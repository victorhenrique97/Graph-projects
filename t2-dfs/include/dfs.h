#ifndef _DFS_H_
#define _DFS_H_

#include <stdio.h>
#include <stdlib.h>
#include <TADgrafo-l.h>

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
FIELD * dfs(GRAFO_L *grafo_l, int s, int d);
void destroy_check(CHECK *check);


#endif