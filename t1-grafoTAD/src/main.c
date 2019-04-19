#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <TADgrafo-m.h>
#include <TADgrafo-l.h>

int main(int argc, char *argv[]){

	GRAFO_M *grafo_m = NULL;
	GRAFO_L *grafo_l = NULL;
	int n_vertices, n_arestas, origem, destino, peso;
	char grafo_tipo, tad_tipo;
	char *cmd;
	

	scanf("%c%*[ \n]%c%*[ \n]%d%*[ \n]%d%*[ \n]", &grafo_tipo, &tad_tipo, &n_vertices, &n_arestas);

	if(tad_tipo == 'M')
		grafo_m = cria_grafo_m(grafo_tipo, n_vertices, 0);
	

	else if(tad_tipo == 'L') 
		grafo_l = cria_grafo_l(grafo_tipo, n_vertices);
	

	for(int i=0; i<n_arestas; i++){
		scanf("%d %d %d%*[ ]", &origem, &destino, &peso);
		if(tad_tipo == 'M') insere_aresta_m(grafo_m, origem, destino, peso);
		else if(tad_tipo == 'L') insere_aresta_l(grafo_l, origem, destino, peso);	
	}

	while(scanf("%ms%*[ \n]", &cmd) != EOF){

		if(!strcmp(cmd,"IG")){
			if(tad_tipo == 'M') imprime_grafo_m(grafo_m);
			else if (tad_tipo == 'L') imprime_grafo_l(grafo_l);
		}

		else if(!strcmp(cmd,"VA")){
			scanf("%d%*[ \n]", &origem);
			if(tad_tipo == 'M') imprime_adjacentes_m(grafo_m, origem);
			else if (tad_tipo == 'L') imprime_adjacentes_l(grafo_l, origem);
		}

		else if(!strcmp(cmd, "AA")){
			scanf("%d %d %d%*[ \n]", &origem, &destino, &peso);
			if(tad_tipo == 'M') insere_aresta_m(grafo_m, origem, destino, peso);
			else if (tad_tipo == 'L') insere_aresta_l(grafo_l, origem, destino, peso);
		}

		else if(!strcmp(cmd, "RA")){
			scanf("%d %d%*[ \n]", &origem, &destino);
			if(tad_tipo == 'M') remove_aresta_m(grafo_m, origem, destino);
			else if (tad_tipo == 'L') remove_aresta_l(grafo_l, origem, destino);
		}

		else if(!strcmp(cmd, "IT")){
			if(tad_tipo == 'M') imprime_transposto_m(grafo_m);
			else if (tad_tipo == 'L') imprime_transposta_l(grafo_l);
		}

		else if(!strcmp(cmd, "MP")){
			if(tad_tipo == 'M') imprime_menor_peso_m(grafo_m);
			else if (tad_tipo == 'L') imprime_menor_peso_l(grafo_l);
		}

		free(cmd);
	}

	destroi_grafo_m(grafo_m);
	destroy_grafo_l(grafo_l);


return 0;
}
