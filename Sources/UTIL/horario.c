/**
 * Este módulo define as funções que passaram o horario e a data do sistema.
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 *
 * @date 27/06/2017
*/
#include<stdio.h>
#include<stdlib.h>
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
