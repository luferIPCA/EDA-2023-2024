/*****************************************************************//**
 * @file   Funcoes.c
 * @brief  Implementa funcões sobre structs ligadas
 * 
 * @author lufer
 * @date   March 2024
 *********************************************************************/
#include <malloc.h>
#include "Dados.h"
#include <string.h>

#pragma warning (disable: 4996)
/**
 * @brief Aloca espaço em menória
 * 
 * @param nome
 * @param idade
 * @return 
 * @author lufer
 *
 */
Pessoa* CriaPessoa(char* nome, int idade) {
	Pessoa* aux = (Pessoa*)malloc(sizeof(Pessoa));
	if (aux == NULL) return aux;
	//Coloca dados
	aux->idade = idade;
	aux->nome = (char*)malloc(sizeof(char) * strlen(nome));
	if(aux->nome!=NULL) strcpy(aux->nome, nome);
	//Inicializa apontador para próximo
	aux->prox = NULL;
	return aux;
}
