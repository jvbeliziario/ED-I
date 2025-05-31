/*Aula 1 – ED1
Prof. Marcus Vinicius Maltempi
Faça um programa em C que cria uma lista Estatica encadeada cujos nós têm dois
campos:
info e
prox (ambos do tipo inteiro). Inicialize propriamente o vetor, criando a
lista de nós livres (apontada por dispo).
a) Faça uma função para inserir nós numa lista ordenada sem repetição, apontada por
L (indica a posição do primeiro nó). Para inserir nós em L, primeiramente deve-se
obtê-los da lista dispo.
b) Faça uma função que receba como parâmetros Vi e Vf (números inteiros), sendo Vi
< Vf. A função deverá eliminar da lista os nós cujos valores do campo
info estejam
compreendidos entre Vi e Vf (inclusive eles). Assuma que os valores de Vi e Vf estão
contidos em L, e que Vi não é o primeiro nó e Vf não é o último nó da lista. Os nós
eliminados deverão ser inseridos apropriadamente na lista indicada por dispo.*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct
{
    int info;
    int prox;
} No;

typedef struct
{
    No lista[MAX];
    int inicio;
    int dispo;
} ListaEstatica;

void InicializarLista(ListaEstatica *L)
{
    ListaEstatica lista;
    L->inicio = -1;
    L->dispo = 0;

    for (int i = 0; i < MAX - 1; i++)
    {
        L->lista[i].prox = i + 1;
    }
    L->lista[MAX - 1].prox = -1;
}

int ObterNo(ListaEstatica *L)
{
    if (L->dispo == -1)
    {
        printf("Erro: Lista Vazia!\n");
        return -1;
    }
    int no = L->dispo;
    L->dispo = L->lista[no].prox;
    return no;
}

ListaEstatica InserirOrdenado(ListaEstatica L, int valor)
{
    int novoNo = ObterNo(&L);
    if (novoNo == -1)
        return L;

    int atual = L.inicio;
    while (atual != -1)
    {
        if (L.lista[atual].info == valor)
        {
            printf("Valor %d já existe!\n", valor);
            L.lista[novoNo].prox = L.dispo;
            L.dispo = novoNo;
            return L;
        }
        atual = L.lista[atual].prox;
    }

    L.lista[novoNo].info = valor;
    L.lista[novoNo].prox = -1;

    if (L.inicio == -1 || valor < L.lista[L.inicio].info)
    {
        L.lista[novoNo].prox = L.inicio;
        L.inicio = novoNo;
    }
    else
    {
        int anterior = L.inicio;
        while (L.lista[anterior].prox != -1 && L.lista[L.lista[anterior].prox].info < valor)
        {
            anterior = L.lista[anterior].prox;
        }

        L.lista[novoNo].prox = L.lista[anterior].prox;
        L.lista[anterior].prox = novoNo;
    }

    return L;
}

void ImprimirLista(ListaEstatica L)
{
    int atual = L.inicio;
    printf("Lista: ");
    while (atual != -1)
    {
        printf("%d ", L.lista[atual].info);
        atual = L.lista[atual].prox;
    }

    printf("\n");
}

ListaEstatica RemoverIntervalo(ListaEstatica L, int Vi, int Vf)
{

    int atual = L.inicio;
    int anterior = -1;

    while (atual != -1 && L.lista[atual].info < Vi)
    {
        anterior = atual;
        atual = L.lista[atual].prox;
    }

    while (atual != -1 && L.lista[atual].info <= Vf)
    {
        int removido = atual;
        atual = L.lista[atual].prox;

        if (anterior != -1)
        {
            L.lista[anterior].prox = atual;
        }
        else
        {
            L.inicio = atual;
        }

        L.lista[removido].prox = L.dispo;
        L.dispo = removido;
    }
    return L;
}

int main()
{

    ListaEstatica lista;

    InicializarLista(&lista);
    lista = InserirOrdenado(lista, 1);
    lista = InserirOrdenado(lista, 2);
    lista = InserirOrdenado(lista, 3);
    lista = InserirOrdenado(lista, 3);
    lista = InserirOrdenado(lista, 5);
    lista = InserirOrdenado(lista, 6);
    lista = InserirOrdenado(lista, 7);
    lista = InserirOrdenado(lista, 8);
    lista = InserirOrdenado(lista, 10);
    lista = RemoverIntervalo(lista, 5, 8);

    ImprimirLista(lista);
    return 0;
}