/*****************************************************************//**
 * @file   Funcoes.c
 * @brief	Aloca��o din�mica de mem�ria
 *			Implementa��o de fun��es de manipula��o
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#include "Funcoes.h"
#include <stdio.h>


 /**
  * @brief Cria espa�o em mem�ria para uma nova pessoa
  *
  * @param nome
  * @param idade
  * @return
  * @author lufer
  */
Pessoa* CriaPessoa(char* nome, int idade) {
	Pessoa* aux = (Pessoa*)malloc(1 * sizeof(Pessoa));
	//Pessoa* aux = (Pessoa*)calloc(1,sizeof(Pessoa));
	if (aux != NULL) {
		strcpy(aux->nome, nome);
		aux->idade = idade;
	}
	return aux;
}

/**
 * @brief Cria espa�o em mem�ria para v�rias pessoas (array).
 * 
 * @param quantas
 * @return 
 * @author lufer
 *
 */
Pessoa* CriaVariasPessoas(int quantas) {
	if (quantas <= 0) return NULL;
	Pessoa* aux = (Pessoa*)malloc(quantas * sizeof(Pessoa));
	return aux;
}

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
int* CriaArray(int n) {
	return ((int*)malloc(n * sizeof(int)));
}

