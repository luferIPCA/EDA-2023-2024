/**

    @file      Graph_bft.c
    @brief     Grafos: Travessia em Largura com Matriz de Adjacências
    @details   Breadth First Traversal Algorithms
               Procura em Largura:		Queue
    @author    lufer
    @date      1.05.2024
    @copyright © lufer - IPCA 2024. All right reserved.

    Analisar: http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
    Aplicação: http://www.geeksforgeeks.org/applications-of-breadth-first-traversal/
**/


#include <stdio.h>  //NULL
#include <stdlib.h> //free
#include <malloc.h> //malloc
#include "Graph.h"
#include "Queue.h"


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

    for (int j = 0; j < MAX; j++) {
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

//======================================================
// Breadth First Traversal/Search Algorithm
//======================================================

/*
Travessia BFT
*/
bool BreadthFirstTraversal(Vertice* lstVertices[], int adj[][MAX], int vOrigin)
 {
    //queue variables
    int queue[MAX];
    int rear, front;

    rear = front = 0;

    bool succ = false;
    int nextVertice;

    //marca vertice como visitado 
    lstVertices[vOrigin]->visited = true;

    //insere vertice na queue 
    succ=insertQueue(queue, &rear,vOrigin);
    if (!succ) return false;

    while (!isQueueEmpty(rear,front)) {
        //trata nodo da frente da queue
        nextVertice = removeQueue(queue,&front);
        ProcessaVertice(lstVertices[nextVertice]);

        //para cada adjacente não visitado
        for (int j = 0; j < MAX; j++) {
            if (adj[nextVertice][j] == 1 && lstVertices[j]->visited == false) {
                //marca
                lstVertices[j]->visited = true;
                //insere na queue
                succ = insertQueue(queue, &rear, j);
            }
        }
    }
}

/*
Travessia BFT
*/
bool BreadthFirstSearch(Vertice* lstVertices[], int adj[][MAX], int vOrigin, int valor)
{
    //queue variables
    int queue[MAX];
    int rear, front;

    rear = front = 0;

    bool succ = false;
    int nextVertice;

    if (vOrigin == valor) return true;  //encontrou!

    //marca vertice como visitado 
    lstVertices[vOrigin]->visited = true;
    //insere vertice na queue 
    succ = insertQueue(queue, &rear, vOrigin);
    if (!succ) return false;

    while (!isQueueEmpty(rear, front)) {
        //trata nodo da frente da queue
        nextVertice = removeQueue(queue, &front);
        if (nextVertice == valor) return true;
        ProcessaVertice(lstVertices[nextVertice]);

        //para cada adjacente não visitado
        for (int j = 0; j < MAX; j++) {
            if (adj[nextVertice][j] == 1 && lstVertices[j]->visited == false) {
                //marca
                lstVertices[j]->visited = true;
                //insere na queue
                succ = insertQueue(queue, &rear, j);
                if (nextVertice == valor) return true;
            }
        }
    }
    return false;
}



bool resetVertices(Vertice* lstVertices[], int numVertices) {
    if (numVertices <= 0 || numVertices>MAX) return false;
    for (int i = 0; i < numVertices; i++) {
        lstVertices[i]->visited = false;
    }
}

 
// 
/**
    @brief              - Breadth First Traversal Recursive
    @param  lstVertices - 
    @param  adj         - 
    @param  vOrigin     - 
    @param  queue       - 
    @retval             - 
    @date   2.05.2024
    @see https://www.techiedelight.com/breadth-first-search/
**/


//BreadthFirstSearch