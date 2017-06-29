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
Produto findProduto(int id);

/**
 * Esta função retorna um ponteiro para todos os 
 * produtos cadastrados no banco de dados.
 *
 */
Produto* getAllProdutos();

/**
 * Esta função retorna quantos produtos 
 * estão cadastrados no banco de dados.
 *
 */
int getQtdAllProdutos();

/**
 * Esta função retorna um ponteiro para todos os 
 * produtos cadastrados no banco de dados.
 *
 * tam - Ponteiro para uma variavel inteira. É usada para
 *       retornar a quantidade de Produtos que contém o ponteiro
 *       que é retornado pela função.
 */
Produtos* getAllProdutos(int* tam);

/**
 * Esta recebe um Produto e faz sua inserção no 
 * banco de dados.
 */
bool insertProduto(const Produto);
 
/**
 * Esta recebe um Produto e atualiza os dados do 
 * produto com o respectivo id no banco de dados. 
 */
bool updateProduto(const Produto);

/**
 * Esta recebe um Produto e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool deleteProduto(const Produto);