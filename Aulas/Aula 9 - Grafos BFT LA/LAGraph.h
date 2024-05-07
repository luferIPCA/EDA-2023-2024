/*
//Biblioteca para gerir Grafos com Lista de Adjacências
//
//lufer
*/
#pragma once

#include <stdbool.h>

#ifndef GRF
#define GRF


//=========================================================
// Estruturas dinâmicas:
//	Lista de Vertices
//  Lista de Adjacências
////=========================================================

typedef struct Adjacent {
	int id;
	float dist;
	struct Adjacent *next;
}Adjacent;

//Vertice
typedef struct Vertice
{
	int id;
	char *city;
	bool visited;
	Adjacent *nextAdjacent;
	struct Vertice *nextVertice;
}Vertice;


typedef struct Graph {
	Vertice* inicioGraph;	//lista de vertices
	int numeroVertices;		//numero corrente de vertices
	int totVertices;		//numero maximo de vertices
}Graph;


//Vertices
Vertice* CriaVertice(int id, char nome[]);
bool ExisteVertice(Vertice* inicio, int id);
Vertice* InsereVertice(Vertice* inicio, Vertice* novo, bool* res);
Vertice* EliminaVertice(Vertice* vertices, int codVertice, bool* res);
Vertice* GetVertice(Vertice* inicio, int id);
void ShowGraph(Vertice* graph);

//Adjacencias
Adjacent* NewAdjacent(int id);
Adjacent* ElimiminaAdj(Adjacent* listAdj, int codAdj, bool* res);
Adjacent* ElimiminaAllAdj(Adjacent* listAdj, bool* res);
Vertice* EliminaAdjacenciaAllVertices(Vertice* vertices, int codAdj, bool* res);
Adjacent* InsereAdj(Adjacent* listaAdja, int idDestino);

//Grafo

void ShowGaphLA(Graph* gr);
Graph* InsereVerticeGrafo(Graph* g, Vertice* vertice, int* res);
Graph* EliminaVerticeGraph(Graph* g, int codVertice, bool* res);
Graph* EliminaAdjGraph(Graph* g, int origem, int destino, bool* res);
Vertice* OndeEstaVerticeGraph(Graph* g, int idVertice);
Graph* InsereAdjaGrafo(Graph* g, int idOrigem, int idDestino, bool* res);
Graph* CriaGraphH3(int v);
bool ExisteVerticeGraph(Graph* inicio, int idVertice);

#pragma endregion

#endif // !GRF

