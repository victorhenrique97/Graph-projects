#include <TADgrafo-l.h>

////////////////////////////////////////////////////////////////////
/*Função que imprime os vertices cuja aresta adjacente possui menor peso*/
void imprime_menor_peso_l(GRAFO_L *grafo_l){

	int vertice1 = 0, vertice2 = 0, peso = INT_MAX;
	NODE *aux = NULL;

	for(int i=0; i < grafo_l->n_vertices; i++){
		aux = grafo_l->vertice[i]; // percorrendo as linhas

		while(aux!= NULL){
			if(aux->peso < peso){
				peso = aux->peso;
				vertice1 = i;
				vertice2 = aux->adjacente;
			}
			aux = aux->next; // percorrendo as colunas
		}
	}

	if (grafo_l->tipo == 'D' || (grafo_l->tipo == 'G' && vertice1 < vertice2)) // impressão ordenada
		printf("%d %d\n", vertice1, vertice2);
	else
		printf("%d %d\n", vertice2, vertice1);
}
/////////////////////////////////////////////////////////////////////
/*Função que desaloca memoria usada em uma lista*/
void destroy_lista(NODE *node){

	if(!node) return;
	destroy_lista(node->next);
	free(node);
}
/////////////////////////////////////////////////////////////////////
/*Função que desaloca memória alocada pelo grafo*/
void destroy_grafo_l(GRAFO_L *grafo_l){

	if(!grafo_l) return;

	for(int i=0; i<grafo_l->n_vertices; i++){
		destroy_lista(grafo_l->vertice[i]);
	}

	free(grafo_l->vertice);
	free(grafo_l);

}
/////////////////////////////////////////////////////////////////////
/*Função que imprime uma lista com os vertices adjacentes a determinado
vertice, bem como o peso dessas arestas*/
void imprime_lista(NODE *node){

	if(!node) return;
	else {
		printf("%d(%d) ", node->adjacente, node->peso);
		imprime_lista(node->next);
	}
}
/////////////////////////////////////////////////////////////////////
/*Função que imprime o grafo*/
void imprime_grafo_l(GRAFO_L *grafo_l){

	NODE *node  = NULL;

	for(int i=0; i<grafo_l->n_vertices; i++){
		printf("%d. ", i);
		node = obtem_adjacentes_l(grafo_l, i);
		imprime_lista(node);
		printf("\n");	
	}
}
////////////////////////////////////////////////////////////////////////
/*Função que retorna uma lista transposta com os vertices correspondentes*/
GRAFO_L *gera_transposta_l(GRAFO_L *grafo_l){

	GRAFO_L *grafo_l_t = NULL;
	NODE *aux = NULL;

	grafo_l_t = cria_grafo_l(grafo_l->tipo, grafo_l->n_vertices);

	for(int i=0; i<grafo_l->n_vertices; i++){
		aux = grafo_l->vertice[i];
		while(aux){
			insere_aresta_l(grafo_l_t, aux->adjacente, i, aux->peso);
			aux = aux->next;
		}
	}

return grafo_l_t;
}
////////////////////////////////////////////////////////////////////////
/*Função que imprime a transposta*/
void imprime_transposta_l(GRAFO_L *grafo_l){

	if(grafo_l->tipo == 'G') return;
	GRAFO_L *grafo_l_t = gera_transposta_l(grafo_l);
	imprime_grafo_l(grafo_l_t);
	destroy_grafo_l(grafo_l_t);

}
/////////////////////////////////////////////////////////////////////////
/*Função que remove uma aresta do grafo*/
void remove_aresta_l(GRAFO_L *grafo_l, int origem, int destino){

	NODE *node_aux = NULL, *node_aux2 = NULL;
	int counter = 0, aux;

	if(grafo_l->tipo == 'D') counter++;

	while(counter < 2){
		node_aux = grafo_l->vertice[origem];
	
			if(node_aux && node_aux->adjacente == destino){ // A B C remove A
				node_aux2 = node_aux;
				grafo_l->vertice[origem] = node_aux2->next;
				free(node_aux2);
				grafo_l->n_arestas--;
			}
	
			else {
				while(node_aux->next->adjacente < destino)
					node_aux = node_aux->next;

				if(node_aux->next->adjacente == destino){ // A B C remove B ou C
					node_aux2 = node_aux->next;
					node_aux->next = node_aux2->next;
					free(node_aux2);
					grafo_l->n_arestas--;
				}
			}

		counter++;
		aux = origem;
		origem = destino;
		destino = aux;
	}
}
/////////////////////////////////////////////////////////////////////
/*Função que imprime os nós adjacentes*/
void imprime_lista2(NODE *node){

	if(!node) return;
	printf("%d ", node->adjacente);
	imprime_lista2(node->next);
}
/////////////////////////////////////////////////////////////////////
/*Função que obtem os nós adjacentes*/
NODE *obtem_adjacentes_l(GRAFO_L *grafo_l, int pos){

return grafo_l->vertice[pos];
}
/////////////////////////////////////////////////////////////////////
/*Função que imprime os vertices adjacentes a determinado vertice*/
void imprime_adjacentes_l(GRAFO_L *grafo_l, int pos){

	NODE *node = obtem_adjacentes_l(grafo_l, pos);
	imprime_lista2(node);
	printf("\n");
}

////////////////////////////////////////////////////////////////////////
/*Função que aloca memória para um determinado vertice*/
NODE *create_node(int destino, int peso){

		NODE *node = (NODE *) calloc(1, sizeof(NODE));
		node->adjacente = destino;
		node->peso = peso;

return node;
}
/////////////////////////////////////////////////////////////////////
/*Função que faz a inserção em uma lista*/
void insere_aresta_l(GRAFO_L *grafo_l, int origem, int destino, int peso){

	int counter = 0, aux;
	NODE *node_aux = NULL, *node_aux2 = NULL;

	if(grafo_l->tipo == 'D') counter++;

	while(counter < 2){
		
		node_aux = grafo_l->vertice[origem];

		if(!node_aux || node_aux->adjacente > destino){ // B C insere A
			node_aux2 = create_node(destino, peso); 
			node_aux2->next = node_aux; 
			grafo_l->vertice[origem] = node_aux2;
			grafo_l->n_arestas++;
		}

		else if(node_aux->adjacente == destino) // A B C atualiza valor de A
			node_aux->peso = peso;
			
		else{
			while(node_aux->next && node_aux->next->adjacente < destino)
				node_aux = node_aux->next;
			
			if(node_aux->next && node_aux->next->adjacente == destino)
				node_aux->next->peso = peso; // A B C atualiza valor de B ou C
				
			else {
				node_aux2 = create_node(destino, peso); // A C insere B ou A B insere C
				node_aux2->next = node_aux->next;
				node_aux->next = node_aux2;
				grafo_l->n_arestas++;
			}
		}		

		counter++;
		aux = origem;
		origem = destino;
		destino = aux;
	}
}
/////////////////////////////////////////////////////////////////////
/*Função que retorna um ponteiro para uma região de memória 
designada para o grafo*/
GRAFO_L *cria_grafo_l(char tipo, int n_vertices){

	GRAFO_L *grafo_l = (GRAFO_L *) calloc(1, sizeof(GRAFO_L));
	grafo_l->vertice = (NODE **) calloc(n_vertices, sizeof(NODE *));
	grafo_l->tipo = tipo;
	grafo_l->n_vertices = n_vertices;

return grafo_l;
}







