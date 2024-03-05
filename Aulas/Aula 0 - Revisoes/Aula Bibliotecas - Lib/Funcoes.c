/*****************************************************************//**
 * @file   Funcoes.c
 * @brief  
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#include "Funcoes.h"

/**
 * @brief .
 * 
 * @param a
 * @param b
 * @return 
 * @author lufer
 *
 */
int Soma(int a, int b) {
	return a + b;
}

/**
 * @brief .
 * 
 * @param x
 * @param y
 * @return 
 * @author lufer
 *
 */
int Maior(int x, int y) {
	//return((x > y) ? x : y);	// ? :

	if (x > y) return x;
	else
		return y;
}
