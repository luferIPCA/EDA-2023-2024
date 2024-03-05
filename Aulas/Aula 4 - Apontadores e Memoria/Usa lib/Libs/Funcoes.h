/*****************************************************************//**
 * @file   Funcoes.h
 * @brief	Aloca��o din�mica de mem�ria
 *			Assinaturas de fun��es
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
 * Cria espa�o para v�rias pessoas (array).
 */
Pessoa* CriaVariasPessoas(int quantas);

/**
 * @brief	Cria espa�o em mem�ria:
 *			se n==1, para um inteiro
 *			se n>1, para um array de inteiros.
 *
 * @param n
 * @return
 * @author lufer
 *
 */
int* CriaArray(int n);


