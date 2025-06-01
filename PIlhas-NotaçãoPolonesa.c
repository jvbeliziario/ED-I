#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura do nó da pilha
typedef struct no {
    int valor;
    struct no *prox;
} No;

// Empilha
void push(No **topo, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = *topo;
    *topo = novo;
}

// Desempilha
int pop(No **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia\n");
        exit(1);
    }
    No *temp = *topo;
    int valor = temp->valor;
    *topo = temp->prox;
    free(temp);
    return valor;
}

// Verifica se é operador
int ehOperador(char *token) {
    return strlen(token) == 1 && strchr("+-*/", token[0]) != NULL;
}

// Aplica a operação
int calcular(char operador, int op1, int op2) {
    switch (operador) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default:
            printf("Operador inválido: %c\n", operador);
            exit(1);
    }
}

// Avalia expressão pós-fixa
int avaliarPosfixo(char *tokens[], int n) {
    No *pilha = NULL;

    for (int i = 0; i < n; i++) {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
            push(&pilha, atoi(tokens[i]));
        } else if (ehOperador(tokens[i])) {
            int op2 = pop(&pilha);
            int op1 = pop(&pilha);
            int res = calcular(tokens[i][0], op1, op2);
            push(&pilha, res);
        }
    }

    return pop(&pilha);
}


int main() {
    // Exemplo: expressão pós-fixa: 3 4 5 * +  → 3 + (4 * 5) = 23
    char *expr[] = {"3", "4", "5", "*", "+"};
    int n = sizeof(expr) / sizeof(expr[0]);

    int resultado = avaliarPosfixo(expr, n);
    printf("Resultado: %d\n", resultado);

    return 0;
}
