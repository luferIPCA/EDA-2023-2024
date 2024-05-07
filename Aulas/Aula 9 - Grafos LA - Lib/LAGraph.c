/*
// Grafos: Lista de Adjacências
//
// lufer
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "LAGraph.h"
#include "assert.h"
// Lidar com "exceções"
// assert(x>=10) - stderror output caso x<10

//Ver: http://www.geeksforgeeks.org/graph-and-its-representations/


#pragma region Grafo_Pesado_Nao_Orientado_Lista_de_Adjacencias

//=========================================================
//H3 - Estruturas Dinâmicas
//=========================================================

#pragma region GerirVertices

void DestroiVertice(Vertice* ptVertice) {
	free(ptVertice->city);				//eliminar memória alocada para o nome
	free(ptVertice);
}

/**
	@brief
	@param  id -
	@retval    -
	@date   23.04.2024
**/
Vertice* CriaVertice(int id, char nome[]) {
	Vertice* aux = (Vertice*)malloc(sizeof(Vertice));
	if (aux == NULL)
	{
		return NULL;
	}
	aux->id = id;
	aux->city = (char*)malloc(sizeof(char) * strlen(nome));
	if ((aux->city = (char*)malloc(strlen(nome) + 1)) == NULL) {
		free(aux);
		return NULL;
	}
	strcpy(aux->city, nome);
	aux->nextVertice = NULL;
	aux->nextAdjacent = NULL;
	aux->visited = false;
	return aux;
}

/**
	@brief  Insere Vertice ordenado
	@param  vertices -
	@param  novo     - Vertice a inserir
	@param  res      -
	@retval          -
	@date   23.04.2024
**/
Vertice* InsereVertice(Vertice* vertices, Vertice* novo, bool* res) {
	*res = false;

	//Insere no grafo vazio
	if (vertices == NULL) {
		*res = 1;
		vertices = novo;
		return vertices;
	}

	//verificar se V já existe na lista de vertices...
	if (ExisteVertice(vertices, novo->id)) {
		return vertices;
	}
	else {
		//procura onde inserir
		Vertice* ant = NULL;
		Vertice* aux = vertices;
		while (aux != NULL && aux->id < novo->id)
		{
			ant = aux;
			aux = aux->nextVertice;
		}
		//Insere
		*res = true;
		if (ant == NULL) {
			novo->nextVertice = vertices;	//insere à cabeça
			vertices = novo;
		}
		else {
			novo->nextVertice = aux;
			ant->nextVertice = novo;
		}
	}
	return vertices;
}


/**
	@brief  Verifica se determinado vertice existe
	@param  inicio -
	@param  id     -
	@retval        -
	@date   23.04.2024
**/
bool ExisteVertice(Vertice* inicio, int id) {
	if (inicio == NULL) return false;
	Vertice* aux = inicio;
	while (aux) {
		if (aux->id == id) return true;
		aux = aux->nextVertice;
	}
	return false;
}

/**
	@brief  Verifica se determinado vertice existe.
			Devolve o vertice, caso exista
	@param  inicio -
	@param  id     -
	@retval        -
	@date   23.04.2024
**/
Vertice* GetVertice(Vertice* inicio, int id) {
	if (inicio == NULL) return NULL;
	Vertice* aux = inicio;
	while (aux) {
		if (aux->id == id) return aux;
		aux = aux->nextVertice;
	}
	return NULL;
}


/**
	@brief  Apaga vertice na lista de vertices de um grafo
	@param  vertices   -
	@param  codVertice -
	@param  res        -
	@retval            -
	@date   29.04.2024
**/
Vertice* EliminaVertice(Vertice* vertices, int codVertice, bool* res) {
	*res = false;
	if (vertices == NULL) return NULL;

	//procurar vertice
	Vertice* aux = vertices;
	Vertice* ant = NULL;
	while (aux->id != codVertice) {
		ant = aux;
		aux = aux->nextVertice;
	}
	if (!aux) return vertices;	//signifca que não existe o vertice

	//apaga vertice no inicio
	if (ant == NULL)
	{
		//apaga todas adjacencias do vertice a eliminar
		aux->nextAdjacent = ElimiminaAllAdj(aux->nextAdjacent, res);
		if (*res == false) return vertices;
		vertices= aux->nextVertice;
	}
	else {
		//apaga vertice
		ant->nextVertice = aux->nextVertice;
	}
	DestroiVertice(aux);
	*res = true;
	return vertices;
}

