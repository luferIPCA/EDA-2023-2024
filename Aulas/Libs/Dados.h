/*****************************************************************//**
 * @file   Dados.h
 * @brief  Definição de estruturas de Dados
 * 
 * @author lufer
 * @date   March 2024
 *********************************************************************/
#pragma once

#pragma region H1
 // Dados da Pessoa contém apontador para proxima pessoa

 /**
  * Define uma pessoa.
  */

typedef struct Pessoa {
	int idade;
	char* nome;
	struct Pessoa* prox;
}Pessoa ;

#pragma endregion

#pragma region H2
// Dados da Pessoa constam na célula da lista

///**
// * Define uma pessoa.
// */
//typedef struct Pessoa {
//	int idade;
//	char* nome;
//}Pessoa;
//
///**
// * Define uma célua que agrupa várias pessoas.
// */
//typedef struct Pessoas {
//	Pessoa p;
//	Pessoa* prox;
//}Pessoas;

#pragma endregion

#pragma region H3
// Dados da Pessoa constam fora da  célula da lista
// 
//typedef struct Pessoa {
//	int idade;
//	char* nome;
//}Pessoa;
//
//typedef struct ListaPessoa {
//	Pessoa* dados;
//	ListaPessoa* prox;
//}ListaPessoa;

#pragma endregion

Pessoa* CriaPessoa(char* nome, int idade);
