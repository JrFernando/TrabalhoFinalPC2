/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Compras, Reposições, Turnos e Movimentações.
 * 
 * CRIEI ESSE ARQUIVO PARA CORRIGIR O ERRO DE CONFLITO DE IMPORTAÇÕES
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include "bd.h"
#include "../MODELO/acoes_funcionario.h"

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
Compra* find_compra_por_caixa(const int id_caixa);

/**
 * Esta função retorna quantas compras 
 * foram efetuadas por um determinado caixa.
 *
 * id_caixa - identificador do caixa que deseja saber quantas compras 
 * foram efetuadas.
 *
 */
int get_qtd_compra_por_caixa(const int id_caixa);

/**
 * Esta função recebe um id de um produto, e busca no banco de dados
 * todas as compras que contém aquele produto. 
 *
 * id_produto - identificador do produto que deseja buscar nas compras
 */
Compra* find_compra_por_produto(const int id_produto);

/**
 * Esta função retorna quantas compras contém o produto desejado.
 *
 * id_produto - identificador do produto que deseja saber quantas compras 
 * o contém.
 *
 */
int get_qtd_compra_por_produto(const int id_produto);

/**
 * Esta função recebe um id de um vendedor, e busca no banco de dados
 * todas as compras efetuadas por ele; 
 *
 * id_vendedor - identificador do vendedor
 */
Compra* find_compra_por_vendedor(const int id_vendedor);

/**
 * Esta função retorna quantas compras foram efetuadas pelo vendedor
 *
 * id_vendedor - identificador do vendedor 
 *
 */
int get_qtd_compra_por_vendedor(const int id_vendedor);

/**
 * Esta função retorna um ponteiro para todas as 
 * compras cadastradas no banco de dados.
 *
 */
Compra* get_all_compras();

/**
 * Esta função retorna quantas compras 
 * estão cadastrados no banco de dados.
 *
 */
int get_qtd_all_compras();

/**
 * Esta recebe uma Compra e faz sua inserção no 
 * banco de dados.
 */
bool insert_compra(const Compra);

/**
 * Retorna o último id cadastrado no banco
 * 
 * @return Último id cadastrado no banco
 */
int get_last_id_compra();

/**
 * Converte MYSQL_ROW para Compra
 * 
 * row - Variavel do tipo MYSQL_ROW
 * 
 * Retorno - Ponteiro para Compra
 * 
 */
Compra* store_result_to_compra(MYSQL_RES *res);

/**
 * Esta recebe uma Compra e atualiza os dados da 
 * compra com o respectivo id no banco de dados. 
 */
//bool update_compra(const Compra); A princípio não será usada

/**
 * Esta recebe uma Compra e a deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
//bool delete_compra(const Compra); A princípio não será usada

/************************************************************************
*************************************************************************
************************** REPOSIÇÃO ************************************
*************************************************************************
*************************************************************************/


/**
 * Esta função recebe um id do funcionario, id do produto e o horario
 * faz a busca no banco de dados pela reposicao correspondente e a retorna. 
 *
 * id_funcioario - identificador do funcionario
 * id_produto - identificador do produto
 * horario - horario em que ocorreu a reposição
 */
Reposicao* find_reposicao(const int id_funcionario, const int id_produto, const struct tm horario);

/**
 * Esta função recebe um id de um funcionario, e busca no banco de dados
 * todas as reposições feitas por ele 
 *
 * id_funcionaro - identificador do funcionario
 */
Reposicao* find_resposicao_por_funcionario(const int id_funcionario);

/**
 * Esta função retorna quantas reposições 
 * foram efetuadas pelo funcioario.
 *
 * id_funcionario - identificador do funcionario 
 *
 */
int get_qtd_reposicao_por_funcionario(const int id_funcionario);

/**
 * Esta função recebe um id de um produto, e busca no banco de dados
 * todas as reposições daquele produto. 
 *
 * id_produto - identificador do produto.
 */
