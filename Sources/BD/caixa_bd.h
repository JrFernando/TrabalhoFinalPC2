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
Caixa* find_caixa(int id);

/**
 * Esta função retorna o valor atual do caixa
 *
 * caixa - caixa que deseja saber o saldo
 *
 * Retorno - Saldo do caixa.
 *
 * Erro - Retorna -1;
 */
float get_saldo_caixa(Caixa caixa);

/**
 * Esta função atualiza o saldo do caixa
 *
 * id - identificador do caixa que deseja atualizar o saldo
 * valor_compra - valor da compra para atualizar o caixa
 */
bool atualiza_saldo_caixa(Caixa caixa);

/**
 * Esta função faz uma baixa no caixa
 *
 * id - identificador do caixa que deseja dar baixa
 * valor_baixa - valor que deseja retirar do caixa
 */
bool movimentar_saldo_caixa(Caixa caixa);

/**
 * Esta função retorna um ponteiro para todos os 
 * caixas cadastrados no banco de dados.
 *
 */
//Caixa* getAllCaixas(); Não utilzar no momento

/**
 * Esta função retorna quantos caixas 
 * estão cadastrados no banco de dados.
 *
 */
//int getQtdAllCaixas(); Não utilizar no momento.

/**
 * Esta recebe um Caixa e faz sua inserção no 
 * banco de dados.
 */
//bool insertCaixa(const Caixa); Não utilizar no momento, terá apenas um caixa
 

/**
 * Esta recebe um Caixa e o deleta do banco de
 * dados de acordo com o id. É necessário somente o id
 * para a exlusão, foi mantido a struct para seguir o padrão 
 * das funções anteriores. 
 */
//bool deleteCaixa(const Caixa); Não utilizar no momento, terá penas um caixa