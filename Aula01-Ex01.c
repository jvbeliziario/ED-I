/*Dado um array de inteiros representando uma lista sequencial, implemente a função:

bool inserirElemento(int arr[], int *tamanho, int capacidade, int valor, int pos);

Essa função deve inserir o número valor na posição pos da lista, deslocando os elementos necessários para a direita.

Regras:

    Se pos for inválido (pos < 0 ou pos > tamanho), a função deve retornar false.
    Se a lista estiver cheia (tamanho == capacidade), retorne false.
    Caso contrário, insira o valor, aumente o tamanho da lista e retorne true.*/

#include <stdio.h>
#include <stdbool.h>

bool inserirElemento(int arr[], int *tamanho, int capacidade, int valor, int pos)
{

    int j;
    if (*tamanho >= capacidade || pos < 0 || pos > *tamanho)
    {
        return false;
    }
    for (j = *tamanho; j > pos; j--)
    {
        arr[j] = arr[j - 1];
    }

    arr[pos] = valor;
    (*tamanho)++;
    return true;
}

