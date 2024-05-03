/*
// Grafos: Travessia em Profundidade com Matriz de Adjacências
//
// Procura em Profundidade: Stack
// Procura em Largura:		Queue
// lufer
// Consultar:
// Descrição: http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
// Aplicação: http://www.geeksforgeeks.org/applications-of-depth-first-search/
*/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include "Graphs.h"
#include "Stack.h"

//======================================================
//graph functions 
//======================================================

/*
adicionar vertice à "list" (array) de vertices
*/
int AddVertice(Vertice* lstVertices[], int numVertices, char label) {
    //assert(Não existe) && (Há espaço)
    Vertice* v = (Vertice*)malloc(sizeof(Vertice));
    if (v != NULL) {
        v->label = label;
        v->visited = false;
        lstVertices[numVertices++] = v;
    }
    return numVertices;
}

/*
Adicionar aresta ao conjunto de arestas. Grafo orientado!
E se for pesado?
*/
bool AddAresta(int adjMatrix[][MAX], int start, int end) {
    //Validações...
    adjMatrix[start][end] = 1;
    //adjMatrix[end][start] = 1;     //se for não orientado!
    return true;
}

/*
Mostra vertices do grafo
*/
void ProcessaVertice(Vertice* v) {
    //testar
    printf("%c ", v->label);
}

/*
devolve o vertice adjacente não visitado
*/
int GetVertAdjNaoVisitado(Vertice* lstVertices[], int adjMatrix[][MAX], int v) {

    for (int j = 0; j < MAX; j++) { //MELHORAR MAX?
        if (adjMatrix[v][j] == 1 && lstVertices[j]->visited == false) {
            return j;
        }
    }
    return -1;
}

/**
    @brief Apresenta grafo
    @param lst -
    @param adj -
    @param v   -
    @date  30.04.2024
**/
void ShowGraph(Vertice* lst[], int adj[][MAX], int v) {
    for (int i = 0; i < v; i++) {
        ProcessaVertice(lst[i]);
        printf("Adjacentes:\n");
        for (int j = i; j < MAX; j++) {
            if (adj[i][j] != 0) {
                printf("\tVertice: %c: Peso:%d\n", lst[j]->label, adj[i][j]);
            }
        }
    }
}

#pragma region DFT

//======================================================
//Depth First Algorithm
//======================================================

/*
DFT
Percorre todo o grafo em profundidade
Não Recursivo
*/
bool DepthFirstTraversal(Vertice* lstVertices[], int adj[][MAX],  int vOrigin) {
    int uv; //unvisitedVertice
    int proxVertice;

    //stack auxiliar
    int stack[MAX];
    int top = -1;

    if (lstVertices[vOrigin]->visited == true) return true;

    //marca vertice como visitado 
    lstVertices[vOrigin]->visited = true;
    //processa vertice origem
    ProcessaVertice(lstVertices[vOrigin]);
    //insere vertice origem na stack
    top=push(stack, top, vOrigin);

    while (!isStackEmpty(top)) {
        proxVertice = peek(stack, top);
        //encontra vertice adjacente ao que está no topo da stack e ainda não foi visitado
        uv = GetVertAdjNaoVisitado(lstVertices, adj, proxVertice);

        //se não tem adjacentes, retira o atual da stack
        if (uv == -1) {
            top=pop(stack, top);
        }
        else {
            //marca
            lstVertices[uv]->visited = true;
            //processa
            ProcessaVertice(lstVertices[uv]);
            //insere na stack
           top = push(stack, top, uv); 
        }
    }
    return true;
}

/**
    @brief  DFT Recursivo
    @param  lstVertices -
    @param  adj         -
    @param  numVertices -
    @param  vOrigin     -
    @param  stack       -
    @param  top         -
    @retval             -
    @date   29.04.2024
**/
bool DepthFirstTraversalRec(Vertice* lstVertices[], int adj[][MAX],int vOrigin) {
    lstVertices[vOrigin]->visited = true;
    ProcessaVertice(lstVertices[vOrigin]);
    for (int j = 0; j < MAX; j++) { //Melhorar: como evitar "MAX"
        if (adj[vOrigin][j] != 0 && lstVertices[j]->visited == false)
            DepthFirstTraversalRec(lstVertices, adj,  j);
    }
    lstVertices[vOrigin]->visited = false;//reset
}



/*
DFS Recursivo
Percorre o grafo em profundidade
Verifica se existe path entre origem e destino

*/
bool DepthFirstSearchRec(Vertice* lstVertices[], int adj[][MAX], int vOrigin, int destino) {
    if (vOrigin == destino) return true;
    bool res = false;
    lstVertices[vOrigin]->visited = true;
    ProcessaVertice(lstVertices[vOrigin]);

    for (int j = 0; j < MAX; j++) {
        if (adj[vOrigin][j] != 0 && lstVertices[j]->visited == false) {
            res = DepthFirstSearchRec(lstVertices, adj, j, destino);
            if (res) return true;
        }
    }
    lstVertices[vOrigin]->visited = false;//reset
    return res;
}

/*
DFS
Find if there is a path between two vertices in a directed graph
Não Recursivo
Percorre o grafo em profundidade
*/
bool DepthFirstSearch(Vertice* lstVertices[], int adj[][MAX], int vOrigin, int vertice) {
    int i;
    int uv; //unvisitedVertice
    int proxVertice;

    //stack auxiliar
    int stack[MAX];
    int top = 0;

    //validações
    if (lstVertices[vOrigin]->visited == true)
        if (vOrigin == vertice) return true;
        else
            return false;

    if (vOrigin == vertice) return true;

    //marca vertice como visitado 
    lstVertices[vOrigin]->visited = true;
    //processa vertice
    ProcessaVertice(lstVertices[vOrigin]);
    //insere vertice na stack
    top = push(stack, top, vOrigin);

    while (!isStackEmpty(top)) {
        proxVertice = peek(stack, top);
        //encontra vertice adjacente ao que está no topo da stack e ainda não foi visitado
        uv = GetVertAdjNaoVisitado(lstVertices, adj, proxVertice);

        if (uv == vertice) return true;

        //se não tem adjacentes, retira o atual da stack
        if (uv == -1) {
            top = pop(stack, top);
        }
        else {
            //marca
            lstVertices[uv]->visited = true;
            //processa
            ProcessaVertice(lstVertices[uv]);
            //insere na stack
            top = push(stack, top, uv);
        }
    }
    return false;
}


#pragma endregion


//==================================================
/* Exercício
Grafo Pesado com distâncias entre vértices (cidades)

Devolver a cidade que se encontra mais perto....e não foi visitada!!
*/
//==================================================