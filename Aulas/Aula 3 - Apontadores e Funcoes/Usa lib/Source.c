/*****************************************************************//**
 * @file   Source.c
 * @brief  Manipular apontadores com arrays
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#include "Libs\Funcoes.h"
#include <stdio.h>

#pragma comment(lib,"libs\\Apontadores e Funcoes.lib")

int main(){

#pragma region Arrays-Apontadores-Funções

	int valores[] = { 23,45,-1 };
	int y = SumArray(valores, 3);

	y = MaxArray(valores, 3);

	y = MaxArrayPtr(valores, 3);

	bool aux = Existe(valores, 3,-1);

#pragma endregion

}