/**
    @brief  Apaga uma determinada adjacencia em todos os vertices
    @param  vertices - 
    @param  codAdj   - 
    @param  res      - 
    @retval          - 
    @date   29.04.2024
**/
Vertice* EliminaAdjacenciaAllVertices(Vertice* vertices, int codAdj, bool* res) {
	*res = false;
	if (vertices == NULL)
		return NULL;

	Vertice* aux = vertices;
	while (aux) {
		aux->nextAdjacent = ElimiminaAdj(aux->nextAdjacent, codAdj, res);
		aux = aux->nextVertice;
	}
	*res = true;
	return vertices;
}


/**
	@brief
	@param graph -
	@date  23.04.2024
**/
void ShowGraph(Vertice* graph) {
	Vertice* current = graph;
	while (current != NULL) {
		printf("%d: ", current->id);
		printf("%s\n", current->city);
		Adjacent* currentAdjacent = current->nextAdjacent;
		while (currentAdjacent != NULL)
		{
			printf("\t");
			printf("adjacent: %d\n", currentAdjacent->id);
			currentAdjacent = currentAdjacent->next;
		}
		current = current->nextVertice;
	}
}

#pragma endregion

#pragma region GereAdjacencias

/**
    @brief  Cria memória para uma nova Adjacência
    @param  id - 
    @retval    - 
    @date   1.05.2024
**/
Adjacent* NewAdjacent(int id)
{
	Adjacent* adjacent;

	adjacent = (Adjacent*)malloc(sizeof(Adjacent));
	if (adjacent == NULL)
	{
		return NULL;
	}
	adjacent->id = id;
	adjacent->next = NULL;
	return adjacent;
}

/**
    @brief Elimina memória alocada para uma adjacência
    @param ptAdjacent - 
    @date  1.05.2024
**/
void AdjacentDestroy(Adjacent* ptAdjacent)
{
	free(ptAdjacent);
}

/**
    @brief  Apaga adjacencia na Lista de Adjacencias
    @param  listAdj - 
    @param  codAdj  - 
    @param  res     - 
    @retval         - 
    @date   29.04.2024
**/
Adjacent* ElimiminaAdj(Adjacent* listAdj, int codAdj, bool* res) {
	*res = false;
	if (listAdj == NULL) return NULL;
	//procura adjacencia
	Adjacent* aux = listAdj;
	Adjacent* ant = NULL;
	while (aux && aux->id != codAdj) {
		ant = aux;
		aux = aux->next;
	}
	if (!aux) return listAdj;	//adjacencia não existe
	//apaga adjacencia no inicio
	if (ant == NULL)
	{
		//apaga todas adjacencias do vertice a eliminar
		listAdj = aux->next;
	}
	else {
		//apaga vertice
		ant->next = aux->next;
	}
	AdjacentDestroy(aux);
	*res = true;
	return listAdj;
}

/**
    @brief  Apaga todas as adjacências de uma LA
    @param  listAdj - 
    @param  res     - 
    @retval         - 
    @date   29.04.2024
**/
Adjacent* ElimiminaAllAdj(Adjacent* listAdj, bool* res) {
	*res = false;
	if (listAdj == NULL) return NULL;

	//percorre lista de adjacencia
	Adjacent* aux = listAdj;
	while (aux) {
		if(aux) 
			listAdj = aux->next;
		AdjacentDestroy(aux);
		aux = listAdj;
	}
	listAdj = NULL;
	*res = true;
	return listAdj;
}

/**
    @brief  Insere nova adjacencia na LA (opcao 1)
			Adjacência criada dentro da função
    @param  listaAdja - 
    @param  idDestino - 
    @retval           - 
    @date   29.04.2024
**/
Adjacent* InsereAdj(Adjacent* listaAdja, int idDestino) {
	Adjacent* newAdj;
	if ((newAdj = NewAdjacent(idDestino)) == NULL)
	{
		return listaAdja;	//se não conseguiu criar nova adjacencia
	}
	
	//se lista de adjacencia estava vazia
	if (listaAdja == NULL) {
		listaAdja = newAdj; //insere a nova adjacencia no inicio
	}
	else
	{
		//por opção, inserir no fim da LA
		Adjacent* aux = listaAdja;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = newAdj;
	}
	return listaAdja;
}

#pragma endregion

#pragma region GereGrafo