Reposicao* find_reposicao_do_produto(const int id_produto);

/**
 * Esta função retorna quantas reposições foram feitas do produto.
 *
 * id_produto - identificador do produto.
 *
 */
int get_qtd_reposicao_do_produto(const int id_produto);

/**
 * Esta função recebe uma data, e busca no banco de dados
 * todas as reposições feitas naquele dia. 
 *
 * data - Data que deseja saber as reposições.
 */
Reposicao* find_reposicao_por_data(const struct tm data);

/**
 * Esta função retorna quantas reposições foram feitas no dia.
 *
 * data - Data que deseja saber quantas reposições ocorreram.
 *
 */
int get_qtd_reposicao_por_data(const struct tm data);

/**
 * Esta função retorna um ponteiro para todas as 
 * reposições cadastradas no banco de dados.
 *
 */
Reposicao* get_all_reposicoes();

/**
 * Esta função retorna quantas reposições 
 * estão cadastrados no banco de dados.
 *
 */
int get_qtd_all_reposicoes();

/**
 * Esta recebe uma Reposicao e faz sua inserção no 
 * banco de dados.
 */
bool insert_reposicao(Reposicao);

/**
 * Converte MYSQL_ROW para Reposicao
 * 
 * row - Variavel do tipo MYSQL_ROW
 * 
 * Retorno - Ponteiro para Reposicao
 * 
 */
Reposicao* row_to_reposicao(MYSQL_ROW row);
 
/**
 * Esta recebe uma Reposicao e atualiza os dados da 
 * reposicao com o respectivo id no banco de dados. 
 */
//bool update_reposicao(const Reposicao); A princípio não será usad

/**
 * Esta recebe uma Reposicao e a deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
//bool delete_reposicao(const Reposicao); A princípio não será usada

/************************************************************************
*************************************************************************
****************************** TURNO ************************************
*************************************************************************
*************************************************************************/

/**
 * Esta função recebe um id do funcionario, id do caixa e o horario de inicio
 * faz a busca no banco de dados pelo turno correspondente e o retorna. 
 *
 * id_funcioario - identificador do funcionario
 * id_caixa - identificador do caixa
 * horario - horario em que o caixa foi aberto
 */
Turno* find_turno(const int id_funcionario, const int id_caixa, const struct tm horario);

/**
 * Esta função recebe um id de um funcionario, e busca no banco de dados
 * todas os turnos do funcionario 
 *
 * id_funcionaro - identificador do funcionario
 */
Turno* find_turnos_do_funcionario(const int id_funcionario);

/**
 * Esta função retorna quantas turnos 
 * o funcioario contém.
 *
 * id_funcionario - identificador do funcionario 
 *
 */
int get_qtd_turnos_do_funcionario(const int id_funcionario);

/**
 * Esta função recebe um id do caixa, e busca no banco de dados
 * todos os turnos efetuados no caixa. 
 *
 * id_caixa - identificador do caixa.
 */
Turno* find_turnos_do_caixa(const int id_caixa);

/**
 * Esta função retorna quantos turnos foram efetuados no caixa.
 *
 * id_caixa - identificador do produto.
 */
int get_qtd_turnos_do_caixa(const int id_caixa);

/**
 * Esta função recebe uma data, e busca no banco de dados
 * todos os turnos daquele dia. 
 *
 * data - Data que deseja saber os turnos.
 */
Turno* find_turno_por_data(const struct tm data);

/**
 * Esta função retorna quantos turnos foram feitos no dia.
 *
 * data - Data que deseja saber quantas turnos ocorreram.
 *
 */
int get_qtd_turno_por_data(const struct tm data);

/**
 * Esta função retorna um ponteiro para todos os 
 * turnos cadastrados no banco de dados.
 *
 */
Turno* get_all_turnos();

/**
 * Esta função retorna quantos turnos 
 * estão cadastrados no banco de dados.
 *
 */
int get_qtd_all_turnos();

