/**
 * Este módulo define a struct Funcionario e é responsável pelas funções de manipulações 
 * da struct.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/
 
typedef struct {
	int id;
	char *nome;
 	//char *senha; //A principio não tem sentido utilizar
 	float salario;
 	//Grupo grupo; Só será utlizado depois das implementações a respeito das permissões
}Funcionario;


//prototipos das funções:
Funcionario lendo_funcionario();

