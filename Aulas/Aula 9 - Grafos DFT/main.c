/*
// Grafos: Fundamentos
// DFT | DFS
// lufer
*/
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>	// ASCII SET

#include "Graphs.h"
#include "Stack.h"


int main() {
	setlocale(LC_ALL, "Portuguese");

	//Stack auxiliar
	int stack[MAX];
	int top = -1;

	//"Lista" de vértices 
	Vertice* lstVertices[MAX];

	//matriz de adjacências
	int adjMatrix[MAX][MAX];

	//inicializa matriz de adjacencias
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			adjMatrix[i][j] = 0;

	int numVertices = AddVertice(lstVertices, 0, 'A');
	numVertices = AddVertice(lstVertices, numVertices, 'B');
	numVertices = AddVertice(lstVertices, numVertices, 'D');
	numVertices = AddVertice(lstVertices, numVertices, 'C');
	numVertices = AddVertice(lstVertices, numVertices, 'E');
	numVertices = AddVertice(lstVertices, numVertices, 'F');

	AddAresta(adjMatrix, 1, 2);
	AddAresta(adjMatrix, 1, 3);
	AddAresta(adjMatrix, 1, 4);
	AddAresta(adjMatrix, 2, 3);
	AddAresta(adjMatrix, 4, 1);
	AddAresta(adjMatrix, 0, 1);
	AddAresta(adjMatrix, 0, 5);

	ShowGraph(lstVertices, adjMatrix, numVertices);

	printf("\nTravessia Depth First: \n"); 
	DepthFirstTraversal(lstVertices, adjMatrix, 0);

	//Repõe o estado de cada vertice         
	for (int i = 0; i < numVertices; i++) {
		lstVertices[i]->visited = false;
	}

	printf("\nTravessia Depth First Recursiva: \n");
	DepthFirstTraversalRec(lstVertices, adjMatrix, 0);
	
	bool b = DepthFirstSearchRec(lstVertices,adjMatrix,2,5);
	printf("\nExiste caminho entre %d e %d: %s \n", 2, 5,(b==true)?"Sim":"Não");

	top = -1;
	b = DepthFirstSearch(lstVertices, adjMatrix, 0, 4);
	printf("\nExiste caminho entre %d e %d: %s \n", 0, 4, (b == true) ? "Sim" : "Não");
 
	return 0;
} 
