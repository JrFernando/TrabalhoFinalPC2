/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Compras, Reposições, Turnos e Movimentações.
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 01/07/2017
 */

#include <string.h>
#include <stdlib.h>

#include "acoes_funcionario_bd.h"
#include "../UTIL/alocacao_memoria.h"
#include "../UTIL/horario.h"

#define TAM_MAX_ID 4
#define TAM_MAX_QTD 5

Compra* find_compra(const int id) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Compras where comp_id =  ;";
    Compra* compra;
    int tamanho = 0, i;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Compras where comp_id = %d;", id);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    compra = (Compra*) alocar_memoria(1, sizeof (Compra));

    if ((resposta = mysql_store_result(&mysql))) {
        compra->total_produtos = mysql_num_rows(resposta);
        compra->produto = (Produto*) alocar_memoria(compra->total_produtos, sizeof (Produto));
        compra->quantidade = (int*) alocar_memoria(compra->total_produtos, sizeof (int));
        for (i = 0; (linhas = mysql_fetch_row(resposta)) != NULL; i++) {
            compra->id = atoi(linhas[0]);
            compra->caixa = *(find_caixa(atoi(linhas[1])));
            compra->produto[i] = *(find_produto(atoi(linhas[2])));
            compra->quantidade[i] = atoi(linhas[3]);
            compra->horario = string_bd_to_tm(linhas[4]);
            if (atoi(linhas[5]) != 0) compra->vendedor = *(find_funcionario(atoi(linhas[5])));
        }
    } else {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return compra;
}

Compra* find_compra_por_caixa(const int id_caixa) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select comp_id from Compras where comp_caix_id =  group by comp_id;";
    Compra *compras, *temp;
    int tamanho = 0, quantidade;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select comp_id from Compras where comp_caix_id = %d group by comp_id;", id_caixa);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);
        compras = alocar_memoria(quantidade, sizeof (Compra));
        temp = compras;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = find_compra(atoi(linhas[0]));
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return compras;
}

int get_qtd_compra_por_caixa(const int id_caixa) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select comp_id from Compras where comp_caix_id =  group by comp_id;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select comp_id from Compras where comp_caix_id = %d group by comp_id;", id_caixa);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Compra* find_compra_por_produto(const int id_produto) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select comp_id from Compras where comp_prod_id = ;";
    Compra *compras, *temp;
    int tamanho = 0, quantidade;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select comp_id from Compras where comp_prod_id = %d;", id_produto);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);
        compras = alocar_memoria(quantidade, sizeof (Compra));
        temp = compras;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = find_compra(atoi(linhas[0]));
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return compras;
}

int get_qtd_compra_por_produto(const int id_produto) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select comp_id from Compras where comp_prod_id = ;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select comp_id from Compras where comp_prod_id = %d;", id_produto);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Compra* find_compra_por_vendedor(const int id_vendedor) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select comp_id from Compras where comp_func_id =  group by comp_id;";
    Compra *compras, *temp;
    int quantidade, i, tamanho;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select comp_id from Compras where comp_func_id = %d group by comp_id;", id_vendedor);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    quantidade = get_qtd_compra_por_vendedor(id_vendedor);
    compras = alocar_memoria(quantidade, sizeof (Compra));
    if ((resposta = mysql_store_result(&mysql))) {
        for (i = 0; (linhas = mysql_fetch_row(resposta)) != NULL; i++) {
            *(compras + i) = *(find_compra(atoi(linhas[0])));
        }
    } else {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return compras;
}

int get_qtd_compra_por_vendedor(const int id_vendedor) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select comp_id from Compras where comp_func_id =  group by comp_id;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select comp_id from Compras where comp_func_id = %d group by comp_id;", id_vendedor);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Compra* get_all_compras() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select comp_id from Compras group by comp_id;";
    Compra *compras;
    int quantidade, i;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    quantidade = get_qtd_all_compras();
    compras = (Compra*) alocar_memoria(quantidade, sizeof (Compra));
    if ((resposta = mysql_store_result(&mysql))) {
        for (i = 0; (linhas = mysql_fetch_row(resposta)) != NULL; i++) {
            *(compras + i) = *(find_compra(atoi(linhas[0])));
        }
    } else {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return compras;
}

int get_qtd_all_compras() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select comp_id from Compras group by comp_id;";
    int quantidade = -1, tamanho = 0;

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

