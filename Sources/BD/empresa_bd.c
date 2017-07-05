/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Empresa
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 29/06/2017
 */
#include <stdlib.h>
#include <string.h>

#include "empresa_bd.h"
#include "../UTIL/alocacao_memoria.h"

Empresa* find_empresa() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Empresa;";
    Empresa *empresa;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        linhas = mysql_fetch_row(resposta);
        if (linhas == NULL) return NULL;

        empresa = (Empresa*) alocar_memoria(1, sizeof (Empresa));

        empresa->nome = (char*) alocar_memoria(strlen(linhas[0]), sizeof (char));
        strcpy(empresa->nome, linhas[0]);

        empresa->cnpj = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
        strcpy(empresa->cnpj, linhas[1]);

        empresa->endereco = (char*) alocar_memoria(strlen(linhas[2]), sizeof (char));
        strcpy(empresa->endereco, linhas[2]);

    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return empresa;
}

bool insert_empresa(const Empresa empresa) {
    MYSQL mysql;
    char* query = "insert into Empresa values (\"\",\"\",\"\");"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(empresa.nome) + strlen(empresa.cnpj) + strlen(empresa.endereco);
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "insert into Empresa values (\"%s\",\"%s\",\"%s\");", empresa.nome, empresa.cnpj, empresa.endereco);

    if (!bd_open(&mysql)) return FALSE;

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return FALSE;
    }
}

bool update_empresa(const Empresa empresa) {
    MYSQL mysql;
    char* query = "update Empresa set empr_nome = \"\", empr_cnpj = \"\", empr_endereco = \"\";"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(empresa.nome) + strlen(empresa.cnpj) + strlen(empresa.endereco);
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "update Empresa set empr_nome = \"%s\", empr_cnpj = \"%s\", empr_endereco = \"%s\";",
            empresa.nome, empresa.cnpj, empresa.endereco);

    if (!bd_open(&mysql)) return FALSE;

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return FALSE;
    }
}