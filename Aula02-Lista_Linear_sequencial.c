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

// BUSCA COM SENTINELA

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

// INSERÇÃO ORDENADA

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

// BUSCA BINÁRIA

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

// EXCLUSÃO DE ELEMENTOS

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