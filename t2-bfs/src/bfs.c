#include <bfs.h>

//////////////////////////////////////////////////////////////////
/*Libera a memoria alocada pela estrutura auxiliar*/
void destroy_check(CHECK *check){

	if(!check) return;

	free(check->vertex);
	free(check->color);
	free(check->dist);
	free(check->pred);
	free(check);

}
//////////////////////////////////////////////////////////////////
/*Libera a memória alocada para a struct com os caminhos */
void destroy_field(FIELD *field){

	if(!field) return;

	free(field->track);
	free(field);
}
//////////////////////////////////////////////////////////////////
/*Função que gera os caminhos */
FIELD *generate_field(CHECK *check, int u){

	int aux;
	FIELD *field = (FIELD *) calloc(1, sizeof(FIELD));

	while(u != -1){ // enquanto não chegar no inicio vai adcionando o vertice percorrido no vetor
		field->track = (int *) realloc(field->track, sizeof(int)*(field->len+1));
		field->track[field->len++] = u;
		u = check->pred[u];
	}

	for(int i=0,j=field->len-1; i<j; i++, j--){ // invertendo o vetor caminho, pois ele é armazenado ao contrario
		aux = field->track[i];
		field->track[i] = field->track[j];
		field->track[j] = aux;
	}

return field;
}

//////////////////////////////////////////////////////////////////
/*Aloca memoria para a estrutura auxiliar */
CHECK *create_check(int n_vertex){

	CHECK *check = (CHECK *) calloc(1, sizeof(CHECK));

	check->vertex = (int *) calloc(n_vertex, sizeof(int));
	check->color = (int *) calloc(n_vertex, sizeof(int));
	check->dist = (int *) calloc(n_vertex, sizeof(int));
	check->pred = (int *) calloc(n_vertex, sizeof(int));

	for(int i=0; i<n_vertex; i++){
		check->vertex[i] = i;
		check->dist[i] = INT_MAX;
		check->pred[i] = -1;
	}

return check;
}

//////////////////////////////////////////////////////////////////
/*Função que faz a busca em largura em um grafo*/
FIELD *bfs(GRAFO_L *grafo_l, int s, int d){

	int u = 0, v = 0;
	FILA *fila = NULL;
	CHECK *check = NULL;
	NODE *aux = NULL;
	FIELD *field = NULL;

	check = create_check(grafo_l->n_vertices); // alloca a estrutura auxiliar
	check->color[s] = GRAY;						// seta a origem como visitado
	check->dist[s] = 0;							// origem = distancia zero
	check->pred[s] = -1;						// n tem predecessor

	fila = create_fila();						// inicialização da fila
	insere_fila(s, fila);						// enfileiro o vertice origem

	while(!is_empty(fila)){						
		u = remove_fila(fila);
		
		if(u == d){								// se encontrei o destino gero o caminho
			field = generate_field(check, u);
			break;
		}

		aux = obtem_adjacentes_l(grafo_l, u); 
												// senão enfileiro os adjacentes
		while(aux != NULL){						// e marco eles como visitados se não foram
			v = aux->adjacente;					// visitados ainda
			if(check->color[v] == WHITE){
				check->color[v] = GRAY;
				check->dist[v] = check->dist[u] + 1; // a distancia dele é 1 + a do vertice anterior a ele
				check->pred[v] = u;
				insere_fila(v, fila);
			}

			aux = aux->next;
		}
		check->color[u] = BLACK;				// caso já tenha enfileirado os adjacentes ele é finalizado.
	}

	destroy_fila(fila);
	destroy_check(check);

return field;
}
