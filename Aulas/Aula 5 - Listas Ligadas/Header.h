#pragma once
#include <stdbool.h>

#define N 20

//h1
typedef struct Pessoa {
	int idade;
	char nome[N];
	struct Pessoa* prox;
}Pessoa;

//h2
typedef struct PessoaLista {
	Pessoa p;
	struct PessoaLista* prox;
};

//h3
typedef struct PessoaListaII {
	Pessoa *p;
	struct PessoaListaII* prox;
};

#pragma region h1

Pessoa* CriaPessoa(char* nome, int idade);
bool MostraPessoa(Pessoa* p);
bool MostraTodasPessoas(Pessoa* p);
Pessoa* InserePessoaInicio(Pessoa* inicio, Pessoa* nova);
Pessoa* InserePessoaFim(Pessoa* inicio, Pessoa* nova);

#pragma endregion
