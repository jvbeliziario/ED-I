#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char letra;
    struct No* prox;
} No;

No* topo = NULL;

void push (char letra){
No* novo = (No*)malloc(sizeof(No));
if (novo ==  NULL){
    printf("erro de memoria");
    return;
}

novo->letra = letra;
novo->prox = topo;
topo = novo;
printf("Empilhando: %c\n", letra);
}

void pop(){
    if (topo == NULL){
        printf("pilha vazia");
        return;
    }

    No* temp =  topo;
    printf("Desempilhando: %c\n", temp->letra);
    topo = topo->prox;
    free(temp);
}

void top(){
    printf("O topo da pilha é: %c\n\n", topo->letra);
}

int main(){
    push('A');
    top();
    push('A');
    top();    
    push('X');
    top();    
    push('D');
    top();
    pop();
    top();    
    pop();
    top();    
    pop();
    top();
}

