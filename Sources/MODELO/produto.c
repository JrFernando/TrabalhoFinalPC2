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
#include "../UTIL/alocacao_memoria.h"
#include "../UTIL/my_bool.h"



Produto lendo_produto(){
	Produto p;
	int id_fabricante;
	Fabricante *f_PTR;
	
	p.nome=alocar_memoria(251,sizeof(char));
	
	//printf("\ndigite o id do produto:");
	//scanf("%d",&p.id);
	
	printf("\ndigite o nome do produto:");
	scanf("\n%[^\n]s",p.nome);
	
	do{
		printf("\ndigite a quantidade em estoque do produto:");
		scanf("%d",&p.quantidade);
		
		if(p.quantidade>0) break;
		else printf("\nnúmero invalido tente novamente");
		
	}while(TRUE);	
	

	printf("\ndigite o preço de compra do produto:");
	scanf("%f",&p.preco_compra);
		

	printf("\ndigite o preço de venda do produto:");
	scanf("%f",&p.preco_venda);
		
	
	//procurar o id do fornecedor no banco de dados e fornecer para o campo p.f.id e p.f.nome os dados.
	do{
		printf("\ndigite o id do fabricante:");
		scanf("%d",&id_fabricante);
		
		if( (f_PTR=find_fabricante(id_fabricante)) != NULL ){
			p.fabricante=*f_PTR;
			printf("\ncodigo do fabricante encontrado-cadastro efetuado com sucesso.");
			break;
		}
		else printf("\n id digitado não encontrando no estoque,tente digitar novamente");	
		
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
	printf("\nid do fabricante do produto:%d",p->fabricante.id);
	printf("\nnome do fabricante do produto:%s",p->fabricante.nome);
}	


void lendo_produto_para_atualizar(Produto *p){
	int codigo_acesso;
	
	printf("\ndeseja alterar o nome do produto:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		
		//alocando memoria:
		p->nome=alocar_memoria(251,sizeof(char));
		printf("\ndigite o novo nome do produto:");
		scanf("\n%[^\n]s",p->nome);
	}
	
	printf("\ndeseja alterar o preco de compra do produto:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		do{
			printf("\ndigite a novo preco de compra do produto.");
			scanf("%f",&p->preco_compra);
			
			if(p->preco_compra>0) break;
			else printf("\nnúmero inválido,tente novamente.");
			
		}while(TRUE);	
	}
	
	printf("\ndeseja alterar o preco de venda do produto:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		do{
			printf("\ndigite o novo preço de venda do produto:");
			scanf("%f",&p->preco_venda);
			if(p->preco_venda>0) break;
			else printf("\nnumero inválido,tente novamente.");
			
		}while(TRUE);	
	}
	
	printf("\ndeseja alterar o nome do fabricante:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		//alocando memoria para a string:
		p->fabricante.nome=alocar_memoria(251,sizeof(char));
		printf("\ndigite o novo nome do fabricante:");
		scanf("\n%[^\n]s",p->fabricante.nome);
	}
	
	//realocando memoria para ambos os vetores:
	p->nome=realocar_memoria(p->nome,strlen(p->nome),sizeof(char));
	p->fabricante.nome=realocar_memoria(p->fabricante.nome,strlen(p->fabricante.nome),sizeof(char));
		
}

void imprimindo_produtos_em_baixa(Produto *p,int tamanho_vetor){
    int i;
    
    printf("\nprodutos em baixa no estoque:");
    for(i=0;i<tamanho_vetor;i++){
        printf("\nid do produto:%d",(p+i)->id);
	printf("\nnome do produto:%s",(p+i)->nome);
	printf("\nquantidade do produto em estoque:%d",(p+i)->quantidade);
	
        
    } 
}

