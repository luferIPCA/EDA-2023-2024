
#include "Header.h"
#include <stdio.h>


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
