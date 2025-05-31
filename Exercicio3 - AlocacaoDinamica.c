#include <stdlib.h>
#include <stdio.h>

int sequencia(char *pilha, char *seq, int topo) {
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
    int max = 100;
    char *pilha = (char *)malloc(max * sizeof(char));
    if (pilha == NULL) {
        printf("Erro de alocação de memória.");
        return 1;
    }
    int topo = -1;
    char seq[] = "baCab";
    if (sequencia(pilha, seq, topo)) {
        printf("Sequência válida!");
    } else {
        printf("Sequência inválida!");
    }
    free(pilha);
    return 0;
}
