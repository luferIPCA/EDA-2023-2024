/**

    @file      GrafoI.c
    @brief     
    @details   ~
    @author    lufer
    @date      19.04.2024
    @copyright © lufer, 2024. All right reserved.

**/
#include "GrafoI.h"
#include <malloc.h>

#pragma region Grafo com Matriz de Adjacencias

#pragma region Matriz de Adjacencias

/**
    @brief  Inicializa a Matriz de Adj
    @param  m           - 
    @param  totVertices - 
    @retval             - 
**/
bool CreateMA(int m[][NUMVERTICES], int totVertices){
	if (totVertices <= 0 || totVertices > NUMVERTICES) 
		return false;
	for (int i = 0; i < totVertices; i++)
		for (int j = 0; j < totVertices; j++)
			m[i][j] = -1;
	return true;
}

/**
    @brief  grafo não orientado, pesado
    @param  m  - 
    @param  v1 - 
    @param  v2 - 
    @param  w  - 
    @retval    - 
**/
bool AddEdge(int m[][NUMVERTICES], int v1, int v2, int w) {
	//Testes...return false
	m[v1][v2] = w;
	m[v2][v1] = w;
	return true;
}

/**
    @brief  
    @param  m  - 
    @param  v1 - 
    @param  v2 - 
    @retval    - 
**/
bool ExistEdge(int m[][NUMVERTICES], int v1, int v2) {
		//testes

	//if (m[v1][v2] != -1) return true;
	//return false;

	return(m[v1][v2] != -1);
}

/**
    @brief  
    @param  m  - 
    @param  v1 - 
    @param  v2 - 
    @param  w  - 
    @retval    - 
**/
bool GetEdgeWeight(int m[][NUMVERTICES], int v1, int v2, int *w) {
	//testes
	if (m[v1][v2] != -1) {
	//if(ExistEdge(m,v1,v2)){
		*w = m[v1][v2];
		return true;
	}
	else {
		*w = -1;
		return false;
	}

}

#pragma endregion

#pragma region Vertices
/**
    @brief  
    @param  v           - 
    @param  numVertices - 
    @retval             - 
    @date   19.04.2024
**/
bool InicializaVertices(Vertice v[], int *totVertices) {
    //testes
    for (int i = 0; i < NUMVERTICES; i++) {
        v[i].valor = -1;
    }
    *totVertices = 0;   //no início não existem vertices
    return true;
}
/**
    @brief  
    @param  g - 
    @param  v - 
    @retval   - 
    @date   19.04.2024
**/
bool NovoVertice(Vertice v[], int *totVertices, Vertice novo) {
    //testes
    v[*totVertices] = novo;
    *totVertices++;
    return true;
}

#pragma endregion

#pragma region Grafo


Grafo* CriaGrafo(int numVertices) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    if (g != NULL) {
        bool succ = CreateMA(g->adj, numVertices);
        if (!succ) return g;
        succ = InicializaVertices(g->vertices, &(g->totVertices));
        if (!succ) return g;
    }
    return g;
}

/**
    @brief  
    @param  g  - 
    @param  v1 - 
    @param  v2 - 
    @param  p  - 
    @retval    - 
    @date   19.04.2024
**/
Grafo* NovaAresta(Grafo* g, Vertice v1, Vertice v2, int p) {
    //testes

    bool succ = AddEdge(g->adj, v1.valor, v2.valor, p);
    //if (succ) 
    return g;
}

int QualPesoAresta(Grafo* g, int v1, int v2) {
    //bool GetEdgeWeight(int m[][NUMVERTICES], int v1, int v2, int *w) {
    //testes
    int peso = -1;
    bool succ = GetEdgeWeight(g->adj, v1, v2, &peso);
    //if (succ) 
    return peso;
}


#pragma endregion

#pragma endregion



