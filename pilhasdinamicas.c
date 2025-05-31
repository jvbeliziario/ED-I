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

/* 

Estruturas

    Pilha voltar: Armazena as páginas visitadas (permite retroceder).

    Pilha avancar: Armazena as páginas retornadas (permite avançar).

    Página atual (pagina_atual): URL da página em exibição.

Passos Sequenciais
1. Inicializar()

    Cria duas pilhas vazias:


    voltar = PilhaVazia()
    avancar = PilhaVazia()
    pagina_atual = NULL

2. Navegar(url)

    Se pagina_atual não é NULL:

        Empilha pagina_atual em voltar.

    Atualiza pagina_atual para url.

    Limpa avancar (nova navegação invalida o histórico de avanço):

    avancar = PilhaVazia()

3. Voltar()

    Se voltar não está vazia:

        Empilha pagina_atual em avancar.

        pagina_atual = Desempilha(voltar).

    Senão:

        Exibe mensagem: "Não há páginas anteriores".

4. Avançar()

    Se avancar não está vazia:

        Empilha pagina_atual em voltar.

        pagina_atual = Desempilha(avancar).

    Senão:

        Exibe mensagem: "Não há páginas posteriores".

Pseudocódigo

Estruturas:
  voltar: Pilha
  avancar: Pilha
  pagina_atual: String

Inicializar():
  voltar = nova Pilha
  avancar = nova Pilha
  pagina_atual = NULL

Navegar(url):
  SE pagina_atual != NULL:
    voltar.empilhar(pagina_atual)
  pagina_atual = url
  avancar = nova Pilha  // Limpa avanços

Voltar():
  SE voltar.naoVazia():
    avancar.empilhar(pagina_atual)
    pagina_atual = voltar.desempilhar()
  SENÃO:
    MOSTRAR "Não há páginas anteriores"

Avançar():
  SE avancar.naoVazia():
    voltar.empilhar(pagina_atual)
    pagina_atual = avancar.desempilhar()
  SENÃO:
    MOSTRAR "Não há páginas posteriores"


*/