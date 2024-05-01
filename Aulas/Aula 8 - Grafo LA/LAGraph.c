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

#pragma region Grafo_Orientado_Não_Pesado_Matrix_Fixa

//=========================================================
//H1 - Grafo orientado, não pesado, matriz fixa (TOTALVERTICES)
//=========================================================

/*
Cria Grafo
Vertices: 0, 1, 2, 3...
Inicializa vertices com lista de adjacencias=NULL
*/
bool CriaGraph(Vertice*gr, int tot) {
	//se número de vertices não for válido
	if (tot <= 0 || tot > TOTALVERTICES) return false;
	//incializa
	for (int i = 0; i < tot; i++) {
		gr[i].valor = 0;
		gr[i].prox = NULL;
	}
	return true;
}
/*
Mostra Grafo
*/
void MostraGrafo(Vertice*lista) {
	int i;
	Vertice* tmp;
	for (i = 0; i < TOTALVERTICES; i++) {
		tmp = lista[i].prox;
		printf("Vertice %d: (%d) ==>\n", i, lista[i].valor);
		printf("Adjacentes: \n");
		while (tmp != NULL) {
			printf("\t%d  \n", tmp->valor);
			tmp = tmp->prox;
		}
		printf("\n");
	}
}

/*
Nova aresta, ordenando adjacências, grafo orientado
Vertice origem:a
Vertice destino:b
*/
bool InsereAresta(Vertice*lista, int a, int b) {
	Vertice*destino;
	Vertice*tmp;

	//O QUE VIOLA ESTE CÓDIGO AQUI?
	//SOLUçÂO?
	//------
	if (lista == NULL) return false;
	//Novo vertice para o destino
	destino = (Vertice*)malloc((int)sizeof(Vertice));
	//assert(aux)
	destino->valor = b;
	destino->prox = NULL;
	//------

	//Regista vertice destino como adjacente
	if (lista[a].prox == NULL)	// se lista vazia - é único adjacente	
		lista[a].prox = destino;
	else {						//insere vértices ordenados
		tmp = lista[a].prox;
		if (tmp->valor > b) {	//insere inicio da lista
			destino->prox = tmp;
			lista[a].prox = destino;
		} 		          
		else if (tmp->prox == NULL) {
			destino->prox = tmp->prox;
			tmp->prox = destino;
		}
		else {
			while ((tmp->prox != NULL) && (tmp->prox->valor < b))
				tmp = tmp->prox;
			destino->prox = tmp->prox;
			tmp->prox = destino;
		}
	}
	lista[a].valor++;			// incrementa número de adjacentes!
	return true;
}

#pragma endregion

#pragma region Grafo_Pesado_Nao_Orientado_Matrix_Calculada

//=========================================================
//H2 - Grafo Não Orientado, Pesado, Matriz calculada
//=========================================================

/*
Novo Nodo
*/
 AdjListNode* newAdjListNode(int val)
{
	AdjListNode* newNode = ( AdjListNode*) malloc(sizeof( AdjListNode));
	assert(newNode);		//lida com invariante ex: assert(x>10) - stderror output
	newNode->valor = val;
	newNode->next = NULL;
	newNode->peso = 0;		//grafo ponderado; (peso=0) por omissão!
	return newNode;
}

/*
Cria grafo preparado para conter "nVertices" 
*/
struct Graph* CreateGraph(int nVertices)
{
	//validações
	//estrutura para guardar todo o grafo
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	assert(graph);
	graph->v = nVertices;

	//Cria array de lista de adjacencias de tamanho nVertices
	graph->vertices = (struct AdjList*) malloc(nVertices * sizeof(struct AdjList));

	// Inicializa cada lista de adjacencias
	int i;
	for (i = 0; i < nVertices; ++i)
		graph->vertices[i].head = NULL;

	return graph;
}

/*
Adicona aresta em grafo não orientado e não pesado
*/
bool AddEdge(struct Graph* graph, int src, int dest)
{
	if (graph == NULL) return false;
	//novo nodo para vertice destino
	struct AdjListNode* newNode = newAdjListNode(dest);
	if (newNode == NULL) return false;

	//Insere à cabeça da lista de adjacências
	newNode->next = graph->vertices[src].head;
	graph->vertices[src].head = newNode;

	// grafo não orientado => addEdgs (graph, dest,src) 
	newNode = newAdjListNode(src);
	newNode->next = graph->vertices[dest].head;
	graph->vertices[dest].head = newNode;
	return true;
}


/*
Insere aresta ponderada, ie, com um peso, em grafo não orientado
*/
bool AddEdgeWeight(struct Graph* graph, int src, int dest, float p)
{
	//validações
	if (graph == NULL) return false;

	//novo nodo para vertice destino
	AdjListNode* vdest = newAdjListNode(dest);	
	vdest->peso = p;		//ponderação

	//Insere à cabeça da lista de adjacências
	vdest->next = graph->vertices[src].head;
	graph->vertices[src].head = vdest;

	// grafo não orientado => addEdgs (graph, dest,src) 
	AdjListNode* vsource = newAdjListNode(src);
	vsource->peso = p;		//ponderação
	vsource->next = graph->vertices[dest].head;
	graph->vertices[dest].head = vsource;;
	return true;
}

//Abordagem recursiva
/*
bool AddEdgeII(struct Graph* graph, int src, int dest, float p)
{
	//validações
	if(graph==NULL) return false;
	//novo nodo para vertice destino
	AdjListNode* newNode = newAdjListNode(dest);
	//Insere à cabeça da lista de adjacências
	newNode->next = graph->array[src].head;
	newNode->peso = p;

	graph->array[src].head = newNode;

	return (AddEdgeII(graph, dest, src, p));

}

bool AddEdgeWeightII(struct Graph* graph, int src, int dest, float p)
{
	//validações
	if(graph==NULL) return false;
	bool succ = AddEdgeII(graph, src, dest, p);
	succ = AddEdgeII(graph, dest, src, p);
	return succ;
}
*/

