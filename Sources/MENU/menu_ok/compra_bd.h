/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Compras
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include "bd.h"
#include "compra.h"

/**
 * Esta função recebe um id, faz a busca no banco de dados
 * pela compra correspondente e a retorna. 
 *
 * id - identificador da compra que deseja buscar
 */
Compra* find_compra(const int id);

/**
 * Esta função recebe um id de um caixa, e busca no banco de dados
 * as compras que ocorreram naquele caixa. 
 *
 * id_caixa - identificador do caixa que deseja buscar as compras
 */
Compra* findCompraPorCaixa(const int id_caixa);

/**
 * Esta função retorna quantas compras 
 * foram efetuadas por um determinado caixa.
 *
 * id_caixa - identificador do caixa que deseja saber quantas compras 
 * foram efetuadas.
 *
 */
int getQtdCompraPorCaixa(const int id_caixa);

/**
 * Esta função recebe um id de um produto, e busca no banco de dados
 * todas as compras que contém aquele produto. 
 *
 * id_produto - identificador do produto que deseja buscar nas compras
 */
Compra* findCompraPorProduto(const int id_produto);

/**
 * Esta função retorna quantas compras contém o produto desejado.
 *
 * id_produto - identificador do produto que deseja saber quantas compras 
 * o contém.
 *
 */
int getQtdCompraPorProduto(const int id_produto);

/**
 * Esta função retorna um ponteiro para todas as 
 * compras cadastradas no banco de dados.
 *
 */
Compra* getAllCompras();

/**
 * Esta função retorna quantas compras 
 * estão cadastrados no banco de dados.
 *
 */
int getQtdAllCompras();

/**
 * Esta função retorna um ponteiro para todas as
 * compras cadastradas no banco de dados.
 *
 * tam - Ponteiro para uma variavel inteira. É usada para
 *       retornar a quantidade de Compras que contém no ponteiro
 *       que é retornado pela função.
 */
Compra* getAllCompras(int* tam);

/**
 * Esta recebe uma Compra e faz sua inserção no 
 * banco de dados.
 */
bool insert_compra(const Compra);
 
/**
 * Esta recebe uma Compra e atualiza os dados da 
 * compra com o respectivo id no banco de dados. 
 */
bool updateCompra(const Compra);

/**
 * Esta recebe uma Compra e a deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool deleteCompra(const Compra);
