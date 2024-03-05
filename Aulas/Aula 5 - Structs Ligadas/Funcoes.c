/*****************************************************************//**
 * @file   Funcoes.c
 * @brief  Implementa func�es sobre structs ligadas
 * 
 * @author lufer
 * @date   March 2024
 *********************************************************************/
#include <malloc.h>
#include "Dados.h"
#include <string.h>

#pragma warning (disable: 4996)
/**
 * @brief Aloca espa�o em men�ria
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
	//Inicializa apontador para pr�ximo
	aux->prox = NULL;
	return aux;
}
