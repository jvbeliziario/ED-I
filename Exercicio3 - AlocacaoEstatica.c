#include <stdlib.h>
#include <stdio.h>
#define MAX 100

int sequencia(char pilha[], char seq[], int topo) {
    int i = 0;
    while (seq[i] != 'C' && seq[i] != '\0') {
        topo++;
        pilha[topo] = seq[i];
        i++;
    }
    if (seq[i] != 'C') {
        printf("ERRO! C não encontrado na sequência.");
        return 0;
    }
    i++;
    while (seq[i] != '\0') {
        if (topo == -1 || pilha[topo] != seq[i]) {
            return 0;
        }
        topo--;
        i++;
    }
    return topo == -1;
}

int main() {
    char pilha[MAX];
    int topo = -1;
    char seq[MAX] = "baCab";
    if (sequencia(pilha, seq, topo)) {
        printf("Sequência válida!\n");
    } else {
        printf("Sequência inválida!\n");
    }
    return 0;
}
