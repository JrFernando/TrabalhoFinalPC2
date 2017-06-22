#include<stdio.h>
#include<stdlib.h>
#include "funcoes.h"
#include "formatacaocupom.h"

/*
-programa que cria um arquivo.txt similiar a uma nota fiscal.
*/

int main(){
	Produto p[4];
	Empresa e;
	Caixa c;
	char nome[]="cupomfiscal.txt";
	char nome1[]="Caixa.bin";
	char nome2[]="empresa.bin";
	char nome3[]="Produto.bin";
	int i;
	
	
	//funcoes.h para leitura de dados:
	c=lendo_caixa(nome1);
	e=lendo_empresa(nome2);
	lendo_produto(nome3,p);
	
	//formatacao do cupom fiscal:
	formatacao_nota_fiscal1(nome,&e);
	for(i=0;i<4;i++)
		formatacao_nota_fiscal2(nome,p[i].id,p[i].nome,p[i].qtd_estoque,p[i].preco_venda);
	formatacao_nota_fiscal3(nome,c.quantidade,c.valor_total,"cartao de credito","sem identificao cliente","fernando",12);
	

	return 0;
}	
