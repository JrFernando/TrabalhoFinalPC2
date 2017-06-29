/**
 * Este módulo define as  funções de manipulações 
 * da struct Produto.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/


#include<stdio.h>
#include "produto.h"
#include<string.h>
#include "alocacao_memoria.h"

Produto lendo_produto(){
	Produto p;
	int id_fabricante;
	
	p.nome=alocar_memoria(51,sizeof(char));
	
	printf("\ndigite o id do produto:");
	scanf("%d",&p.id);
	
	printf("\ndigite o nome do produto:");
	scanf("\n%[^\n]s",p.nome);
	
	printf("\ndigite o preço de compra do produto:");
	scanf("%f",&p.preco_compra);
	
	printf("\ndigite o preço de venda do produto:");
	scanf("%f",&p.preco_venda);
	
	printf("\ndigite o id do fabricante:");
	scanf("%d",&id_fabricante);
	
	//procurar o id do fabricante no banco de dados e fornecer para o campo p.f.id e p.f.nome os dados.
	
	p.nome=realocar_memoria(p.nome,strlen(p.nome),sizeof(char));
	
	return p;
}	
	
	
	