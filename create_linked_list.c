#include <stdlib.h>
#include <stdio.h>
// Create a linked list, based on the tutorial @ https://www.geeksforgeeks.org/how-to-create-a-linked-list-in-c/

typedef struct node {
    int data;
    struct node* next;
} Node;


int main(void) {
    Node* first = (Node*) malloc(sizeof(Node));
    Node* current = first;

    first->data = 100;
    for (int i = 0; i < 39; i++) {
        Node* next = (Node*) malloc(sizeof(Node));
        next->data = random();
        current->next = next;
        current = current->next;
    }

    current = first;
    Node* last = (Node*) malloc(sizeof(Node));
    int elements = 0;
    while (current)
    {
        elements++;
        printf("%d ", current->data);

        last = current;
        current = current->next;
        free(last);
    }
    printf("\nlen: %d", elements);
    return 0;
}
