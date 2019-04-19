#include <utils.h>

/////////////////////////////////////////////////////////////////
/*Libera a memória alocada para a struct com os caminhos */
void destroy_field(FIELD *field){

	if(!field) return;
	if(field->track)
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

	if(field)
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
	free(check->dist);
	free(check->pred);
	free(check);

}
///////////////////////////////////////////////////////////////
/*Cria a estrutura auxiliar que guarda predecessores, distancia e o vertice*/
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
////////////////////////////////////////////////////////////////
/*Função que extrai o menor valor de um vetor que nao foi usado ainda (cinza)*/
int pega_minimo(CHECK *check, int n_elem){

	int aux = INT_MAX;
	int pos = -1;

	for(int i=0; i<n_elem; i++)
		if(check->color[i] == GRAY && check->dist[i] < aux){
			aux = check->dist[i];
			pos = i;
		}

return pos;
}