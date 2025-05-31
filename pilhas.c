#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int topo = -1;
char pilha[MAX];

void push(char valor){
   if (topo < MAX - 1){
    ++topo;
    pilha[topo] = valor;
   }
   printf ("Empilhando: %d\n", valor);
}


void pop (){
    if(topo >= 0){
        printf ("Desempilhando: %d\n", pilha[topo]);
        topo--;
    }
}

int main(){

    push(10);
    push(20);
    push(30);
    pop();
    pop();
    pop();

    return 0;

}