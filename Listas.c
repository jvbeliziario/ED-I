#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} No;

int contar(No *inicio) {
    int count = 0;
    while (inicio != NULL) {
        count++;
        inicio = inicio->prox;
    }
    return count;
}

int somar(No *inicio) {
    int soma = 0;
    while (inicio != NULL) {
        soma += inicio->info;
        inicio = inicio->prox;
    }
    return soma;
}

void removerValor(No **inicio, int v) {
    No *atual = *inicio, *anterior = NULL;

    while (atual != NULL && atual->info != v) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor %d não encontrado.\n", v);
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
}

void removerIndice(No **inicio, int indice) {
    No *atual = *inicio, *anterior = NULL;
    int i = 0;

    while (atual != NULL && i < indice) {
        anterior = atual;
        atual = atual->prox;
        i++;
    }

    if (atual == NULL) {
        printf("Índice fora do intervalo.\n");
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
}

void inverter(No **inicio) {
    No *anterior = NULL, *atual = *inicio, *prox = NULL;

    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = prox;
    }

    *inicio = anterior;
}

//guardar nova lista valores não repetidos

int existe(No *lista, int x) {
    while (lista != NULL) {
        if (lista->info == x) return 1;
        lista = lista->prox;
    }
    return 0;
}

void inserirFim(No **inicio, int x) {
    No *novo = malloc(sizeof(No));
    novo->info = x;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    No *aux = *inicio;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = novo;
}

void unicos(No *L1, No *L2, No **L3) {
    while (L1 != NULL) {
        if (!existe(L2, L1->info)) {
            inserirFim(L3, L1->info);
        }
        L1 = L1->prox;
    }

    while (L2 != NULL) {
        if (!existe(*L3, L2->info) && !existe(L1, L2->info)) {
            inserirFim(L3, L2->info);
        }
        L2 = L2->prox;
    }
}
