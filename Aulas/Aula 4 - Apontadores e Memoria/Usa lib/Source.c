/*****************************************************************//**
 * @file   Source.c
 * @brief  Manipular apontadores com arrays
 * 
 * @author lufer
 * @date   February 2024
 *********************************************************************/
#include "Libs\Funcoes.h"
#include <stdio.h>

#pragma comment(lib,"libs\\Apontadores e Memoria.lib")

int main(){

#pragma region Memoria

	Pessoa* aux1 = CriaPessoa("ola", 12);
	Pessoa* aux2;
	aux2 = CriaVariasPessoas(4);
	strcpy(aux2[0].nome, "");// = (char*)malloc(20 * sizeof(char));
	aux2[0].idade = 3;

	//aux2 = Inicializa(5);
	for (int i = 0; i < 5; i++) {
		Escreve(aux2[i]);
	}

#pragma endregion


#pragma region Apontadores_Structs

	//Pessoa p2;

	Pessoa* ptr2;

	//ptr = &p2;

	//ptr2=(Pessoa*)malloc(sizeof(Pessoa));
	//ptr2->idade = 20;

	//Atribuir valores
	ptr2 = (Pessoa*)malloc(50 * sizeof(Pessoa));
	if (ptr2 != NULL) {
		(ptr2 + 1)->idade = 23;
		//ou
		ptr2[2].idade = 45;
	}

	//inicializar array
	for (int i = 0; i < 50; i++)
	{
		if (ptr2 != NULL) {
			ptr2[i].idade = i;
			strcpy(ptr2[i].nome, "*");
			//ou
			//(ptr2 + i)->idade = i;
			//strcpy((ptr2 + i)->nome, "*");
		}
	}

#pragma endegion
}
