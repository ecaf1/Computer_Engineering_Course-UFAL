#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

typedef struct  Node {
    int item;
    struct Node *next;
}Node;

Node *add(Node *node, int item){
    Node *new_node = (Node *)(malloc(sizeof(Node)));
    new_node->item = item;
    new_node->next = node;
    return new_node;
}

void print_linked_list(Node *node){
    while (node != NULL) {
        printf("%d\n", node->item);
        node = node->next;
    }
}

int main(){
    int* freq = (int *)(calloc(SIZE, sizeof(int)));
    char letra;
    Node *head = NULL;
    while(scanf("%c", &letra) != EOF){
        freq[letra]++;
    }
    for(int i = 0;i <SIZE; i++){
        if(freq[i] != 0){
            add(head, freq[i]);
        }
    }
    print_linked_list(head);
    return 0;

}