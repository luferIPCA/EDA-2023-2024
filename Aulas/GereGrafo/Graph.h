/**

    @file      Graph.h
    @brief     Grafo Não Orientado
    @details   Usa arrays de vertices e Matriz de Adjacências
    @author    lufer (lufer@ipca.pt)
    @date      3.05.2024
    @copyright © lufer - IPCA 2024. All right reserved.

**/
#pragma once

#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct Vertice{
	char label;
	bool visited;       /*!< Controlar travessia do Grafo */
}Vertice;

typedef struct Grafo
{
    Vertice* vertices;  //será array de vertices
    int** adj;          //será matriz de adjacencias
}Grafo;

//Graph functions

void ShowArestas(int** adj, int nVertices);
void ShowGraph(Vertice* lst, int** adj, int numVertices);
int AddVertice(Vertice* lstVertices, int numVertices, char label);
bool AddAresta(int** adj, int v1, int v2);
int** CriaInicializaMatrizAdjacencias(int numVertices);
Grafo* CriaGrafo(int numVertices, bool* res);
void ProcessaVertice(Vertice* v);


