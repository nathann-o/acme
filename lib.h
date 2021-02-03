#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct funcionario{
    int id;
    char nome[100];
    char endereco[100];
    int idade;
    float salario;
    char cargo[100];
}Funcionario;

typedef struct elemento* Lista;

Lista *criaLista();

int menu();

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int adiciona_funcionario(Lista *li, Funcionario fun);

int remove_funcionario(Lista *li, int id);

int edita_funcionario(Lista *li, int id);

int busca_funcionario(Lista *li, int id);

int lista_funcionario(Lista *li);

void lista_funcionario_salario(Lista *li, float salario);

void apagaLista(Lista *li);

#endif // LIB_H_INCLUDED
