#include<stdio.h>
#include<stdlib.h>
#include "lib.h"

struct elemento{
    Funcionario dados;
    struct elemento *prox;
};
typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int menu(){
    system("cls");
    int opc;
    printf("--------------------------------------\n");
    printf("|          FABRICA ACME              |\n");
    printf("--------------------------------------\n");
    printf("\n1 - Adicionar funcionario");
    printf("\n2 - Excluir  funcionario");
    printf("\n3 - Editar  funcionario");
    printf("\n4 - Buscar  funcionario");
    printf("\n5 - Exibir lista de funcionarios por id");
    printf("\n6 - Exibir lista de funcionarios por faixa salarial");
    printf("\n7 - Sair do programa");
    printf("\nDigite a opcao desejada:");
    scanf("%d", &opc);

    return opc;
}

int listaCheia(Lista *li){
    return 0;
}

int listaVazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int adiciona_funcionario(Lista *li, Funcionario fun){
    if(li == NULL){
        return 0;
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = fun;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.id < fun.id){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
        no->prox = (*li);
        *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }

        return 1;
    }
}

int remove_funcionario(Lista *li, int id){
    if(li == NULL){
        return 0;
    }
    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.id != id){
        ant = no;
        no = no->prox;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

