#include<stdio.h>
#include<stdlib.h>
#include "lib.h"

int main()
{
    int opc, x;

    Lista *li;
    li = criaLista();
    struct funcionario f1;

    do{
        opc = menu();
        printf("%d", opc);
        if(opc == 1){
            system("cls");
            printf("id: ");
            scanf("%d", &f1.id);
            printf("\nNome: ");
            getchar();
            gets(&f1.nome);
            printf("\nEndereco: ");
            getchar();
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
        if(opc == 2){
            system("cls");
            printf("\nDigite o id do funcionario que deseja remover: ");
            int id_remove;
            scanf("%d", &id_remove);
            x = remove_funcionario(li, id_remove);
        }
        if(opc == 3){
            system("cls");
            printf("\nDigite o id do funcionario que deseja editar: ");
            int id_edita;
            scanf("%d", &id_edita);
            x = edita_funcionario(li, id_edita);
        }
    }while(opc != 8);







}
