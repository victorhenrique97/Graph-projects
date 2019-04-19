#include <stdlib.h>
#include <stdio.h>
#include <dfs.h>
#include <TADgrafo-l.h>

int main (int argc, char *argv[]){
	
	int n_vertices, n_arestas, origem, destino;
	GRAFO_L *grafo_l = NULL;
	FIELD *field = NULL;

	scanf("%d%*[ \n]%d%*[ \n]", &n_vertices, &n_arestas);
	grafo_l = cria_grafo_l('D', n_vertices); 		

	for(int i=0; i<n_arestas; i++){							// montando o grafo
		scanf("%d%*[ \n]%d%*[ \n]", &origem, &destino);
		insere_aresta_l(grafo_l, origem, destino, 0);
	}
	while(scanf("%d%*[ \n]%d%*[ \n]", &origem, &destino) != EOF){	// lendo enquanto não acabar o arquivo
		field = dfs(grafo_l, origem, destino);

		if(field){													// caso encontre solução, há a struct field
			for(int i=0; i<field->len; i++)							// nela contem o vetor com os caminhos
					printf("%d ", field->track[i]);
			destroy_field(field);
		}
		
		printf("\n");
	}

	destroy_grafo_l(grafo_l);

	

return 0;
}