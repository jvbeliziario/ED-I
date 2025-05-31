/*
Implementar um programa em C para gerenciar uma lista ordenada de números inteiros. Seu programa deverá suportar as seguintes operações:

    Inserção Ordenada: Inserir um número na lista, garantindo que ela permaneça ordenada.
    Busca Binária: Retornar a posição de um número na lista (ou -1 se não for encontrado).
    Exclusão de um Elemento: Remover um número da lista, mantendo-a ordenada.
    Busca com Sentinela: Verificar se um número está na lista usando o método de sentinela.

A lista tem capacidade máxima de 50 elementos. Você deve implementar uma estrutura LISTA que armazena os elementos e seu tamanho atual.
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->nroElem = 0;
}

bool inserirElemListaOrd(LISTA *l, REGISTRO reg)
{
    if (l->nroElem >= MAX)
    {
        return false;
    }

    int pos = l->nroElem;

    while (pos > 0 && l->A[pos - 1].chave > reg.chave)
    {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }

    l->A[pos] = reg;
    l->nroElem++;
    return true;
}

int buscaBinaria(LISTA *l, TIPOCHAVE ch)
{
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem - 1;

    while (esq <= dir)
    {
        meio = ((esq + dir) / 2);
        if (l->A[meio].chave == ch)
        {
            return meio;
        }
        else
        {
            if (l->A[meio].chave < ch)
            {
                esq = meio + 1;
            }
            else
            {
                dir = meio - 1;
            }
        }
    }
    return -1;
}

int buscaSentinela(LISTA *l, TIPOCHAVE ch)
{
    int i = 0;
    l->A[l->nroElem].chave = ch;
    while (l->A[i].chave != ch)
    {
        i++;
    }
    if (i == l->nroElem)
    {
        return -1;
    }
    else
    {
        return i;
    }
}

bool excluirElemLista(LISTA *l, TIPOCHAVE ch)
{
    int pos, j;
    pos = buscaBinaria(l, ch);
    if (pos == -1)
        return false;
    for (j = pos; j < l->nroElem - 1; j++)
    {
        l->A[j] = l->A[j + 1];
    }
    l->nroElem--;

    return true;
}

int main()
{

    LISTA lista;
    inicializarLista(&lista);

    int opcao, valor, pos, contador;

    do
    {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento (Binária)\n");
        printf("3. Buscar elemento (Sentinela)\n");
        printf("4. Excluir elemento\n");
        printf("5. Exibir lista\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            printf("Quantos elementos serão inseridos? \n");
            scanf("%d", &contador);
            for (int i = 0; i < contador; i++)
            {
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                REGISTRO reg = {valor};
                inserirElemListaOrd(&lista, reg);
                printf("Valor inserido com sucesso\n");
            }
            break;

        case 2:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            pos = buscaBinaria(&lista, valor);
            if (pos == -1)
            {
                printf("Valor não encontrado\n");
            }
            else
            {
                printf("Valor encontrado na posição %d\n", pos);
            }
            break;

        case 3:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            pos = buscaSentinela(&lista, valor);
            if (pos == -1)
            {
                printf("Valor não encontrado\n");
            }
            else
            {
                printf("Valor encontrado na posição %d\n", pos);
            }
            break;

        case 4:
            printf("Digite o valor a ser excluído: ");
            scanf("%d", &valor);
            if (excluirElemLista(&lista, valor))
            {
                printf("Valor excluído com sucesso\n");
            }
            else
            {
                printf("Valor não encontrado\n");
            }
            break;

        case 5:
            printf("Lista:");
            for (int i = 0; i < lista.nroElem; i++)
            {
                printf(" %d", lista.A[i].chave);
            }
            printf("\n");
            break;

        case 0:
            printf("Saindo...\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}
