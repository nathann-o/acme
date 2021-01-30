#include<stdio.h>
#include<stdlib.h>
#include "lib.h"

int main()
{
    int opc, x;

    Lista *li;
    li = criaLista();



    //se tornarão uma função
    struct funcionario f1;

    f1.id = 1;
    f1.nome = "nathann";
    f1.endereco = "luiz gonzaga";
    f1.idade = 20;
    f1.salario = 2000;
    f1.cargo = "desenvolvedor";

    opc = menu();
    printf("%d", opc);
    if(opc == 1){
        x = adiciona_funcionario(li, f1);
        opc = menu();
    }
    if(opc == 2){
        system("cls");
        printf("\nDigite o id do funcionario que deseja remover: ");
        int id_remove;
        scanf("%d", &id_remove);
        x = remove_funcionario(li, id_remove);
        opc = menu();
    }







}
