#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int item;
    struct Node *next;
} Node;

Node* add(Node *node, int item) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->item = item;
    new_node->next = node;
    return new_node;
}

void find_longest_zero_sequence(Node *head, int *start, int *end) {
    int current_start = -1;
    int current_length = 0;
    int max_length = 0;
    *start = -1;
    *end = -1;
    int position = 0;

    while (head != NULL) {
        if (head->item == 0) {
            if (current_start == -1) {
                current_start = position;
            }
            current_length++;
        } else {
            if (current_length > max_length) {
                max_length = current_length;
                *start = current_start;
                *end = position - 1;
            }
            current_start = -1;
            current_length = 0;
        }
        head = head->next;
        position++;
    }

    // Verifica a última sequência, se for maior
    if (current_length > max_length) {
        *start = current_start;
        *end = position - 1;
    }
}

int main() {
    Node *node = NULL;
    int num;
    while(scanf("%d", &num) != EOF){
        add(node, num);
    }
    int start, end;
    find_longest_zero_sequence(head, &start, &end);

    return 0;
}
