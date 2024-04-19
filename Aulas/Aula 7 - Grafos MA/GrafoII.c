/**

    @file      GrafoII.c
    @brief     Lidar com grafos com Matrizes de dimensão variadda
    @details   ~
    @author    Lufer
    @date      19.04.2024
    @copyright © lufer - IPCA 2024. All right reserved.

**/

/*
* Grafos
* lufer
* 
* 
* 
//h1
//int **array = malloc(nrows * sizeof(int *));
//array[i]=(int*)malloc(ncols * sizeof(int));
//usar
//array[i][j]=0;

// h2
//g->adj = (int**)malloc(sizeof(int) * v * v);
//usar
//g->adj[i*v+j] = 0;
*/
#include "GrafoII.h"
#include <malloc.h>

#pragma region h1
/*
* Cria estrutura de grafo e inicializa Matriz de Adjacencias a NULL
*/

GraphII* CriaGraphII() {
	GraphII* aux = (GraphII*)malloc(sizeof(GraphII));
	if (aux != NULL) {
		aux->adj = NULL;
		aux->v = 0;
	}
	return aux;
}

/**
    @brief  Cria Matriz de Adjacências
    @param  g - 
    @param  v - 
    @retval   - 
**/
GraphII* CriaMAGraphII(GraphII* g, int v) {
	//Testes
	if (g == NULL) return g;
	g->adj = (int**)malloc(sizeof(int*) * v);
	if (g->adj == NULL) return NULL;

	for (int i = 0; i < v; i++) {
		g->adj[i] = (int*)malloc(sizeof(int)*v);
		if (g->adj[i] == NULL) return NULL;
	}
	//inicializa
	for (int i = 0; i < v; i++)
		for (int j = 0; j <v; j++)
		{
			g->adj[i][j] = 0;
		}
	g->v = v;
	return g;
}

/**
    @brief  Adiciona nova aresta, grafo não pesado
    @param  g  - 
    @param  v1 - 
    @param  v2 - 
    @retval    - 
**/
GraphII* AddEdgeII(GraphII* g, int v1, int v2) {
	//testes
	g->adj[v1][v2] = 1;
	g->adj[v2][v1] = 1;
	return g;
}

/**
    @brief Mostra grafo
    @param g - 
**/
void ShowMA(GraphII* g) {
	//testes
	for (int i = 0; i < g->v; i++) {
		for (int j = 0; j < g->v; j++) {
			printf("[%d] ", g->adj[i][j]);
		}
		printf("\n");
	}
}

#pragma endregion

#pragma region h2

/**
    @brief  Cria Matriz de Adjacências
    @param  g - 
    @param  v - 
    @retval   - 
**/
GraphII* CriaMAGraphIIh2(GraphII* g, int v) {
	if (g == NULL) return g;

	g->adj = (int**)malloc(sizeof(int) * v * v);
	if (g->adj != NULL) {
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
			{
				g->adj[i * v + j] = 0;
			}
	}
	g->v = v;
	return g;
}

GraphII* AddEdgeIIh2(GraphII* g, int v1, int v2, int numV) {
	g->adj[v1 * numV + v2]= 1;
	g->adj[v2 * numV + v1] = 1;
	return g;
}

void ShowMAh2(GraphII* g) {
	//testes
	for (int i = 0; i < g->v; i++) {
		for (int j = 0; j < g->v; j++) {
			printf("[%d] ", g->adj[i*g->v+j]);
		}
		printf("\n");
	}
}

#pragma endregion

