/*
Apontadores
Aritmetica de apontadores
lufer

ATENÇÃO:

1) Precedence of prefix ++ and * is same. Associativity of both is right to left.
	Ex: ++*k
2) Precedence of postfix ++ is higher than both * and prefix ++. Associativity of postfix ++ is left to right.
	Ex: *k++

a)	The expression ++*p has two operators of same precedence, so compiler looks for associativity. 
	Associativity of operators is right to left. 
	Therefore the expression is treated as ++(*p).

b) The expression *p++ is treated as *(p++) as the precedence of postfix ++ is higher than *.
	
c) The expression *++p has two operators of same precedence, so compiler looks for associativity. 
	Associativity of operators is right to lef.
	Therefore the expression is treated as *(++p)

	Ver: https://www.geeksforgeeks.org/operators-in-c/
*/

#include "Header.h"
#include <stdio.h>





int main() {

#pragma region Basico
	int p = 7;
	
	printf("Valor de p = %d\n", p);
	printf("p está na posicao = %p\n", &p);

	int* k;								//k apontador para inteiro
	//O que faz isto?
	k = p;								//k fica com valor de p
										//k não aponta para p
	//printf("Valor de k = %p\n", k);
	//printf("Apontado por k = %d\n", *k);	//CUIDADO!!!

	k = &p;								//k fica com endereço de p
										//k aponta para p
	printf("Valor de k = %p\n", k);
	printf("Apontado por k = %d\n", *k);
#pragma endregion

#pragma region Ex1

	int x = (*k)++;
	printf("Valor de p = %d\n", p);
	printf("Valor de x = %d\n", x);
	printf("Valor de k = %p\n", k);

	x = *(k++);						//equivalente a *k++
	printf("Valor de p = %d\n", p);
	printf("Valor de x = %d\n", x);
	printf("Valor de k = %p\n", k);

	x = *k++;						//pela precedência de operadores, vale primeiro o que está à direita, 
									//depois á esquerda										
	printf("Valor de p = %d\n", p);
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

#pragma region Structs

	Pessoa p1;
	p1.idade = 2;
	strcpy(p1.nome, "Ola");

	printf("Nome: %s\n", p1.nome);

	Pessoa* ptr;		//Apontador para pessoa
	ptr = &p1;			//ptr aponta para p1

	int idade = (*ptr).idade;
	idade = ptr->idade;
	strcpy(ptr->nome, "");

	/*
	* (*ptr).campo == ptr->campo
	*/

	printf("Nome: %s\n", ptr->nome);
	printf("&p1: %p\n", &p1);
	printf("ptr: %p\n", ptr);

#pragma endregion

#pragma region Arrays

#pragma region ArraysSimples

	int valores[] = { 3,2,4,6 };
	// Como calcula o tamanho do array???
	// Ver sizeof(valores)
	int size = sizeof(valores) / sizeof(valores[0]);

	//Visualizar o conteúdo do array
	for (int i = 0; i < size; i++) {
		printf("Valores[%d]=%d\n", i, valores[i]);
	}

	// endereço de memória do array valores
	printf("&Valores: %p\n", valores);

	// endereço de memória do 1º elemento do array valores
	printf("&Valores[0]: %p\n", &valores[0]);
	/*
	Conclusão:
	 O nome do array corresponde ao endereço
	 da primeira posição do array
	 valores == &valores[0]
	*/

	//Expressões equivalentes
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
		printf("*ptrArray[%d]=%d\n", i, *(ptrArray[i]));
	}

	//Outro Exemplo
	int a = 5, b = 10, c = 15, d = 20, e = 25;
	int* ptrArray2[5] = { &a, &b, &c, &d, &e };

	for (int i = 0; i < 5; i++) {
		printf("Valor de ptrArray2[%d] = %p\n", i, ptrArray2[i]);
		printf("Valor de *ptrArray2[%d] = %d\n", i, *ptrArray2[i]);
	}
#pragma endregion

#pragma endregion

#pragma region Ex2

	int arr[] = { 10, 20 };
	int* n = arr;
	//n = &arr[0];
	++*n;
	printf("arr[0] = %d, arr[1] = %d, *n = %d\n",
		arr[0], arr[1], *n);

#pragma endregion

#pragma region Ex3

	int arr1[] = { 10, 20 };
	int* q = arr;
	q = &arr[0];
	*q++;
	printf("arr[0] = %d, arr[1] = %d, *q = %d\n",
		arr1[0], arr1[1], *q);
#pragma endregion

#pragma region Ex4
	int arr2[] = { 10, 20 };
	int* r = arr;
	*++r;
	printf("arr[0] = %d, arr[1] = %d, *r = %d\n",
		arr[0], arr[1], *r);
#pragma endregion

	//char nome[50];
	char* nome = (char*)malloc(sizeof(char) * 10);

	Aluno a1;
	a1.numero = 12;
	a1.nome = (char*)malloc(sizeof(char) * strlen("Andre"));
	strcpy(a1.nome, "Andre");


	Aluno* a2 = CriaAluno("ola", 12);

	Aluno* turma = CriaTurma(45);

	turma->numero = 12;
	turma->nome = (char*)malloc(sizeof(char) * strlen("Ola"));
	strcpy(turma->nome, "ola");

	(turma + 1)->numero = 2;
	(turma+1)->nome = (char*)malloc(sizeof(char) * strlen("Ola1"));
	strcpy((turma+1)->nome, "ola1");

	int pos;
	bool existe = ExisteAluno(turma, 45, 12, &pos);


	Clube *c;
	Clube* inicio=NULL;

	c = (Clube*)malloc(sizeof(Clube));

	if(inicio==NULL) inicio = c;

	inicio = InsereClube(inicio, c);

	c = CriaClube("Braga", 100);
	inicio = InsereClube(inicio, c);

	printf("Total: %d\n", PercorreListaClubes(inicio));

	int t;
	Clube* exist = QuantosExistemClube(inicio, "Braga",&t);

	printf("Total Bragas: %d\n", PercorreListaClubes(exist));

	return 0;
}






