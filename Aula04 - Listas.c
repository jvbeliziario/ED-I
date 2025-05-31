#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct no {
    int info;
    struct no *prox;
};

// Função para inserir elemento no final da lista
void inserir(int x, struct no **inicio, struct no **fim) {
    // Aloca novo nó
    struct no *aux = (struct no *)malloc(sizeof(struct no));
    if (aux == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    // Preenche dados
    aux->info = x;
    aux->prox = NULL;

    // Se a lista estiver vazia (*fim == NULL), o novo nó será o início
    if (!(*fim)) {
        *inicio = aux;
    } else {
        // Liga o último nó atual ao novo
        (*fim)->prox = aux;
    }

    // Atualiza o ponteiro para o novo último nó
    *fim = aux;
}

void inserir_inicio(int x, struct no **inicio) {
    struct no *aux;
    aux = (struct no *)malloc(sizeof(struct no));
    if (aux == NULL) {
        printf("Erro de alocação\n");
        return;
    }
    aux->info = x;
    aux->prox = *inicio;  // o novo nó aponta para o atual início
    *inicio = aux;        // atualiza o ponteiro de início
}

void elimina(int *elem, struct no **inicio, struct no **fim){
    struct no *aux = *inicio;

    if (!(*inicio)){
        printf("Underflow\n");
        return;
    }

    *elem = aux->info;           // Armazena o valor a ser removido
    *inicio = (*inicio)->prox;   // Avança o ponteiro de início
    if (!(*inicio)){             // Se a lista ficou vazia, ajusta o fim
        *fim = NULL;
    }

    free(aux);                   // Libera o nó removido
}

void eliminar(int *elem, int *inicio, int *fim, int fila[]) {
    // Verifica se a fila está vazia
    if (*inicio == *fim) {
        printf("Underflow\n"); // Fila vazia, nada a remover
    } else {
        (*inicio)++; // Avança o índice de início
        *elem = fila[*inicio]; // Captura o valor removido
    }
}

