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

void coleta_dados(Funcionario f1, Lista *li){
    int x = 0;
    printf("id: ");
    scanf("%d", &f1.id);
    fflush(stdin);

    printf("\nNome: ");
    gets(&f1.nome);


    printf("\nEndereco: ");
    gets(&f1.endereco);

    printf("\nIdade: ");
    scanf("%d", &f1.idade);
    printf("\nSalario: ");
    scanf("%f", &f1.salario);

    printf("\nCargo: ");
    getchar();
    gets(&f1.cargo);


    x = adiciona_funcionario(li, f1);
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
        printf("\nFuncionario adicionado!\n");
        system("pause");

        return 1;
    }
}

int remove_funcionario(Lista *li, int id){
    if(li == NULL){
        return 0;
    }
    ELEM *ant, *no = *li;
    if(no == NULL){
        printf("\nNao ha funcionarios cadastrados, por favor, adicione um funcionario antes de tentar remover\n");
        system("pause");
        return 1;
    }
    while(no != NULL && no->dados.id != id){
        ant = no;
        if(no->prox == NULL){
            printf("Funcionario nao encontrado!\n");
            system("pause");
            return 1;
        }
        no = no->prox;
    }
    printf("\nDeseja remover o seguinte funcionario?\n");
    printf("\nId: %d", no->dados.id);
    printf("\nNome: %s", &no->dados.nome);
    printf("\nEndereco: %s", &no->dados.endereco);
    printf("\nIdade: %d", no->dados.idade);
    printf("\nSalario: %.2f", no->dados.salario);
    printf("\nCargo: %s\n", &no->dados.cargo);
    printf("\n(1 - Sim/ 2 - Nao) :");
    int opc2;
    scanf("%d", &opc2);

    if(opc2 == 1){
        if(no == *li){
            *li = no->prox;
        }else{
            ant->prox = no->prox;
        }
        free(no);
        printf("\nFuncionario removido!\n");
        system("pause");
        return 1;
    }else{
        printf("\nOperacao interrompida! Funcionario nao removido\n");
        system("pause");
        return 1;
    }
}

int edita_funcionario(Lista *li, int id){
    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    if(no == NULL){
        printf("\nNao ha funcionarios cadastrados, por favor, adicione um funcionario antes de tentar remover\n");
        system("pause");
        return 1;
    }
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL){
        printf("\nID nao encontrado!\n");
        system("pause");
        return 0;
    }else{
        printf("Deseja reajustar o salario? (1 - Sim/ 2 - Nao) :");
        int opc2;
        scanf("%d", &opc2);
        if(opc2 == 1){
            printf("Digite a porcentagem do reajuste: ");
            float reaj;
            scanf("%f", &reaj);
            no->dados.salario += no->dados.salario * (reaj/100);
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
        printf("\nAlteracoes realizadas com sucesso!\n");
        system("pause");
        return 1;
    }
}

int busca_funcionario(Lista *li, int id){
    ELEM *no = *li;
    if(no == NULL){
        printf("\nNao ha funcionarios cadastrados, por favor, adicione um funcionario antes de tentar buscar\n");
        system("pause");
        return 1;
    }
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL){
        printf("\nID nao encontrado!\n");
        system("pause");
        return 1;
    }
    else{

        printf("\nId: %d", no->dados.id);
        printf("\nNome: %s", &no->dados.nome);
        printf("\nEndereco: %s", &no->dados.endereco);
        printf("\nIdade: %d", no->dados.idade);
        printf("\nSalario: %.2f", no->dados.salario);
        printf("\nCargo: %s\n", &no->dados.cargo);
        system("pause");
        return 1;

    }
}

int lista_funcionario(Lista *li){
    ELEM *no = *li;
    if(no == NULL){
        printf("\nNao ha funcionarios cadastrados, por favor, adicione um funcionario antes de tentar listar\n");
        system("pause");
        return 1;
    }
    while(no != NULL){

        printf("\nId: %d", no->dados.id);
        printf("\nNome: %s", &no->dados.nome);
        printf("\nEndereco: %s", &no->dados.endereco);
        printf("\nIdade: %d", no->dados.idade);
        printf("\nSalario: %.2f", no->dados.salario);
        printf("\nCargo: %s\n", &no->dados.cargo);
        printf("\n==================================\n");
        no = no->prox;
    }
    system("pause");
}

void lista_funcionario_salario(Lista *li, float salario){
    float min, max;

    printf("\n Por favor inserir um valor minimo de Salario: R$");
    scanf("%f", &min);
    printf("\n Por favor inserir um valor maximo de Salario: R$");
    scanf("%f", &max);

    if(li == NULL){
        return 0;
    }
    ELEM *no = *li;
    if(no == NULL){
        printf("\nNao ha funcionarios cadastrados, por favor, adicione um funcionario antes de tentar listar\n");
        system("pause");
        return 1;
    }
    while(no != NULL){

    if(no->dados.salario >= min && no->dados.salario <= max){
        printf("Funcionarios com salario entre R$%.2f e R$%.2f", min, max);
        printf("\nId: %d", no->dados.id);
        printf("\nNome: %s", &no->dados.nome);
        printf("\nIdade: %d", no->dados.idade);
        printf("\nCargo: %s\n", &no->dados.cargo);
        printf("\nSalario: %.2f", no->dados.salario);
        printf("\n==================================\n");
    }
        no = no->prox;
    }
    system("pause");
}

void apagaLista(Lista *li){
    ELEM *no;
    while((*li) != NULL){
        no = *li;
        *li = (*li)->prox;
        free(no);
    }
    free(li);
    exit(1);
}

