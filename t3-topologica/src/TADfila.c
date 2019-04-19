#include <TADfila.h>
/*Tad fila: Inserção no final e remoção no começo*/
////////////////////////////////////////////////////
FILA *create_fila(){

	FILA *fila = (FILA *) calloc(1, sizeof(FILA));

return fila;
}
///////////////////////////////////////////////////// 
void insere_fila(int elem, FILA *fila){

	NODE_F *aux = (NODE_F *) calloc(1, sizeof(NODE_F));
	aux->elem = elem;

	if(is_empty(fila))
		fila->fim = fila->inicio = aux;	

	else{
	fila->fim->suc = aux;
	fila->fim = aux;
	fila->n_elem++;	
	}
}

//////////////////////////////////////////////////////
int remove_fila(FILA *fila){

	int ret;
	NODE_F *aux;

	aux = fila->inicio;
	fila->inicio = aux->suc;
	ret = aux->elem;

	free(aux);
	fila->n_elem--;

return ret;
}
//////////////////////////////////////////////////////
int elem_inicio(FILA *fila){

return fila->inicio->elem;
}

//////////////////////////////////////////////////////
int is_empty(FILA *fila){

	if(fila->inicio == NULL) return 1;

return 0;
}

/////////////////////////////////////////////////////
void destroy_fila(FILA *fila){

	if(!fila) return;

	while(fila->inicio != NULL){
		remove_fila(fila);
	}

	free(fila);
}