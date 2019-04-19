#include <minimaltree.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////
/*Função que recebe um grafo como entrada e imprime a MST de acordo
com a saida pedida*/
void minimal_tree(GRAFO_L *grafo_l){

	NODE *aux = NULL;
	FILA *fila = create_fila(grafo_l->n_vertices);
	int u = -1;

	atualiza_peso(fila, 0, 0);

	for(int i=0; i<grafo_l->n_vertices; i++){

		u = pega_minimo(fila);

		if(fila->elem[u]->pred != -1){
			if(u > fila->elem[u]->pred)
			printf("(%d,%d) ",fila->elem[u]->pred, u);
			else printf("(%d,%d) ",u, fila->elem[u]->pred);
		}

		atualiza_check(fila, u);
		
		aux = obtem_adjacentes_l(grafo_l, u);

		while(aux != NULL){
			if(!ischeck(fila, aux->adjacente) && aux->peso < fila->elem[aux->adjacente]->peso){
				atualiza_pred(fila,aux->adjacente, u);
				atualiza_peso(fila, aux->adjacente, aux->peso);
			}
				aux = aux->next;
		}	
	}
	printf("\n");
	destroy_fila(fila);
}
////////////////////////////////////////////////////////////////