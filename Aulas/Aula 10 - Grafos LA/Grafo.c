/*****************************************************************//**
 * @file   Grafo.c
 * @brief	Implementação de Grafo Pesado e Orientado
 *			Preservação de dados do Grafo
 *
 * @author lufer
 * @date   2024
 *********************************************************************/

#include <stdlib.h>
#include <string.h>
#include "Grafo.h"

#pragma region GRAFO

/**
 * @brief Inicia um Grafo Pesado, Não Orientado 
 * 
 * @return 
 * @author lufer
 *
 */
Vertice* CriaGrafo() {
	return NULL;
}

/**
 * @brief Cria vértice para o grafo
 * 
 * @param cidade	//!< nome da Cidade do Vértice
 * @return 
 * @author lufer
 */
Vertice* CriaVertice(char* cidade, int cod) {
	Vertice* novo = (Vertice*)calloc(1, sizeof(Vertice));
	if (novo == NULL) return NULL;
	novo->cod = cod;
	strcpy(novo->cidade, cidade);
	novo->next = NULL;			//com "calloc" isto é dispensável
	novo->adjacentes = NULL;	//com "calloc" isto é dispensável
	return novo;
}

/**
 * @brief Inserir Vertice no grafo.
 * 
 * @param g		Grafo 
 * @param novo	Novo Vertice  
 * @param res	Resultado da operação 
 * @return		Grafo alterado  
 * @author lufer
 *
 */
//bool InsereVertice(Vertice** g, Vertice* novo)
Vertice* InsereVertice(Vertice* g, Vertice* novo, bool* res) {
	if (g == NULL) {
		g = novo;
		*res = true;
		return g;
	}
	else
	{
		Vertice* aux = g;
		Vertice* ant = aux;
		while (aux && strcmp(aux->cidade, novo->cidade) <0 ) {
			ant = aux;
			aux = aux->next;
		}
		if (aux == g) {
			novo->next = g;
			g = novo;
		}
		else
		{
			novo->next = aux;
			ant->next = novo;
		}
		*res = true;
	}
	return g;
}

/**
 * @brief Apresenta grafo.
 * 
 * @param g
 * @author lufer
 *
 */
void MostraGrafo(Vertice* g) {
	if (g == NULL) return;
	printf("V: %d - %s\n", g->cod,g->cidade);
	MostraAdjacencias(g->adjacentes);
	MostraGrafo(g->next);
}

/**
 * @brief .
 * 
 * @param g
 * @return 
 * @author lufer
 *
 */
Vertice* DestroyGraph(Vertice* g) {
	if (g == NULL) return NULL;
	Vertice* aux = NULL;
	while (g) {
		if (g->next)
			aux = g->next;
		g->adjacentes = DestroyAdj(g->adjacentes);
		free(g);
		g = aux;
		aux = NULL;
	}
	return g;
}

/// @brief Verifica qual o código do vertice de uma determinada cidade
/// @param g 
/// @param cidade 
/// @return 
int ProcuraCodigoVertice(Vertice* g, char* cidade) {
	if (g == NULL) return -1;
	if (strcmp(g->cidade, cidade) > 0) return -2;
	if(strcmp(g->cidade, cidade)==0) return g->cod;
	return(ProcuraCodigoVertice(g->next, cidade ));
	/* Não recursivo*/
	/*
	Vertice* aux = g;
	while (aux) {
		if (strcmp(g->cidade, cidade) > 0) return -2;
		if (strcmp(g->cidade, cidade) == 0) return(g->cod);
		aux = aux->next;
	}
	*/
}

/**
 * @brief .
 * 
 * @param g
 * @param cidade
 * @return 
 * @author lufer
 *
 */
Vertice* ProcuraVertice(Vertice* g, char* cidade) {
	if (g == NULL) return NULL;
	if (strcmp(g->cidade, cidade) == 0) return g;
	return(ProcuraVertice(g->next, cidade));
}

Vertice* ProcuraVerticeCod(Vertice* g, int cod) {
	if (g == NULL) return NULL;
	if (g->cod==cod) return g;
	return(ProcuraVerticeCod(g->next, cod));
}

/**
 * @brief Limpa estado "visitado".
 *
 * @param g
 * @return
 * @author lufer
 *
 */
Vertice* ResetVerticesVisitados(Vertice* g) {
	Vertice* aux = g;
	while (aux) {
		aux->visitado = false;
		aux = aux->next;
	}
	return g;
}

#pragma endregion


#pragma region ADJACENCIAS

