/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Turnos
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include "bd.h"
#include "turno.h"

/**
 * Esta função recebe um id do funcionario, id do caixa e o horario de inicio
 * faz a busca no banco de dados pelo turno correspondente e o retorna. 
 *
 * id_funcioario - identificador do funcionario
 * id_caixa - identificador do caixa
 * horario - horario em que o caixa foi aberto
 
 */
Turno findReposicao(const int id_funcionario, const int id_caixa, const struct tm horario);

/**
 * Esta função recebe um id de um funcionario, e busca no banco de dados
 * todas os turnos do funcionario 
 *
 * id_funcionaro - identificador do funcionario
 */
 
void fechar_turno(const turno);
 
 
Turno* findTurnosDoFuncionario(const int id_funcionario);

/**
 * Esta função retorna quantas turnos 
 * o funcioario contém.
 *
 * id_funcionario - identificador do funcionario 
 *
 */
int getQtdTurnosDoFuncionario(const int id_funcionario);

/**
 * Esta função recebe um id do caixa, e busca no banco de dados
 * todos os turnos efetuados no caixa. 
 *
 * id_caixa - identificador do caixa.
 */
Turno* findTurnosDoCaixa(const int id_caixa);

/**
 * Esta função retorna quantos turnos foram efetuados no caixa.
 *
 * id_caixa - identificador do produto.
 */
int getQtdTurnosDoCaixa(const int id_caixa);

/**
 * Esta função recebe uma data, e busca no banco de dados
 * todos os turnos daquele dia. 
 *
 * data - Data que deseja saber os turnos.
 */
Turno* findTurnoPorData(const struct tm data);

/**
 * Esta função retorna quantos turnos foram feitos no dia.
 *
 * data - Data que deseja saber quantas turnos ocorreram.
 *
 */
int getQtdTurnoPorData(const struct tm data);

/**
 * Esta função retorna um ponteiro para todos os 
 * turnos cadastrados no banco de dados.
 *
 */
Turno* getAllTurnos();

/**
 * Esta função retorna quantos turnos 
 * estão cadastrados no banco de dados.
 *
 */
int getQtdAllTurnos();

/**
 * Esta função retorna um ponteiro para todos os
 * turnos cadastrados no banco de dados.
 *
 * tam - Ponteiro para uma variavel inteira. É usada para
 *       retornar a quantidade de turnos que contém no ponteiro
 *       que é retornado pela função.
 */
Turno* getAllTurnos(int* tam);

/**
 * Esta recebe um Turno e faz sua inserção no 
 * banco de dados.
 */
bool insert_turno(const Turno);

/**
 * Esta recebe um Turno e atualiza os dados do 
 * turno com o respectivo id no banco de dados. 
 */
bool updateTurno(const Turno);

/**
 * Esta função recebe um Turno e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool deleteTurno(const Turno);
