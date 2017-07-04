#include<stdio.h>
#include "empresa.h"
#include "alocacao_memoria.h"
#include<string.h>

Empresa lendo_empresa(){
	Empresa e;
	
	//alocando memoria para as strings:
	e.nome=alocar_memoria(151,sizeof(char));
	e.cnpj=alocar_memoria(151,sizeof(char));
	e.endereco=alocar_memoria(151,sizeof(char));
	
	printf("digite o nome da empresa:");
	scanf("\n%[^\n]s",e.nome);
	
	printf("digite o CNPJ da empresa:");
	scanf("\n%[^\n]s",e.cnpj);
	
	printf("digite o endereço da empresa:");
	scanf("\n%[^\n]s",e.endereco);
	
	//realocando memoria para as strings:
	e.nome=realocar_memoria(e.nome,strlen(e.nome),sizeof(char));
	e.cnpj=realocar_memoria(e.cnpj,strlen(e.cnpj),sizeof(char));
	e.endereco=realocar_memoria(e.endereco,strlen(e.endereco),sizeof(char));
	
	return e;
	
} 
