#pragma once
/*
// Grafos Não Orientados | Orientados
//
// Procura em Profundidade: Stack
// Procura em Largura:		Queue
// lufer
// Consultar: 
//	https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
//	http://www.tutorialspoint.com/data_structures_algorithms/depth_first_traversal_in_c.htm
*/

#include <stdbool.h>

// =====================================================
// Depth First Algorithm : STACK
// =====================================================

//funções da stack

int push(int stack[], int top, int item);
int pop(int stack[], int top);
int peek(int stack[], int top);
bool isStackEmpty(int top);

