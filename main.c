#include<stdio.h>
#include<stdlib.h>
#include "lib.h"

int main()
{
    int opc, x, posicao=1;

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
        else if(opc == 2){
            system("cls");
            printf("\nDigite o id do funcionario que deseja remover: ");
            int id_remove;
            scanf("%d", &id_remove);
            x = remove_funcionario(li, id_remove);
        }
        else if(opc == 3){
            system("cls");
            printf("\nDigite o id do funcionario que deseja editar: ");
            int id_edita;
            scanf("%d", &id_edita);
            x = edita_funcionario(li, id_edita);
        }
        else if(opc == 4){
            system("cls");
            printf("\nDigite o id do funcionario que deseja buscar: ");
            int id_busca;
            scanf("%d", &id_busca);
            x = busca_funcionario(li, id_busca);
        }
        else if(opc == 5){
            system("cls");
            x = lista_funcionario(li);
        }

        else if(opc == 6){
            system("cls");
            float salario;
            lista_funcionario_salario(li, salario);
        }

        else if(opc == 7){
            system("cls");
            apagaLista(li);
        }

    }while(opc < 8);

}
