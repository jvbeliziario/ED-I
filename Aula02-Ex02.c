/* Aula 2 – ED1
Prof. Marcus Vinicius Maltempi
Faça um programa em C que cria uma lista Dinamica encadeada cujos nós têm dois
campos:
info e
prox (ambos do tipo inteiro). Inicialize propriamente o vetor, criando a
lista de nós livres (apontada por dispo).
a) Faça uma função para inserir nós numa lista ordenada sem repetição, apontada por
L (indica a posição do primeiro nó). Para   inserir nós em L, primeiramente deve-se
obtê-los da lista dispo.
b) Faça uma função que receba como parâmetros Vi e Vf (números inteiros), sendo Vi
< Vf. A função deverá eliminar da lista os nós cujos valores do campo
info estejam
compreendidos entre Vi e Vf (inclusive eles). Assuma que os valores de Vi e Vf estão
contidos em L, e que Vi não é o primeiro nó e Vf não é o último nó da lista. Os nós
eliminados deverão ser inseridos apropriadamente na lista indicada por dispo. */

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{

    int info;
    struct No *prox;

} No;

No *dispo = NULL;

No *obterNo(int valor)
{
    No *novoNo;

    if (dispo != NULL){                      //caso que a lista não está vazia.
        novoNo = dispo;
        dispo = dispo->prox;
        novoNo->info = valor;
        novoNo->prox = NULL;

    } else {                                //caso a lista esteja vazia, alocar memória para o nó.
        novoNo = (No*)malloc(sizeof(No));
        if (novoNo == NULL){
            printf ("Erro de memória");
            exit(1);
        }
        novoNo->info = valor;
        novoNo->prox = NULL;
    }
    return novoNo;
}

void inserirOrdenado(No **L, int valor)
{
    No *novoNo = obterNo(valor);
    No *atual = *L;    
    No *anterior = NULL;

    while (atual != NULL && atual->info < valor)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->info == valor)
    {
        printf("O Valor %d já existe!\n", valor);
        free(novoNo);
        return;
    }

    if (anterior == NULL)
    {
        novoNo->prox = *L;
        *L = novoNo;
    }
    else
    {
        novoNo->prox = atual;
        anterior->prox = novoNo;
    }
}

void imprimirLista(No *L)
{
    printf("Lista: ");

    while (L != NULL)
    {
        printf("%d ", L->info);
        L = L->prox;
    }
    printf("\n");
}

void liberarLista(No **L)
{
    No *atual = *L;

    while (atual != NULL)
    {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    *L = NULL;
}

void removerIntervalo (No **L, int Vi, int Vf){
    No *atual = *L;
    No *anterior = NULL;
    No *dispo = NULL;

    while (atual != NULL && atual->info < Vi){
        anterior = atual;
        atual = atual -> prox;
    }

    while (atual != NULL && atual->info <= Vf){
     No *temp= atual;
     atual = atual->prox;

    if (anterior != NULL){
        anterior->prox = atual;
    }else{
        *L = atual;
    }

    temp->prox = dispo;
    dispo = temp;

    }

}

int main()
{
    No *lista = NULL;

    inserirOrdenado(&lista, 1);
    inserirOrdenado(&lista, 3);
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 5);
    inserirOrdenado(&lista, 6);
    inserirOrdenado(&lista, 8);
    inserirOrdenado(&lista, 8);
    inserirOrdenado(&lista, 10);
    inserirOrdenado(&lista, 7);
    inserirOrdenado(&lista, 2);
    inserirOrdenado(&lista, 12);
    inserirOrdenado(&lista, 4);
    removerIntervalo(&lista, 2, 5);

    imprimirLista(lista);

    liberarLista(&lista);
    return 0;
}
