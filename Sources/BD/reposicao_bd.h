/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Reposicoes
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include "bd.h"
#include "../MODELO/reposicao.h"

/**
 * Esta função recebe um id do funcionario, id do produto e o horario
 * faz a busca no banco de dados pela reposicao correspondente e a retorna. 
 *
 * id_funcioario - identificador do funcionario
 * id_produto - identificador do produto
 * horario - horario em que ocorreu a reposição
 */
Reposicao findReposicao(const int id_funcionario, const int id_produto, const struct tm horario);

/**
 * Esta função recebe um id de um funcionario, e busca no banco de dados
 * todas as reposições feitas por ele 
 *
 * id_funcionaro - identificador do funcionario
 */
Reposicao* findResposicaoPorFuncionario(const int id_funcionario);

/**
 * Esta função retorna quantas reposições 
 * foram efetuadas pelo funcioario.
 *
 * id_funcionario - identificador do funcionario 
 *
 */
int getQtdReposicaoPorFuncionario(const int id_funcionario);

/**
 * Esta função recebe um id de um produto, e busca no banco de dados
 * todas as reposições daquele produto. 
 *
 * id_produto - identificador do produto.
 */
Reposicao* findReposicaoDoProduto(const int id_produto);

/**
 * Esta função retorna quantas reposições foram feitas do produto.
 *
 * id_produto - identificador do produto.
 *
 */
int getQtdReposicaoDoProduto(const int id_produto);

/**
 * Esta função recebe uma data, e busca no banco de dados
 * todas as reposições feitas naquele dia. 
 *
 * data - Data que deseja saber as reposições.
 */
Reposicao* findReposicaoPorData(const struct tm data);

/**
 * Esta função retorna quantas reposições foram feitas no dia.
 *
 * data - Data que deseja saber quantas reposições ocorreram.
 *
 */
int getQtdReposicaoPorData(const struct tm data);

/**
 * Esta função retorna um ponteiro para todas as 
 * reposições cadastradas no banco de dados.
 *
 */
Reposicao* getAllReposicoes();

/**
 * Esta função retorna quantas reposições 
 * estão cadastrados no banco de dados.
 *
 */
int getQtdAllReposicoes();

/**
 * Esta função retorna um ponteiro para todas as
 * resposicoes cadastradas no banco de dados.
 *
 * tam - Ponteiro para uma variavel inteira. É usada para
 *       retornar a quantidade de reposições que contém no ponteiro
 *       que é retornado pela função.
 */
Reposicao* getAllReposicoes(int* tam);

/**
 * Esta recebe uma Reposicao e faz sua inserção no 
 * banco de dados.
 */
bool insertReposicao(const Reposicao);
 
/**
 * Esta recebe uma Reposicao e atualiza os dados da 
 * reposicao com o respectivo id no banco de dados. 
 */
bool updateReposicao(const Reposicao);

/**
 * Esta recebe uma Reposicao e a deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool deleteReposicao(const Reposicao);