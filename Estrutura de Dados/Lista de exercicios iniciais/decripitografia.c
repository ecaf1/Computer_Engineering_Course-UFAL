#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Para resolver esse problema usaremos a estrategia de armazenar os parenteses finais em uma pilha sendo assim:
// Usaremos as seguinte funções já prontas

#define SIZE_MAX  100

typedef struct Stack{
    int current_size;
    char stack[SIZE_MAX];
}Stack;

Stack* creat_stack(){
    Stack *stack =(Stack*)(malloc(sizeof(Stack)));
    stack->current_size = 0;
    return stack;
}

void push(Stack *stack, char item ){
    if(stack->current_size == SIZE_MAX){
        printf("Stack Overflow");
    }
    else{
        stack->stack[stack->current_size++] = item;
    }
}

void pop(Stack *starck){
    printf("%c",starck->stack[--starck->current_size]);
}

int is_empty(Stack *stack){
    if(stack->current_size = 0)return 0;
    else return 1;
}

char peek(Stack *stack){
    if (is_empty(stack)){
        printf("Stack underflow");
        return -1;
    }
    else return stack->stack[stack->current_size - 1];
}

int main(){
    // Variaveis auxiliares
    char x;
    int cont = 1;
    // criação da pilha 
    Stack *stack = creat_stack();

    while (scanf("%c", &x) != EOF){
        if(x == '*'){
            printf("(%d", cont);
            // add pareteces para  ser exibido no final 
            push(stack, ')');
            cont++;
        }
        else if(x == '_'){
            printf("%d", cont);
            cont++;
        }
    }
    int tam = stack->current_size;
    printf("%d", tam);
    for(int i = 0; i < tam; i++){
        pop(stack);
    }
    
    return 0;
}
