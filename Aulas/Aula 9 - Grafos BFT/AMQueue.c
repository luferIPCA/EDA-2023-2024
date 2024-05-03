/*
// Grafos: Travessia em Largura com Matriz de Adjacências
//
// Procura em Largura:		Queue
// lufer
*/

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "Graph.h"
#include "Queue.h"
// Analisar: http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
// Aplicação: http://www.geeksforgeeks.org/applications-of-breadth-first-traversal/

// Queue functions 
 
bool insertQueue(int queue[], int *rear, int data) {;
	//testes
   queue[(*rear)++] = data; 
   return true;
} 
 
int removeQueue(int queue[], int *front) { 
   return queue[(*front)++];  
} 
 
bool isQueueEmpty(int rear, int front) {
   return rear == front; 
} 
 

 