/**
 * Esta recebe um Turno e faz sua inserção no 
 * banco de dados.
 */
bool insert_turno(const Turno);

/**
 * Esta recebe um Turno com horario final para  
 * registrar o horario final na tabela assim fechando o turno.
 */
bool fecha_turno(const Turno);

/**
 * Converte MYSQL_ROW para Turno
 * 
 * row - Variavel do tipo MYSQL_ROW
 * 
 * Retorno - Ponteiro para Turno
 * 
 */
Turno* row_to_turno(MYSQL_ROW row);

/**
 * Esta recebe um Turno e atualiza os dados do 
 * turno com o respectivo id no banco de dados. 
 */
//bool update_turno(const Turno);

/**
 * Esta função recebe um Turno e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
//bool delete_turno(const Turno); A princípio não será usada

/************************************************************************
*************************************************************************
************************* MOVIMENTAÇÃO **********************************
*************************************************************************
*************************************************************************/

/**
 * Esta função recebe um id do funcionario, id do caixa e o horario da movimentacao
 * e faz a busca no banco de dados pela movimentacao correspondente e o retorna. 
 *
 * id_funcioario - identificador do funcionario
 * id_caixa - identificador do caixa
 * horario - horario que ocorreu a movimentacao
 */
Movimentacao* find_movimentacao(const int id_funcionario, const int id_caixa, const struct tm horario);

/**
 * Esta função recebe um id de um funcionario, e busca no banco de dados
 * todas as movimentações do funcionario 
 *
 * id_funcionaro - identificador do funcionario
 */
Movimentacao* find_movimentacoes_do_funcionario(const int id_funcionario);

/**
 * Esta função retorna quantas movimentacoes 
 * o funcionario efetuou
 *
 * id_funcionario - identificador do funcionario 
 *
 */
int get_qtd_movimentacoes_do_funcionario(const int id_funcionario);

/**
 * Esta função recebe um id do caixa, e busca no banco de dados
 * todas as movimentações daquele caixa. 
 *
 * id_caixa - identificador do caixa.
 */
Movimentacao* find_movimentacoes_do_caixa(const int id_caixa);

/**
 * Esta função retorna quantas movimentacoes ocorreram no caixa.
 *
 * id_caixa - identificador do produto.
 */
int get_qtd_movimentacoes_do_caixa(const int id_caixa);

/**
 * Esta função recebe uma data, e busca no banco de dados
 * todas as movimentacoes daquele dia. 
 *
 * data - Data que deseja saber as movimentacoes.
 */
Movimentacao* find_movimentacoes_por_data(const struct tm data);

/**
 * Esta função retorna quantas movimentacoes foram feitas no dia.
 *
 * data - Data que deseja saber quantas movimentações ocorreram.
 */
int get_qtd_movimentacoes_por_data(const struct tm data);

/**
 * Esta função retorna um ponteiro para todas as 
 * movimentações cadastradas no banco de dados.
 *
 */
Movimentacao* get_all_movimentacoes();

/**
 * Esta função retorna quantas movimentações 
 * estão cadastrados no banco de dados.
 *
 */
int get_qtd_all_movimentaoes();

/**
 * Esta recebe uma Movimentacao e faz sua inserção no 
 * banco de dados.
 */
bool insert_movimentacao(Movimentacao);

/**
 * Converte MYSQL_ROW para Movimentacao
 * 
 * row - Variavel do tipo MYSQL_ROW
 * 
 * Retorno - Ponteiro para Movimentacao
 * 
 */
Movimentacao* row_to_movimentacao(MYSQL_ROW row);

/**
 * Esta recebe uma Movimentacao e atualiza os dados da
 * movimentação com o respectivo id no banco de dados. 
 */
//bool update_movimentacao(const Movimentacao); A princípio não será usada

/**
 * Esta função recebe uma Movimentacao e a deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
//bool delete_movimentacao(const Movimentacao); A princípio não será usada