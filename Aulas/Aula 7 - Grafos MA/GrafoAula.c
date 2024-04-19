#include "DadosAula.h"
#include <stdio.h>

Grafo* CriaGrafoH1(int totv) {
	//testes
	if (totv > TOT || totv <= 0) return NULL;
	Grafo* aux = (Grafo*)malloc(sizeof(Grafo));
	bool b = InicializaMA(aux->matrix,totv);
	//inicializ vertices
	//o que fazer aos arrays: vertices e adj
	aux->totVertices = 0;
	return aux;
}

/*
*/
bool InicializaMA(int m[][TOT], int t) {
	//testes..return false!!!
	for (int i = 0; i < t; i++)
		for (int j = 0; j < t; j++)
			m[i][j] = 0;
	return true;
}

bool InsereV(Grafo* g, V v) {
	//testes
	//verificar se vertice existe
	g->vertices[g->totVertices] = v;
	g->totVertices++;
	return true;
}

bool InsereAresta(Grafo* g, int v1, int v2, int p) {
	g->matrix[v1][v2] = p;
	g->matrix[v2][v1] = p;
}