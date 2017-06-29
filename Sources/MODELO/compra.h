/**
 * Este módulo define a struct Compra e é responsável pelas funções de manipulações 
 * da struct.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/

#include <time.h>

#include "caixa.h"
#include "produto.h"
  
typedef struct {
	int id;
 	Caixa caixa;
 	Produto* produto;
 	int quantidade;
 	struct tm horario;
 	int total_produtos; //Para saber quantos produtos contém a compra
} Compra;
