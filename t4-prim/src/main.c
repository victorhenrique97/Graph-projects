#include <stdlib.h>
#include <stdio.h>
#include <minimaltree.h>
#include <TADgrafo-l.h>
#include <utils.h>

int main (int argc, char *argv[]){
		
	int n_vertices, n_arestas, origem, destino, peso;
	GRAFO_L *grafo_l = NULL;
	

	scanf("%d%*[ \n]%d%*[ \n]", &n_vertices, &n_arestas);
	grafo_l = cria_grafo_l('G', n_vertices);	

	for(int i=0; i<n_arestas; i++){							// montando o grafo
		scanf("%d%*[ \n]%d%*[ \n]%d%*[ \n]", &origem, &destino, &peso);
		insere_aresta_l(grafo_l, origem, destino, peso);
	}

	minimal_tree(grafo_l);
	destroy_grafo_l(grafo_l);

return 0;
}