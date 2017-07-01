/**
 * Este módulo define a struct Reposicao e é responsável pelas funções de manipulações 
 * da struct.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 27/06/2017
*/
#include <time.h>

#include "funcionario_bd.h"
#include "produto_bd.h"
#include "caixa_bd.h"

  
typedef struct {
 	Funcionario funcionario;
 	Produto produto;
 	struct tm horario;
 	int quantidade;
}Reposicao;

typedef struct {
 	Funcionario funcionario;
 	Caixa caixa;
 	struct tm horario_inicio;
 	struct tm horario_final;
} Turno;

 typedef struct {
 	Funcionario funcionario;
 	Caixa caixa;
 	struct tm horario;
 	float valor;
 } Movimentacao;

 typedef struct {
	int id;
 	Caixa caixa;
 	Produto* produto; //Vetor de produto
 	int* quantidade; //Vetor de quantidade para cada produto
 	struct tm horario;
 	int total_produtos; //Para saber quantos produtos contém a compra
 	Funcionario vendedor; //Caso exista um vendedor adiciona-lo
} Compra;