/*
Mostra Grafo
*/
void PrintGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->v; ++v)
	{
		AdjListNode* aux = graph->vertices[v].head;
		printf("\n Lista de Adjacencia do Vertice (%d)", v);
		while (aux)
		{
			printf("-> %d", aux->valor);
			aux = aux->next;
		}
		printf("\n");
	}
}

/*
Mostra grafo pesado ou não
*/
void PrintGraphWeight(struct Graph* graph, bool pesado)
{
	int v;
	for (v = 0; v < graph->v; ++v)
	{
		struct AdjListNode* aux = graph->vertices[v].head;
		printf("\n Lista de Adjacencia do Vertice (%d)", v);
		while (aux)
		{
			if(pesado==false)
				printf("-> %d", aux->valor);
			else
				printf("-> (%d): Peso= %2.0f", aux->valor, aux->peso);
			
			aux = aux->next;
		}
		printf("\n");
	}
}

/*
Menor distância saindo de um determinado verticce
*/
float ShorterDistance(struct Graph* graph, int v) {
	float menor = 0;
	//assert (v existe e é válido)
	struct AdjListNode* aux = graph->vertices[v].head;
	while (aux)
	{
		if ((aux->peso > menor) && (aux->peso != 0))
			menor = aux->peso;
		aux = aux->next;
	}
	return menor;
}

#pragma endregion


#pragma region Grafo_Pesado_Nao_Orientado_Lista_de_Adjacencias

//=========================================================
//H3 - Estruturas Dinâmicas
//=========================================================

#pragma region GerirVertices

void DestroiVertice(Node* ptNode) {
	free(ptNode->city);				//eliminar memória alocada para o nome
	free(ptNode);
}

/**
	@brief
	@param  id -
	@retval    -
	@date   23.04.2024
**/
Node* CriaVertice(int id, char nome[]) {
	Node* aux = (Node*)malloc(sizeof(Node));
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
Node* InsereVertice(Node* vertices, Node* novo, bool* res) {
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
		Node* ant = NULL;
		Node* aux = vertices;
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
bool ExisteVertice(Node* inicio, int id) {
	if (inicio == NULL) return false;
	Node* aux = inicio;
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
Node* OndeEstaVertice(Node* inicio, int id) {
	if (inicio == NULL) return NULL;
	Node* aux = inicio;
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
Node* EliminaVertice(Node* vertices, int codVertice, bool* res) {
	*res = false;
	if (vertices == NULL) return NULL;

	//procurar vertice
	Node* aux = vertices;
	Node* ant = NULL;
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
Node* EliminaAdjacenciaAllVertices(Node* vertices, int codAdj, bool* res) {
	*res = false;
	if (vertices == NULL)
		return NULL;

	Node* aux = vertices;
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
void ShowGraph(Node* graph) {
	Node* current = graph;
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
Graph3* CriaGraphH3(int tot) {
	//validações
	Graph3* aux = (Graph3*)malloc(sizeof(Graph3));
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
Graph3* InsereVerticeGrafo(Graph3* g, Node* novo, int* res) {
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

	//h1: fazer tudo diretamente aqui
	////Insere no grafo vazio
	//if (g->inicioGraph == NULL) {
	//    *res = 1;
	//    g->inicioGraph = novo;
	//    g->numeroVertices++;
	//}
	//else {
	//    //h1: Insere sempre no inicio
	//    novo->nextVertice = g->inicioGraph;
	//    g->inicioGraph = novo;

	//    //h2: insere sempre no fim
	//    Node* aux = g->inicioGraph;
	//    while (aux->nextVertice != NULL)
	//        aux = aux->nextVertice;
	//    aux->nextVertice = novo;
	//    *res = 1;

	//    //h3:insere ordenado - TPC
	//}

	//h2: invocar função que insere vertices
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
Graph3* InsereAdjaGrafo(Graph3* g, int idOrigem, int idDestino, bool* res) {

	*res = false;
	//Validações
	if (g == NULL) return NULL;
	//Verificar se vertices existem
	Node* originNode = OndeEstaVerticeGraph(g, idOrigem);
	if (originNode == NULL) return g;
	Node* destinyNode = OndeEstaVerticeGraph(g, idDestino);
	if (!destinyNode) return g;

	originNode->nextAdjacent = InsereAdj(originNode->nextAdjacent, idDestino);

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
Graph3* EliminaAdjGraph(Graph3* g, int origem, int destino, bool* res) {
	
	*res = false;

	//validações
	if (g == NULL) return NULL;
	//Verificar se vertices existem
	Node* originNode = OndeEstaVerticeGraph(g, origem);
	if (originNode == NULL) return g;
	Node* destinyNode = OndeEstaVerticeGraph(g, destino);
	if (!destinyNode) return g;

	originNode->nextAdjacent = ElimiminaAdj(originNode->nextAdjacent, destino, res);
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
Node* OndeEstaVerticeGraph(Graph3* g, int idVertice) {
	if (g == NULL) return NULL;
	return (OndeEstaVertice(g->inicioGraph, idVertice));
}

/**
	@brief  Verifica se determinado vertice existe num grafo
	@param  g         -
	@param  idVertice -
	@retval           -
	@date   23.04.2024
**/
bool ExisteVerticeGraph(Graph3* g, int idVertice) {
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
Graph3* EliminaVerticeGraph(Graph3* g, int codVertice, bool* res) {
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
void ShowGaphLA(Graph3* gr) {
	ShowGraph(gr->inicioGraph);
}

#pragma endregion

#pragma endregion