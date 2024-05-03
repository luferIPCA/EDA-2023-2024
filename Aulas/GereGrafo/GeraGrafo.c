/**

	@file      GeraGrafo.c
	@brief     Aplicação que utiliza uma biblioteca para gerir Grafos
	@details   ~
	@author    lufer
	@date      3.05.2024
	@copyright © lufer - IPCA 2024. All right reserved.

**/

#pragma region ARRAYS_REVIEW


//see 
// https://www.scaler.com/topics/c/pass-array-to-function-in-c/
// https://www.skillvertex.com/blog/how-to-pass-a-2d-array-as-a-parameter-in-c/

void print_array(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
		// or printf("%d ", *(arr + i)); //*(arr + i)==arr[i]
		//or printf("%d ", *arr); arr++;	
	}
	printf("\n");
}

#define N 10
void print_2D(int(*arr)[N])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			printf("%d ", arr[i][j]);
}


void print_2D_array(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
}

#pragma endregion

#include "Graph.h"
#pragma comment(lib,"Graph.lib")

#include<stdio.h>
#include <stdbool.h>
#include <malloc.h>


int main() {

	bool succ;
	int numVertices = 10;

	Grafo* grafo = CriaGrafo(numVertices, &succ);
	//Vertice* grafo = (Vertice*)calloc(numVertices, sizeof(Vertice));        //array

	//int** adj = CriaGrafo(numVertices, &succ);                              //matriz

	int numv = 0;
	numv = AddVertice(grafo->vertices, numv, 'P');		//0
	numv = AddVertice(grafo->vertices, numv, 'L');		//1

	succ = AddAresta(grafo->adj, 0, 1);
	succ = AddAresta(grafo->adj, 1, 0);

	ShowArestas(grafo->adj, numv);

	ShowGraph(grafo->vertices, grafo->adj, numv);


}