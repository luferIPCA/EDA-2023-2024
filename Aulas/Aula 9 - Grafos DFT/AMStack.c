/*
// Grafos: Travessia em Profundidade com Matriz de Adjacências
//
// Procura em Profundidade: Stack
// Procura em Largura:		Queue
// lufer
// Consultar:
// Descrição: http://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
// Aplicação: http://www.geeksforgeeks.org/applications-of-depth-first-search/
// Exercicio:
// Analisar http://www.thecrazyprogrammer.com/2014/03/depth-first-search-dfs-traversal-of-a-graph.html

*/

#include <stdbool.h>
#include "Stack.h"


//======================================================
//Stack Functions
//======================================================
int push(int stack[], int top, int item) {  
    stack[++top] = item; 
    return top;
}  
 
int pop(int stack[], int top) {
   return --top;
}  
 
int peek(int stack[], int top) {
   return stack[top]; 
} 
 
bool isStackEmpty(int top) {
   return (top == -1); 
} 