/**
 * @brief Cria novo nodo de adjecência.
 * 
 * @param cod
 * @param peso
 * @return 
 * @author lufer
 *
 */
Adj* CriaAdj(int cod, float peso) {
	Adj* novo = (Adj*)calloc(1, sizeof(Adj));
	if (novo == NULL) return NULL;
	novo->cod = cod;
	novo->dist = peso;
	novo->next = NULL;
	return novo;
}

/**
 * @brief Insere nova adjecência no grafo.
 * 
 * @param g			Grafo orientado
 * @param origem	Nome de Vertice origem
 * @param tot		Total de vértices
 * @param dest		Nome de Vertice destino
 * @param peso		Peso
 * @param res		Resultado da operação
 * @return			Grafo alterado
 * @author lufer
 *
 */
Vertice* InsereAdjacenteVertice(Vertice* g, char* origem, char* dest, float peso, bool* res)
{
#pragma region Validações
	*res = false;				//por defeito é falso
	
	if (g == NULL) return g;	//<! se grafo está vazio, ignora operação

	Vertice* aux = ProcuraVertice(g, origem);	//<! procura vertice origem
	int cod = ProcuraCodigoVertice(g, dest);	//<! procura vertice destino
	//ou
	//Vertice* d = ProcuraVertice(g, dest);
	
	if (aux == NULL || cod<0) return g;			//<! Se não encontrou vertice origem e destino, ignora operação

	if (ExisteAdjacentes(aux->adjacentes, cod) == true) 
		return g; //Se já foi registado esta adjacencia, ignorar a operação
#pragma endregion

#pragma region Ação
	//Insere nova adjacencia no vertice "Origem"
	Adj* novoAdj = CriaAdj(cod, peso);
	aux->adjacentes= InsereAdj(aux->adjacentes, novoAdj, res);
	return g;
	//Se for não orientado
	//return (InsereAdjacenteVertice(g, dest, origem, peso, res));
#pragma endregion

}

/**
 * @brief Insere Adjacente a partir dos códigos dos vertices.
 *
 * @param g
 * @param codOrigem
 * @param codDest
 * @param peso
 * @param res
 * @return
 * @author lufer
 *
 */
Vertice* InsereAdjacenteVerticeCod(Vertice* g, int codOrigem, int codDest, float peso, bool* res) {

#pragma region Validações
	* res = false;				//por defeito é falso

	if (g == NULL) return g;	//<! se grafo está vazio, ignora operação

	Vertice* o = ProcuraVerticeCod(g, codOrigem);	//<! procura vertice origem
	Vertice* d = ProcuraVerticeCod(g, codDest);	//<! procura vertice destino
	if (o == NULL || d == NULL) return g;		//<! Se não encontrou vertice origem e destino, ignora operação

	if (ExisteAdjacentes(o->adjacentes, codDest) == true)
		return g; //Se já foi registado esta adjacencia, ignorar a operação
#pragma endregion

	//g=InsereAdjacenteVertice(g, o->cidade, d->cidade, peso, res);

#pragma region Ação
	//Insere nova adjacencia no vertice "Origem"
	Adj* novoAdj = CriaAdj(codDest, peso);
	o->adjacentes = InsereAdj(o->adjacentes, novoAdj, res);
	return g;
	//Se for não orientado
	//return (InsereAdjacenteVertice(g, dest, origem, peso, res));
#pragma endregion

}

#pragma region GERE_LISTA_ADJACENCIAS

/**
 * @brief	Verifica se determinado adj já existe.
 *			Forma Recursiva
 * 
 * @param h		Lista de Adjacencias
 * @param cod	Código a procurar
 * @return		Verdadeiro ou Falso
 * @author lufer
 *
 */
bool ExisteAdjacentes(Adj* h, int cod) {
	if (h == NULL) return false;
	if (h->cod == cod) return true;
	return ExisteAdjacentes(h->next, cod);
}

/**
 * @brief	Insere novo adjacente de um vertice.
 *			Não admite vertices repetidos
 * 
 * @param h
 * @param novo
 * @param res
 * @return 
 * @author lufer
 *
 */
Adj* InsereAdj(Adj* h, Adj* novo, bool* res) {
	
	*res = false;		//por defeito é falso
	
	if (novo == NULL)	//Se novo adjacente é nulo, ignora operação
		return h;
		
	if (ExisteAdjacentes(h, novo->cod) == true) return h; // Se novo adj existe, ignorar operação

	// Inserir nova adjacencia!
	*res = true;		
	if (h == NULL) {	//Se lista de adjacencias é vazia, esta é a primeira adjacencia
		h = novo;
		return h;
	}
	//senão insere no início das adjacências! Podia ser de outra forma!
	novo->next = h;
	h = novo;

	return h;
}

