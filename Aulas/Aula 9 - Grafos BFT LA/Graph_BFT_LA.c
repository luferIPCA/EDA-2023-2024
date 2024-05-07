/**

    @file      Graph_BFT_LA.c
    @brief     Grafos: Travessia em Largura com Lista de Adjacências
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

#include "Queue.h"
#include "LAGraph.h"

#define MAX 10

//======================================================
// graph functions : estão na biblioteca
//======================================================


//======================================================
// Breadth First Traversal/Search Algorithm
//======================================================

void ProcessaVertice(Vertice* v) {
    printf("%d | ", v->id);
}

/*
Travessia BFT
*/
bool BreadthFirstTraversalLA(Graph*g, int vOrigin)
 {
    //queue variables
    int queue[MAX];
    int rear, front;

    rear = front = 0;

    bool succ = false;
    int nextVertice;

    Vertice* lstVertices = g->inicioGraph;

    //marca vertice como visitado 
    Vertice* aux = GetVertice(lstVertices, vOrigin);
    if (aux == NULL) return false;
    aux->visited = true;
    
    //insere vertice na queue 
    succ=insertQueue(queue, &rear,vOrigin);
    if (!succ) return false;

    while (!isQueueEmpty(rear,front)) {
        //trata nodo da frente da queue
        nextVertice = removeQueue(queue,&front);
        aux = GetVertice(lstVertices, nextVertice);
        if (aux == NULL) return false;
        ProcessaVertice(aux);

        Adjacent* adj = aux->nextAdjacent;
        while (adj) {
            aux = GetVertice(lstVertices, adj->id);
            if (aux->visited == false)
            {
                aux->visited = true;
                succ = insertQueue(queue, &rear, adj->id);
            }
            adj = adj->next;
        }
    }
}

/*
Travessia BFT
*/
bool BreadthFirstSearchLA(Graph* g, int vOrigin, int valor)
{
    // Auxiliar variables
    // Queue
    int queue[MAX];
    int rear, front;
    rear = front = 0;

    bool succ = false;
    int nextVertice;

    Vertice* lstVertices = g->inicioGraph;

    //marca vertice como visitado 
    Vertice* aux = GetVertice(lstVertices, vOrigin);
    if (aux == NULL) return false;
    if (aux->id == valor) return true;
    aux->visited = true;

    //insere vertice na queue 
    succ = insertQueue(queue, &rear, vOrigin);
    if (!succ) return false;

    while (!isQueueEmpty(rear, front)) {
        //trata nodo da frente da queue
        nextVertice = removeQueue(queue, &front);
        aux = GetVertice(lstVertices, nextVertice);
        if (aux == NULL) return false;
        if (aux->id == valor) return true;
        ProcessaVertice(aux);

        Adjacent* adj = aux->nextAdjacent;
        while (adj) {
            aux = GetVertice(lstVertices, adj->id);
            if (aux->visited == false)
            {
                aux->visited = true;
                succ = insertQueue(queue, &rear, adj->id);
            }
            adj = adj->next;
        }
    }
    return false;
}



Vertice* ResetVertices(Vertice* inicio) {
    Vertice* aux = inicio;
    while (aux) {
        aux->visited = false;
        aux = aux->nextVertice;
    }
    return inicio;
}

 