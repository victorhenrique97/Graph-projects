#include <dfs.h>

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
/*Libera a memoria alocada pela estrutura auxiliar*/
void destroy_check(CHECK *check){

	if(!check) return;

	free(check->vertex);
	free(check->color);
	free(check->time1);
	free(check->time2);
	free(check->pred);
	free(check);

}
//////////////////////////////////////////////////////////////////
/*Aloca memoria para a estrutura auxiliar */
CHECK *create_check(int n_vertex){

	CHECK *check = (CHECK *) calloc(1, sizeof(CHECK));

	check->vertex = (int *) calloc(n_vertex, sizeof(int));
	check->color = (int *) calloc(n_vertex, sizeof(int));
	check->time1 = (int *) calloc(n_vertex, sizeof(int));
	check->time2 = (int *) calloc(n_vertex, sizeof(int));
	check->pred = (int *) calloc(n_vertex, sizeof(int));

	for(int i=0; i<n_vertex; i++){
		check->vertex[i] = i;
		check->pred[i] = -1;
	}

return check;
}

//////////////////////////////////////////////////////////////////
/*Função que faz a busca recursiva */
void ordenacao_topologica2(GRAFO_L *grafo_l, CHECK *check, int u, int *time, LISTA *l){

	NODE *aux = NULL;
	int v = 0;

	(*time)++;						
	check->color[u] = GRAY;
	check->time1[u] = (*time);				// tempo inicial

	aux = obtem_adjacentes_l(grafo_l, u);

	while(aux != NULL){						
			v = aux->adjacente;					
			if(check->color[v] == WHITE){ 					// caso eu não tenha visitado eu
				check->pred[v] = u;		  					// coloco o atual como pred de v 
				ordenacao_topologica2(grafo_l, check, v, time, l); 	// faço a busca em v 	
			}												
			aux = aux->next;
	}

	check->color[u] = BLACK;
	insere_list(u, l);									// finalizo o nó
	(*time)++;
	check->time2[u] = (*time);									// tempo final

}
//////////////////////////////////////////////////////////////////
/*Função incial da busca topologica, recebe o grafo e o numero de vertices */
void ordenacao_topologica(GRAFO_L *grafo_l, int n_vertex, LISTA *l){

	int time = 0;
	CHECK *check = NULL;

	check = create_check(grafo_l->n_vertices);
	for(int i=0; i<n_vertex; i++){			// chamo a dfs para todos os vertices
		if(check->color[i] == WHITE)
			ordenacao_topologica2(grafo_l, check, i, &time, l); // chamo recursivamente a função que faz a busca
	}

	destroy_check(check);

}

//////////////////////////////////////////////////////////////////
/*Função que faz a busca recursiva */
FIELD *dfs_2(GRAFO_L *grafo_l, CHECK *check, int u, int d, int time){

	NODE *aux = NULL;
	FIELD *field = NULL;
	int v = 0;

	time++;						
	check->color[u] = GRAY;
	check->time1[u] = time;				// tempo inicial

	if(u == d){
		field = generate_field(check, u);	// encontrei o destino gero o caminho
		return field;
	}

	aux = obtem_adjacentes_l(grafo_l, u);

	while(aux != NULL){						
			v = aux->adjacente;					
			if(check->color[v] == WHITE){ 					// caso eu não tenha visitado eu
				check->pred[v] = u;		  					// coloco o atual como pred de v 
				field = dfs_2(grafo_l, check, v, d, time); 	// faço a busca em v 
				if(field) break; 							// se eu já tiver encontrado
			}												// eu não percorro mais nada
			aux = aux->next;
	}

	check->color[u] = BLACK;								// finalizo o nó
	time++;
	check->time2[u] = time;									// tempo final

return field;												// retorno o vetor de caminhos
}
//////////////////////////////////////////////////////////////////
/*Função incial da busca em profundidade, recebe o grafo, a origem
e o destino */
FIELD *dfs(GRAFO_L *grafo_l, int s, int d){

	int time = 0;
	CHECK *check = NULL;
	FIELD *field = NULL;

	check = create_check(grafo_l->n_vertices);
	field = dfs_2(grafo_l, check, s, d, time); // chamo recursivamente a função que faz a busca
	destroy_check(check);

return field;
}
////////////////////////////////////////////////////////////////