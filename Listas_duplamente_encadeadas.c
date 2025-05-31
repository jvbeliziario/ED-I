#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int dado;
    struct No *prox;
    struct No *ant;
}No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

//Inicializar lista

Lista *criar_lista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->fim =  NULL;
    lista->tamanho = 0;
    return lista;
}

void inserir_inicio (Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->ant = NULL;
    novo->prox = lista->inicio;

    if (lista->inicio == NULL){
        lista->fim = novo;
    }else{
        lista->inicio->ant = novo;
    }

    lista->inicio = novo;
    lista->tamanho++;
}

void inserir_fim (Lista *lista, int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = lista->fim;

    if (lista->fim == NULL){  
        lista->inicio = novo;
    } else {
        lista->fim->prox = novo;
    }

    lista->fim = novo;
    lista->tamanho++;    
}

void remover(Lista *lista, int valor){
    No *atual = lista->inicio;

    while (atual != NULL){
        if (atual->dado == valor){
            if (atual->ant != NULL){
                atual->ant->prox = atual->prox;
            } else {
                lista->inicio = atual->prox;
            }

            if (atual->prox != NULL){
                atual->prox->ant = atual->ant;
            } else {
                lista->fim = atual->ant;
            }
        }
        atual = atual->prox;
    }
    printf ("Valor %d não encontrado!", valor);
}

No* buscar(Lista *lista, int valor) {
    No *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->dado == valor) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL; // Valor não encontrado
}

void exibir(Lista *lista) {
    No *atual = lista->inicio;
    printf("Lista (Ordem Direta): ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void exibir_inverso(Lista *lista) {
    No *atual = lista->fim;
    printf("Lista (Ordem Inversa): ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->ant;
    }
    printf("\n");
}

int main() {
    Lista *lista = criar_lista();

    inserir_inicio(lista, 10);
    inserir_fim(lista, 20);
    inserir_inicio(lista, 5);
    inserir_fim(lista, 30);

    exibir(lista);          // Saída: 5 10 20 30
    exibir_inverso(lista);  // Saída: 30 20 10 5

    remover(lista, 10);
    exibir(lista);          // Saída: 5 20 30

    No *resultado = buscar(lista, 20);
    if (resultado != NULL) {
        printf("Valor 20 encontrado!\n");
    } else {
        printf("Valor 20 não encontrado!\n");
    }

    return 0;
}
