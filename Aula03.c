#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char c)
{
    if (s->top < MAX_SIZE - 1)
    {
        s->data[++(s->top)] = c;
    }
}

char pop(Stack *s)
{
    if (s->top >= 0)
    {
        return s->data[(s->top)--];
    }
    return '\0';
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

bool isValid (char *s){

    Stack stack;
    stack.top = -1;

    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push (&stack, s[i]);
        } else {
            if (isEmpty(&stack)) return false;
            char top = pop(&stack);
            if ((s[i] == ')' && top != '(') ||
            (s[i] == ']' && top != '[') ||
            (s[i] == '}' && top != '{')) {
                return false;
            }

        }
    }
    return isEmpty(&stack);
}

int main (){
    char s [] = "(({[]}))";
    printf ("%s\n", isValid (s) ? "Válido" : "Inválido");
    return 0;
}