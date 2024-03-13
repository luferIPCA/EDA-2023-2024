#include "Header.h"
#include <stdio.h>
#include <string.h>

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

	printf("\nINICIO\n");
	p = CriaPessoa("Nova", 10);
	inicio = InserePessoaInicio(inicio, p);
	MostraTodasPessoas(inicio);

	printf("\nFIM\n");
	p = CriaPessoa("FIM", 10);
	inicio = InserePessoaFim(inicio, p);
	MostraTodasPessoas(inicio);

	//Insere ordenado
	printf("\nPOR ORDEM\n");
	p = CriaPessoa("Paulo", 12);
	inicio = InserePessoa(inicio, p, &aux);
	if (aux == true) {
		puts("Sucesso!!!");
		MostraTodasPessoas(inicio);
	}
	//Ordenação
	Pessoa* ordenada = OrdenaPessoas(inicio, &aux);
	puts("\nORDENADA\n");
	MostraTodasPessoas(ordenada);
	puts("\nAntes\n");
	MostraTodasPessoas(inicio);

	//Remover
	puts("\nREMOVIDO\n");
	inicio = RemovePessoa(inicio, "Nova",&aux);
	MostraTodasPessoas(inicio);

	//ALtera idade
	puts("\nALTERADO\n");
	inicio = AlterarIdadePessoa(inicio, "Paulo", 72, &aux);
	MostraTodasPessoas(inicio);

#pragma endregion


#pragma region Files

#pragma region FileBinario

	aux = SaveAll("dados.bin", inicio);
	inicio = RemoveAll(inicio);
	puts("Após Limpar!!!");
	MostraTodasPessoas(inicio);
	aux = false;
	inicio = LoadAll("dados.bin", &aux);
	if (aux == true) MostraTodasPessoas(inicio);

	//h0
	puts("\n Nova Abordagem \n");
	aux = SaveII("dadosII.bin", inicio);
	inicio = RemoveAll(inicio);
	MostraTodasPessoas(inicio);
	aux = false;
	inicio = LoadII("dadosII.bin", &aux);
	if (aux == true) MostraTodasPessoas(inicio);

#pragma endregion

#pragma region FileCSV

	aux = ToCsv("dados.csv", inicio);

	inicio = RemoveAll(inicio);
	puts("\nVeio do CSV!!!");
	inicio = readCsv("dados.csv", &aux);
	if (aux) 
		MostraTodasPessoas(inicio);

#pragma endregion

#pragma endregion
}
