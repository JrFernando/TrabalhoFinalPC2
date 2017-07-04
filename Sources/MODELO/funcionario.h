/**
 * Este módulo define a struct Funcionario e é responsável pelas funções de manipulações 
 * da struct.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 *
 * @date 27/06/2017
*/
#include "../BD/grupo_bd.h"
 
typedef struct {
	int id;
	char *nome;
 	//char *senha; //A principio não tem sentido utilizar
 	float salario;
 	Grupo grupo;
}Funcionario;


//prototipos das funções:
Funcionario lendo_funcionario();
void lendo_funcionario_para_atualizar(Funcionario *);
void imprimindo_funcionario(Funcionario *);

