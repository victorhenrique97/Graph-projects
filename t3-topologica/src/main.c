#include <stdlib.h>
#include <stdio.h>
#include <dfs.h>
#include <TADlista.h>
#include <TADgrafo-l.h>

int main (int argc, char *argv[]){
	
	int n_vertices, n_arestas, origem, destino;
	GRAFO_L *grafo_l = NULL;
	LISTA *l = NULL;

	scanf("%d%*[ \n]%d%*[ \n]", &n_vertices, &n_arestas);
	grafo_l = cria_grafo_l('D', n_vertices);
	l = create_list();		

	for(int i=0; i<n_arestas; i++){							// montando o grafo
		scanf("%d%*[ \n]%d%*[ \n]", &origem, &destino);
		insere_aresta_l(grafo_l, origem, destino, 0);
	}
	
	ordenacao_topologica(grafo_l, n_vertices, l);

	while(!is_empty_list(l))
		printf("%d ", remove_primeiro(l));
	printf("\n");	

	if(l) destroy_list(l);
	destroy_grafo_l(grafo_l);

return 0;
}