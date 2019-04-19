#include <TADlista.h>

//////////////////////////////////////////////////////
int is_empty_list(LISTA *lista){

	if(lista->inicio == NULL) return 1;

return 0;
}
/////////////////////////////////////////////////////////
LISTA *create_list(){

	LISTA *lista = (LISTA *) calloc(1, sizeof(LISTA));

return lista;
}
////////////////////////////////////////////////////////
void insere_list(int elem, LISTA *lista){

	NODE_L *aux = (NODE_L *) calloc(1, sizeof(NODE_L));
	aux->elem = elem;

	if(is_empty_list(lista))
		lista->inicio = aux;

	else{
		aux->prox = lista->inicio;
		lista->inicio = aux;
	}

}
////////////////////////////////////////////////////////
void destroy_list(LISTA *lista){

	if(!lista) return;
	NODE_L *aux = lista->inicio;
	NODE_L *aux2 = NULL;

	while(aux != NULL){
		aux2 = aux;
		aux = aux->prox;
		free(aux2);
	}

	free(lista);
}
/////////////////////////////////////////////////////////
int remove_primeiro(LISTA *lista){

	if(!lista) return -1;
	NODE_L *aux = lista->inicio;
	int elem = -1;
	
	if(is_empty_list(lista)) return -1;

	else{
		elem = aux->elem;
		lista->inicio = aux->prox;
		free(aux);
	}

return elem;
}