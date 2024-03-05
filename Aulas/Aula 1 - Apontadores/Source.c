/*****************************************************************//**
 * @file   Source.c
 * @brief  
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/

#include <stdio.h>
#include "Header.h"
#include <malloc.h>
#include <string.h>

#pragma warning (disable:4996)
#pragma warning (disable:6011)

int main() {

#pragma region Ex1

	int x, y, z;
	x = 7;
	y = &x;
	//z = *y;		CUIDADO!!

	printf("X: %d\n", x);
	printf("&X: %u\n", y);

	y++;
	printf("Y: %u\n", y);

#pragma endregion

#pragma region Ex2
	int* p;			//p é apontador para inteiro!!
	p = &x;			//p fica com o endereço de x

	x = 1;

	printf("P: %p\n", p);
	printf("&P: %p\n", &p);
	printf("*P: %d\n", *p);

#pragma endregion

#pragma region Ex3

	int *k = &p;
	x = (*k)++;
	printf("Valor de p = %p\n", p);
	printf("Valor de x = %d\n", x);
	printf("Valor de k = %p\n", k);

	x = *(k++);						//equivalente a *k++
	printf("Valor de p = %p\n", p);
	printf("Valor de x = %d\n", x);
	printf("Valor de k = %p\n", k);

	x = *k++;						//pela precedência de operadores, vale primeiro o que está à direita, 
									//depois á esquerda										
	printf("Valor de p = %p\n", p);
	printf("Valor de x = %d\n", x);
	printf("Valor de k = %p\n", k);

	// Tamanho de memória ocupado por um inteiro
	printf("int: %lu\n", sizeof(x));
	// Tamanho de memória ocupado por apontador para  inteiro
	printf("*int: %lu\n", sizeof(k));
	// Tamanho de memória ocupado por um double
	double aux;
	printf("double: %lu\n", sizeof(aux));

#pragma endregion

#pragma region Apontadores e Structs I

	Pessoa r;
	r.idade = 12;
	strcpy(r.nome, "ola");
	printf("Nome:%s\n", r.nome);

	Escreve(r);

	Pessoa* ptr;
	ptr = &r;			//aponta para a pessoa r
	ptr->idade = 13;	//coloca 13 na idade da pessoa r
	//o mesmo que:
	//(*ptr).idade = 13;
	printf("Nome:%s\n", ptr->nome);

#pragma endregion


return 0;
}




