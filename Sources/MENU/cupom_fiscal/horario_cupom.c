/**
 * Este módulo define as funções que passaram o horario e a data do sistema.
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/
#include<stdio.h>
#include<stdlib.h>
#include "horario_cupom.h"
#include<time.h>

char* gerando_horario_cupom(void){
	int minutos,hora,segundos;
	char *horario;
	struct tm *local;
	time_t t;
	
	//alocando memoria para a variavel horario:
	horario=(char *)calloc(51,sizeof(char));
	if(!horario){
		printf("ERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	t=time(NULL);
	local=localtime(&t);
	
	//lendo o horario no computador:
	segundos=local->tm_sec;
	minutos=local->tm_min;
	hora=local->tm_hour;
	
	//transformando a data em uma string.
	sprintf(horario,"%d:%d:%d",hora,minutos,segundos);
	
	return horario;
}

char* gerando_data_cupom(void){
	int dia,mes,ano;
	char *data;
	struct tm *local;
	time_t t;
	
	//alocando memoria para o data:
	data=(char *)calloc(51,sizeof(char));
	if(!data){
		printf("ERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}	
	
	t=time(NULL);
	local=localtime(&t);
	
	//lendo o dia no computador:
	dia=local->tm_mday;
	mes=local->tm_mon+1;
	ano=local->tm_year+1900;

	//transformando a data em uma string.
	sprintf(data,"%d/%d/%d",dia,mes,ano);
	
	return data;
}
