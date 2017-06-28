/**
 * Este módulo define a struct Reposicao e é responsável pelas funções de manipulações 
 * da struct.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 27/06/2017
*/
 
#include <time.h>

#include "funcionario.h"
#include "produto.h"
  
struct {
 	Funcionario funcionario;
 	Produto produto;
 	struct tm horario;
 	int quantidade;
} Reposicao;
