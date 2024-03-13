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


Inteiro* CriaInteiro(int x) {
	Inteiro* aux = (Inteiro*)malloc(sizeof(Inteiro));
	//calloc
	if (aux == NULL) return NULL;
	aux->x = x;
	aux->next = NULL;
	return aux;
}

Inteiro* Insere(Inteiro* inicio, Inteiro* novo) {
	//nada para inserir...
	if (novo == NULL) return inicio;
	//lista vazia
	if (inicio == NULL) {
		inicio = novo;
		return inicio;
	}
	//antes do inicio
	if (inicio->x > novo->x) {
		novo->next = inicio;
		inicio = novo;
	}
	else
	{
		Inteiro* aux = inicio;
		Inteiro* ant = aux;
		while (aux != NULL && aux->x < novo->x)
		{
			ant = aux;
			aux = aux->next;
		}
		//testar se é para inserir no fim
		if (aux == NULL) {
			ant->next = novo;
		}
		else  //insere entre ant e aux!!!
		{
			novo->next = aux;
			ant->next = novo;
		}
	}
	return inicio;
}

