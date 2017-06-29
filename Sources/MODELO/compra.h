/**
 * Este módulo define a struct Compra e é responsável pelas funções de manipulações 
 * da struct.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 27/06/2017
*/
 
#include <time.h>

#include "caixa.h"
#include "produto.h"
  
struct {
	int id;
 	Caixa caixa;
 	Produto* produto; //Vetor de produto
 	int* quantidade; //Vetor de quantidade para cada produto
 	struct tm horario;
 	int total_produtos; //Para saber quantos produtos contém a compra
} Compra;
