#include <dijkstra.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////
/*Função que encontra o menor caminho dado origem e destino*/
FIELD *dijkstra(GRAFO_L *grafo_l, int origem, int destino){

	NODE *aux = NULL;
	CHECK *check = create_check(grafo_l->n_vertices);
	FIELD *field = NULL;
	int u = -1, v = -1;

	check->color[origem] = GRAY; // ja visitei o vertice
	check->dist[origem] = 0; // distancia da origem é zero

	for(int i=0; i<grafo_l->n_vertices; i++){

		u = pega_minimo(check, grafo_l->n_vertices);
		if(u == -1) break; // caso seja invalido ou seja, não tenha minimo(algoritmo nao tenha encontrado caminho eu finalizo)

		check->color[u] = BLACK; // ja processei entao a cor fica preto

		aux = obtem_adjacentes_l(grafo_l, u); // obtenho os adjacentes desse vertice

		while(aux != NULL){
			v = aux->adjacente;
			if(check->color[v] == WHITE || check->dist[v] > (check->dist[u] + aux->peso)){ // atualizo as distancias 
				check->color[v] = GRAY;
				check->dist[v] = check->dist[u] + aux->peso;
				check->pred[v] = u;
			}
			aux = aux->next;
		}	
	}

	field = generate_field(check, destino);
	destroy_check(check);

return field;	
}
////////////////////////////////////////////////////////////////