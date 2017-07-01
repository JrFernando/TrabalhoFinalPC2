/**
 * Este módulo define as funções que criaram a nota fiscal.
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
  @author Lucas Baleeiro Dominato <lucasdominato2@gmail.com>
 
 * @date 27/06/2017
*/

#include<stdio.h>
#include<stdlib.h>
#include "horario_cupom.h"
#include "formatacao_cupom.h"

/*
-arquivo que contem as funcoes que vao formatar o cupom fiscal.
*/

void formatacao_nota_fiscal1(char *nome_arquivo,char *nome_empresa,char *cnpj,char *endereco){
	FILE *file_PTR;
	
	//abrindo um arquivo para escrita:
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("ERRO AO ABRIR ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	//gravando os dados no arquivo.
	fprintf(file_PTR,"%s\n",nome_empresa);
	fprintf(file_PTR,"CNPJ:%s\n",cnpj);
	fprintf(file_PTR,"%s\n",endereco);
	fprintf(file_PTR,"----------------------------------------------------------------------\n");
	fprintf(file_PTR,"DANFE NFC-e-Documento Auxiliar da Nota Fiscal de Consumidor eletronica\n");
	fprintf(file_PTR,"Nao permite aproveitamento de credito de ICMS\n");
	fprintf(file_PTR,"----------------------------------------------------------------------\n");;
	fprintf(file_PTR,"Codigo     Produto           \n");
	fprintf(file_PTR,"      QDTE    Valor unitario   Total\n");
	fprintf(file_PTR,"----------------------------------------------------------------------\n");
	
	//fechando o arquivo:
	fclose(file_PTR);
}

void formatacao_nota_fiscal2(char *nome_arquivo,int codigo_produto,char *nome_produto,int quantidade,float preco_venda){
	FILE *file_PTR;
	
	//abrindo o arquivo ja no final da linha pra cadastrados dos produtos:
	file_PTR=fopen(nome_arquivo,"a");
	if(!file_PTR){
		printf("\nERRO AO ABRIR ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	//formatacao da nota fiscal:
	fprintf(file_PTR,"%d           %s   \n",codigo_produto,nome_produto);
	fprintf(file_PTR,"    %d        %.2f           %.2f\n",quantidade,preco_venda,preco_venda*quantidade);
	
	//fechando o arquivo:
	fclose(file_PTR);
}

void formatacao_nota_fiscal3(char *nome_arquivo,float qtd_total,float valor_total,char *nome_operador,int codigo_operador){
	FILE  *file_PTR;
	
	file_PTR=fopen(nome_arquivo,"a");
	if(!file_PTR){
		printf("\nERRO AO ABRIR ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	fprintf(file_PTR,"----------------------------------------------------------------------\n");
	fprintf(file_PTR,"QTD.TOTAL DE ITENS                           %.2f\n",qtd_total);
	fprintf(file_PTR,"VALOR TOTAL R$                               %.2f\n",valor_total);
	fprintf(file_PTR,"----------------------------------------------------------------------\n");
	fprintf(file_PTR,"      AREA DE MENSAGEM FISCAL\n");
	fprintf(file_PTR,"      EMISSAO:%s %s\n",gerando_data_cupom(),gerando_horario_cupom());
	fprintf(file_PTR,"----------------------------------------------------------------------\n");
	fprintf(file_PTR,"Op:%d\n",codigo_operador);
	fprintf(file_PTR,"Operador:%s\n",nome_operador);
	fprintf(file_PTR,"OBRIGADO PELA PREFERENCIA\n");
	fprintf(file_PTR,"VOLTE SEMPRE\n");
	fprintf(file_PTR,"----------------------------------------------------------------------\n");
	fprintf(file_PTR,"Itaucusys Brasil Ltda\n");
        fprintf(file_PTR,"----------------------------------------------------------------------\n");
	fprintf(file_PTR,"Op:%d\n",codigo_operador);
	fprintf(file_PTR,"Operador:%s        %s %s",nome_operador,gerando_data_cupom(),gerando_horario_cupom());
	
	//fechando arquivo:
	fclose(file_PTR);
}
