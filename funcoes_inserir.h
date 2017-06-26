#include<string.h>
#include"estruturas.h"
#include"alocacao_memoria.h"

/*
-arquivo com as funções para inserir dados em diversas structs
*/


Funcionario cadastro_funcionario(){
	Funcionario f;
	
	//alocando memoria a strings da estrutura:
	f.func_nome=alocacao_memoria_strings();
	
	//lendo os dados:
	printf("\ndigite o nome do funcionario:");
	scanf("\n%[^\n]s",f.func_nome);
	printf("\ndigite o salario do funcionario:");
	scanf("%f",&f.func_salario);
	
	//usando o realloc para evitar desperdicio de memoria:
	f.func_nome=realloc(f.func_nome,strlen(f.func_nome)*sizeof(char));
	if(!f.func_nome){
		printf("\nERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	return f;
}

Fabricantes cadastro_fabricante(){
	Fabricantes f;
	
	//alocando memoria para string da estrutura:
	f.fabr_nome=alocacao_memoria_strings();
	
	//lendo os dados:
	printf("\ndigite o nome do fabricante:");
	scanf("\n%[^\n]s",f.fabr_nome);
	
	//usando o realloc para evitar desperdicio de memoria:
	f.fabr_nome=realloc(f.fabr_nome,strlen(f.fabr_nome)*sizeof(char));
	if(!f.fabr_nome){
		printf("\nERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	return f;
}

Produtos cadastro_produtos(){
	Produtos p;
	
	//alocando memoria para memoria para o produto:
	p.prod_nome=alocacao_memoria_strings();
	
	//lendo dados:
	printf("\ndigite o nome do fabricante:");
	scanf("\n%[^\n]s",p.prod_nome);
	printf("\ndigite a quantidade do produto no estoque:");
	scanf("%d",&p.prod_quantidade);
	printf("\ndigite o preço do produto comprado no fabricante:");
	scanf("%f",&p.prod_preco_compra);
	printf("\ndigite o preço do produto para venda na loja:");
	scanf("%f",&p.prod_preco_venda);
	printf("\ndigite o codigo do fabricante:");
	scanf("%d",&p.prod_fabr_id);
	//ideal confirmar se existe no banco o id desse fabricante.
	
	//usando o realloc para evitar desperdicio de memoria:
	p.prod_nome=realloc(p.prod_nome,strlen(p.prod_nome)*sizeof(char));
	if(!p.prod_nome){
		printf("\nERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	return p;
}

Empresa lendo_empresa(){
	Empresa e;
	
	//alocando memoria para a strings da estrutura:
	e.nome_empresa=alocacao_memoria_strings();
	e.endereco=alocacao_memoria_strings();
	
	printf("\ndigite o nome da empresa:");
	scanf("\n%[^\n]s",e.nome_empresa);
	
	printf("\ndigite o CNPJ da EMPRESA:");
	scanf("%ld",&e.cnpj);
	
	printf("\ndigite o endereco da empresa:");
	scanf("\n%[^\n]s",e.endereco);
	
	printf("\ndigite 1-se a empresa tem vendedores ou 2-se a empresa não tem vendedores");
	scanf("%d",&e.codigo_func);
	
	//realocando memoria a partir do tamanho da strings(evitar espaço desnecessario):
	e.nome_empresa=realloc(e.nome_empresa,strlen(e.nome_empresa)*sizeof(char));
	if(!e.nome_empresa){
		printf("\nERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	e.endereco=realloc(e.endereco,strlen(e.endereco)*sizeof(char));
	if(!e.endereco){
		printf("\nERRO AO ALOCAR MEMORIA-FIM DO PROGRAMA");
		exit(1);
	}
	
	return e;		
}
	
