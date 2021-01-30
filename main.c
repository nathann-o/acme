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
        if(x){
            printf("\nInserido ordenadamente com sucesso!");
        }else{
            printf("\nNao foi possivel inserir ordenadamente.");
        }
    }







}
