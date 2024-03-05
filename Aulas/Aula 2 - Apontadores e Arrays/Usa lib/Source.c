/*****************************************************************//**
 * @file   Source.c
 * @brief  Manipular apontadores com arrays
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#include "Libs\Funcoes.h"
#include <stdio.h>

#pragma comment(lib,"libs\\Apontadores e Arrays.lib")

int main(){
	
#pragma region ArraysSimples - Revis�o

	int valores[] = { 3,2,4,6 };
	// Como calcula o tamanho do array???
	// Ver sizeof(valores)
	int size = sizeof(valores) / sizeof(valores[0]);

	//Visualizar o conte�do do array
	for (int i = 0; i < size; i++) {
		printf("Valores[%d]=%d\n", i, valores[i]);
	}

	// endere�o de mem�ria do array valores
	printf("&Valores: %p\n", valores);

	// endere�o de mem�ria do 1� elemento do array valores
	printf("&Valores[0]: %p\n", &valores[0]);
	/*
	Conclus�o:
	 O nome do array corresponde ao endere�o
	 da primeira posi��o do array
	 valores == &valores[0]
	*/

	//Express�es equivalentes
	int* xx = &valores[0];
	int* yy = valores;

	printf("Valores[0]=%d - %d\n", *xx, *yy);

#pragma endregion

#pragma region ArrayApontadores

	int* ptrArray[N];
	//Inicializar o array
	for (int i = 0; i < N; i++) {
		ptrArray[i] = NULL;
	}
	ptrArray[0] = &p;
	*(ptrArray[0]) = 123;

	printf("*ptrArray[0]%d\n", *(ptrArray[0]));

	//Visualizar as variaveis que ptrArray aponta
	for (int i = 0; i < 5; i++) {
		printf("ptrArray[%d]=%p\n", i, ptrArray[i]);
		if (ptrArray[i] == NULL) continue;
		printf("*ptrArray[%d]=%d\n", i, *ptrArray[i]);
	}

	//Outro Exemplo
	int a = 5, b = 10, c = 15, d = 20, e = 25;
	int* ptrArray2[5] = { &a, &b, &c, &d, &e };

	for (int i = 0; i < 5; i++) {
		printf("Valor de ptrArray2[%d] = %p\n", i, ptrArray2[i]);
		printf("Valor de *ptrArray2[%d] = %d\n", i, *ptrArray2[i]);
	}

	//ATEN��O
	//&x[0] � equivalente a x
	//x[0] � equivalente a *x
	//&x[i] � equivalente a x + i
	//x[i] � equivalente a *(x + i).

#pragma endregion

#pragma region Arrays-Apontadores-Fun��es

	int x = Sum(2, 3);

	int valores[] = { 23,45,-1 };
	int y = SumArray(valores, 3);

	y = MaxArray(valores, 3);

	y = MaxArrayPtr(valores, 3);

	bool aux = Existe(valores, 3,-1);

#pragma endregion

}
