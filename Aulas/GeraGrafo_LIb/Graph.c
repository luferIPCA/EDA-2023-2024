/**

    @file      Graph.c
    @brief     Grafos: Manipulação de Grafos com Matriz de Adjacências
    @details   Biblioteca
    @author    lufer
    @date      1.05.2024
    @copyright © lufer - IPCA 2024. All right reserved.
**/


#include <stdio.h>  //NULL
#include <stdlib.h> //free
#include <malloc.h> //malloc
#include "Graph.h"

//======================================================
//graph functions 
//======================================================


/**
    @brief - Mostra dados do vertice do grafo
    @param v - Vertice
    @date  3.05.2024
**/
void ProcessaVertice(Vertice* v) {
    //testar
    printf("%c ", v->label);
}

/**
	@brief  Aloca espaço suficiente para a matriz adjacente
	@param  numVertices - total de vertices a suportar
	@retval             -
	@date   3.05.2024
**/
int** CriaInicializaMatrizAdjacencias(int numVertices) {
	//array bidimensional
	int** matriz = (int**)calloc(sizeof(int*), numVertices);
	if (matriz == NULL) return NULL;
	for (int i = 0; i < numVertices; i++)
	{
		//colunas para cada linha
		matriz[i] = (int*)calloc(numVertices, sizeof(int));
		if (matriz[i] == NULL) return NULL;
	}
	return matriz;
}

/**
    @brief  Cria grafo e inicializa estruturas
    @param  numVertices - 
    @param  res         - 
    @retval             - 
    @date   3.05.2024
**/
Grafo* CriaGrafo(int numVertices, bool* res) {
	Grafo* g = (Grafo*)calloc(1, sizeof(Grafo));
	if (g != NULL) {
		g->adj = CriaInicializaMatrizAdjacencias(numVertices);			//matriz
		g->vertices = (Vertice*)calloc(numVertices, sizeof(Vertice));	//array
		*res = true;
		return g;
	}
	*res = false;
	return NULL;
}

/**
    @brief  Acrescenta aresta
    @param  adj - 
    @param  v1  - 
    @param  v2  - 
    @retval     - 
    @date   3.05.2024
**/
bool AddAresta(int** adj, int v1, int v2) {
	adj[v1][v2] = 1;
	return true;
}

/**
	@brief  adicionar vertice à "list" (array) de vertices
	@param  lstVertices -
	@param  numVertices -
	@param  label       -
	@retval             -
	@date   3.05.2024
**/
int AddVertice(Vertice* lstVertices, int numVertices, char label) {
	//assert(se vertice ainda não existe) && (Há espaço)
	Vertice* newVertice = (Vertice*)calloc(1, sizeof(Vertice));
	if (newVertice != NULL) {
		newVertice->label = label;
		newVertice->visited = false;
		lstVertices[numVertices] = *newVertice;
		numVertices++;
	}
	return numVertices;
}


/**
	@brief Apresenta grafo
	@param lst -
	@param adj -
	@param v   -
	@date  30.04.2024
**/
void ShowGraph(Vertice* lst, int** adj, int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		ProcessaVertice(&lst[i]);
		printf("Adjacentes:\n");
		for (int j = 0; j < numVertices; j++) {
			if (adj[i][j] != 0) {
				printf("\tVertice: %c: Peso:%d\n", (lst + j)->label, adj[i][j]);
			}
		}
	}
}

/**
	@brief  Apresenta toda a matriz de adjacencias
	@param adj       -
	@param nVertices -
	@date  3.05.2024
**/
void ShowArestas(int** adj, int nVertices) {
	for (int i = 0; i < nVertices; i++) {
		for (int j = 0; j < nVertices; j++)
			printf("%d ", adj[i][j]);
		printf("\n");
	}
}
