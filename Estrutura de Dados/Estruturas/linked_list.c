#include <stdio.h>
#include <stdlib.h>

typedef struct  Node {
    int item;
    struct Node *next;
}Node;


/*
Função bosta, pois na verdade deveria somente retornar null, pois o alocamento é feito na função add.
Node *create_linked_list(){
    Node *node = (Node *)(malloc(sizeof(Node)));
    node->next = NULL;
    return node;
}
*/

Node *add(Node *node, int item){
    Node *new_node = (Node *)(malloc(sizeof(Node)));
    new_node->item = item;
    new_node->next = node;
    return new_node;
}

/*Tem uma obs pertinete sobre essa função, se retornamos diretamente o node podemos ter um grave problema 
    de segurança, uma vez que o user teria acessoa ao next!*/
Node *search(Node *node, int item){
    while( node->next != NULL){
        if(node->item == item){
            Node *copia = node;
            copia->next = NULL;
            return copia;
        }
        else{
            node= node->next;
        }
    }
    return NULL;
}


Node *remove_item(Node *node, int item){
    Node *previus = NULL;
    Node *current = node;
    while( current->next != NULL && current->item != item){
        previus = current;
        current = current->next;
    }
    if(current == NULL) return node;
    if(previus == NULL) return current->next;
    else{
        previus->next = current->next;
    }
    free(current);
    return node;
}


int is_empty(Node *node){
    return node == NULL;
}
void print_linked_list(Node *node){
    while (node != NULL) {
        printf("%d\n", node->item);
        node = node->next;
    }
}





int main(){

    return 0;
}