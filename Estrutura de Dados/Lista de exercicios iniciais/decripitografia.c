#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE_MAX  100
typedef struct Stack{
    int current_size;
    char stack[SIZE_MAX];
}Stack;

void pop(Stack *my_stack){
    char x = my_stack->stack[--my_stack->current_size];
    printf("%c", x);
}


int main() {
    char x;
    while(scanf("%c", &x) != EOF){
        printf("%c", x);
    }
	return 0;
}