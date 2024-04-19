#pragma once
/*
Aula 15-04-2024
ESI
*/
#include <stdbool.h>
#define TOT 100
#define N 50

#pragma region H1

//h1 - Estatico - grafo não pesado, não é orientado

//vertice

typedef struct V {
	char nome[N];
}V;
//vertices (grafo)
V vertices[TOT];

//matriz de Ad
int matrix[TOT][TOT];

typedef struct Grafo {
	int matrix[TOT][TOT];
	V vertices[TOT];
	int totVertices;
}Grafo;

//Assinatura

Grafo* CriaGrafoH1(int totv);
//Grafo* InicializaMA(Grafo* g);
bool InicializaMA(int m[][TOT], int x);
//Inserir vertice
bool InsereV(Grafo* g, V x);
//Inserir aresta

bool InsereAresta(Grafo* g, int v1, int v2, int p);
//Existe Ligação?
//Quanto custa ir de A a B?


#pragma endregion