/**
 * @brief Mostra lista de adjacentes.
 * 
 * @param h
 * @author lufer
 *
 */
void MostraAdjacencias(Adj* h) {
	if (h == NULL) return;
	printf("\tAdj: %d - (%.0f)\n", h->cod, h->dist);
	MostraAdjacencias(h->next);
}

/**
 * @brief .
 * 
 * @param h
 * @return 
 * @author lufer
 *
 */
Adj* DestroyAdj(Adj* h) {
	if (h == NULL) return NULL;
	Adj* aux = NULL;
	while (h) {
		if (h->next != NULL)
			aux = h->next;
		free(h);
		h = aux;
		aux = NULL;
	}
	return h;
}
#pragma endregion

#pragma endregion


#pragma region ALGORITMOS

/**
 * @brief Count all the paths between two vertices, recursively
 * 
 * @param src
 * @param dst
 * @param vertice	- Grafo pesado, orientado
 * @return 
 * @author lufer
 *
 */
int CountPaths(Vertice *g, int src, int dst, int pathCount) {
	if (g == NULL) return 0;

	// If current vertex is same as destination, then increment count
	if (src == dst) return (++pathCount);
	
	else { // Recur for all the vertices adjacent to this vertex
		Vertice *aux = ProcuraVerticeCod(g, src);
		Adj* hAdj = aux->adjacentes;
		while (hAdj) {
			Vertice* v = ProcuraVerticeCod(g, hAdj->cod);
			pathCount = CountPaths(g, v->cod, dst, pathCount);
			hAdj = hAdj->next;
		}
	}
	return pathCount;
}

/**
 * @brief	Count all the paths between two vertices, recursively.
 *			Using vertices names
 * 
 * @param g
 * @param src
 * @param dest
 * @param pathCount
 * @return 
 * @author lufer
 *
 */
int CountPathsVerticesName(Vertice* g, char* src, char* dest, int pathCount) {
	int s = ProcuraCodigoVertice(g, src);
	int d = ProcuraCodigoVertice(g, dest);
	return CountPaths(g, s, d, 0);
}

/**
 * @brief	DFT Search Recursivo.
 *			Verifica se existe caminho entre dois vertices
 * @param g
 * @param origem
 * @param dest
 * @return 
 * @author lufer
 *
 */
bool DepthFirstSearchRec(Vertice*g, int origem, int dest)
{
	int j;

	if (origem == dest) return true;

	Vertice* aux = ProcuraVerticeCod(g, origem);
	aux->visitado = true;
	//printf(" Vertice: %s : %d\n", aux->cidade, aux->cod);

	Adj* adj = aux->adjacentes;
	while (adj) {
		Vertice*  aux = ProcuraVerticeCod(g, adj->cod);
		if (aux->visitado == false)
		{
			bool existe = DepthFirstSearchRec(g, adj->cod, dest);
			return existe;
		}
		else
			aux = aux->next;
	}
	return true;
}

/**
 * @brief	DFT Search Recursivo.
 *			Verifica se existe caminho entre dois vertices a partir dos seus nomes.
 * 
 * @param g
 * @param src
 * @param dest
 * @return 
 * @author lufer
 *
 */
bool DepthFirstSearchNamesRec(Vertice* g, char* src, char* dest) {
	int o = ProcuraCodigoVertice(g, src);
	int d = ProcuraCodigoVertice(g, dest);
	return DepthFirstSearchRec(g, o, d);
}

/**
 * @brief	Dijkstra’s Algorithm.
 *			Using Cost´s Matrix
 * @param adjMatrix
 * @param n			total of Vertices
 * @param v			initial vertice
 * @return
 * @author lufer
 *
 */
