/**

    @file      Grafo.h
    @brief     Mais métodos para gerir um Grafo
    @details	- Grafos e Ficheiros
				- Algoritmo Dijkstra
    @author    lufer
    @date      9.05.2024
    @copyright © lufer - IPCA 2024. All right reserved.

**/
#pragma once

#pragma once

#include <stdio.h>
#include <stdbool.h>

#define N 20

#pragma warning (disable: 4996)
/**
 * Estrutura de uma Adjacência.
 */
typedef struct Adj {
	int cod;		/*!< Código da Adjacência */
	float dist;		/*!< Peso */
	struct Adj *next;
}Adj;

/**
 * Estrutura de uma Adjacência para Ficheiro
 */
typedef struct AdjFile {
	int codOrigem;
	int codDestino;		/*!< Código da Adjacência */
	float weight;		/*!< Peso */
}AdjFile;

/**
 * Descrição de um Vértice do grafo.
 */
typedef struct Vertice {
	int cod;					/*!< Código do Vértice */
	char cidade[N];				/*!< Nome da Cidade */
	bool visitado;
	struct Vertice* next;		/*!< Lista de Vértices */
	struct Adj* adjacentes;		/*!< Lista de Adjacências */
} Vertice;

/**
    @struct VerticeFile
    @brief  Estrutura de vertice para guardar em ficheiro
**/
typedef struct VerticeFile {
	int cod;					/*!< Código do Vértice */
	char cidade[N];				/*!< Nome da Cidade */
} VerticeFile;


//Auxiliar ao Dijkstra
#define MAX 5
#define MAXDISTANCE 9999

typedef struct Best {
	int distance[MAX];		//weight
	int anteriores[MAX];	//vertices cod
}Best;

#pragma region GRAFO

Vertice* CriaGrafo();
Vertice* InsereVertice(Vertice* g, Vertice* novo, bool*res);
Vertice* CriaVertice(char* cidade, int tot);
void MostraGrafo(Vertice* g);
int ProcuraCodigoVertice(Vertice* g, char* cidade);
Vertice* ProcuraVertice(Vertice* g, char* cidade);
Vertice* ProcuraVerticeCod(Vertice* g, int cod);
Vertice* DestroyGraph(Vertice* g);


#pragma endregion

#pragma region ADJACENCIAS

Vertice* InsereAdjacenteVertice(Vertice* g, char* origem, char* dest, float peso, bool* res);
Vertice* InsereAdjacenteVerticeCod(Vertice* g, int origem, int dest, float peso, bool* res);

#pragma region LISTA_ADJACENCIAS

Adj* CriaAdj(int cod, float peso);
Adj* InsereAdj(Adj* h, Adj* novo, bool* res);
bool ExisteAdjacentes(Adj* h, int cod);
void MostraAdjacencias(Adj* h);
Adj* DestroyAdj(Adj* h);

#pragma endregion

#pragma endregion

#pragma region ALGORITMOS

int CountPaths(Vertice* g, int src, int dst, int pathCount);
int CountPathsVerticesName(Vertice* g, char* src, char* dest, int pathCount);

bool DepthFirstSearchRec(Vertice* g, int origem, int dest);
bool DepthFirstSearchNamesRec(Vertice* g, char* src, char* dest);

Vertice* ResetVerticesVisitados(Vertice* g);

//Dijkstra’
Best BestPath(Vertice *g, int n, int v);

void ShowAllPath(Best b, int n, int v);

#pragma endregion

#pragma region PRESERVAÇÂO

int SaveGraph(Vertice* h, char* fileName);
int SaveAdj(Adj* h, char* fileName, int cod);
Vertice* LoadGraph(Vertice* h, char* fileName, bool* res);
Vertice* LoadAdj(Vertice* g, bool* res);


#pragma endregion


