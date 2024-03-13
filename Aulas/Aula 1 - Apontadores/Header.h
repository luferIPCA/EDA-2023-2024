/*****************************************************************//**
 * @file   Header.h
 * @brief  Descreve....
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

void Escreve(Pessoa p);



typedef struct Inteiro {
	int x;
	struct Inteiro* next;
}Inteiro;

Inteiro* CriaInteiro(int x);

Inteiro* Insere(Inteiro* inicio, Inteiro* novo);
//TPC
Inteiro* InsereII(Inteiro* inicio, Inteiro* novo, bool*r);



