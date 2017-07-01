/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Fabricante
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 30/06/2017
 */
#include <string.h>

#include "fabricante_bd.h"
#include "../UTIL/alocacao_memoria.h"

#define TAM_MAX_ID 4

Fabricante* find_fabricante(int id) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Fabricantes where fabr_id =  ;";
    Fabricante* fabricante;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Fabricantes where fabr_id = %d;", id);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        fabricante = (Fabricante*) alocar_memoria(1, sizeof (Fabricante));
        linhas = mysql_fetch_row(resposta);

        fabricante->id = atoi(linhas[0]);

        fabricante->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
        strcpy(fabricante->nome, linhas[1]);
    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return fabricante;
}

Fabricante* get_all_fabricantes() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Fabricantes;";
    Fabricante *fabricantes, *temp;
    int quantidade;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        fabricantes = (Fabricante*) alocar_memoria(quantidade, sizeof (Fabricante));

        temp = fabricantes;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->id = atoi(linhas[0]);

            temp->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
            strcpy(temp->nome, linhas[1]);

            temp++;
        }

    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return fabricantes;
}

int get_qtd_all_fabricantes() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    char *query = "select * from Fabricantes;";
    int quantidade = -1;

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

bool insert_fabricante(const Fabricante fabricante) {
    MYSQL mysql;
    char* query = "insert into Fabricantes (fabr_nome) values (\"\");"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(fabricante.nome);
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "insert into Fabricantes (fabr_nome) values (\"%s\");", fabricante.nome);

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

bool update_fabricante(const Fabricante fabricante) {
    MYSQL mysql;
    char* query = "update Fabricantes set fabr_nome = \"\" where fabr_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(fabricante.nome) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "update Fabricantes set fabr_nome = \"%s\" where fabr_id = %d;", fabricante.nome, fabricante.id);

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

bool delete_fabricante(const Fabricante fabricante) {
    MYSQL mysql;
    char* query = "delete from Fabricantes where fabr_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "delete from Fabricantes where fabr_id = %d;", fabricante.id);

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