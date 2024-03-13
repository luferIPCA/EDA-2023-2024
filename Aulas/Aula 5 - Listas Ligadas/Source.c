/*****************************************************************//**
 * @file   Source.c
 * @brief  Implementação de funções que manipulam uma Lista Ligada Simples
 * 
 * @author lufer
 * @date   March 2024
 *********************************************************************/
#include "Header.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning (disable:4996)

/**
 * @brief Aloca espaço na memoria ....
 * 
 * @param nome
 * @param idade
 * @return 
 * @author lufer
 *
 */
Pessoa* CriaPessoa(char* nome, int idade) {
	Pessoa* aux = (Pessoa*)malloc(sizeof(Pessoa));
	if (aux == NULL) return NULL;
	aux->idade = idade;
	strcpy(aux->nome, nome);
	aux->prox = NULL;
	return aux;
}

/**
 * @brief Mostra os dados de uma pessoa.
 * 
 * @param p
 * @return 
 * @author lufer
 *
 */
bool MostraPessoa(Pessoa* p) {
	if (p == NULL) return false;
	printf("Nome: %s\n", p->nome);
	printf("Idade: %d\n", p->idade);
	return true;
}

/**
 * @brief Mostra todas as pessoas existentes na lista.
 * 
 * @param inicio
 * @return 
 * @author lufer
 *
 */
bool MostraTodasPessoas(Pessoa* inicio) {
	if (inicio == NULL) return false;
	Pessoa* aux = inicio;
	while (aux != NULL) {	//enquanto não chegar ao fim
		MostraPessoa(aux);
		aux = aux->prox;
	}
	return true;
}

/**
 * @brief Insere uma pessoa no inicio da Lista.
 * 
 * @param inicio
 * @param nova
 * @return 
 * @author lufer
 *
 */
Pessoa* InserePessoaInicio(Pessoa* inicio, Pessoa* nova) {
	if (nova == NULL) return inicio;
	if (inicio == NULL)
		inicio = nova;
	else
	{
		nova->prox = inicio;
		inicio = nova;
	}
	return inicio;
}

/**
 * @brief Insere uma pessoa no final da lista.
 * 
 * @param inicio
 * @param nova
 * @return 
 * @author lufer
 *
 */
Pessoa* InserePessoaFim(Pessoa* inicio, Pessoa* nova) {
	if (nova == NULL) return inicio;
	if (inicio == NULL)
		inicio = nova;
	else
	{
		Pessoa* aux = inicio;
		while (aux->prox != NULL) aux = aux->prox;
		aux->prox = nova;
	}
	return inicio;
}

/**
 * @brief Insere nova pessoa de forma ordenada.
 * 
 * @param inicio
 * @param nova
 * @param res
 * @return 
 * @author lufer
 *
 */
Pessoa* InserePessoa(Pessoa* inicio, Pessoa* nova, bool* res) {
	if ((nova == NULL))
	{
		*res = false;
		return NULL;
	}
	Pessoa* aux = inicio;
	//insere à cebeça da lista
	if (inicio==NULL || strcmp(nova->nome, inicio->nome) < 0) {
		inicio = InserePessoaInicio(inicio, nova);
	}
	else
	{
		//procura posição onde inserir
		while (aux->prox && strcmp(aux->prox->nome, nova->nome) < 0)
			aux = aux->prox;
		//se parou na última posição
		if (aux->prox == NULL) {	//insere no fim
			aux->prox = nova;
		}
		else //insere entre duas celulas
		{
			nova->prox = aux->prox;
			aux->prox=nova;
		}
	}
	*res = true;
	return inicio;
}

/**
 * @brief 
 *			Preserva Lista em ficheiro binário
 *			Estrutura auxiliar para ficar em ficheiro com apontador a NULL
 * 
 * @param fileName
 * @param inicio
 * @return 
 * @author lufer
 *
 */
bool SaveAll(char* fileName, Pessoa* inicio) {
	FILE* fp;
	Pessoa t;

	if (inicio == NULL || strlen(fileName) == 0) 
		return false;
	fp = fopen(fileName, "wb");
	if (fp == NULL)
		return false;

	Pessoa* aux = inicio;
	while (aux)	// mesmo que while(aux!=NULL)
	{	
		t.idade=aux->idade;
		t.prox = NULL;
		strcpy(t.nome, aux->nome);
		fwrite(&t, 1, sizeof(Pessoa), fp);
		aux = aux->prox;
	}
	fclose(fp);
	return true;
}


/**
 * @brief Carrega dados de um ficheiro binário.
 *		  
 * @param fileName
 * @param r
 * @return 
 * @author lufer
 *
 */
Pessoa* LoadAll(char* fileName, bool* r) {
	FILE* fp;
	fp = fopen(fileName, "rb");
	if (fp == NULL) {
		*r = false; 
		return NULL;
	}
	Pessoa t;
	Pessoa* inicio = NULL; 
	Pessoa* aux;
	while (fread(&t, 1, sizeof(Pessoa), fp)) {
		aux = CriaPessoa(t.nome, t.idade);
		inicio = InserePessoa(inicio, aux, r);
	}
	fclose(fp);
	return inicio;
}

/**
 * @brief 
 *			Preserva Lista em ficheiro binário
 *			Estrutura auxiliar para ficar em ficheiro sem apontador
 * @param fileName
 * @param inicio
 * @return 
 * @author lufer
 *
 */
