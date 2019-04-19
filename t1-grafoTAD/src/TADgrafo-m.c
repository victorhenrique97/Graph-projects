#include <TADgrafo-m.h>

//////////////////////////////////////////////////////////////////
/*Função que cria um grafo, ela pode ou não já alocar uma matriz 
com -1 em todas as posições*/
GRAFO_M *cria_grafo_m(char tipo, int n_vertices, int flag){

	GRAFO_M *grafo_m = (GRAFO_M *) calloc(1, sizeof(GRAFO_M));
	grafo_m->n_vertices = n_vertices;
	grafo_m->tipo = tipo;

	if(flag == 0){ 
		grafo_m->matriz = alloca_matriz(n_vertices, n_vertices);
		seta_matriz(grafo_m->matriz, n_vertices, n_vertices);
	}

return grafo_m;
}
//////////////////////////////////////////////////////////////////
/*Função que faz a inserção de uma aresta no grafo*/
void insere_aresta_m(GRAFO_M *grafo_m, int origem, int destino, int peso){

		if(grafo_m->n_vertices < origem -1) return;

		grafo_m->matriz[origem][destino] = peso;
		grafo_m->n_arestas++;

		if(grafo_m->tipo == 'G') // caso seja grafo preciso espelhar
			grafo_m->matriz[destino][origem] = peso;
}
////////////////////////////////////////////////////////////////////
/*Funçao que faz a remoção de uma aresta*/
void remove_aresta_m(GRAFO_M *grafo_m, int origem, int destino){

	if(grafo_m->n_vertices < origem -1) return;

	grafo_m->matriz[origem][destino] = -1;
	grafo_m->n_arestas--;

	if(grafo_m->tipo == 'G') // caso seja um grafo, preciso remover o espelhamento
			grafo_m->matriz[destino][origem] = -1;
			
}
/////////////////////////////////////////////////////////////////////
/*Função que imprime o grafo*/
void imprime_grafo_m(GRAFO_M *grafo_m){

	imprime_matriz(grafo_m->matriz, grafo_m->n_vertices, grafo_m->n_vertices);
}

//////////////////////////////////////////////////////////////////////
/*Função que gera o grafo transposto*/
GRAFO_M *gera_transposto_m(GRAFO_M *grafo_m){

	GRAFO_M *grafo_mt = NULL;
	
	grafo_mt = cria_grafo_m(grafo_m->tipo, grafo_m->n_vertices, -1);
	grafo_mt->matriz = matriz_transposta(grafo_m->matriz, grafo_m->n_vertices, grafo_m->n_vertices);

return grafo_mt;
}

//////////////////////////////////////////////////////////////////////
/*Função que retorna um vetor ordenado dentro de uma struct com os 
vertices adjacentes ordenados */
ADJACENTES_G *retorna_adjacentes_m(GRAFO_M *grafo_m, int pos){

	int n_vertices;
	ADJACENTES_G *adjacentes_g = (ADJACENTES_G *) calloc(1, sizeof(ADJACENTES_G));

	n_vertices = grafo_m->n_vertices;

	for(int i=0; i<n_vertices; i++)
		if (grafo_m->matriz[pos][i] != -1){
			adjacentes_g->adjacentes = (int *) realloc(adjacentes_g->adjacentes, sizeof(int)*((adjacentes_g->n_adjacentes)+1));
			adjacentes_g->adjacentes[adjacentes_g->n_adjacentes++] = i;
		}

	qsort(adjacentes_g->adjacentes, adjacentes_g->n_adjacentes, sizeof(int), (void *)int_compare); // ordenação
	
return adjacentes_g;	
}
////////////////////////////////////////////////////////////////////////
/*Função que imprime a aresta de menor peso*/
void imprime_menor_peso_m(GRAFO_M *grafo_m){

	int vertice1 = 0, vertice2 = 0, peso = INT_MAX, n_vertices;

	n_vertices = grafo_m->n_vertices;

	for(int i=0; i<n_vertices; i++)
		for(int j=0; j<n_vertices; j++) // obtendo os vertices...
			if(grafo_m->matriz[i][j] < peso && grafo_m->matriz[i][j] != -1){
				peso = grafo_m->matriz[i][j];
				vertice1 = i;
				vertice2 = j;
			}

	if(grafo_m->tipo == 'D' || (grafo_m->tipo == 'G' && vertice1 < vertice2)){ // correção para impressão crescente
		printf("%d %d\n", vertice1, vertice2);
	} else printf("%d %d\n", vertice2, vertice1);
}

///////////////////////////////////////////////////////////////////////
/*Função que desaloca a memória alocada para representar o grafo*/
void destroi_grafo_m(GRAFO_M *grafo_m){

	if(!grafo_m)return;

	free_matriz(grafo_m->matriz, grafo_m->n_vertices);
	free(grafo_m);
}
//////////////////////////////////////////////////////////////////////
/*Função que pega o vetor de adjacentes e imprime o mesmo*/
void imprime_adjacentes_m(GRAFO_M *grafo_m, int pos){

	ADJACENTES_G *adjacentes_g = NULL;
	
	adjacentes_g = retorna_adjacentes_m(grafo_m, pos);
	
	for(int i=0; i<adjacentes_g->n_adjacentes; i++)
		printf("%d ", adjacentes_g->adjacentes[i]);
	printf("\n");

	if(adjacentes_g->adjacentes) free(adjacentes_g->adjacentes);
	if(adjacentes_g) free(adjacentes_g);
}
/////////////////////////////////////////////////////////////////////
/*Função que pega a transposta e imprime ela*/
void imprime_transposto_m(GRAFO_M *grafo_m){

	GRAFO_M *grafo_mt = NULL;

	if(grafo_m->tipo == 'G') return;
	grafo_mt = gera_transposto_m(grafo_m);
	imprime_grafo_m(grafo_mt);
	destroi_grafo_m(grafo_mt);
}

