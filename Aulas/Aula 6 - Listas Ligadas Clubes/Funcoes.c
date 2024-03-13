/*****************************************************************//**
 * @file   Funcoes.c
 * @brief  
 * 
 * @author lufer
 * @date   March 2024
 *********************************************************************/
#include "Header.h"

#include <stdio.h>

/**
 * @brief .
 * 
 * @param ini
 * @param novo
 * @return 
 * @author lufer
 *
 */
	Clube* InsereClube(Clube * ini, Clube * novo){

		if (ini == NULL) ini = novo;
		else
		{
			novo->next = ini;
			ini = novo;
		}
		return ini;
	}

	/**
	 * @brief .
	 * 
	 * @param nome
	 * @param s
	 * @return 
	 * @author lufer
	 *
	 */
	Clube* CriaClube(char* nome, float s) {
		Clube* aux = (Clube*)malloc(sizeof(Clube));
		if (aux == NULL) return NULL;
		aux->next = NULL;
		aux->socios = s;
		strcpy(aux->nome, nome);
		return aux;
	}

	/**
	 * @brief Percorre toda a lista e conta quantos clubes existem.
	 * 
	 * @param ini
	 * @return 
	 * @author lufer
	 *
	 */
	int PercorreListaClubes(Clube* ini) {
		int c = 0;
		Clube* aux = ini;
		while (aux)//!=NULL)
		{
			c++;
			aux = aux->next;
		}
		return c;
	}

	/**
	 * @brief Verifica se determinado clube existe. Devolve a respetiva informação.
	 * 
	 * @param ini
	 * @param nome
	 * @return 
	 * @author lufer
	 *
	 */
	Clube* ExisteClube(Clube* ini, char* nome) {
		if (ini == NULL) return NULL;
		Clube* aux = ini;
		while (aux != NULL) {
			if (strcmp(aux->nome, nome) == 0) return aux;
			aux = aux->next;
		}
		return NULL;
	}

	/**
	 * @brief Verica quais e quantos clubes têm determinado nome.
	 * 
	 * @param ini
	 * @param nome
	 * @param tot
	 * @return 
	 * @author lufer
	 *
	 */
	Clube* QuantosExistemClube(Clube* ini, char* nome, int*tot) {
		int c = 0;
		if (ini == NULL) {
			*tot = 0;
			return NULL;
		}
		Clube* existentes = NULL;
		Clube* aux = ini;
		while (aux != NULL) {
			if (strcmp(aux->nome, nome) == 0) {
				existentes = InsereClube(existentes, aux);
				c++;
			}
			aux = aux->next;
		}
		*tot = c;
		return existentes;
	}
