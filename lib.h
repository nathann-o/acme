#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct funcionario{
    int id;
    char nome;
    char endereco;
    int idade;
    float salario;
    char cargo;
}Funcionario;

typedef struct elemento* Lista;

Lista *criaLista();

int menu();

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int adiciona_funcionario(Lista *li, Funcionario fun);

int remove_funcionario(Lista *li, int id);

int edita_funcionario(Lista *li, int id);



#endif // LIB_H_INCLUDED
