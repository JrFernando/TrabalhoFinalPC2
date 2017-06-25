#include<stdio.h>
#include<stdlib.h>
#include "estruturas.h"
#include "formatacaocupom.h"
#include "horario.h"
#include "alocacao_memoria.h"
#define TRUE 1


/*
-criando a a estrutura do caixa, como vai funcionar sua interação com o usuario.
-caixa simples,nao vai entrar aqui o fato do usuario ter de fornecer id para o caixa,senha ,etc 
*/


/*
-antes dessa tela temos quer ter os seguintes dados ja disponiveis:
	-caixa_id==comp_caix_id(no banco de dados),ambos da struct Compra e caixa.
	-comp_id(podemos gerar antes ou o proprio banco de dados pode gerar.
	-prescisa dos dados da struct empresa tambem para colocar na nota fiscal.

*/

//mudar esse int main,ideal que isso seja um funcao de nome void caixa(),usando o int main apenas paras fins de compilação.
int main(){
	int codigo_acesso;
	int codigo_produto;
	int quantidade_produto;
	
	
	//necessita de uma menu para entrar nessa tela.
	
	//abrindo o cupom fisca aqui:
	//formatacao_nota_fiscal1(nome_do_arquixo_txt,struct empresa com os dados);
	
	do{
		do{
			printf("\ndigite 1-para adicionar uma compra,0-para fechar a compra");
			scanf("%d",&codigo_acesso);
			if(codigo_acesso==1 || codigo_acesso==0) break;
			else printf("\ncodigo digitado invalido");
			
		//evita o usuario digitar elementos errados aqui.	
		}while(TRUE);
		
		//fechando a compra;
		if(!codigo_acesso) break;
		
		do{
			printf("\ndigite o codigo do produto comprado pelo cliente:");
			scanf("%d",&codigo_produto);
			
		//funcao do banco de dados que vai procurar esse codigo e fornecer os dados dos produto,caso não provalvemente entre em um looping novamente,para o usuario digitar corretamente o codigo do produto.
		}while(TRUE);
		
		do{
			do{
				printf("\n digite a quantidade do produto comprada pelo ciente:");
				scanf("%d",&quantidade_produto);
				if(quantidade_produto>0) break;
				else printf("\ncodigo digitado inválido");
			}while(TRUE);	
			
			//conferiri no banco se tem estoque.
			//senao informar a nao existencia do estoque,se tem,da um break e sai desse loop.
			
		}while(TRUE);
		
		//formatacao do cupom fiscal parte 2:
		//formatacao_nota_fiscal2(nome_do_arquivo_txt,id_do_produto,nome_produto,quantidade_produto_comprada,preco_produto)
		//aqui entra no looping e vai adicionando produtos a nota fiscal.
		
		//Parte da atualização do banco de dados por causa da compra:
		//multiplicamos a quantidade do produto pelo preço do produto e assim por diante,temos,um elemento para o fluxo do caixa.
		/*depois dessa operação temos que atualizar o os seguintes campos no banco de dados:
		 	-prod_quantidade=prod_quantidade-quantidade_produto(da tabela Produtos,similiar a uma atualização de estoque).
		 	-comp_qtd_produto=quantidade_produto(da tabela Compras).
		 	-caixa_saldo=caixa_saldo+preco_venda*quantidade_produto.(deve acumular)
		 	-comp_horario=gerando_horario() biblioteca horario.h;
		*/
		
		
	}while(TRUE);
	
	//final do cupom fiscal parte3(finaliza o cupom fiscal):
	//o banco deve calcular a soma total de itens da compra(ou adicionarmos uma variavel aqui para isso),e o valor total da compra.
	//formatacao_nota_fiscal3(nome_do_arquivo_txt,valor_total_compra,char *forma de pagamento,
	
	return 0;
		
}	

