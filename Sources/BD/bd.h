/**
 * Este módulo é responsável por gerenciar as conexões com o servidor MySQL
 * através da biblioteca mysql.h 
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 23/06/2017
 */

#include <stdio.h>
#include <mysql/mysql.h>

#include "../UTIL/my_bool.h" //Para utilizar o tipo bool

#define HOST "localhost"
#define USER "root"
#define PASSWORD "123"
#define DATABASE "SCCE_BD"

/**
 * Esta função abre uma conexão com o servidor MySQL
 * com as credenciais indicadas nas macros e conecta com 
 * o banco de dados também indicado na macro.
 */
MYSQL* bd_open(MYSQL*);

/**
 * Esta função fecha a conexão com o servidor MySQL
 * ela apenas chama o função mysql_close, defini para manter
 * o padrão de nomeclatura.
 */
MYSQL* bd_close(MYSQL*);
