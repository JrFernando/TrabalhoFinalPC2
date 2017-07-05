/**
 * Este módulo é responsável pelas funções de manipulações dos dados
 * da tabela Produtos
 *
 * @author Fernando Júnior Gomes da Silva <fernandojunior20110@gmail.com>
 * @date 01/07/2017
 */
#include <string.h>
#include <stdlib.h>

#include "produto_bd.h"
#include "../UTIL/alocacao_memoria.h"

#define TAM_MAX_ID 4
#define TAM_MAX_QTD 5
#define TAM_MAX_PRECO 6
#define TAM_MAX_NOME 61

Produto* find_produto(const int id) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Produtos where prod_id =  ;";
    Produto* produto;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Produtos where prod_id = %d;", id);

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

        produto = (Produto*) alocar_memoria(1, sizeof (Produto));
        produto->id = atoi(linhas[0]);

        produto->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
        strcpy(produto->nome, linhas[1]);

        produto->quantidade = atoi(linhas[2]);
        produto->preco_compra = atof(linhas[3]);
        produto->preco_venda = atof(linhas[4]);

        produto->fabricante = *(find_fabricante(atoi(linhas[5])));

    } else {
        //Descomente para debugar
        //printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }

    mysql_free_result(resposta);
    bd_close(&mysql);

    return produto;
}

/*Produto* find_produto_nome(const char* nome) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Produtos where prod_nome like  %;";
    Produto *produtos, *temp;
    int tamanho = 0, quantidade;

    tamanho = strlen(query) + TAM_MAX_NOME;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Produtos where prod_nome like \"%s%\";", nome);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);
        produtos = (Produto*) alocar_memoria(quantidade, sizeof (Produto));
        temp = produtos;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->id = atoi(linhas[0]);

            temp->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
            strcpy(temp->nome, linhas[1]);

            temp->quantidade = atoi(linhas[2]);
            temp->preco_compra = atof(linhas[3]);
            temp->preco_venda = atof(linhas[4]);

            temp->fabricante = *(find_fabricante(atoi(linhas[5])));

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

    return produtos;
}


int get_qtd_find_produto_nome(const char* nome) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    char *query = "select * from Produtos where prod_nome like  %;";
    int quantidade = -1, tamanho;

    if (!bd_open(&mysql)) return -1;

    tamanho = strlen(query) + TAM_MAX_NOME;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Produtos where prod_nome like \"%s%\";", nome);

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
}*/


Produto* find_produtos_estoque_baixo(int n) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Produtos where prod_quantidade <= ;";
    Produto *produtos, *temp;
    int tamanho = 0, quantidade;

    tamanho = strlen(query) + TAM_MAX_QTD;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Produtos where prod_quantidade <= %d;", n);

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);
        produtos = (Produto*) alocar_memoria(quantidade, sizeof (Produto));
        temp = produtos;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->id = atoi(linhas[0]);

            temp->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
            strcpy(temp->nome, linhas[1]);

            temp->quantidade = atoi(linhas[2]);
            temp->preco_compra = atof(linhas[3]);
            temp->preco_venda = atof(linhas[4]);

            temp->fabricante = *(find_fabricante(atoi(linhas[5])));

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

    return produtos;
}

int get_qtd_find_produtos_estoque_baixo(int n) {
    MYSQL mysql;
    MYSQL_RES *resposta;
    char *query = "select * from Produtos where prod_quantidade <= ;";
    int quantidade = -1, tamanho;

    if (!bd_open(&mysql)) return -1;

    tamanho = strlen(query) + TAM_MAX_QTD;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "select * from Produtos where prod_quantidade <= %d", n);

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

Produto* find_produtos_mais_vendidos() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select prod_id from Produtos inner join Compras on comp_prod_id = prod_id group by prod_id order by sum(comp_qtd_produto) desc;";
    Produto *produtos, *temp;
    int tamanho = 0, quantidade;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);
        produtos = (Produto*) alocar_memoria(quantidade, sizeof (Produto));
        temp = produtos;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            *temp = *(find_produto(atoi(linhas[0])));
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

    return produtos;
}

