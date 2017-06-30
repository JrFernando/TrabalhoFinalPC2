/**
 * Este módulo é responsável por gerenciar as conexões com o servidor MySQL
 * através da biblioteca mysql.h 
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */

#include "bd.h"

MYSQL* bd_open(MYSQL* mysql){

	mysql_init(mysql);

	if(mysql_real_connect(mysql, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0) ) ;//printf("Conectado com sucesso!\n");
	else {
		//Descomente para debugar
		//printf("Erro %d: %s\n", mysql_errno(mysql), mysql_error(mysql));
		return NULL;
	}
}

MYSQL* bd_close(MYSQL* mysql){
	mysql_close(mysql);
}