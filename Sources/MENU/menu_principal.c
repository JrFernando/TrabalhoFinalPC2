#include<stdio.h>
#include<stdlib.h>
#include"caixa.h"

/*
-programa que fornece o menu_principal do programa,indicando ao usuario o que ele pode fazer no programa:
-faltar criar funcoes para cadastrar produto,funcionarios e entre outros.
-as bibliotecas da structs estão dentro da setup_incial não há necessidade de inclui-la novamente no codigo do programa.
*/

int main(){
	int codigo_acesso;
	int codigo_estoque;
	int codigo_funcionario;
	int codigo_planilhas;
	Empresa e;
	Produtos p;
	Funcionario f;
	
	//setup de instalacao,pedi os dados da empresa,se tem funcionario ou nao.(modelagem do codigo).
	//if(){ 
		//aqui deve ter uma funcao que confirme no banco de dados se tem os dados da empresa
		//se nao entra aqui.
		printf("\nBEM VINDO AO MENU INICIAL DO PROGRAMA,NESSE MOMENTO VAMOS PEDIR ALGUMAS INFORMAÇÕES DA SUA EMPRESA ESSENCIAIS PARA O FUNCIONAMENTO DO PROGRAMA");
		e=lendo_empresa();
	
		printf("\nPROCESSANDO OS DADOS...");
		//ideal gravar os dados da struct e em um banco de dados(estes dados vao modelar o programa).}
	
	do{
	
		printf("\nBEM VINDO AO MENU-PRINCIPAL DO PROGRAMA.");
		printf("\nDIGITE:");
		printf("\n1-PARA ABRIR O CAIXA.");
		printf("\n2-PARA CONTROLE DO ESTOQUE");
		printf("\n3-PARA CONTROLE DE FUNCIONARIOS.");
		printf("\n4-PARA EMISSAO DE PLANILHAS ELETRONICAS");
		printf("\n0-SAIR DO PROGRAMA");
		scanf("%d",&codigo_acesso);
	
		switch(codigo_acesso){
			case 1:
				//funcoes do caixa.
				//if(depende do campo da empresa struct,codigo_func==1 tem vendedores e o caixa2(e,p) senao e o caixa(sem vendedores).
				break;
			case 2:
				printf("\nVOCÊ ESTÁ NO MENU DO ESTOQUE.");
				printf("\nDIGITE:");
				printf("\n1-PARA CADASTRAR PRODUTOS NO ESTOQUE.");
				printf("\n2-PARA VERIFICAR QUAIS PRODUTOS ESTÃO EM BAIXA NO ESTOQUE.");
				printf("\n3-PARA EXCLUIR UM PRODUTO DO ESTOQUE(necessario id do produto)");
				printf("\n4-PARA ALTERAR OS DADOS DE UM PRODUTO CADASTRADO NO ESTOQUE.");
				printf("\n5-PARA BUSCAR OS DADOS DE UM PRODUTO(POR NOME).");
				printf("\n6-PARA BUSCAR OS DADOS DE UM PRODUTO(POR ID DO PRODUTO).");
				printf("\nPARA CADASTRAR OS FABRICANTES E FORNECEDORES.");
				scanf("%d",&codigo_estoque);
				switch(codigo_estoque){
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;	
					default:
						printf("\nCODIGO INVÀLIDO TENTE NOVAMENTE");
						break;
				}
				break;
			case 3:
				printf("\nVOCÊ ESTÁ NO MENU DO FUNCIONÁRIOS.");
				printf("\nDIGITE:");
				printf("\n1-PARA CADASTRAR UM FUNCIONÁRIO");
				printf("\n2-PARA ATUALIZAR UM CADASTRO DE UM FUNCIONÁRIO.");
				printf("\n3-PARA EXCUIR UM CADASTRO DE UM FUNCIONÁRIO(necessario o id do produto)");
				printf("\n4-PARA FAZER UMA BUSCA DOS DADOS DE UM FUNCIONARIO(POR ID DO FUNCIONÁRIO)");
				printf("\n5-PARA FAZER UMA BUSCA DOS DADOS DE UM FUNCIONÁRIO(POR NOME DO FUCIONÁRIO)");
				scanf("%d",&codigo_funcionario);
				switch(codigo_funcionario){
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						break;
					default:
						printf("\nCODIGO INVÀLIDO TENTE NOVAMENTE");
						break;
				}							
				break;
				
											
			case 4:
				printf("\nVOCÊ ESTÁ NO MENU DE PLANILHAS ELETRONICAS.");
				printf("\nDIGITE:");
				printf("\n1-PARA CRIAR UMA TABELA COM OS PRODUTOS MAIS VENDIDOS.");
				printf("\n2-PARA CRIAR UMA TABELA COM OS PRODUTOS MAIS LUCRATIVOS.");
				printf("\n3-PARA CRIAR UMA TABELA COM A RECEITA DOS CAIXAS COM ID DO FUNCIONÁRIO E MOVIMENTAÇÕES DO CAIXA.");
				printf("\n4-PARA CRIAR UMA TABELA COM OS PRODUTOS E SUAS QUANTIDADES EM ESTOQUE.");
				scanf("%d",&codigo_planilhas);
				switch(codigo_planilhas){
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					default:
						printf("\nCODIGO INVÁLIDO TENTE NOVAMENTE");
						break;
				}
				break;						
			
		}
	}while(codigo_acesso);
	
	
	return 0;
} 
