/**
 * Este módulo define a struct Caixa e é responsável pelas funções de manipulações 
 * da struct.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/
  
typedef struct {
	char *nome;
 	char *cnpj;
 	char *endereco;
}Empresa;


//protótipos das funções da empresa:
Empresa lendo_empresa();
