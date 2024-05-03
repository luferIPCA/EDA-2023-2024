#pragma once
/*
// Grafos Não Orientados | Orientados
//
// Procura em Profundidade: Stack
// Procura em Largura:		Queue
// lufer
*/

#include <stdio.h>
#include <stdbool.h>


#define MAX 10

typedef struct Vertice {
	char label;
	bool visited;
	//int totAdjacencias;
}Vertice;

//graph functions

int AddVertice(Vertice* lstVertices[], int numVertices, char label);
bool AddAresta(int adjMatrix[][MAX], int start, int end);
void ProcessaVertice(Vertice* v);
int GetVertAdjNaoVisitado(Vertice* lstVertices[], int adjMatriz[][MAX], int vOrigin);
void ShowGraph(Vertice* lst[], int adj[][MAX], int v);

#pragma region DFT

//DFT|DFS
bool DepthFirstSearchRec(Vertice* lstVertices[], int adj[][MAX], int vOrigin, int valor);
bool DepthFirstSearch(Vertice* lstVertices[], int adj[][MAX], int vOrigin, int vertice);
bool DepthFirstTraversal(Vertice* lstVertices[], int adj[][MAX], int vOrigin);
bool DepthFirstTraversalRec(Vertice* lstVertices[], int adj[][MAX], int vOrigin);

#pragma endregion