bool insert_compra(const Compra compra) {
    MYSQL mysql;
    char* query = "insert into Compras (comp_id, comp_caix_id, comp_prod_id, comp_qtd_produto, comp_horario) values (\"\",\"\",\"\",\"\",\"\",\"\");"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0, id, i;
    bool ok = TRUE;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_STRING_DATE + TAM_MAX_QTD + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    id = get_last_id_compra() + 1;

    bd_open(&mysql);
    for (i = 0; i < compra.total_produtos; i++) {
        if (compra.vendedor.id == 0)
            sprintf(query, "insert into Compras (comp_id, comp_caix_id, comp_prod_id, comp_qtd_produto, comp_horario) values (\"%d\",\"%d\",\"%d\",\"%d\",\"%s\");",
                id, compra.caixa.id, compra.produto[i].id, compra.quantidade[i], tm_to_string_bd(compra.horario));
        else
            sprintf(query, "insert into Compras values (\"%d\",\"%d\",\"%d\",\"%d\",\"%s\",\"%d\");",
                id, compra.caixa.id, compra.produto[i].id, compra.quantidade[i], tm_to_string_bd(compra.horario), compra.vendedor.id);

        if (!mysql_query(&mysql, query));
        else {
            //Descomente para debugar
            printf("Erro Compra: %s\n", mysql_error(&mysql));
            bd_close(&mysql);
            ok = FALSE;
        }
    }
    bd_close(&mysql);

    return ok;
}

int get_last_id_compra() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select max(comp_id) from Compras;";
    int id_max;

    if(get_qtd_all_compras() == 0) return 0;


    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        linhas = mysql_fetch_row(resposta);

        id_max = atoi(linhas[0]);

    } else {
        //Descomente para debugar
        printf("Erro Compra: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return id_max;
}

Compra* store_result_to_compra(MYSQL_RES *res) {
    MYSQL_ROW linhas;
    Compra *compra;
    int i;

    compra->total_produtos = mysql_num_rows(res);

    compra->produto = (Produto*) alocar_memoria(compra->total_produtos, sizeof (Produto));
    compra->quantidade = (int*) alocar_memoria(compra->total_produtos, sizeof (int));

    for (i = 0; (linhas = mysql_fetch_row(res)) != NULL; i++) {

        compra->id = atoi(linhas[0]);
        compra->caixa = *(find_caixa(atoi(linhas[1])));
        compra->produto[i] = *(find_produto(atoi(linhas[2])));
        compra->quantidade[i] = atoi(linhas[3]);
        compra->horario = string_bd_to_tm(linhas[4]);
        compra->vendedor = *(find_funcionario(atoi(linhas[5])));
    }

    return compra;
}

/************************************************************************
 *************************************************************************
 ************************** REPOSIÇÃO ************************************
 *************************************************************************
 *************************************************************************/

Reposicao* find_reposicao(const int id_funcionario, const int id_produto, const struct tm horario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes where repo_func_id =  and repo_prod_id =  and repo_horario = ;";
    Reposicao* reposicao;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_STRING_DATE;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Reposicoes where repo_func_id = %d and repo_prod_id = %d and repo_horario = %s;", id_funcionario, id_produto, tm_to_string_bd(horario));

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        linhas = mysql_fetch_row(resposta);

        reposicao = row_to_reposicao(linhas);

    } else {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return reposicao;
}

Reposicao* find_resposicao_por_funcionario(const int id_funcionario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes where repo_func_id = ;";
    Reposicao *reposicoes, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Reposicoes where repo_func_id = %d;", id_funcionario);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        reposicoes = (Reposicao*) alocar_memoria(quantidade, sizeof (Reposicao));

        temp = reposicoes;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = row_to_reposicao(linhas);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return reposicoes;
}

int get_qtd_reposicao_por_funcionario(const int id_funcionario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes where repo_func_id = ;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Reposicoes where repo_func_id = %d;", id_funcionario);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Reposicao* find_reposicao_do_produto(const int id_produto) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes where repo_prod_id = ;";
    Reposicao *reposicoes, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Reposicoes where repo_prod_id = %d;", id_produto);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        reposicoes = (Reposicao*) alocar_memoria(quantidade, sizeof (Reposicao));
        temp = reposicoes;

        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = row_to_reposicao(linhas);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return reposicoes;
}

int get_qtd_reposicao_do_produto(const int id_produto) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes where repo_prod_id = ;";
    Reposicao *reposicoes, *temp;
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Reposicoes where repo_prod_id = %d;", id_produto);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Reposicao* find_reposicao_por_data(const struct tm data) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes where cast(repo_horario as date) = ;";
    Reposicao *reposicoes, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Reposicoes where cast(repo_horario as date) = %s;", tm_to_string_date_bd(data));

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        reposicoes = (Reposicao*) alocar_memoria(quantidade, sizeof (Reposicao));
        temp = reposicoes;

        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = row_to_reposicao(linhas);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return reposicoes;
}