int* find_qtd_produtos_mais_vendidos() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select sum(comp_qtd_produto) from Produtos inner join Compras on comp_prod_id = prod_id group by prod_id order by sum(comp_qtd_produto) desc;";
    int *totais_vendidos, *temp;
    int tamanho = 0, quantidade;

    if (!bd_open(&mysql)) return NULL;

    if (mysql_query(&mysql, query)) {
        //Descomente para debugar
        printf("Erro: %s\n", mysql_error(&mysql));
        bd_close(&mysql);
        return NULL;
    }


    if ((resposta = mysql_store_result(&mysql))) {
        quantidade = mysql_num_rows(resposta);
        totais_vendidos = (int*) alocar_memoria(quantidade, sizeof (int));
        temp = totais_vendidos;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            *temp = atoi(linhas[0]);
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

    return totais_vendidos;
}

int get_qtd_find_produtos_mais_vendidos() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    char *query = "select prod_id from Produtos inner join Compras on comp_prod_id = prod_id group by prod_id order by sum(comp_qtd_produto) desc;";
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

Produto* get_all_produtos() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    MYSQL_ROW linhas;
    char *query = "select * from Produtos;";
    Produto *produtos, *temp;
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

        produtos = (Produto*) alocar_memoria(quantidade, sizeof (Produto));

        temp = produtos;
        while ((linhas = mysql_fetch_row(resposta)) != NULL) {
            temp->id = atoi(linhas[0]);

            temp->nome = (char*) alocar_memoria(strlen(linhas[1]), sizeof (char));
            strcpy(temp->nome, linhas[1]);

            temp->quantidade = atoi(linhas[2]);
            temp->preco_compra = atof(linhas[3]);
            temp->preco_venda = atof(linhas[4]);

            temp->fabricante = *(find_fabricante(atoi(linhas[5])));

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

    return produtos;
}

int get_qtd_all_produtos() {
    MYSQL mysql;
    MYSQL_RES *resposta;
    char *query = "select * from Produtos;";
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

bool insert_produto(const Produto produto) {
    MYSQL mysql;
    char* query = "insert into Produtos (prod_nome, prod_quantidade, prod_preco_compra, prod_preco_venda, prod_fabr_id) values (\"\",\"\",\"\",\"\",\"\");"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(produto.nome) + TAM_MAX_QTD + TAM_MAX_PRECO + TAM_MAX_PRECO + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "insert into Produtos (prod_nome, prod_quantidade, prod_preco_compra, prod_preco_venda, prod_fabr_id) values (\"%s\",\"%d\",\"%.2f\",\"%.2f\",\"%d\");",
            produto.nome, produto.quantidade, produto.preco_compra, produto.preco_venda, produto.fabricante.id);

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

bool atualiza_estoque_produto(Produto produto, int quantidade) {
    MYSQL mysql;
    char* query = "update Produtos set prod_quantidade =  where prod_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + TAM_MAX_ID + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "update Produtos set prod_quantidade = %d where prod_id = %d;", produto.quantidade - quantidade, produto.id);

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

bool set_novo_estoque_produto(Produto produto, int quantidade) {
    MYSQL mysql;
    char* query = "update Produtos set prod_quantidade =  where prod_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(produto.nome) + TAM_MAX_QTD + TAM_MAX_PRECO + TAM_MAX_PRECO + TAM_MAX_ID + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "update Produtos set prod_quantidade = %d where prod_id = %d;", quantidade, produto.id);

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

bool update_produto(const Produto produto) {
    MYSQL mysql;
    char* query = "update Produtos set prod_nome = \"\", prod_quantidade = , prod_preco_compra = , prod_preco_venda = , prod_fabr_id =  where prod_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(produto.nome) + TAM_MAX_QTD + TAM_MAX_PRECO + TAM_MAX_PRECO + TAM_MAX_ID + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "update Produtos set prod_nome = \"%s\", prod_quantidade = %d, prod_preco_compra = %.2f, prod_preco_venda = %.2f, prod_fabr_id = %d where prod_id = %d;",
            produto.nome, produto.quantidade, produto.preco_compra, produto.preco_venda, produto.fabricante.id, produto.id);

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

bool delete_produto(const Produto produto) {
    MYSQL mysql;
    char* query = "delete from Produtos where prod_id = ;"; //Para que eu possa calcular o tamanho da string final e alocar memória suficiente;
    int tamanho = 0;

    tamanho = strlen(query) + strlen(produto.nome) + TAM_MAX_QTD + TAM_MAX_PRECO + TAM_MAX_PRECO + TAM_MAX_ID + TAM_MAX_ID;
    query = (char*) alocar_memoria(tamanho, sizeof (char));

    sprintf(query, "delete from Produtos where prod_id = %d;", produto.id);

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