Best BestPath(Vertice *g, int n, int v) {

	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;

	//pred[] guarda o vertice anterior ao atual
	//count número de nodos visitados até ao momento
	//cria matriz de custos a partir da matriz de adjacencias

	//inicializações matriz de custos
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++)
			cost[i][j] = MAXDISTANCE;

	//Colocar custos efectivos
	Vertice* aux = g;
	while (aux) {
		if (aux->adjacentes) {
			Adj* auxAdj = aux->adjacentes;
			while (auxAdj) {
				cost[aux->cod][auxAdj->cod] = auxAdj->dist;
				auxAdj = auxAdj->next;
			}
		}
		aux = aux->next;
	}

	//pred[],distance[] and visited[]
	aux = g;
	while (aux) {
		distance[aux->cod] = cost[v][aux->cod];
		pred[aux->cod] = v;
		visited[aux->cod] = 0;
		aux = aux->next;
	}


	distance[v] = 0;
	visited[v] = 1;
	count = 1;
	nextnode = 0;
	while (count < n - 1)
	{
		mindistance = MAXDISTANCE;
		//nextnode é o vertice à menor distância do atual
		for (i = 0; i < n; i++)
		{
			if (distance[i] < mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}
		}

		//Verifica se existe um melhor caminho
		visited[nextnode] = 1;
		for (i = 0; i < n; i++) {
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		}
		count++;
	}
	//Devolve resultados
	Best b;
	for (int i = 0; i < n; i++) {
		b.anteriores[i] = pred[i];
		b.distance[i] = distance[i];
	}
	return b;
}

/*
Auxiliar
*/
void ShowAllPath(Best b, int n, int v) {
	int j;
	for (int i = 0; i < n; i++)
		if (i != v)
		{
			printf("\nDistancia até ao vertice %d = %d", i, b.distance[i]);
			printf("\nPath = %d", i);

			j = i;
			do
			{
				j = b.anteriores[j];
				printf(" <- %d", j);
			} while (j != v);
		}
}

#pragma endregion


#pragma region FICHEIROS

/**
 * @brief Grava Grafo em ficheiro binário.
 *
 * @param h
 * @param fileName
 * @return
 * @author lufer
 *
 */
int SaveGraph(Vertice* h, char* fileName) {

	if (h == NULL) return -1;
	FILE* fp;
	int r;
	fp = fopen(fileName, "wb");
	if (fp == NULL) return -2;

	Vertice* aux = h;
	VerticeFile auxFicheiro;	//estrutura de vertice para gravar em ficheiro
	while (aux != NULL) {
		auxFicheiro.cod = aux->cod;
		strcpy(auxFicheiro.cidade, aux->cidade);
		fwrite(&auxFicheiro, 1, sizeof(VerticeFile), fp);
		//Pode gravar de imediato as adjacencias!
		if (aux->adjacentes) {
			r = SaveAdj(aux->adjacentes, aux->cidade, aux->cod);
			if (r <0) break;
		}
		aux = aux->next;
	}
	fclose(fp);
	return 1;
}

/**
 * @brief Gravar Adj em ficheiro binário.
 *
 * @param h
 * @param fileName
 * @return
 * @author lufer
 *
 */
int SaveAdj(Adj* h, char* fileName, int codVerticeOrigem) {
	FILE* fp;
	if (h == NULL) return -2;
	fp = fopen(fileName, "wb");
	if (fp == NULL) return -1;

	Adj* aux = h;
	AdjFile auxFile;
	while (aux) {
		auxFile.codDestino = aux->cod;
		auxFile.codOrigem = codVerticeOrigem;
		auxFile.weight = aux->dist;
		fwrite(&auxFile, 1, sizeof(AdjFile), fp);
		aux = aux->next;
	}
	fclose(fp);
	return 1;
}

/**
 * @brief Load de grafo de ficheiro.
 *
 * @param h
 * @param fileName
 * @param res
 * @return
 * @author lufer
 *
 */
Vertice* LoadGraph(Vertice* h, char* fileName, bool* res) {
	*res = false;
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) return NULL;

	VerticeFile aux;
	Vertice* novo;
	while (fread(&aux, 1, sizeof(VerticeFile), fp)) {
		novo = CriaVertice(aux.cidade, aux.cod);
		h = InsereVertice(h, novo, res);
	}
	fclose(fp);
	return h;
}

/**
 * @brief Load de Adjacencias de um Grafo. REVER!!!
 *
 * @param g
 * @param fileName
 * @param res
 * @return
 * @author lufer
 *
 */
Vertice* LoadAdj(Vertice* g, bool* res) {
	*res = false;
	FILE* fp;
	if (g == NULL) return -1;
	AdjFile aux;
	Vertice* auxGraph = g;
	while (auxGraph) {
		fp = fopen(auxGraph->cidade, "rb");
		if (fp != NULL) {
			while (fread(&aux, 1, sizeof(AdjFile), fp)) {
				g = InsereAdjacenteVerticeCod(g, aux.codOrigem, aux.codDestino, aux.weight, res);
			}
			fclose(fp);
		}
		auxGraph = auxGraph->next;
	}
	return g;
}

#pragma endregion



