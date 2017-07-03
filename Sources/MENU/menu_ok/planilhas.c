#include<stdio.h>
#include<stdlib.h>
#include "horario.h"
#include "horario_cupom.h"


typedef struct {
	int id;
 	float saldo;
}Caixa;

typedef struct {
	int id;
	char *nome;
 	//char *senha; //A principio não tem sentido utilizar
 	float salario;
 	//Grupo grupo;
}Funcionario;

typedef struct {
	int id;
	char *nome;
 	int quantidade;
 	float preco_compra;
 	float preco_venda;
 	//Fabricante fabricante;
}Produto;

typedef struct {
	char *nome;
 	char *cnpj;
 	char *endereco;
}Empresa;

typedef struct {
 	Funcionario funcionario;
 	Caixa caixa;
 	struct tm horario_inicio;
 	struct tm horario_final;
}Turno;

typedef struct {
 	Funcionario funcionario;
 	Caixa caixa;
 	struct tm horario;
 	float valor;
}Movimentacao;

typedef struct{
	int id;
 	Caixa caixa;
 	Produto* produto; //Vetor de produto
 	int* quantidade; //Vetor de quantidade para cada produto
 	struct tm horario;
 	int total_produtos; //Para saber quantos produtos contém a compra
 	Funcionario vendedor; //Caso exista um vendedor adiciona-lo
}Compra;


void produtos_mais_vendidos(Produto *vetor,int tamanho_vetor,char *nome_arquivo){
	int i;
	FILE* file_PTR;
	
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("\nERRO AO GERAR O ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	fprintf(file_PTR,"Produtos mais vendidos:\n");
	fprintf(file_PTR,"Nome do Produto,Id do produto,total de vendas\n");
	for(i=0;i<tamanho_vetor;i++){
		fprintf(file_PTR,"%s,%d,%d",(vetor+i)->nome,(vetor+i)->id,(vetor+i)->quantidade);
		fprintf(file_PTR,"\n");
	}
	
	//fechando arquivo:
	fclose(file_PTR);
}

void produtos_mais_lucrativos(Produto *vetor,int tamanho_vetor,char *nome_arquivo){
	int i;
	FILE* file_PTR;
	
	file_PTR=fopen(nome_arquivo,"w");
	if(!file_PTR){
		printf("\nERRO AO GERAR O ARQUIVO-FIM DO PROGRAMA");
		exit(1);
	}
	
	fprintf(file_PTR,"Produtos mais lucrativos:\n");
	fprintf(file_PTR,"Nome do Produto,Id do produto,faturamento\n");
	for(i=0;i<tamanho_vetor;i++){
		fprintf(file_PTR,"%s,%d,%d",(vetor+i)->nome,(vetor+i)->id,(vetor+i)->quantidade);
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
	
	fprintf(file_PTR,"Todas compras até o momento:%s,%s",gerando_data_cupom(),gerando_horario_cupom());
	for(i=0;i<tamanho_vetor;i++){
		fprintf(file_PTR,"Id da compra:,horario da compra:,dia da compra:,Produtos da compra:,quantidade de produtos vendidos:\n");
		fprintf(file_PTR,"%d\n,",(vetor_c+i)->id);
		fprintf(file_PTR,"%d:%d:%d,",(vetor_c+i)->horario.tm_hour,(vetor_c+i)->horario.tm_min,(vetor_c+i)->horario.tm_sec);
		fprintf(file_PTR,"%d:%d:%d,",(vetor_c+i)->horario.tm_mday,(vetor_c+i)->horario.tm_mon+1,(vetor_c+i)->horario.tm_year+1900);
		for(j=0;j<(vetor_c+i)->total_produtos;j++){
			fprintf(file_PTR,"%s,",((vetor_c+i)->produto+j)->nome);
			fprintf(file_PTR,"%d",(*(vetor_c+i)->quantidade+j));
			fprintf(file_PTR,"\n");
		}
		fprintf(file_PTR,"saldo do caixa nessa venda:%.2f\n",((vetor_c+i)->caixa.saldo));
	}
}	
			
			
	
	
	
	
	
	
	
	
		
	

