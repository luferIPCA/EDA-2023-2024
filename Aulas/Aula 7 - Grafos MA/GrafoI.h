#pragma once
/*
* Grafos com Matrizes de Adjacências
* Assinatura de funções
* 
* =========================================================
* a) Grafo orientado, não pesado
* b) Grafo orientado e pesado
* c) Grafo não orientado e pesado
* d) Grafo não orientado e não pesado
*=========================================================
*/
#include <stdbool.h>
#define NUMVERTICES 20
#define N 20


#pragma region Grafo - Estático

// Matriz de Adjacências
// h1: estrutura estática

bool CreateMA(int m[][NUMVERTICES], int totVertices);
bool AddEdge(int m[][NUMVERTICES], int v1, int v2, int w);	//grafo pesado
//bool addEdge(int m[][NUMVERTICES], int v1, int v2);		//grafo não pesado				//grafo não pesado
bool ExistEdge(int m[][NUMVERTICES], int v1, int v2);
bool GetEdgeWeight(int m[][NUMVERTICES], int v1, int v2, int*w);

//Vertices
typedef struct Vertice Vertice;

struct Vertice{
	int valor;	//valor do vértice
};

bool NovoVertice(Vertice v[], int *totVertices, Vertice novo);

//Grafo
typedef struct Grafo {
	int totVertices;					//Número de vertices
	int adj[NUMVERTICES][NUMVERTICES];	//Matrix Adj
	Vertice vertices[NUMVERTICES];		//vertices
}Grafo;

bool InicializaVertices(Vertice v[], int *totVertices);
Grafo* CriaGrafo(int totVertices);
Grafo* NovaAresta(Grafo* g, Vertice v1, Vertice v2, int p);
int QualPesoAresta(Grafo* g, int v1, int v2);

#pragma endregion


