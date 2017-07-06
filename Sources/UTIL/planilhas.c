#include<stdio.h>
#include<stdlib.h>
#include "horario.h"
#include "../MENU/cupom_fiscal/horario_cupom.h"
#include "planilhas.h"


void produtos_mais_vendidos(Produto *vetor,int tamanho_vetor,int *p_vendidos,char *nome_arquivo){
	int i;
	FILE* file_PTR;
	
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("\nERRO AO GERAR O ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	fprintf(file_PTR,"Produtos mais vendidos:\n");
	fprintf(file_PTR,"Nome do Produto,Id do produto,total de vendas\n");
	for(i=0;i<tamanho_vetor;i++,p_vendidos++){
		fprintf(file_PTR,"%s,%d,%d",(vetor+i)->nome,(vetor+i)->id,*p_vendidos);
		fprintf(file_PTR,"\n");
	}
	
	//fechando arquivo:
	fclose(file_PTR);
}

void produtos_mais_lucrativos(Produto *vetor,int tamanho_vetor,float *p_vendas,char *nome_arquivo){
	int i;
	FILE* file_PTR;
	
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("\nERRO AO GERAR O ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	fprintf(file_PTR,"Produtos mais lucrativos:\n");
	fprintf(file_PTR,"Nome do Produto,Id do produto,faturamento\n");
	for(i=0;i<tamanho_vetor;i++,p_vendas++){
		fprintf(file_PTR,"%s,%d,%.2f",(vetor+i)->nome,(vetor+i)->id,*p_vendas);
		fprintf(file_PTR,"\n");
	}
	
	//fechando arquivo:
	fclose(file_PTR);
}

void produtos_e_estoque(Produto *vetor,int tamanho_vetor,char *nome_arquivo){
	int i;
	FILE* file_PTR;
	
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("\nERRO AO GERAR O ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	fprintf(file_PTR,"Produtos e quantidades em estoque:\n");
	fprintf(file_PTR,"Nome do Produto,Id do produto,quantidade de estoque\n");
	for(i=0;i<tamanho_vetor;i++){
		fprintf(file_PTR,"%s,%d,%d",(vetor+i)->nome,(vetor+i)->id,(vetor+i)->quantidade);
		fprintf(file_PTR,"\n");
	}
	
	//fechando arquivo:
	fclose(file_PTR);
}

void compras_realizadas(Compra *vetor_c,int tamanho_vetor,char *nome_arquivo){
	int i,j;
	FILE *file_PTR;
	
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("\nERRO AO GERAR O ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	fprintf(file_PTR,"Todas compras até o momento:%s,%s\n",gerando_data_cupom(),gerando_horario_cupom());
	fprintf(file_PTR,"Id da compra:,horario da compra:,dia da compra:,Produtos da compra:,quantidade de produtos vendidos:\n");
	for(i=0;i<tamanho_vetor;i++){
		fprintf(file_PTR,"%d,",(vetor_c+i)->id);
		fprintf(file_PTR,"%d:%d:%d,",(vetor_c+i)->horario.tm_hour,(vetor_c+i)->horario.tm_min,(vetor_c+i)->horario.tm_sec);
		fprintf(file_PTR,"%d:%d:%d,",(vetor_c+i)->horario.tm_mday,(vetor_c+i)->horario.tm_mon,(vetor_c+i)->horario.tm_year);
		for(j=0;j<(vetor_c+i)->total_produtos;j++){
			fprintf(file_PTR,"%s,",((vetor_c+i)->produto+j)->nome);
			fprintf(file_PTR,"%d",(*(vetor_c+i)->quantidade+j));
			fprintf(file_PTR,"\n");
			fprintf(file_PTR," , , ,");
		}
		fprintf(file_PTR," , ,saldo do caixa nessa venda:%.2f\n",((vetor_c+i)->caixa.saldo));
	}
	
	fclose(file_PTR);
}	

void receita_dos_caixas(Turno *vetor,int tamanho_vetor,char *nome_arquivo){
	int i;
	FILE *file_PTR;
	
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("\nerro ao abrir o arquivo-fim do programa");
		exit(1);
	}
	
	fprintf(file_PTR,"Data:,Horario incio do caixa:,Horario final do caixa:,Saldo do caixa:\n");
	for(i=0;i<tamanho_vetor;i++){
		fprintf(file_PTR,"%d/%d/%d,",(vetor+i)->horario_inicio.tm_mday,(vetor+i)->horario_inicio.tm_mon,(vetor+i)->horario_inicio.tm_year);
		fprintf(file_PTR,"%d:%d:%d,",(vetor+i)->horario_inicio.tm_hour,(vetor+i)->horario_inicio.tm_min,(vetor+i)->horario_inicio.tm_sec);
		fprintf(file_PTR,"%d:%d:%d,",(vetor+i)->horario_inicio.tm_hour,(vetor+i)->horario_inicio.tm_min,(vetor+i)->horario_inicio.tm_sec);
		fprintf(file_PTR,"%.2f",(vetor+i)->caixa.saldo);
		fprintf(file_PTR,"\n");
	}
	
	//fechando o arquivo:
	fclose(file_PTR);	
}

void funcionario_que_mais_venderam(Funcionario *vetor,int tamanho_vetor,int *vetor_vendas,char *nome_arquivo){
	float vendas_funcionario;
	int i;
	FILE *file_PTR;
	
	//vetor_vendas recebe o total de vendas de cada funcionario.
	
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("\nerro ao abrir o arquivo-fim do programa");
		exit(1);
	}
	
	fprintf(file_PTR,"Funcionarios que mais venderam:\n");
	fprintf(file_PTR,"ID do funcionario:,Nome do funcionario:,total de vendas:\n");
	for(i=0;i<tamanho_vetor;i++,vetor_vendas++){
		fprintf(file_PTR,"%d,%s,%d",(vetor+i)->id,(vetor+i)->nome,*vetor_vendas);
		fprintf(file_PTR,"\n");
	}
	
	//fechando o arquivo:
	fclose(file_PTR);
}	
