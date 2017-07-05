/**
 * Este módulo define a struct Turno e é responsável pelas funções de manipulações 
 * da struct.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 27/06/2017
*/
 
#include <time.h>

#include "funcionario.h"
#include "caixa.h"
  
typedef struct {
 	Funcionario funcionario;
 	Caixa caixa;
 	struct tm horario_inicio;
 	struct tm horario_final;
}Turno;
