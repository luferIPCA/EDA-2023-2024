#pragma once
/*****************************************************************//**
 * @file   Header.h
 * @brief  Listas Ligadas.
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/

/**
 * .
 */
#define N 20

#include <stdbool.h>

typedef struct Clube {
	char nome[N];
	float socios;
	struct Clube* next;
}Clube, *ClubePtr;


Clube* InsereClube(Clube* ini, Clube* novo);
Clube* CriaClube(char* nome, float s);
int PercorreListaClubes(Clube* ini);
Clube* QuantosExistemClube(Clube* ini, char* nome, int* tot);
