#pragma once
#include <stdbool.h>

#define N 20

//h0
typedef struct PessoaFile {
	int idade;
	char nome[N];
}PessoaFile;

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
}PessoaLista;

//h3
typedef struct PessoaListaII {
	Pessoa *p;
	struct PessoaListaII* prox;
}PessoaListaII;

#pragma region h1

Pessoa* CriaPessoa(char* nome, int idade);
bool MostraPessoa(Pessoa* p);
bool MostraTodasPessoas(Pessoa* p);
Pessoa* InserePessoaInicio(Pessoa* inicio, Pessoa* nova);
Pessoa* InserePessoaFim(Pessoa* inicio, Pessoa* nova);
Pessoa* InserePessoa(Pessoa* inicio, Pessoa* nova, bool* res);
Pessoa* RemoveAll(Pessoa* inicio);
Pessoa* RemovePessoa(Pessoa* ini, char* nome, bool* res);
Pessoa* OrdenaPessoas(Pessoa* ini, bool*r);
Pessoa* AlterarIdadePessoa(Pessoa* ini, char* nome, char idade, bool* res);

//ficheiros
bool SaveAll(char* fileName, Pessoa* inicio);
Pessoa* LoadAll(char* fileName, bool* r);
bool SaveII(char* fileName, Pessoa* inicio);
Pessoa* LoadII(char* fileName, bool* r);
bool ToCsv(char* fileName, Pessoa* inicio);
Pessoa* readCsv(char* fileName, bool* r);
#pragma endregion
