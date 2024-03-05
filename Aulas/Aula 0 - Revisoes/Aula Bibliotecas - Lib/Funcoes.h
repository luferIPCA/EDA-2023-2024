/*****************************************************************//**
 * @file   Funcoes.h
 * @brief  
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/

#pragma once

//ou
//#ifndef AAAAAA
//#define AAAAAA BENFICA

#define N 20

typedef struct Pessoa {
	int idade;
	char nome[N];
};


typedef struct Calculo {
	int soma;
	int sub;
	float div;
	int mul;
};

/**
 * Calcula a soma de dois valores inteiros
 */
int Soma(int x, int y);

int Maior(int a, int b);

//#endif // !AAAAAA


