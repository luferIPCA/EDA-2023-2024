#include "Header.h"
#include <stdio.h>

int main() {

	Pessoa* p = CriaPessoa("Ana", 12);
	bool aux = MostraPessoa(p);

	//Apontador inicio da Lista
	Pessoa* inicio = NULL;

#pragma region ManipulaListaDiretamente

	//Inserir no inicio
	if (inicio == NULL)
		inicio = p;
	p = CriaPessoa("Pedro", 13);

	//Insere no inicio
	p->prox = inicio;
	inicio = p;
	
	p = CriaPessoa("Maria", 14);

	//Insere no fim
	inicio->prox->prox = p;

	MostraTodasPessoas(inicio);

#pragma endregion

#pragma region ManipulaListaFuncoes

	p = CriaPessoa("Nova", 10);
	inicio = InserePessoaInicio(inicio, p);
	printf("NOVA\n");
	MostraTodasPessoas(inicio);

	p = CriaPessoa("FIM", 10);
	inicio = InserePessoaFim(inicio, p);
	MostraTodasPessoas(inicio);

#pragma endregion
}
