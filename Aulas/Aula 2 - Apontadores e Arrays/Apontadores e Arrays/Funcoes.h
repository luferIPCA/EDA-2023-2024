/*****************************************************************//**
 * @file   Funcoes.h
 * @brief	Arrays e Apontadores
 *			Assinaturas de funções
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#pragma once
#include <stdbool.h>

 /**
  * @brief Calcula a soma de dois valores inteiros.
  *
  * @param x
  * @param y
  * @return
  * @author lufer
  */
extern int Sum(int x, int y);

/**
 * @brief Calcula a soma dps valores de um array de inteiros.
 *
 * @param x
 * @param y
 * @return
 * @author lufer
 */
extern int SumArray(int* valores, int size);
extern int MaxArrayPtr(int* valores, int n);
extern int MaxArray(int valores[], int n);
bool Existe(int* valores[], int size, int v);
