#include<stdio.h>
#include<stdio.h>
#include<time.h>

char* gerando_horario(void){
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

char* gerando_data(void){
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
