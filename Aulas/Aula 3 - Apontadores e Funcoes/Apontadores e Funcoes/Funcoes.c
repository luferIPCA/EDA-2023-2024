/*****************************************************************//**
 * @file   Funcoes.c
 * @brief	Arrays e Apontadores
 *			Implementação de funções de manipulação
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#include "Funcoes.h"


/**
 * @brief	Calcula a soma de um array de valores.
 *			Array passa como apontador
 * 
 * @param valores
 * @param size
 * @return 
 * @author lufer
 *
 */
int SumArray(int* valores, int size) {
	int soma = 0;
	for (int i = 0; i < size; i++) {
		soma += valores[i];
	}
	return soma;
}

/**
 * @brief	Encontra o maior valor de um array.
 *			Array passa como apontador
 * 
 * @param valores
 * @param n
 * @return 
 * @author lufer
 *
 */
int MaxArrayPtr(int* valores, int n) {
	int *max = valores;		
	//equivalente a
	//int *max = &valores[0];
	for (int i = 1; i < n; i++)
	{
		if (*max < *(valores + i)) *max = *(valores + i);
	}
	return *max;
}

/**
  * @brief	Encontra o maior valor de um array.
 *			Array passa como parametro normal
 * 
 * @param valores
 * @param n
 * @return 
 * @author lufer
 *
 */
int MaxArray(int valores[], int n) {
	int max = valores[0];
	for (int i = 1; i < n; i++)
		if (max < valores[i]) max = valores[i];
	return max;
}

/**
 * @brief	Encontra determinado valor num array de apontadores.
 *			Passsa um array de aprontadores
 * @param valores
 * @param size
 * @param v
 * @return 
 * @author lufer
 *
 */
bool Existe(int* valores[], int size, int v) {
	int* p = valores;
	for (int i = 0; i < size; i++) {
		if (*(p + i) == v) return true;
	}
	return false;
}