int get_qtd_reposicao_por_data(const struct tm data) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes where cast(repo_horario as date) = ;";
    Reposicao *reposicoes, *temp;
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Reposicoes where cast(repo_horario as date) = %s;", tm_to_string_date_bd(data));

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Reposicao* get_all_reposicoes() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes;";
    Reposicao *reposicoes, *temp;
    int quantidade;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        reposicoes = (Reposicao*) alocar_memoria(quantidade, sizeof (Reposicao));
        temp = reposicoes;

        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = row_to_reposicao(linhas);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return reposicoes;
}

int get_qtd_all_reposicoes() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Reposicoes;";
    Reposicao *reposicoes, *temp;
    int quantidade = -1;

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

bool insert_reposicao(Reposicao reposicao) {
    MYSQL mysql;
    char* query = "insert into Reposicoes values ( , ,\"\", );"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    //Clásula de guarda
    if (!set_novo_estoque_produto(reposicao.produto, reposicao.quantidade)) return FALSE;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_STRING_DATE + TAM_MAX_QTD;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "insert into Reposicoes values (%d,%d,\"%s\",%d);",
            reposicao.funcionario.id, reposicao.produto.id, tm_to_string_bd(reposicao.horario), reposicao.quantidade);

    bd_open(&mysql);

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        //printf("Erro Reposição: %s\n", mysql_error(&mysql));
        bd_close(&mysql);

        return FALSE;
    }
}

Reposicao* row_to_reposicao(MYSQL_ROW row) {
    Reposicao *reposicao;

    reposicao = alocar_memoria(1, sizeof (Reposicao));
    reposicao->funcionario = *(find_funcionario(atoi(row[0])));
    reposicao->produto = *(find_produto(atoi(row[1])));
    reposicao->horario = string_bd_to_tm(row[2]);
    reposicao->quantidade = atoi(row[3]);

    return reposicao;
}

/************************************************************************
 *************************************************************************
 ****************************** TURNO ************************************
 *************************************************************************
 *************************************************************************/

Turno* find_turno(const int id_funcionario, const int id_caixa, const struct tm horario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos where turn_func_id =  and turn_caix_id =  and turn_horario_inicio = \"\" ;";
    Turno* turno;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_STRING_DATE;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Turnos where turn_func_id = %d and turn_caix_id = %d and turn_horario_inicio = \"%s\";", id_funcionario, id_caixa, tm_to_string_bd(horario));

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql)))
        turno = row_to_turno(mysql_fetch_row(resposta));
    else {
        //Descomente para debugar
        printf("Erro Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return turno;
}

Turno* find_turnos_do_funcionario(const int id_funcionario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos where turn_func_id = ;";
    Turno *turnos, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Turnos where turn_func_id = %d;", id_funcionario);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);
        printf("%d\n", quantidade);
        turnos = (Turno*) alocar_memoria(quantidade, sizeof (Turno));

        temp = turnos;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {

            temp->funcionario = *(find_funcionario(atoi(linhas[0])));
            temp->caixa = *(find_caixa(atoi(linhas[1])));
            temp->horario_inicio = string_bd_to_tm(linhas[2]);
            if (linhas[3] != NULL) temp->horario_final = string_bd_to_tm(linhas[3]);

            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return turnos;
}

int get_qtd_turnos_do_funcionario(const int id_funcionario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos where turn_func_id = ;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Turnos where turn_func_id = %d;", id_funcionario);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Turno* find_turnos_do_caixa(const int id_caixa) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos where turn_caix_id = ;";
    Turno *turnos, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Turnos where turn_caix_id = %d;", id_caixa);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        turnos = (Turno*) alocar_memoria(quantidade, sizeof (Turno));

        temp = turnos;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->funcionario = *(find_funcionario(atoi(linhas[0])));
            temp->caixa = *(find_caixa(atoi(linhas[1])));
            temp->horario_inicio = string_bd_to_tm(linhas[2]);
            if (linhas[3] != NULL) temp->horario_final = string_bd_to_tm(linhas[3]);

            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return turnos;
}

int get_qtd_turnos_do_caixa(const int id_caixa) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos where turn_caix_id = ;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Turnos where turn_caix_id = %d;", id_caixa);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Turno* find_turno_por_data(const struct tm data) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos where cast(turn_horario_inicio as date) = \"\";";
    Turno *turnos, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Turnos where cast(turn_horario_inicio as date) = \"%s\";", tm_to_string_date_bd(data));
    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        turnos = (Turno*) alocar_memoria(quantidade, sizeof (Turno));
        temp = turnos;

        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->funcionario = *(find_funcionario(atoi(linhas[0])));
            temp->caixa = *(find_caixa(atoi(linhas[1])));
            temp->horario_inicio = string_bd_to_tm(linhas[2]);
            if (linhas[3] != NULL) temp->horario_final = string_bd_to_tm(linhas[3]);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return turnos;
}

