/*
Grafos: Fundamentos
lufer
Consultar:
https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/
*/
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>	// ASCII SET
#include "LAGraph.h"


int main() {
	setlocale(LC_ALL, "Portuguese");


	//Grafo
	Vertice lista[TOTALVERTICES + 1];

#pragma region LISTA_ADJACENCIAS_H1

	  //==========================
	  // Lista de Adjacencias
	  //==========================

	  //======================================
	  //H1 - Estrutura de Vértices Fixa
	  //======================================
	  int i, a, b;

	  bool succ = CriaGraph(lista, TOTALVERTICES);

	  succ = InsereAresta(lista, 7, 1);
	  succ = InsereAresta(lista, 0, 1);
	  succ = InsereAresta(lista, 0, 2);
	  succ = InsereAresta(lista, 2, 3);
	  succ = InsereAresta(lista, 3, 1);

	  printf("\nGrafo Orientado\n");
	  MostraGrafo(lista);


#pragma endregion

#pragma region LISTA_ADJACENCIAS_H2

	  //======================================
	  //H2 - Grafo não orientado e pesado
	  //======================================
	  
	  int v = 5;
	  struct Graph* g = CreateGraph(v);
	  succ = AddEdgeWeight(g, 0, 1,27);	//sem peso
	  succ = AddEdgeWeight(g, 0, 4,43);
	  succ = AddEdgeWeight(g, 1, 2,34);
	  succ = AddEdgeWeight(g, 1, 3,12);
	  succ = AddEdgeWeight(g, 1, 4,56);
	  succ = AddEdgeWeight(g, 2, 3,4.2);
	  succ = AddEdgeWeight(g, 3, 4, (float)7);

	  //Mostra Grafo
	  printf("\nGrafo Não Orientado\n");
	  PrintGraph(g);

	  printf("\nPesos no Grafo Não Orientado\n");
	  // mostra a lista de adjacências
	  PrintGraphWeight(g, true);

	  //Menor Distância saindo de um Vertice v

	  printf("\nMenor Distância saindo de (%d) = %2.0f\n", 2, ShorterDistance(g, 2));

#pragma endregion

#pragma region LISTA_ADJACENCIAS_H3

	  //======================================
	  //H3
	  //======================================

	  int res;
	  Graph3* g2 = CriaGraphH3(10);

	  Node* novo1 = CriaVertice(1, "Porto");
	  g2 = InsereVerticeGrafo(g2, novo1, &res);

	  novo1 = CriaVertice(0, "Lisboa");
	  g2 = InsereVerticeGrafo(g2, novo1, &res);

	  novo1 = CriaVertice(2, "Braga");
	  g2 = InsereVerticeGrafo(g2, novo1, &res);

	  novo1 = CriaVertice(3, "Barcelos");
	  g2 = InsereVerticeGrafo(g2, novo1, &res);

	  novo1 = CriaVertice(4, "Coimbra");
	  g2 = InsereVerticeGrafo(g2, novo1, &res);

	  ShowGraph(g2->inicioGraph);


	  g2 = InsereAdjaGrafo(g2, 0, 1, &res);
	  g2 = InsereAdjaGrafo(g2, 0, 4, &res);

	  g2 = InsereAdjaGrafo(g2, 1, 0, &res);
	  g2 = InsereAdjaGrafo(g2, 1, 2, &res);
	  g2 = InsereAdjaGrafo(g2, 1, 3, &res);
	  g2 = InsereAdjaGrafo(g2, 1, 4, &res);

	  g2 = InsereAdjaGrafo(g2, 2, 1, &res);
	  g2 = InsereAdjaGrafo(g2, 2, 3, &res);

	  g2 = InsereAdjaGrafo(g2, 3, 1, &res);
	  g2 = InsereAdjaGrafo(g2, 3, 2, &res);
	  g2 = InsereAdjaGrafo(g2, 3, 4, &res);

	  g2 = InsereAdjaGrafo(g2, 4, 0, &res);
	  g2 = InsereAdjaGrafo(g2, 4, 1, &res);
	  g2 = InsereAdjaGrafo(g2, 4, 3, &res);

	  ShowGraph(g2->inicioGraph);

#pragma endregion

	  printf("\nAbordagem H3\n\n");


#pragma region LISTA_ADJACENCIAS_Outra_Abordagem

	  Graph3 *g3 = CriaGraphH3(100);

	  novo1 = CriaVertice(1, "Porto");
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

	  printf("\nApós Eliminar Vertice %d\n\n", 1);
	  g3 = EliminaVerticeGraph(g3, 1, &res);
	  ShowGaphLA(g3);

	  novo1 = CriaVertice(100, "Porto");
	  g3 = InsereVerticeGrafo(g3, novo1, &res);
	  printf("\nApós Adiconar Vertice %d\n\n", novo1->id);

	  g3 = InsereAdjaGrafo(g3, 100, 2, &res);
	  g3 = InsereAdjaGrafo(g3, 2, 100, &res);

	  ShowGaphLA(g3);

	  g3 = EliminaAdjGraph(g3, 2, 100, &res);

	  printf("\nApós Eliminar Aresta %d - %d\n\n", 2, 100);
	  ShowGaphLA(g3);

#pragma endregion


#pragma endregion

	  system("pause");
	  return 0;
} 
