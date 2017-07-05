/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Caixas
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 30/06/2017
 */
#include <string.h>

#include "caixa_bd.h"
#include "../UTIL/alocacao_memoria.h"

#define TAM_MAX_ID 4
#define TAM_MAX_SALDO 6

Caixa* find_caixa(int id){
	MYSQL mysql;
	MYSQL_RES *resposta;
	MYSQL_ROW linhas;
	char *query = "select * from Caixas where caix_id =  ;";
	Caixa* caixa;
	int tamanho = 0;

	tamanho = strlen(query) + TAM_MAX_ID;	
	query = (char*) alocar_memoria(tamanho, sizeof(char));

	sprintf(query, "select * from Caixas where caix_id = %d;", id);

	if(! bd_open(&mysql) ) return NULL;

	if(mysql_query(&mysql, query)){
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return NULL;
	}


	if( (resposta = mysql_store_result(&mysql) )){
		caixa = (Caixa*) alocar_memoria(1, sizeof(Caixa));
		linhas = mysql_fetch_row(resposta);

		caixa->id = atoi(linhas[0]);
                
		caixa->saldo = atof(linhas[1]);
	} else {
		//Descomente para debugar
    		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return NULL;
	}

	mysql_free_result(resposta);
	bd_close(&mysql);
        
	return caixa;
} 

float get_saldo_caixa(Caixa caixa){
	MYSQL mysql;
	MYSQL_RES *resposta;
	MYSQL_ROW linhas;
	char *query = "select * from Caixas where caix_id =  ;";
	float saldo;
	int tamanho = 0;
	
	tamanho = strlen(query) + TAM_MAX_ID;	
	query = (char*) alocar_memoria(tamanho, sizeof(char));

	sprintf(query, "select * from Caixas where caix_id = %d;", caixa.id);

	if(! bd_open(&mysql) ) return -1;

	if(mysql_query(&mysql, query)){
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return -1;
	}


	if( (resposta = mysql_store_result(&mysql) )){
		linhas = mysql_fetch_row(resposta);
		saldo = atof(linhas[1]);
	} else {
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return -1;
	}

	mysql_free_result(resposta);
	bd_close(&mysql);

	return saldo;
}

bool atualiza_saldo_caixa(Caixa caixa){
	MYSQL mysql;
	char* query = "update Caixas set caix_saldo =  where caix_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
	int tamanho = 0;
	
	tamanho = strlen(query) + TAM_MAX_SALDO + TAM_MAX_ID;
	query = (char*) alocar_memoria(tamanho, sizeof(char));

	sprintf(query, "update Caixas set caix_saldo = %.2f where caix_id = %d;", caixa.saldo, caixa.id);

	if(! bd_open(&mysql) ) return FALSE;

	if(! mysql_query(&mysql, query)) {
		bd_close(&mysql);
		return TRUE;
	} else{
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return FALSE;
	}
}

bool movimentar_saldo_caixa(Caixa caixa){
	MYSQL mysql;
	char* query = "update Caixas set caix_saldo =  where caix_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
	int tamanho = 0;

	tamanho = strlen(query) + TAM_MAX_SALDO + TAM_MAX_ID;
	query = (char*) alocar_memoria(tamanho, sizeof(char));

	sprintf(query, "update Caixas set caix_saldo = %.2f where caix_id = %d;", caixa.saldo, caixa.id);

	if(! bd_open(&mysql) ) return FALSE;

	if(! mysql_query(&mysql, query)) {
		bd_close(&mysql);
		return TRUE;
	} else{
		//Descomente para debugar
		//printf("Erro: %s\n", mysql_error(&mysql));
		bd_close(&mysql);
		return FALSE;
	}
}