int get_qtd_turno_por_data(const struct tm data) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos where cast(turn_horario_inicio as date) = \"\";";
    Turno *reposicoes, *temp;
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Turnos where cast(turn_horario_inicio as date) = \"%s\";", tm_to_string_date_bd(data));

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Turno* get_all_turnos() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos;";
    Turno *turnos, *temp;
    int quantidade;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        turnos = (Turno*) alocar_memoria(quantidade, sizeof (Turno));
        temp = turnos;

        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->funcionario = *(find_funcionario(atoi(linhas[0])));
            temp->caixa = *(find_caixa(atoi(linhas[1])));
            temp->horario_inicio = string_bd_to_tm(linhas[2]);
            if (linhas[3] != NULL) temp->horario_final = string_bd_to_tm(linhas[3]);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro Movimentação Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return turnos;
}

int get_qtd_all_turnos() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Turnos;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Turnos;");

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

bool insert_turno(const Turno turno) {
    MYSQL mysql;
    char* query = "insert into Turnos (turn_func_id, turn_caix_id, turn_horario_inicio) values (\"\",\"\",\"\");"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_STRING_DATE;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "insert into Turnos (turn_func_id, turn_caix_id, turn_horario_inicio) values (\"%d\",\"%d\",\"%s\");",
            turno.funcionario.id, turno.caixa.id, tm_to_string_bd(turno.horario_inicio));

    if (!bd_open(&mysql)) return FALSE;

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        printf("Erro Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);

        return FALSE;
    }
}

bool fecha_turno(const Turno turno) {
    MYSQL mysql;
    char* query = "update Turnos set turn_horario_fim = \"\" where turn_func_id =  and turn_caix_id =  and turn_horario_inicio = \"\";"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_STRING_DATE + TAM_MAX_STRING_DATE;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "update Turnos set turn_horario_fim = \"%s\" where turn_func_id = %d and turn_caix_id = %d and turn_horario_inicio = \"%s\";",
            tm_to_string_bd(turno.horario_final), turno.funcionario.id, turno.caixa.id, tm_to_string_bd(turno.horario_inicio));

    if (!bd_open(&mysql)) return FALSE;

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        printf("Erro Turno: %s\n", mysql_error(&mysql));
        bd_close(&mysql);

        return FALSE;
    }
}

Turno* row_to_turno(MYSQL_ROW row) {
    Turno *turno;

    turno = alocar_memoria(1, sizeof (Turno));
    turno->funcionario = *(find_funcionario(atoi(row[0])));
    turno->caixa = *(find_caixa(atoi(row[1])));
    turno->horario_inicio = string_bd_to_tm(row[2]);
    if (row[3] != NULL) turno->horario_final = string_bd_to_tm(row[3]);

    return turno;
}

/************************************************************************
 *************************************************************************
 ************************* MOVIMENTAÇÃO **********************************
 *************************************************************************
 *************************************************************************/

Movimentacao* find_movimentacao(const int id_funcionario, const int id_caixa, const struct tm horario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacoes where movi_func_id =  and movi_caix_id =  and movi_horario = \"\";";
    Movimentacao* movimentacao;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_STRING_DATE;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Movimentacoes where movi_func_id = %d and movi_caix_id = %d and movi_horario = \"%s\";", id_funcionario, id_caixa, tm_to_string_bd(horario));

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        linhas = mysql_fetch_row(resposta);

        movimentacao = row_to_movimentacao(linhas);

    } else {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return movimentacao;
}

