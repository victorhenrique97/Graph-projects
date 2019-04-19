#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdlib.h>
#include <stdio.h>

int int_compare(const void *a, const void *b);
void seta_matriz(int **matrix, int nrow, int ncol);
int **alloca_matriz(int nrow, int ncol);
void free_matriz(int **matrix, int nrow);
int **matriz_transposta(int **matrix, int nrow, int ncol);
void imprime_matriz(int **matrix, int nrow, int ncol);

#endif