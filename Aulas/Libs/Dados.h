/*****************************************************************//**
 * @file   Dados.h
 * @brief  Defini��o de estruturas de Dados
 * 
 * @author lufer
 * @date   March 2024
 *********************************************************************/
#pragma once

#pragma region H1
 // Dados da Pessoa cont�m apontador para proxima pessoa

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
// Dados da Pessoa constam na c�lula da lista

///**
// * Define uma pessoa.
// */
//typedef struct Pessoa {
//	int idade;
//	char* nome;
//}Pessoa;
//
///**
// * Define uma c�lua que agrupa v�rias pessoas.
// */
//typedef struct Pessoas {
//	Pessoa p;
//	Pessoa* prox;
//}Pessoas;

#pragma endregion

#pragma region H3
// Dados da Pessoa constam fora da  c�lula da lista
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