Movimentacao* find_movimentacoes_do_funcionario(const int id_funcionario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacoes where movi_func_id = ;";
    Movimentacao *movimentacoes, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Movimentacoes where movi_func_id = %d;", id_funcionario);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        movimentacoes = (Movimentacao*) alocar_memoria(quantidade, sizeof (Movimentacao));

        temp = movimentacoes;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = row_to_movimentacao(linhas);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return movimentacoes;
}

int get_qtd_movimentacoes_do_funcionario(const int id_funcionario) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacaos where movi_func_id = ;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Movimentacaos where movi_func_id = %d;", id_funcionario);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Movimentacao* find_movimentacoes_do_caixa(const int id_caixa) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacoes where movi_caix_id = ;";
    Movimentacao *movimentacoes, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Movimentacoes where movi_caix_id = %d;", id_caixa);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        movimentacoes = (Movimentacao*) alocar_memoria(quantidade, sizeof (Movimentacao));

        temp = movimentacoes;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = row_to_movimentacao(linhas);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return movimentacoes;
}

int get_qtd_movimentacoes_do_caixa(const int id_caixa) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacoes where movi_caix_id = ;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Movimentacoes where movi_caix_id = %d;", id_caixa);

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Movimentacao* find_movimentacoes_por_data(const struct tm data) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacoes where cast(movi_horario as date) = ;";
    Movimentacao *movimentacoes, *temp;
    int quantidade, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Movimentacoes where cast(movi_horario as date) = %s;", tm_to_string_date_bd(data));

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        movimentacoes = (Movimentacao*) alocar_memoria(quantidade, sizeof (Movimentacao));
        temp = movimentacoes;

        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = row_to_movimentacao(linhas);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return movimentacoes;
}

int get_qtd_movimentacoes_por_data(const struct tm data) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacoes where cast(movi_horario as date) = ;";
    Movimentacao *reposicoes, *temp;
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Movimentacoes where cast(movi_horario as date) = %s;", tm_to_string_date_bd(data));

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

Movimentacao* get_all_movimentacoes() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacoes;";
    Movimentacao *movimentacoes, *temp;
    int quantidade;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);

        movimentacoes = (Movimentacao*) alocar_memoria(quantidade, sizeof (Movimentacao));
        temp = movimentacoes;

        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp = row_to_movimentacao(linhas);
            temp++;
        }

    } else {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return movimentacoes;
}

int get_qtd_all_movimentaoes() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Movimentacoes;";
    int quantidade = -1, tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Movimentacoes;");

    if (!bd_open(&mysql)) return -1;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return -1;
    }

    if ((resposta = mysql_store_result(&mysql))) quantidade = mysql_num_rows(resposta);

    mysql_free_result(resposta);
    bd_close(&mysql);

    return quantidade;
}

bool insert_movimentacao(Movimentacao movimentacao) {
    MYSQL mysql;
    char* query = "insert into Movimentacoes values (\"\",\"\",\"\",\"\");"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID + TAM_MAX_STRING_DATE + TAM_MAX_QTD;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    movimentacao.caixa.saldo -= movimentacao.valor;

    //Cláusula de guarda
    if (!atualiza_saldo_caixa(movimentacao.caixa)) return FALSE;

    sprintf(query, "insert into Movimentacoes values (\"%d\",\"%d\",\"%s\",\"%.2f\");",
            movimentacao.funcionario.id, movimentacao.caixa.id, tm_to_string_bd(movimentacao.horario), movimentacao.valor);

    if (!bd_open(&mysql)) return FALSE;

    if (!mysql_query(&mysql, query)) {
        bd_close(&mysql);
        return TRUE;
    } else {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);

        return FALSE;
    }
}

Movimentacao* row_to_movimentacao(MYSQL_ROW row) {
    Movimentacao *movimentacao;

    movimentacao = alocar_memoria(1, sizeof (Movimentacao));
    movimentacao->funcionario = *(find_funcionario(atoi(row[0])));
    movimentacao->caixa = *(find_caixa(atoi(row[1])));
    movimentacao->horario = string_bd_to_tm(row[2]);
    movimentacao->valor = atof(row[3]);

    return movimentacao;
}