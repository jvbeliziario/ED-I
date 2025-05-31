#include <stdio.h>
#include <stdlib.h>


int sequencia(char *seq, int *topo) {
    int i = 0;

    while (seq[i] != 'C' && seq[i] != '\0'){
        (*topo)++;
        seq[*topo] = seq[i];
        i++;
    }

    if (seq[i] != 'C'){
        printf ("C não existe");
        return 0;
    }
    i++;

    while (seq[i] != '\0'){
        if (*topo == -1 || seq[*topo] != seq[i]){
            return 0;
        }
        (*topo)--;
        i++;
    }

    return *topo == -1;

}

int main (){
    int topo = -1;
    char seq[] = "abbCbba";

    if (seq == NULL){
      printf ("Erro de memória!");
      return 1;
    }

   if (sequencia(seq, &topo)){
    printf("true");
   } else {
    printf ("fake");
    }

    return 0;

}