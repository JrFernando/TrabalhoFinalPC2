/**
 * Este módulo define a struct Movimentacao e é responsável pelas funções de manipulações 
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
 	struct tm horario;
 	float valor;
}Movimentacao;
