/**
 * Este módulo define as funções que passaram o horario e a data do sistema.
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/
#include<stdio.h>
#include<stdlib.h>
#include "horario.h"

tm* gerando_horario(void){
	tm *local;
	
	local=localtime(time(NULL));
	
	return local;
}
