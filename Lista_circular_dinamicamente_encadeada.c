//lista circular encadeada em alocação dinamica

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No *prox;
}No;

//inicialização

No *criar_lista(){
    return NULL; // lista vazia
}

//  inserção inicio
No *inserir_inicio(No *lista, int valor){ 
    No *novo = (No *)malloc(sizeof(No));
    novo->info = valor;

    if (lista == NULL){
        novo->prox = novo;
        return novo;
    } else {
        novo->prox = lista->prox;
        lista->prox = novo;
        return lista;
    }
}


//remoçao - questão 

No *remover(No *lista, int valor) {
    if (lista == NULL) {
        printf("Lista Vazia");
        return NULL;
    }

    No *atual = lista->prox;
    No *anterior = lista;
    No *inicio = lista->prox;
    int encontrado = 0;

    do {
        if (atual->info == valor) {
            encontrado = 1;
            break;
        }
        anterior = atual;
        atual = atual->prox;
    } while (atual != inicio);

    if (!encontrado) {
        printf("Valor %d não encontrado!", valor); // nó não existente
        return lista;
    }

    if (atual == anterior && atual->prox == atual) { //único nó
        free(atual);
        return NULL;
    }

    anterior->prox = atual->prox;

    if (atual = inicio){            //primeiro nó
        lista->prox = atual->prox; //Atualização do ponteiro do ultimo nó
    }

    if (atual == lista) {
        lista = anterior; //ultimo nó
    }

    free(atual);
    return lista;
}
