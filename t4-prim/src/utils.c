#include <utils.h>
//////////////////////////////////////////////////////
/*Função que libera memoria alocada pela fila de prioridades*/
void destroy_fila(FILA *fila){

	if(!fila) return;
	
	for(int i=0; i<fila->n_elem; i++)
		if(fila->elem[i]) free(fila->elem[i]);
	
	free(fila->elem);
	free(fila);
}
//////////////////////////////////////////////////////
/*Função que aloca memoria para a fila de prioridades*/
FILA *create_fila(int n){

	FILA *fila = (FILA *) calloc(1, sizeof(FILA));
	fila->n_elem = n;
	fila->elem = (ELEM **) calloc(n, sizeof(ELEM *));

	for(int i=0; i<n; ++i){
		fila->elem[i] = (ELEM *) calloc(1, sizeof(ELEM));
		fila->elem[i]->peso = INT_MAX;
		fila->elem[i]->pred = -1;
	}

return fila;
}
//////////////////////////////////////////////////////
/*Função que atualiza o peso*/
void atualiza_peso(FILA *fila, int pos, int peso){

		fila->elem[pos]->peso = peso;
}
//////////////////////////////////////////////////////
/*Função que atualiza o predecessor*/
void atualiza_pred(FILA *fila, int pos, int pred){

	fila->elem[pos]->pred = pred;
}

//////////////////////////////////////////////////////
/*Função que marca uma flag quando o vertice ja foi inserido na MST*/
void atualiza_check(FILA *fila, int pos){
	fila->elem[pos]->check = 1;
}
//////////////////////////////////////////////////////
/*Função que percorre a fila e retona o indice do elemento de maior prioridade*/
int pega_minimo(FILA *fila){

	int tamanho = fila->n_elem;
	int aux = INT_MAX;
	int pos = -1;

	for(int i=0; i<tamanho; ++i)
		if(!(fila->elem[i]->check) && fila->elem[i]->peso < aux){
			aux = fila->elem[i]->peso;
			pos = i;
		}

return pos;
}
//////////////////////////////////////////////////////
/*Função que diz se um elemento já foi inserido no MST*/
int ischeck(FILA *fila, int pos){

return fila->elem[pos]->check;
}