bool SaveII(char* fileName, Pessoa* inicio) {

	if (inicio == NULL || strlen(fileName) == 0) return false;
	FILE* fp;
	PessoaFile t;

	fp = fopen(fileName, "wb");
	if (fp == NULL) return false;
	Pessoa* aux = inicio;
	while (aux)	// mesmo que while(aux!=NULL)
	{
		t.idade = aux->idade;
		strcpy(t.nome, aux->nome);
		fwrite(&t, 1, sizeof(PessoaFile), fp);
		aux = aux->prox;
	}
	fclose(fp);
	return true;
}

Pessoa* LoadII(char* fileName, bool* r) {
	FILE* fp;
	fp = fopen(fileName, "rb");
	if (fp == NULL) {
		*r = false;
		return NULL;
	}
	PessoaFile t;
	Pessoa* inicio = NULL;
	Pessoa* aux;
	while (fread(&t, 1, sizeof(PessoaFile), fp)) {
		aux = CriaPessoa(t.nome, t.idade);
		inicio = InserePessoa(inicio, aux, r);
	}
	fclose(fp);
	return inicio;
}


/**
 * @brief Grava lista num ficheiro csv.
 * 
 * @param fileName
 * @param inicio
 * @return 
 * @author lufer
 *
 */
bool ToCsv(char* fileName, Pessoa* inicio) {
	FILE* fp;
	if (inicio == NULL) return false;
	fp = fopen(fileName, "w");
	Pessoa* aux = inicio;
	while (aux) {
		fprintf(fp,"%s;%d\n", aux->nome, aux->idade);
		aux = aux->prox;
	}
	fclose(fp);

	return true;
}

/**
 * @brief Le dados de um ficheiro csv.
 * 
 * @param fileName
 * @param r
 * @return 
 * @author lufer
 *
 */
Pessoa* readCsv(char* fileName, bool* r) {
	Pessoa* inicio = NULL;
	FILE* fp;
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		*r = false;
		return NULL;
	}
	*r = true;
	//Pessoa p;
	Pessoa * aux;
	char nome[20]; int idade;
	while (!feof(fp)) {
		//fscanf(fp, "%[^;];%d\n", p.nome, &p.idade);
		//aux = CriaPessoa(p.nome, p.idade);
		int col=fscanf(fp, "%[^;];%d\n", nome, &idade);
		aux = CriaPessoa(nome, idade);
		inicio = InserePessoa(inicio, aux,r);
	}
	fclose(fp);
	return inicio;
}


/**
 * @brief Remove....
 *
 * @param ini
 * @param nome
 * @param res
 * @return
 * @author lufer
 *
 */

Pessoa* RemovePessoa(Pessoa * ini, char* nome, bool* res){
	//Lista vazia ou nome inválido
	if (ini == NULL || strlen(nome) == 0) {
		*res = false;
		return NULL;
	}

	//1º Remover no inicio
	Pessoa* aux, * ant;
	if (strcmp(ini->nome, nome) == 0) {
		*res = true;
		ant = ini;
		ini = ini->prox;
		free(ant);
	}
	//procurra a posição
	else {

		aux = ini; ant = aux;
		while (aux != NULL && strcmp(aux->nome, nome) != 0) {
			ant = aux;
aux = aux->prox;
		}
		//testa se não existe
		if (aux == NULL) {
			*res = false;
			return ini;
		}
		//testa se apaga no fim
		if (aux->prox == NULL) {
			*res = true;
			ant->prox = NULL;
			free(aux);
		}
		else {
			*res = true;
			ant->prox = aux->prox;
			free(aux);
		}
		//ou apenas
		//Apaga no fim e no meio
		//*res = true;
		//ant->next = aux->next;
		//free(aux);

	}
	return ini;
}


/**
 * @brief Elimina toda a memória alocada numa lista.
 *
 * @param inicio
 * @return
 * @author lufer
 *
 */
Pessoa* RemoveAll(Pessoa* inicio) {
	Pessoa* aux = inicio;
	if (aux->prox == NULL) {
		free(aux);
		return NULL;
	}
	Pessoa* t;
	while (aux->prox) {
		t = aux->prox;
		free(aux);
		aux = t;
	}
	return NULL;
}

/**
 * @brief Cria lista ordenada.
 *
 * @param ini
 * @param r
 * @return
 * @author lufer
 *
 */
Pessoa* OrdenaPessoas(Pessoa* ini, bool* r) {
	*r = false;
	if (ini == NULL) return NULL;
	Pessoa* aux = ini;
	Pessoa* novaLista = NULL;
	Pessoa* nova;
	while (aux) {
		nova = CriaPessoa(aux->nome, aux->idade);
		novaLista = InserePessoa(novaLista, nova, r);
		aux = aux->prox;
	}
	return novaLista;
}

/**
 * @brief ALtera conteúdo de celula.
 *
 * @param ini
 * @param nome
 * @param idade
 * @param res
 * @return
 * @author lufer
 *
 */
Pessoa* AlterarIdadePessoa(Pessoa* ini, char* nome, char idade, bool* res) {
	*res = false;
	if (ini == NULL || strlen(nome) == 0 || idade < 0)
		return ini;
	Pessoa* aux = ini;
	while (aux != NULL && strcmp(aux->nome, nome) < 0) {
		aux = aux->prox;
	}
	//se existe, altera
	if (strcmp(aux->nome, nome) == 0){
		*res = true;
		aux->idade = idade;
	}
	return ini;
}
