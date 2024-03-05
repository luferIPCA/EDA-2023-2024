/*****************************************************************//**
 * @file   Funcoes.c
 * @brief  
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#include "Header.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#pragma warning (disable:4996)

void Escreve(Pessoa p) {
	printf("Nome:%s\n", p.nome);
	printf("Idade:%d\n", p.idade);
}


