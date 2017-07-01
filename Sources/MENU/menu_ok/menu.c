#include<stdio.h>
#include<stdlib.h>

#include "cupom_fiscal/horario_cupom.h"
#include "alocacao_memoria.h"
#include "empresa_bd.h"
#include "horario.h"
#include "acoes_funcionario_bd.h"
#include "cupom_fiscal/formatacao_cupom.h"


/*
-programa que fornece o menu_principal do programa,indicando ao usuario o que ele pode fazer no programa:
-faltar criar funcoes para cadastrar produto,funcionarios e entre outros.
-as bibliotecas da structs estão dentro da setup_incial não há necessidade de inclui-la novamente no codigo do programa.
*/

int main(){
	int codigo_estoque;
	int codigo_funcionario;
	int codigo_planilhas;
	int parametro_baixa_estoque;
	int multiuso;
	int acesso_compra;
	int codigo_acesso,acesso_caixa;
	int id_produto_caixa;
	int qtd_produto_caixa;
	int flag_caixa;
	float valor_compra;
	float movimentacao;
	Funcionario fu,*fu_PTR,fu_caixa,fu_venda;
	Fabricante f;
	Empresa e,*e_PTR;
	Produto p,*p_PTR;
	Turno t;
	Caixa c,*c_PTR;
	Compra co;
	Movimentacao m;
	Reposicao r;
	
	
	//procurar no banco de dados,se nao tem o cadastro da empresa,cadastrar a propria empresa e colocar no banco de dados:
	if( !(e_PTR=find_empresa()) ){ 
		printf("\nBEM VINDO AO MENU INICIAL DO PROGRAMA,NESSE MOMENTO VAMOS PEDIR ALGUMAS INFORMAÇÕES DA SUA EMPRESA ESSENCIAIS PARA O FUNCIONAMENTO DO PROGRAMA");
		e=lendo_empresa();
		
		//inserindo struct empresa no banco de dados:
		if(!insert_empresa(e)){
			printf("\nERRO NO SISTEMA-FECHANDO O PROGRAMA");
			exit(1);
		}	
		printf("\nPROCESSANDO OS DADOS...");
		//ideal gravar os dados da struct e em um banco de dados(estes dados vao modelar o programa).
	}
	else e=*e_PTR;
		
	do{
	
		printf("\nBEM VINDO AO MENU-PRINCIPAL DO PROGRAMA.");
		printf("\nDIGITE:");
		printf("\n1-PARA ABRIR O CAIXA.");
		printf("\n2-PARA CADASTRO DE PRODUTO");
		printf("\n3-PARA CONTROLE DE FUNCIONARIOS.");
		printf("\n4-PARA EMISSAO DE PLANILHAS ELETRONICAS");
		printf("\n0-SAIR DO PROGRAMA");
		scanf("%d",&codigo_acesso);
	
		switch(codigo_acesso){
			case 1:
				//funcoes do caixa:
				
				//pegando os dados do funcionario(caixa);
				do{
					printf("\ndigite o id do funcionario responsavel pelo caixa:");
					scanf("%d",&multiuso);
					
					//procurando o funcionario do id fornecido no banco:
					if( (fu_PTR=find_funcionario(multiuso)) != NULL ){
							printf("\nFUNCIONARIO ENCONTRADO COM SUCESSO");
							fu_caixa=*fu_PTR;
							free(fu_PTR);
							break;
					}
					
				}while(TRUE);
				
				do{
					printf("\ndigite o id do funcionario responsavel pela venda:");
					scanf("%d",&multiuso);
					
					//procurando o funcionario do id fornecido no banco.
					if( (fu_PTR=find_funcionario(multiuso)) != NULL ){
							printf("\nFUNCIONARIO ENCONTRADO COM SUCESSO");
							fu_venda=*fu_PTR;
							free(fu_PTR);
							break;
					}
					else printf("\nid nao encontrado,tente novamente");		
					
				}while(TRUE);
				
				//colocando funcionario vendendor na struct compras:
				co.vendedor=fu_venda;
					
				//primeira coisa abrir o caixa colocando dados do banco de dados na struct caixa(cuidado existe somente um caixa aqui),entao ele vai retornar o mesmo:
				c_PTR=find_caixa(1);
				c=*c_PTR;
				free(c_PTR);
				
				//definindo o turno(horario de entrada) e as outros elementos de turno:
				t.funcionario=fu_caixa;
				t.caixa=c;
				t.horario_inicio=*(gerando_horario());
				
				//inserindo turno no banco de dados:
				if(!insert_turno(t)){
					printf("ERRO NO SISTEMA-FIM DO PROGRAMA");
					exit(1);
				}	
				
				//definindo os principais elementos de compra:
				co.produto=(Produto *)alocar_memoria(1,sizeof(Produto));
				co.quantidade=(int *)alocar_memoria(1,sizeof(int));
				
				printf("\nVocê está na tela da caixa,bem vindo");
				do{
					do{
						printf("\ndigite 1-para continuar no caixa,2-para fechar o caixa e encerrar turno");
						scanf("%d",&acesso_caixa);
					}while(acesso_caixa !=1 && acesso_caixa !=2);
					
					if(acesso_caixa==2) break;
					
					//principais elementos da struct compra e da compra no caixa:
					co.caixa=c;
					valor_compra=0; //valor total dos produtos.
					co.total_produtos=0; //total de produtos na compra.
					
					//começando a impressa da nota fiscal:
					formatacao_nota_fiscal1("nota_fiscal.txt",e.nome,e.cnpj,e.endereco);
					
					//entrando no menu propriamente dito do caixa:
					do{
						do{
							printf("\ndigite 1-para continuar ou entrar na compra,2-para encerrar a compra");
							scanf("%d",&acesso_caixa);
						
						}while(acesso_caixa !=1 && acesso_caixa !=2);
					
						//encerra a compra:
						if(acesso_caixa==2) break;
						
						do{					
							printf("\ndigite o id do produto comprado pelo cliente");
							scanf("%d",&id_produto_caixa);
					
							//procurar o id no banco:
							if( (p_PTR=find_produto(id_produto_caixa)) != NULL ){
								printf("\nPRODUTO ENCONTRADO COM SUCESSO");
								p=*p_PTR;
								free(p_PTR);
								break;
							}
							else printf("\nProduto nao encontrado,tente novamente");
						}while(TRUE);
					
						do{
							do{
								printf("\nDigite a quantidade de produto comprada pelo cliente");
								scanf("%d",&qtd_produto_caixa);
							
								if(qtd_produto_caixa>=0) break;
							
							}while(TRUE);	
					        
					        	if(qtd_produto_caixa<=p.quantidade){
					        		printf("\nCompra autorizada,produto presente no estoque!");
					        		
					        		//impressao da nota fiscal:
					        		formatacao_nota_fiscal2("nota_fiscal.txt",p.id,p.nome,qtd_produto_caixa,p.preco_venda);
					        		
					        		flag_caixa=1;
					        		break;
					        	}
					        	else if(qtd_produto_caixa==0){
					        		printf("\nProduto não disponivel no estoque,não é possivel realizar a compra,entre com um novo produto.");
					        		flag_caixa=0;
					        		break;
					        	}
					        			
					        	
						}while(TRUE);
					
						if(flag_caixa==1){
						//atualizar uma serie de campos necessario:
						
							//-o total de produtos da compra aumenta:
							co.total_produtos++;
							
							co.produto=(Produto *)realocar_memoria(co.produto,co.total_produtos,sizeof(Produto));
							co.quantidade=(int *)realocar_memoria(co.quantidade,co.total_produtos,sizeof(int));
							//adicionando os dados aos vetores de produtos e quantidade da struct compra:
							*(co.produto+co.total_produtos-1)=p;
							*(co.quantidade+co.total_produtos-1)=qtd_produto_caixa;
							
							//atualizando saldo do caixa:
							c.saldo=c.saldo+(p.preco_venda*qtd_produto_caixa);
							valor_compra=valor_compra+(p.preco_venda+qtd_produto_caixa);
							
							//funcao atualizar estoque,vai ter como parametro  a quantidade_produto_caixa.
							//criar essa função.
						}			
								
					}while(TRUE);
					
					//atualizacao da nota fiscal:
					formatacao_nota_fiscal3("nota_fiscal.txt",co.total_produtos,valor_compra,fu_caixa.nome,fu_caixa.id);
					printf("\nnota fiscal presente na pasta do programa:");
	
					//ultimas atualizacoes necessarias:
					co.horario=*(gerando_horario());
					
					//inserindo compra no banco de dados:
					if(!insert_compra(co)){
						printf("\nERRO NO SISTEMA-FIM DO PROGRAMA");
						exit(1);
					}
					
					//inserindo caixa e atualizacoes:
					atualiza_saldo_caixa(c,valor_compra);
					
				}while(TRUE);
				
				//finalizando o caixa,atualizacao dos campos:
				t.horario_final=*(gerando_horario());
				
				//inserindo o turno no banco de dados:
				if(!fechar_turno(t)){
					printf("ERRO DO SISTEMA-FIM DO PROGRAMA");
					exit(1);
				}
				
				//entrando na tela de movimentacao:
				printf("\ndeseja fazer uma movimentação de dinheiro no caixa,se sim:digite-1 se sim,senao digite-2");
				scanf("%d",&multiuso);
				
				if(multiuso==1){
					
					printf("\nQual o valor a ser retirado do caixa:");
					scanf("%f",&movimentacao);
					
					//preenchendo struct movimentacao:
					m.funcionario=fu_caixa;
					m.caixa=c;
					m.horario=*(gerando_horario());
					m.valor=movimentacao;
					
					//inserindo movimentacao no banco de dados:
					if(!insert_movimentacao(m)){
						printf("ERRO DO SISTEMA-FIM DO PROGRAMA");
						exit(1);
					}	
				}	
				break;
				
			case 2:
				printf("\nVOCÊ ESTÁ NO MENU DO ESTOQUE.");
				printf("\nDIGITE:");
				printf("\n1-PARA CADASTRAR PRODUTOS NO ESTOQUE.");
				printf("\n2-PARA VERIFICAR QUAIS PRODUTOS ESTÃO EM BAIXA NO ESTOQUE.");
				printf("\n3-PARA EXCLUIR UM PRODUTO DO ESTOQUE(necessario id do produto)");
				printf("\n4-PARA ALTERAR OS DADOS DE UM PRODUTO CADASTRADO NO ESTOQUE.(menos da quantidade do produto em estoque)");
				printf("\n5-PARA BUSCAR OS DADOS DE UM PRODUTO(POR NOME).");
				printf("\n6-PARA BUSCAR OS DADOS DE UM PRODUTO(POR ID DO PRODUTO).");
				printf("\n7-PARA CADASTRAR OS FABRICANTES E FORNECEDORES.");
				printf("\n8-PARA ALTERAR A QUANTIDADE DE UM PRODUTO EM ESTOQUE");
				scanf("%d",&codigo_estoque);
				switch(codigo_estoque){
					case 1:
						p=lendo_produto();
						if(!insert_produto(p)){
							printf("\nERRO NO SISTEMA-FIM DO PROGRAMA");
							exit(1);
						}	
						break;
						
					case 2:
						printf("\nQual a quantidade considerada baixa no estoque");
						scanf("%d",&parametro_baixa_estoque);
						//criar funcao para realizar tal elemento.
						break;
						
					case 3:
						do{
							printf("\ndigite o id do produto que deseja excluir do estoque");
							scanf("%d",&multiuso);
							if( (p_PTR=find_produto(multiuso)) != NULL){
								printf("\nPRODUTO ENCONTRADO COM SUCESSO");
								break;
							}
							else printf("id digitado nao encontrado no estoque");
						
						}while(TRUE);
						
						p=*p_PTR;
						delete_produto(p);
						free(p_PTR);
						break;
						
					case 4:
						do{
							printf("\nDigite o id do produto que deseja atualizar seu dados");
							scanf("%d",&multiuso);
							if( (p_PTR=find_produto(multiuso)) != NULL){
								printf("\nPRODUTO ENCONTRADO COM SUCESSO");
								break;
							}
							else printf("id digitado nao encontrado no estoque");
						}while(TRUE);
						lendo_produto_para_atualizar(p_PTR);
						p=*p_PTR;
						update_produto(p);
						free(p_PTR);
						break;
					case 5:
						//criar a funcao de buscar por nome no banco de dados.
						break;
					case 6:
						do{
							printf("\ndigite o id do produto que deseja procurar");
							scanf("%d",&multiuso);
							
							if( (p_PTR=find_produto(multiuso)) != NULL ){
								printf("\nPRODUTO ENCONTRADO COM SUCESSO");
								break;
							}	
						}while(TRUE);
						imprimindo_produto(p_PTR);	
						free(p_PTR);
						break;
					case 7:
						f=lendo_fabricante();
						if(!insert_fabricante(f)){
							printf("\nERRO NO SISTEMA-FIM DO PROGRAMA");
							exit(1);
						}
						printf("\nfabricante cadastrado com sucesso!");	
						break;
					case 8:
					
						//preenchendo a struct reposição e cadastrando a mesma no banco de dados:
						do{
							printf("\nDigite o id do funcionario que vai fazer a reposição ou mudança de quantidade do produto no estoque");
							scanf("%d",&multiuso);
							if( (fu_PTR=find_funcionario(multiuso) ) != NULL){
								printf("\nfuncionario encontrado com sucesso.");
								fu=*fu_PTR;
								free(fu_PTR);
								break;
							}
						}while(TRUE);
								
						//inserindo os dados de funcionario na struct reposicao:
						r.funcionario=fu;
						
						do{
							printf("\nDigite o id do produto que vai fazer a reposição ou mudança de quantidade do produto no estoque");
							scanf("%d",&multiuso);
							if( (p_PTR=find_produto(multiuso) ) != NULL){
								printf("\nproduto encontrado com sucesso.");
								p=*p_PTR;
								free(p_PTR);
								break;
							}
						}while(TRUE);
						
						//inserindo os dados do produto na struct reposição:
						r.produto=p;
						
						do{
							printf("Digite a quantidade do produto que deseja substituir no estoque");
							scanf("%d",&multiuso);
							
							if(multiuso>0) break;
							
						}while(TRUE);
						
						r.quantidade=multiuso;
						r.horario=*(gerando_horario());
						
						//inserindo a struct reposicao no banco de dados:
						if( !insert_reposicao(r) ){
							printf("ERRO NO SISTEMA-FIM DO PROGRAMA");
							exit(1);
						}	
							
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
				printf("\n3-PARA EXCLUIR UM CADASTRO DE UM FUNCIONÁRIO(necessario o id do produto)");
				printf("\n4-PARA FAZER UMA BUSCA DOS DADOS DE UM FUNCIONARIO(POR ID DO FUNCIONÁRIO)");
				printf("\n5-PARA FAZER UMA BUSCA DOS DADOS DE UM FUNCIONÁRIO(POR NOME DO FUCIONÁRIO)");
				scanf("%d",&codigo_funcionario);
				switch(codigo_funcionario){
					case 1:
						fu=lendo_funcionario();
						if(!insert_funcionario(fu)){
							printf("\nERRO NO SISTEMA-FIM DO PROGRAMA");
							exit(1);
						}
						printf("\nfuncionario cadastro com sucesso");	
						break;
					case 2:
						do{
							printf("\ndigite o id do funcionario que deseja atualizar seus dados:");
							scanf("%d",&multiuso);
							if( (fu_PTR=find_funcionario(multiuso)) != NULL ){
								printf("\nFUNCIONARIO ENCONTRANDO COM SUCESSO");
								break;
							}
						}while(TRUE);	
						lendo_funcionario_para_atualizar(fu_PTR);
						fu=*fu_PTR;
						update_funcionario(fu);
						free(fu_PTR);
						printf("\natualizacao efetuada com sucesso");
						break;
						
					case 3:
						do{
							printf("\ndigite o id do funcionario que deseja excluir.");
							scanf("%d",&multiuso);
							if( (fu_PTR=find_funcionario(multiuso)) != NULL){
								printf("\nFUNCIONARIO ENCONTRADO COM SUCESSO");
								break;
							}
							else printf("id digitado para o funcionario não encontrado no banco.");
						
						}while(TRUE);
						fu=*fu_PTR;
						delete_funcionario(fu);
						free(fu_PTR);
						printf("\nregistro excluido com sucesso");
						break;
					case 4:
					
						do{
							printf("\ndigite o id do produto que deseja procurar");
							scanf("%d",&multiuso);
							
							if( (fu_PTR=find_funcionario(multiuso)) != NULL ){
								printf("\nPRODUTO ENCONTRADO COM SUCESSO");
								break;
							}	
						}while(TRUE);
						free(fu_PTR);
						imprimindo_funcionario(fu_PTR);
						break;
						
					case 5:
						//criar a funcao para procurar por nome.
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
