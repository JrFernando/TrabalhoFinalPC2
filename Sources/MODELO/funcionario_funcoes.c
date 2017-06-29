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


Funcionario lendo_funcionario(void){
	Funcionario f;
	
	f.nome=alocar_memoria(51,sizeof(char));
	
	printf("\ndigite o id do funcionário:");
	scanf("%d",&f.id);
	
	printf("\ndigite o nome do funcionário:");
	scanf("\n%[^\n]s",f.nome);
	
	printf("\ndigite o salário do funcionário:");
	scanf("%f",&f.salario);
	
	//realocando memoria a partir do tamanho da string:
	f.nome=realocar_memoria(f.nome,strlen(f.nome),sizeof(char));
	
	return f;
}	
	
	