/**
    @brief  Cria memória para a estrutura Grafo
    @param  tot - 
    @retval     - 
    @date   1.05.2024
**/
Graph* CriaGraphH3(int tot) {
	//validações
	Graph* aux = (Graph*)malloc(sizeof(Graph));
	//testar
	if (aux != NULL) {
		aux->inicioGraph = NULL;
		aux->numeroVertices = 0;
		aux->totVertices = tot;		//numa LA pode não fazer sentido
	}
	return aux;
}


/**
	@brief  Insere Vertice num grafo (opcao 2)
	@param  g    - grafo
	@param  novo - Vertice a inserir
	@param  res  - controla sucesso da função: sucesso=1
	@retval      - grafo alterado
	@date   23.04.2024
**/
Graph* InsereVerticeGrafo(Graph* g, Vertice* novo, int* res) {
	*res = 1;
	//validações
	if (novo == NULL) { //vertice invalido
		*res = 0;
		return g;
	}
	if (g == NULL) { // grafo vazio
		*res = -1;
		return NULL;
	}
	//verificar se V já existe no grafo...
	if (ExisteVerticeGraph(g, novo->id)) { //vertice desconhecido
		*res = -2;
		return g;
	}
	g->inicioGraph = InsereVertice(g->inicioGraph, novo, res);
	if (*res == true)
		g->numeroVertices++;

	return g;
}

/**
	@brief  Insere nova adjacencia (opcao 2) no grafo
			Com controlo de sucesso
			Invoca função que gere lista de adjacencias
	@param  g         -
	@param  idOrigem  -
	@param  idDestino -
	@param  res       -
	@retval           -
	@date   24.04.2024
**/
Graph* InsereAdjaGrafo(Graph* g, int idOrigem, int idDestino, bool* res) {

	*res = false;
	//Validações
	if (g == NULL) return NULL;
	//Verificar se vertices existem
	Vertice* originVertice = OndeEstaVerticeGraph(g, idOrigem);
	if (originVertice == NULL) return g;
	Vertice* destinyVertice = OndeEstaVerticeGraph(g, idDestino);
	if (!destinyVertice) return g;

	originVertice->nextAdjacent = InsereAdj(originVertice->nextAdjacent, idDestino);

	*res = true;
	return g;
}

/**
    @brief  Apaga adjacencia entre dois vertices
    @param  g       - 
    @param  origem  - 
    @param  destino - 
    @param  res     - 
    @retval         - 
    @date   29.04.2024
**/
Graph* EliminaAdjGraph(Graph* g, int origem, int destino, bool* res) {
	
	*res = false;

	//validações
	if (g == NULL) return NULL;
	//Verificar se vertices existem
	Vertice* originVertice = OndeEstaVerticeGraph(g, origem);
	if (originVertice == NULL) return g;
	Vertice* destinyVertice = OndeEstaVerticeGraph(g, destino);
	if (!destinyVertice) return g;

	originVertice->nextAdjacent = ElimiminaAdj(originVertice->nextAdjacent, destino, res);
	return g;
}

/**
    @brief  Procura determinado vertice num grafo
			Devolve o vertice, caso exista
    @param  g         - 
    @param  idVertice - 
    @retval           - 
    @date   29.04.2024
**/
Vertice* OndeEstaVerticeGraph(Graph* g, int idVertice) {
	if (g == NULL) return NULL;
	return (GetVertice(g->inicioGraph, idVertice));
}

/**
	@brief  Verifica se determinado vertice existe num grafo
	@param  g         -
	@param  idVertice -
	@retval           -
	@date   23.04.2024
**/
bool ExisteVerticeGraph(Graph* g, int idVertice) {
	if (g == NULL) return false;
	return (ExisteVertice(g->inicioGraph, idVertice));
}

/**
	@brief  Apaga vertice de um grafo
	@param  g          -
	@param  codVertice -
	@param  res        -
	@retval            -
	@date   29.04.2024
**/
Graph* EliminaVerticeGraph(Graph* g, int codVertice, bool* res) {
	*res = false;
	if (g == NULL) return NULL;

	g->inicioGraph = EliminaVertice(g->inicioGraph, codVertice, res);
	g->inicioGraph = EliminaAdjacenciaAllVertices(g->inicioGraph, codVertice, res);
	if (*res == true) {
		g->numeroVertices--;
	}
	return g;
}

/**
    @brief Apresenta grafo
    @param gr - 
    @date  29.04.2024
**/
void ShowGaphLA(Graph* gr) {
	ShowGraph(gr->inicioGraph);
}

#pragma endregion

#pragma endregion