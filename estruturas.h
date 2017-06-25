#include<stdio.h>

//arquivo que contèm as estruturas que vamos usar no programa:

/*
-structs simliares as tabelas dos bancos de dados,não sei se todoas vao ser usadas no código,mas estão criadas.
*/

typedef struct{
	 int caixa_id;
	 float caixa_saldo;
}Caixa;

typedef struct{
	int func_int;
	char *func_nome;
	char *func_senha;
	float func_salario;
	int func_cate_id;
}Funcionario;

typedef struct{
	int turn_func_id;
	int turn_caix_id;
	long int turn_horario_inicio;
	long int turn_horario_fim;
}Turnos;

typedef struct{
	int comp_id;
	int comp_caix_id;
	int comp_prod_id;
	int comp_qtd_produto;
	long int comp_horario;
}Compras;//ou listadecompra

typedef struct{
	int prod_id;
	char *prod_nome;
	int prod_quantidade;
	float prod_preco_compra;
	float prod_preco_venda;
	int prod_fabr_id;
}Produtos;

typedef struct{
	int fabr_id;
	char *fabr_nome;
}Fabricantes;

typedef struct{
	char *nome_empresa;
	long int cnpj;
	char *endereco;
}Empresa;
		
		
		 
