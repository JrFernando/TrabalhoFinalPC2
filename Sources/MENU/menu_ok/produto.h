/**
 * Este módulo define as  funções de manipulações 
 * da struct Produto.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/
#include "fabricante_bd.h"
 
typedef struct {
	int id;
	char *nome;
 	int quantidade;
 	float preco_compra;
 	float preco_venda;
 	Fabricante fabricante;
}Produto;


//Prototipos das funções produto:

Produto lendo_produto(void);
void lendo_produto_para_atualizar(Produto *);
void imprimindo_produto(Produto *);
