#include <utils.h>

///////////////////////////////////////////////////////////////////
int int_compare(const void *a, const void *b){
	return *((int *)a) - *((int *)b);
}

////////////////////////////////////////////////////////////////////
/*Fuũnção que seta um valor na matrix*/
void seta_matriz(int **matrix, int nrow, int ncol){

	for(int i=0; i<nrow; i++)
		for(int j=0; j<ncol; j++)
			matrix[i][j] = -1;
}
////////////////////////////////////////////////////////////////////
/*Função que alloca uma matrix dado numero de linhas e colunas*/
int **alloca_matriz(int nrow, int ncol){

	int **matrix = (int **) calloc(nrow, sizeof(int *));

	for(int i=0; i<ncol; i++)
		matrix[i] = (int *) calloc(ncol, sizeof(int));

return matrix;
}

////////////////////////////////////////////////////////////////////
/*Função que desaloca uma matrix*/
void free_matriz(int **matrix, int nrow){

	for(int i=0; i<nrow; i++)
		free(matrix[i]);

	free(matrix);
}

/////////////////////////////////////////////////////////////////////
/*gera a matrix transposta*/
int **matriz_transposta(int **matrix, int nrow, int ncol){

	int **matrix_t = alloca_matriz(nrow, ncol);

	for(int i=0; i<nrow; i++)
		for(int j=0; j<ncol; j++)
			matrix_t[j][i] = matrix[i][j];

return matrix_t;
}

///////////////////////////////////////////////////////////////////////
/*Imprime a matrix*/
void imprime_matriz(int **matrix, int nrow, int ncol){

	for(int i=0; i<nrow; i++){
		for(int j=0; j<ncol; j++){
			if(matrix[i][j] == -1) printf(". ");
			else printf("%d ", matrix[i][j]);
		}
	printf("\n");
	}
}
