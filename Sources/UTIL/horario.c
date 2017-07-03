/**
 * Este módulo define as funções que passaram o horario e a data do sistema.
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 *
 * @date 27/06/2017
*/
#include <stdlib.h>

#include "horario.h"

tm* gerando_horario(void){
	tm *local;
	time_t t;
	
	t=time(NULL);
	local=localtime(&t);
	
	local->tm_mon += 1;
	local->tm_year += 1900;
	
	return local;
}

char* tm_to_string_bd(tm horario){
    char* retorno;
    
    retorno = (char*) alocar_memoria(TAM_MAX_STRING_DATE, sizeof(char));    
    sprintf(retorno, "%d-%d-%d %d:%d:%d", horario.tm_year, horario.tm_mon, horario.tm_mday,
                                            horario.tm_hour, horario.tm_min, horario.tm_sec);
    
    return retorno;
}

char* tm_to_string_date_bd(tm horario){
    char* retorno;
    
    retorno = (char*) alocar_memoria(TAM_MAX_STRING_DATE, sizeof(char));    
    sprintf(retorno, "%d-%d-%d", horario.tm_year, horario.tm_mon, horario.tm_mday);
    
    return retorno;
}

tm string_bd_to_tm(char* string){
    tm horario;
 
    horario.tm_year = atoi(substring(string, 0, 4));;
    horario.tm_mon = atoi(substring(string, 5, 7));
    horario.tm_mday = atoi(substring(string, 8, 10));
    horario.tm_hour = atoi(substring(string, 11, 13));
    horario.tm_min = atoi(substring(string, 14, 16));
    horario.tm_sec = atoi(substring(string, 17, 19));
    
    return horario;

}