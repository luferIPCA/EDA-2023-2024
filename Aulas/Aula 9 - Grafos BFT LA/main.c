/*
// Grafos: Fundamentos
//
// lufer
*/
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>	// ASCII SET

#include "LAGraph.h"
#pragma comment(lib,"LAGraph.lib")
#include "BFT.h"

#define MAX 10

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int res = false;
	Graph* g3 = CriaGraphH3(100);

	Vertice *novo1 = CriaVertice(1, "Porto");
	g3 = InsereVerticeGrafo(g3, novo1, &res);
	//analisar resultado
	if (res != 1) {
		if (res == -1) {

		}
		if (res == -2) {}
	}

	novo1 = CriaVertice(2, "Braga");
	g3 = InsereVerticeGrafo(g3, novo1, &res);

	novo1 = CriaVertice(3, "Lisboa");
	g3 = InsereVerticeGrafo(g3, novo1, &res);

	g3 = InsereAdjaGrafo(g3, 1, 2, &res);
	g3 = InsereAdjaGrafo(g3, 2, 1, &res);
	g3 = InsereAdjaGrafo(g3, 1, 3, &res);
	g3 = InsereAdjaGrafo(g3, 3, 2, &res);

	ShowGaphLA(g3);

	//printf("\nApós Eliminar Vertice %d\n\n", 1);
	//g3 = EliminaVerticeGraph(g3, 1, &res);
	//ShowGaphLA(g3);

	novo1 = CriaVertice(100, "Porto");
	g3 = InsereVerticeGrafo(g3, novo1, &res);
	printf("\nApós Adiconar Vertice %d\n\n", novo1->id);

	g3 = InsereAdjaGrafo(g3, 100, 2, &res);
	g3 = InsereAdjaGrafo(g3, 2, 100, &res);

	ShowGaphLA(g3);

	//g3 = EliminaAdjGraph(g3, 2, 100, &res);
	//printf("\nApós Eliminar Aresta %d - %d\n\n", 2, 100);
	//ShowGaphLA(g3);

	g3->inicioGraph=ResetVertices(g3->inicioGraph);

	BreadthFirstTraversalLA(g3, 1);

	g3->inicioGraph = ResetVertices(g3->inicioGraph);

	bool succ=BreadthFirstSearchLA(g3, 1,100);
	printf("Existe caminho entre %d e %d: %s\n", 1, 100, (succ == true ? "Sim" : "Não"));

	succ = BreadthFirstSearchLA(g3, 2, 3);
	printf("Existe caminho entre %d e %d: %s\n", 2, 3, (succ == true ? "Sim" : "Não"));

	system("pause");
	return 0;
} 
