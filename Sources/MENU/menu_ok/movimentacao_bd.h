/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Movimentacoes
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include "bd.h"
#include "movimentacao.h"

/**
 * Esta função recebe um id do funcionario, id do caixa e o horario da movimentacao
 * e faz a busca no banco de dados pela movimentacao correspondente e o retorna. 
 *
 * id_funcioario - identificador do funcionario
 * id_caixa - identificador do caixa
 * horario - horario que ocorreu a movimentacao
 */
Movimentacao findMovimentacao(const int id_funcionario, const int id_caixa, const struct tm horario);

/**
 * Esta função recebe um id de um funcionario, e busca no banco de dados
 * todas as movimentações do funcionario 
 *
 * id_funcionaro - identificador do funcionario
 */
Movimentacao* findMovimentacoesDoFuncionario(const int id_funcionario);

/**
 * Esta função retorna quantas movimentacoes 
 * o funcionario efetuou
 *
 * id_funcionario - identificador do funcionario 
 *
 */
int getQtdMovimentacoesDoFuncionario(const int id_funcionario);

/**
 * Esta função recebe um id do caixa, e busca no banco de dados
 * todas as movimentações daquele caixa. 
 *
 * id_caixa - identificador do caixa.
 */
Movimentacao* findMovimentacoesDoCaixa(const int id_caixa);

/**
 * Esta função retorna quantas movimentacoes ocorreram no caixa.
 *
 * id_caixa - identificador do produto.
 */
int getQtdMovimentacoesDoCaixa(const int id_caixa);

/**
 * Esta função recebe uma data, e busca no banco de dados
 * todas as movimentacoes daquele dia. 
 *
 * data - Data que deseja saber as movimentacoes.
 */
Movimentacao* findMovimentacoesPorData(const struct tm data);

/**
 * Esta função retorna quantas movimentacoes foram feitas no dia.
 *
 * data - Data que deseja saber quantas movimentações ocorreram.
 */
int getQtdMovimentacoesPorData(const struct tm data);

/**
 * Esta função retorna um ponteiro para todas as 
 * movimentações cadastradas no banco de dados.
 *
 */
Movimentacao* getAllMovimentacoes();

/**
 * Esta função retorna quantas movimentações 
 * estão cadastrados no banco de dados.
 *
 */
int getQtdAllMovimentaoes();

/**
 * Esta função retorna um ponteiro para todos as
 * movimentacoes cadastradas no banco de dados.
 *
 * tam - Ponteiro para uma variavel inteira. É usada para
 *       retornar a quantidade de movimentacoes que contém no ponteiro
 *       que é retornado pela função.
 */
Movimentacao* getAllMovimentacoes(int* tam);

/**
 * Esta recebe uma Movimentacao e faz sua inserção no 
 * banco de dados.
 */
bool insert_movimentacao(const Movimentacao);

/**
 * Esta recebe uma Movimentacao e atualiza os dados da
 * movimentação com o respectivo id no banco de dados. 
 */
bool updateMovimentacao(const Movimentacao);

/**
 * Esta função recebe uma Movimentacao e a deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool deleteMovimentacao(const Movimentacao);
