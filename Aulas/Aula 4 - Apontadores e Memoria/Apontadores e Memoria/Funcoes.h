/*****************************************************************//**
 * @file   Funcoes.h
 * @brief	Alocação dinâmica de memória
 *			Assinaturas de funções
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#pragma once
#include <stdbool.h>

#define N 20

typedef struct Pessoa {
	char nome[N];
	int idade;
}Pessoa;


/**
 * Cria uma nova pessoa.
 */
Pessoa* CriaPessoa(char* nome, int idade);

/**
 * Cria espaço para várias pessoas (array).
 */
Pessoa* CriaVariasPessoas(int quantas);

/**
 * @brief	Cria espaço em memória:
 *			se n==1, para um inteiro
 *			se n>1, para um array de inteiros.
 *
 * @param n
 * @return
 * @author lufer
 *
 */
int* CriaArray(int n);


