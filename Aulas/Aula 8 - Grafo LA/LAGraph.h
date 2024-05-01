/*
//Grafos: Lista de Adjac�ncias
//
//lufer
*/
#pragma once

#include <stdbool.h>

#ifndef GRF
#define GRF

#pragma region H1

//=========================================================
//H1 : grafo orientado, n�o pesado, com Matriz Fixa de Lista de Adjacencias
// 
// IMPLEMENTA��O DEVE SER MELHORADA!!!
//=========================================================
#define TOTALVERTICES 8

//Vertice
typedef struct Vertice {
	int valor;				//n�mero de adjacentes ou valor do vertice
	struct Vertice* prox;	//lista de adjacentes
}Vertice;


//Vertice listaAdg[TOTALVERTICES]

bool CriaGraph(Vertice*gr, int tot);
void MostraGrafo(Vertice*lista);
bool InsereAresta(Vertice*lista, int a, int b);

#pragma endregion

#pragma region H2

//=========================================================
//H2 - Grafo orientado e pesado - Matriz calculada
// 
// IMPLEMENTA��O DEVE SER MELHORADA!!!
//=========================================================

// nodo da Lista de Adjac�ncias
typedef struct AdjListNode
{
	int valor;			//numero de adjacentes
	float peso;			//grafo pesado
	struct AdjListNode* next;
}AdjListNode;

// Lista de Adjac�ncias
struct AdjList
{
	AdjListNode *head;  // head da Lista
};

// Um Grafo. Um array de Lista de Adjac�ncias!!!
// Array = numero de v�rtices do Grafo
struct Graph
{
	int v;						//total de vertices
	struct AdjList* vertices;	//ser� array
};

//prototipos fun��es

struct Graph* CreateGraph(int nVertices);
//Insere em grafo n�o orientado e pesado
bool AddEdgeWeight(struct Graph* graph, int src, int dest, float p);

//Mostra grafo
void PrintGraph(struct Graph* graph);
void PrintGraphWeight(struct Graph* graph, bool pesado);

//Menor Dist�ncia
float ShorterDistance(struct Graph* graph, int v);

#pragma endregion

#pragma region H3

//=========================================================
//H3
//S� estruturas din�micas
////=========================================================

typedef struct Adjacent {
	int id;
	float dist;
	struct Adjacent *next;
}Adjacent;

//Vertice
typedef struct Node
{
	int id;
	char *city;
	Adjacent *nextAdjacent;
	struct Node *nextVertice;
}Node;


typedef struct Graph3 {
	Node* inicioGraph;		//lista de vertices
	int numeroVertices;		//numero corrente de vertices
	int totVertices;		//numero maximo de vertices
}Graph3;


//Vertices
Node* CriaVertice(int id, char nome[]);
bool ExisteVertice(Node* inicio, int id);
Node* InsereVertice(Node* inicio, Node* novo, bool* res);
Node* EliminaVertice(Node* vertices, int codVertice, bool* res);
Node* OndeEstaVertice(Node* inicio, int id);
void ShowGraph(Node* graph);

//Adjacencias
Adjacent* NewAdjacent(int id);
Adjacent* ElimiminaAdj(Adjacent* listAdj, int codAdj, bool* res);
Adjacent* ElimiminaAllAdj(Adjacent* listAdj, bool* res);
Node* EliminaAdjacenciaAllVertices(Node* vertices, int codAdj, bool* res);
Adjacent* InsereAdj(Adjacent* listaAdja, int idDestino);

//Grafo

void ShowGaphLA(Graph3* gr);
Graph3* InsereVerticeGrafo(Graph3* g, Node* vertice, int* res);
Graph3* EliminaVerticeGraph(Graph3* g, int codVertice, bool* res);
Graph3* EliminaAdjGraph(Graph3* g, int origem, int destino, bool* res);
Node* OndeEstaVerticeGraph(Graph3* g, int idVertice);
Graph3* InsereAdjaGrafo(Graph3* g, int idOrigem, int idDestino, bool* res);
Graph3* CriaGraphH3(int v);
bool ExisteVerticeGraph(Graph3* inicio, int idVertice);

#pragma endregion

#endif // !GRF

