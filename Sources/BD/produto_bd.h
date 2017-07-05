/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Produtos
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include "bd.h"
#include "../MODELO/produto.h"

/**
 * Esta função recebe um id, faz a busca no banco de dados
 * pelo produto correspondente e o retorna. 
 *
 * id - identificador do produto que deseja buscar
 */
Produto* find_produto(const int id);

/**
 * Esta função recebe um nome, faz a busca no banco de dados
 * pelo produto correspondente e o retorna. 
 *
 * nome - nome do produto que deseja buscar
 */
Produto* find_produto_nome(const char* nome);

/**
 * Esta função retorna quantos produtos 
 * foram encontrados na função find_produto_nome.
 *
 */
int get_qtd_find_produto_nome(const char* nome);

/**
 * Esta função retonar os produtos que estão
 * com o estoque abaixo do valor informado.
 * 
 * @param n número referência para determinar se o produto esta em baixa no estoque
 * @return Ponteiro para vários produtos;
 */
Produto* find_produtos_estoque_baixo(int n);

/**
 * Esta função retorna a quantidade de elementos que contém
 * o retorno da função find_produtos_estoque_baixo;
 * 
 * @param n Número referência para determinar se o produto esta em baixa no estoque
 * @return Quantidade de elementos que a função find_produtos_estoque_baixo irá retornar;
 */
int get_qtd_find_produtos_estoque_baixo(int n);

/**
 * Esta função retonar os produtos que são mais vendidos
 * 
 * @return Ponteiro para vários produtos;
 */
Produto* find_produtos_mais_vendidos();

/**
 * Esta função retorna um ponteiro para int com o total de vendas
 * para cada produto, na mesma ordem da função find_produtos_mais_vendidos
 * 
 * @return Ponteiros para vários totais de vendas;
 */
int* find_qtd_produtos_mais_vendidos();

/**
 * Esta função retorna a quantidade de elementos que contém
 * o retorno da função find_produtos_mais_vendidos;
 * 
 * @return Quantidade de elementos que a função find_produtos_mais_vendidos irá retornar;
 */
int get_qtd_find_produtos_mais_vendidos();

/**
 * Esta função retorna um ponteiro para todos os 
 * produtos cadastrados no banco de dados.
 *
 */
Produto* get_all_produtos();

/**
 * Esta função retorna quantos produtos 
 * estão cadastrados no banco de dados.
 *
 */
int get_qtd_all_produtos();

/**
 * Esta função atualiza o estoque do produto
 * 
 * @param produto Produto a ser atualizado o estoque
 * @param quantidade Quantidade do produto
 * @return TRUE caso de certo e FALSE caso deu errado.
 */
bool atualiza_estoque_produto(Produto produto, int quantidade);

/**
 * Esta função é utiliza para repor o estoque
 * 
 * @param produto Produto a ser reposto o estoque
 * @param quantidade Nova quantidade do produto
 * @return TRUE caso de certo e FALSE caso deu errado.
 */
bool set_novo_estoque_produto(Produto produto, int quantidade);

/**
 * Esta recebe um Produto e faz sua inserção no 
 * banco de dados.
 */
bool insert_produto(const Produto);
 
/**
 * Esta recebe um Produto e atualiza os dados do 
 * produto com o respectivo id no banco de dados. 
 */
bool update_produto(const Produto);

/**
 * Esta recebe um Produto e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool delete_produto(const Produto);