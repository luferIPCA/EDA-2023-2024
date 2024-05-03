/*
// Grafos: Fundamentos
//
// lufer
*/
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>	// ASCII SET

#include "Graph.h"


int main() {
	setlocale(LC_ALL, "Portuguese");

	//Queue variables 

	int queue[MAX];
	int rear = -1;
	int front = 0;
	int queueItemCount = 0;


	//=============
	//BFT
    //=============


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
	numVertices = AddVertice(lstVertices, numVertices, 'C');
	numVertices = AddVertice(lstVertices, numVertices, 'D');

	numVertices = AddVertice(lstVertices, numVertices, 'E');
	numVertices = AddVertice(lstVertices, numVertices, 'F');

	AddAresta(adjMatrix, 1, 2);
	AddAresta(adjMatrix, 1, 3);
	AddAresta(adjMatrix, 1, 4);
	AddAresta(adjMatrix, 2, 3);
	AddAresta(adjMatrix, 4, 1);
	AddAresta(adjMatrix, 0, 1);
	AddAresta(adjMatrix, 0, 5);

	printf("\nGraph:\n");
	ShowGraph(lstVertices, adjMatrix, numVertices);

	printf("\nTravessia Breadth First: \n"); 
	BreadthFirstTraversal(lstVertices, adjMatrix,0);

	//repõe o estado de cada vertice         
	bool succ=resetVertices(lstVertices, numVertices);
	//if (!succ)
	succ =  BreadthFirstSearch(lstVertices, adjMatrix, 0, 3);
	printf("\nExiste caminho entre %c e %c: %s\n", lstVertices[0]->label, lstVertices[3]->label, (succ==true ? "Sim": "não"));

	system("pause");
	return 0;
} 
