/*****************************************************************//**
 * @file	Main.c
 * @brief	Grafos - Algoritmos de manipula��o
 * 
 * @author lufer
 * @date   2024
 *********************************************************************/

#include  "Grafo.h"
#include <locale.h>

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Portuguese");	//para escrever caracteres portugueses

	static int tot = 0;					//total de vertices
	bool res;

#pragma region GRAFOS

	Vertice *graf = CriaGrafo();

	Vertice* novoVertice = CriaVertice("Braga",tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Porto",tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Famalic�o",tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Lisboa", tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	novoVertice = CriaVertice("Faro", tot);
	if (novoVertice != NULL) {
		graf = InsereVertice(graf, novoVertice, &res);
		tot++;
	}

	MostraGrafo(graf);	

	//Adjacencias
	//Criar liga��o "Braga" a "Porto"
	graf = InsereAdjacenteVertice(graf, "Braga", "Porto", 35, &res);
	//if(res==false){...}
	graf = InsereAdjacenteVertice(graf, "Braga", "Famalic�o", 15, &res);
	graf = InsereAdjacenteVertice(graf, "Famalic�o", "Porto", 22, &res);
	graf = InsereAdjacenteVertice(graf, "Porto", "Lisboa", 250, &res);

	MostraGrafo(graf);		//recursivo
	
	int pathCount = 0;
	int x = CountPaths(graf, 0, 2, pathCount);

	int contaPath = 0;
	x = CountPathsVerticesName(graf, "Braga", "Porto", contaPath);
	x = CountPathsVerticesName(graf, "Braga", "Lisboa", contaPath);

	x = CountPaths(graf, 0, 1, 0);

	printf("\nExiste Path?\n");
	bool existe = DepthFirstSearchRec(graf, 0, 3);
	printf(" Existe Path entre %d e %d: %s\n", 0,3,(existe == true ? "Sim" : "N�o"));


	graf = ResetVerticesVisitados(graf);

	existe = DepthFirstSearchNamesRec(graf, "Braga", "Porto");
	printf(" Existe Path entre %s e %s: %s\n", "Braga", "Porto",(existe == true ? "Sim" : "N�o"));

#pragma region FICHEIROS

	
	int res1 = SaveGraph(graf, "Vertices.bin");
	if (res1>0) puts("\nGrafo gravado em ficheiro");

	graf = DestroyGraph(graf);

	puts("\nGrafo em mem�ria:");
	MostraGrafo(graf);

	
	graf = LoadGraph(graf, "Vertices.bin", &res);
	if (graf!=NULL) puts("\nVertices do Grafo lido de ficheiro\n");
	MostraGrafo(graf);

	puts("\nLer Adjac�ncias do grafo de ficheiro\n");
	graf = LoadAdj(graf, &res);

	MostraGrafo(graf);

#pragma endregion
	//Assumi 5 v�rtices
	//Pensar numa vers�o sem Matriz de Custos?
	Best b = BestPath(graf, 5, 0);
	ShowAllPath(b, 5, 0);

#pragma endregion

}
