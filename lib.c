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

int edita_funcionario(Lista *li, int id){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL){
        printf("\nID nao encontrado!");
        return 0;
    }else{
        printf("Deseja reajustar o salario? (1 - Sim/ 2 - Nao) :");
        int opc2;
        scanf("%d", &opc2);
        if(opc2 == 1){
            printf("Digite a porcentagem do reajuste: ");
            int reaj;
            scanf("%d", &reaj);
            no->dados.salario +=  no->dados.salario * (reaj/100);
        }else{
            printf("\nNovo Id: ");
            scanf("%d", &no->dados.id);
            printf("\nNovo nome: ");
            getchar();
            gets(&no->dados.nome);
            printf("\nNovo endereco: ");
            getchar();
            gets(&no->dados.endereco);
            printf("\nNova idade: ");
            scanf("%d", &no->dados.idade);
            printf("\nNovo salario: ");
            scanf("%f", &no->dados.salario);
            printf("\nNovo cargo: ");
            getchar();
            gets(&no->dados.cargo);
            int t = 5;
        }

        return 1;
    }
}

