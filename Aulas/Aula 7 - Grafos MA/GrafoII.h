#pragma once
/*
* Grafos com Matrizes de Adjacências "de tamanho dinâmico"
* Assinatura de funções
*
* =========================================================
* a) Grafo orientado, não pesado
* b) Grafo orientado e pesado
* c) Grafo não orientado e pesado
* d) Grafo não orientado e não pesado
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

//h2: Matriz de Adjacências com dimensão variada

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
