/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Grupo
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
#include <stdlib.h>
#include <string.h>

#include "grupo_bd.h"
#include "../UTIL/alocacao_memoria.h"

#define TAM_MAX_ID 4

Grupo* find_grupo(int id){
	MYSQL mysql;
	MYSQL_RES *resposta;
	MYSQL_ROW linhas;
	char *query = "select * from Grupos where grup_id =  ;";
	Grupo *grupo;
	int tamanho = 0;
	
	tamanho = strlen(query) + TAM_MAX_ID;	
	query = (char*) alocar_memoria(tamanho, sizeof(char));

	sprintf(query, "select * from Grupos where grup_id = %d;", id);

	if(! bd_open(&mysql) ) return NULL;

	if(mysql_query(&mysql, query)){
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return NULL;
	}


	if( (resposta = mysql_store_result(&mysql) )){
		grupo = (Grupo*) alocar_memoria(1, sizeof(Grupo));
		linhas = mysql_fetch_row(resposta);

		grupo->id = atoi(linhas[0]);

		grupo->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof(char));
		strcpy(grupo->nome, linhas[1]);

		grupo->descricao = (char*) alocar_memoria(strlen(linhas[2]), sizeof(char));
		strcpy(grupo->descricao, linhas[2]);

	} else {
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return NULL;
	}

	mysql_free_result(resposta);
	bd_close(&mysql);

	return grupo;
}

Grupo* get_all_grupos(){
	MYSQL mysql;
	MYSQL_RES *resposta;
	MYSQL_ROW linhas;
	char *query = "select * from Grupos;";
	Grupo *grupo, *temp;
	int quantidade;

	if(! bd_open(&mysql) ) return NULL;

	if(mysql_query(&mysql, query)){
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return NULL;
	}

	if( (resposta = mysql_store_result(&mysql) )){
		quantidade = mysql_num_rows(resposta);

		grupo = (Grupo*) alocar_memoria(quantidade, sizeof(Grupo));
		
		temp = grupo;
		while((linhas = mysql_fetch_row(resposta)) != NULL){
			temp->id = atoi(linhas[0]);

			temp->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof(char));
			strcpy(temp->nome, linhas[1]);

			temp->descricao = (char*) alocar_memoria(strlen(linhas[2]), sizeof(char));
			strcpy(temp->descricao, linhas[2]);

			temp++;
		}
	
	} else {
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return NULL;
	}

	mysql_free_result(resposta);
	bd_close(&mysql);

	return grupo;
}

int get_qtd_all_grupos(){
	MYSQL mysql;
	MYSQL_RES *resposta;
	char *query = "select * from Grupos;";
	int quantidade = -1;

	if(! bd_open(&mysql) ) return -1;

	if(mysql_query(&mysql, query)){
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return -1;
	}

	if( (resposta = mysql_store_result(&mysql) )) quantidade = mysql_num_rows(resposta);

	mysql_free_result(resposta);
	bd_close(&mysql);

	return quantidade;
}