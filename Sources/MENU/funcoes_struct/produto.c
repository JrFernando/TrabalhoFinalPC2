/**
 * Este módulo define as  funções de manipulações 
 * da struct Produto.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/

#include<stdio.h>
#include "produto.h"
#include<string.h>
#include "alocacao_memoria.h"



Produto lendo_produto(){
	Produto p;
	int id_fabricante;
	
	p.nome=alocar_memoria(251,sizeof(char));
	
	printf("\ndigite o id do produto:");
	scanf("%d",&p.id);
	
	printf("\ndigite o nome do produto:");
	scanf("\n%[^\n]s",p.nome);
	
	printf("\ndigite a quantidade em estoque do produto:");
	scanf("%d",&p.quantidade);
	
	printf("\ndigite o preço de compra do produto:");
	scanf("%f",&p.preco_compra);
	
	printf("\ndigite o preço de venda do produto:");
	scanf("%f",&p.preco_venda);
	
	printf("\ndigite o id do fabricante:");
	scanf("%d",&id_fabricante);
	
	//procurar o id do fornecedor no banco de dados e fornecer para o campo p.f.id e p.f.nome os dados.
	do{
		if( (p.fabricante=find_fabricante(id_fabricante)) != NULL ){
			printf("\ncodigo do fabricante encontrado-cadastro efetuado com sucesso.");
			break;
		}	
		
	}while(TRUE);	
	
	//realocando memoria para o o vetor string:	
	p.nome=realocar_memoria(p.nome,strlen(p.nome),sizeof(char));
	
	return p;
}

void imprimindo_produto(Produto *p){
	
	printf("\ninformacoes do produto:");
	printf("\nid do produto:%d",p->id);
	printf("\nnome do produto:%s",p->nome);
	printf("\nquantidade do produto em estoque:%d",p->quantidade);
	printf("\npreco de compra do produto:%.2f",p->preco_compra);
	printf("\npreco de venda do produto:%.2f",p->preco_venda);
	printf("\nid do fabricante do produto:%d",p->fabricante->id);
	printf("\nnome do fabricante do produto:%s",p->fabricante->nome);
}	


void lendo_produto_para_atualizar(Produto *p){
	int codigo_acesso;
	
	printf("\ndeseja alterar o nome do produto:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		
		//alocando memoria:
		p->nome=alocar_memoria(251,sizeof(char));
		printf("\ndigite o novo nome da struct:");
		scanf("\n%[^\n]s",p->nome);
	}
	
	printf("\ndeseja alterar o preco de compra do produto:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		printf("\ndigite a novo preco de compra do produto.");
		scanf("%f",&p->preco_compra);
	}
	
	printf("\ndeseja alterar o preco de venda do produto:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		printf("\ndigite o novo preço de venda do produto:");
		scanf("%f",&p->preco_venda);
	}
	
	printf("\ndeseja alterar o nome do fabricante:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		//alocando memoria para a string:
		p->fabricante->nome=alocar_memoria(251,sizeof(char));
		printf("\ndigite o novo nome do fabricante");
		scanf("\n%[^\n]s",p->fabricante->nome);
	}
	
	//realocando memoria para ambos os vetores:
	p->nome=realocar_memoria(p->nome,strlen(p->nome),sizeof(char));
	p->fabricante->nome=realocar_memoria(p->fabricante->nome,strlen(p->fabricante->nome),sizeof(char));
		
}		

