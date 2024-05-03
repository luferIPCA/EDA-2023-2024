#pragma once

/*
// Grafos Não Orientados | Orientados
//
// Procura em Largura:		Queue
// lufer
// Consultar: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
*/


#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct Vertice {
	char label;
	bool visited;
}Vertice;


//Graph functions

int AddVertice(Vertice* lstVertices[], int numVertices, char label);
bool AddAresta(int adjMatrix[][MAX], int start, int end);
void ProcessaVertice(Vertice* v);
int GetVertAdjNaoVisitado(Vertice* lstVertices[], int adjMatriz[][MAX], int vOrigin);
void ShowGraph(Vertice* lst[], int adj[][MAX], int v);

// =====================================================
// Breadth First Traversal/Search Algorithm (BFT/BFS)
// =====================================================

bool BreadthFirstTraversal(Vertice* lstVertices[], int adj[][MAX], int vOrigin);
/*BreadthFirstTraversalRec
* see https://www.techiedelight.com/breadth-first-search/
*/
bool BreadthFirstSearch(Vertice* lstVertices[], int adj[][MAX], int vOrigin, int valor);
//auxiliar
bool resetVertices(Vertice* lstVertices[], int numVertices);



