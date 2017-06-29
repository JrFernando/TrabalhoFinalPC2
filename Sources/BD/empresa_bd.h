/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Empresa
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
 
#include <stdlib.h>

#include "bd.h"
#include "../MODELO/empresa.h"

/**
 * Esta função faz a busca as informações da empresa
 * no banco de dados.
 *
 *
 * return - Retorna uma struct empresa. Caso não exista retorna NULL. 
 */
Empresa findEmpresa();

/**
 * Esta recebe uma Empresa e faz sua inserção no 
 * banco de dados.
 */
bool insertEmpresa(const Empresa);

/**
 * Esta recebe uma Empresa e atualiza os dados da
 * empresa no banco de dados. 
 */
bool updateEmpresa(const Empresa);