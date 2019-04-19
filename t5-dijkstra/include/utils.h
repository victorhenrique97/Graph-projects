#ifndef _UTILS_H_
#define _UTILS_H_

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
	int *dist;
	int *pred;
	int *ispassed;
};

struct FIELD{
	int *track;
	int len;
}; 

int pega_minimo(CHECK *check, int n_elem);
CHECK *create_check(int n_vertex);
void destroy_check(CHECK *check);
FIELD *generate_field(CHECK *check, int u);
void destroy_field(FIELD *field);

#endif