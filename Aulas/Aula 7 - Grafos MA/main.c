/*
* Grafos - MA
* ESI
* lufer
*/

#include "GrafoI.h"
#include "GrafoII.h"

int main() {

#pragma region Graph - Matriz de Adjacencia

	Grafo* g1 = CriaGrafo(10);

	//matriz de adjacencias
	//int adj[NUMVERTICES][NUMVERTICES];

	bool succ = CreateMA(g1->adj, 14);
	if (succ == true)
		printf("ok\n");

	succ =AddEdge(g1->adj, 4, 7,5);
	//if (succ)...

	int peso;
	succ = GetEdgeWeight(g1->adj, 4, 7, &peso);
	if (succ == true)
		printf("Dist=%d\n", peso);
	else
		printf("Nao pode ir por ai...");

#pragma endregion

#pragma region Graph - Matriz de dimensão variada

	//h1
	printf("\nsizeof Graph2=%d\n", sizeof(GraphII));
	GraphII* g2 = CriaGraphII();
	g2 = CriaMAGraphII(g2, 3);
	g2 = AddEdgeII(g2, 1, 2);
	g2 = AddEdgeII(g2, 0, 1);
	ShowMA(g2);
	printf("\n");

	//h2
	GraphII* g3 = CriaGraphII();
	g3 = CriaMAGraphIIh2(g3, 3);	//Matriz 3x3
	g3 = AddEdgeIIh2(g3, 1, 2, 3);
	ShowMAh2(g3);

	GraphII* g4 = CriaGraphII();
	g4 = CriaMAGraphII(g4, 20);		//Matriz 20x20
#pragma endregion





#pragma endregion

}