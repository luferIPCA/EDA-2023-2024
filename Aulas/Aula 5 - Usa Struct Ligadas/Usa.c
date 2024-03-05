#include <stdio.h>
#include "..\Libs\Dados.h"


#pragma comment (lib,"..\\Libs\\Aula 5 - Structs Ligadas.lib")
int main() {

	Pessoa* p = CriaPessoa("Ana", 12);
	Pessoa* head;
	head = p;

	printf("Nome: %s\n", p->nome);
	printf("Idade: %d\n", p->idade);

	printf("Head- Nome: %s\n", head->nome);
	printf("Head - Idade: %d\n", head->idade);
	

	head->prox = CriaPessoa("Jose", 13);

	printf("Nome: %s\n", head->prox->nome);
	printf("Idade: %d\n", head->prox->idade);

}
