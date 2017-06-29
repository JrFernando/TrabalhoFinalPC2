#include<stdio.h>
#include "empresa.h"
#include "alocacao_memoria.h"

Empresa lendo_empresa(){
	Empresa e;
	
	printf("digite o nome da empresa:");
	scanf("\n%[^\n]s",e.nome);
	
	printf("digite o CNPJ da empresa:");
	scanf("\n%[^\n]s",e.cnpj);
	
	printf("digite o endereço da empresa:");
	scanf("\n%[^\n]s",e.endereco);
	
	return e;
}	
