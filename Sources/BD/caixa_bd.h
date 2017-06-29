/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Caixas
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include "bd.h"
#include "../MODELO/caixa.h"

/**
 * Esta função recebe um id, faz a busca no banco de dados
 * pelo caixa correspondente e o retorna. 
 *
 * id - identificador do caixa que deseja buscar
 */
Caixa findCaixa(int id);

/**
 * Esta função retorna um ponteiro para todos os 
 * caixas cadastrados no banco de dados.
 *
 */
Caixa* getAllCaixas();

/**
 * Esta função retorna quantos caixas 
 * estão cadastrados no banco de dados.
 *
 */
int getQtdAllCaixas();

/**
 * Esta função retorna um ponteiro para todos os 
 * caixas cadastrados no banco de dados.
 *
 * tam - Ponteiro para uma variavel inteira. É usada para
 *       retornar a quantidade de Caixas que contém o ponteiro
 *       que é retornado pela função.
 */
Caixa* getAllCaixas(int* tam);

/**
 * Esta recebe um Caixa e faz sua inserção no 
 * banco de dados.
 */
bool insertCaixa(const Caixa);
 
/**
 * Esta recebe um Caixa e atualiza os dados do 
 * produto com o respectivo id no banco de dados. 
 */
bool updateCaixa(const Caixa);

/**
 * Esta recebe um Caixa e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
bool deleteCaixa(const Caixa);