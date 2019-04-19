#include <stdio.h>
#include <TADgrafo-l.h>
#include <utils.h>
#include <dijkstra.h>

int main (int argc, char *argv[]){
		
	int n_vertices, n_arestas, origem, destino, peso;
	GRAFO_L *grafo_l = NULL;
	FIELD *field = NULL;

	scanf("%d%*[ \n]%d%*[ \n]", &n_vertices, &n_arestas);
	grafo_l = cria_grafo_l('D', n_vertices);	

	for(int i=0; i<n_arestas; i++){							// montando o grafo
		scanf("%d%*[ \n]%d%*[ \n]%d%*[ \n]", &origem, &destino, &peso);
		insere_aresta_l(grafo_l, origem, destino, peso);
	}

	while(scanf("%d%*[ \n]%d%*[ \n]", &origem, &destino) != EOF){
		field = dijkstra(grafo_l, origem, destino);					// chamo o algoritmo que gera o caminho minimo

		if(field){
			if(field->track[field->len-1] == destino && field->track[0] == origem) // caso nao encontre caminho entre origem e destino nao imprimo
				for(int i=0; i<field->len; i++)							
					printf("%d ", field->track[i]);
			printf("\n");
			destroy_field(field);
		}	
	}
	destroy_grafo_l(grafo_l);
return 0;
}