#pragma once
/*
* Grafos com Matrizes de Adjac�ncias
* Assinatura de fun��es
* 
* =========================================================
* a) Grafo orientado, n�o pesado
* b) Grafo orientado e pesado
* c) Grafo n�o orientado e pesado
* d) Grafo n�o orientado e n�o pesado
*=========================================================
*/
#include <stdbool.h>
#define NUMVERTICES 20
#define N 20


#pragma region Grafo - Est�tico

// Matriz de Adjac�ncias
// h1: estrutura est�tica

bool CreateMA(int m[][NUMVERTICES], int totVertices);
bool AddEdge(int m[][NUMVERTICES], int v1, int v2, int w);	//grafo pesado
//bool addEdge(int m[][NUMVERTICES], int v1, int v2);		//grafo n�o pesado				//grafo n�o pesado
bool ExistEdge(int m[][NUMVERTICES], int v1, int v2);
bool GetEdgeWeight(int m[][NUMVERTICES], int v1, int v2, int*w);

//Vertices
typedef struct Vertice Vertice;

struct Vertice{
	int valor;	//valor do v�rtice
};

bool NovoVertice(Vertice v[], int *totVertices, Vertice novo);

//Grafo
typedef struct Grafo {
	int totVertices;					//N�mero de vertices
	int adj[NUMVERTICES][NUMVERTICES];	//Matrix Adj
	Vertice vertices[NUMVERTICES];		//vertices
}Grafo;

bool InicializaVertices(Vertice v[], int *totVertices);
Grafo* CriaGrafo(int totVertices);
Grafo* NovaAresta(Grafo* g, Vertice v1, Vertice v2, int p);
int QualPesoAresta(Grafo* g, int v1, int v2);

#pragma endregion


