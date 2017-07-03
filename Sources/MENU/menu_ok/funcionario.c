/**
 * Este módulo define as funções de cadastro do funcionario.
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/
#include<stdio.h>
#include "funcionario.h"
#include "alocacao_memoria.h"
#include<string.h>
#include "my_bool.h"


Funcionario lendo_funcionario(void){
	Funcionario f;
	int id_grupo;
	Grupo *g_PTR;
	
	f.nome=alocar_memoria(51,sizeof(char));
	
	//printf("\ndigite o id do funcionário:");
	//scanf("%d",&f.id);
	
	printf("\ndigite o nome do funcionário:");
	scanf("\n%[^\n]s",f.nome);
	
	do{
		printf("\ndigite o salário do funcionário:");
		scanf("%f",&f.salario);
		
		if(f.salario>0) break;
		else printf("\nnumero digitado inválido");
		
	}while(TRUE);
	
	//busca no banco de dados e fornecendo o resto de informacoes do funcionario em realacao ao seu grupo:	
	do{
		printf("\ndigite o id do grupo(digite 1-para vendedor,2-para caixa).");
		scanf("%d",&id_grupo);
		
		if( (g_PTR=find_grupo(id_grupo)) != NULL){
			f.grupo=*g_PTR;
			printf("\nID DO GRUPO ENCONTRANDO COM SUCESSO");
			break;
		}
		else printf("id do grupo não encontrando tente novamente");
				
	
	}while(TRUE);
	
	//realocando memoria a partir do tamanho da string:
	f.nome=realocar_memoria(f.nome,strlen(f.nome),sizeof(char));
	
	return f;
}

void lendo_funcionario_para_atualizar(Funcionario *f){
	int codigo_acesso;
	int id_grupo;
	Grupo *g_PTR;
	
	
	printf("\nDeseja atualizar o nome do funcionario:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		printf("\ndigite o novo nome do funcionario:");
		scanf("\n%[^\n]s",f->nome);
	}
	
	printf("\nDeseja atualizar o salario do funcionario:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		do{
			printf("\ndigite o novo salário do funcionario:");
			scanf("%f",&f->salario);
			
			if(f->salario>0) break;
			else printf("\nnumero digitado inválido tente novamente");
			
		}while(TRUE);	
	}
	
	printf("\nDeseja atualizar o grupo pertencente ao funcionario(se e vendedor ou caixa:1-se sim,2-se nao");
	scanf("%d",&codigo_acesso);
	if(codigo_acesso==1){
		do{
			printf("\ndigite o id do grupo(digite 1-para vendedor,2-para caixa).");
			scanf("%d",&id_grupo);
		
			if( (g_PTR=find_grupo(id_grupo)) != NULL){
				f->grupo=*g_PTR;
				printf("\nID DO GRUPO ENCONTRANDO COM SUCESSO");
				break;
			}			
	
		}while(TRUE);
	}			
}

void imprimindo_funcionario(Funcionario *f){
			
	printf("\nInformacoes do funcionario:");
	printf("\nID do funcionario:%d",f->id);
	printf("\nNome do funcionario:%s",f->nome);
	printf("\nSalário do funcionario:%.2f",f->salario);
	printf("\nGrupo do funcionario:%s",f->grupo.nome);
	
}	
