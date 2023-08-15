#include <stdio.h>
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
    printf(starck->stack[--starck->current_size]);
}


char peek(Stack *stack){
    if (is_empty(stack)){
        printf("Stack underflow");
        return -1;
    }
    else return stack->stack[stack->current_size - 1];
}