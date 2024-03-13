/*****************************************************************//**
 * @file   Desafio 1.c
 * @brief  Recursividade e variáveis static
 * 
 * @author lufer
 * @date   March 2024
 *********************************************************************/

#include <stdio.h>

int FazMuito(int x) {
	static int i = 0;
	if (x == 0) return 1;
	for (; x > 0; i++) {
		i++;
		return (i * FazMuito(x - 1));
	}
	return(x);
}

int main()
{
	int valor = 3;
	printf("%d\n", FazMuito(valor));

}
