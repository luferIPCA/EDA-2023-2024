#pragma once
/*
* Grafos com Matrizes de Adjac�ncias "de tamanho din�mico"
* Assinatura de fun��es
*
* =========================================================
* a) Grafo orientado, n�o pesado
* b) Grafo orientado e pesado
* c) Grafo n�o orientado e pesado
* d) Grafo n�o orientado e n�o pesado
*=========================================================
* Ref:	https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Graphs.html
*		https://c-faq.com/aryptr/dynmuldimary.html
*/

#include <stdbool.h>
#include <stdio.h>
#define NUMVERTICES 20
#define N 50


#pragma region Matriz

#pragma region Dinamico

//h2: Matriz de Adjac�ncias com dimens�o variada

typedef struct GraphII {
	int v;	//tot vertices
	int** adj;
}GraphII;

//h1
GraphII* CriaGraphII();
GraphII* CriaMAGraphII(GraphII* g, int numV);
GraphII* AddEdgeII(GraphII* g, int v1, int v2);
void ShowMA(GraphII* g);

//h2
GraphII* CriaMAGraphIIh2(GraphII* g, int v);
GraphII* AddEdgeIIh2(GraphII* g, int v1, int v2, int numV);
void ShowMAh2(GraphII* g);

#pragma endregion

#pragma endregion
