#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insert_first(Node** head, int data) {
    Node* first = (Node*) malloc(sizeof(Node));
    first->data = data;
    first->next = *head;
    *head = first;
}

void insert_before(Node* head, int key, int data) {
    Node* curr = head;
    Node* prev = (Node*) malloc(sizeof(Node));

    for (int i = 1; i < key; i++) {
        prev = curr;
        if (curr->next) {
            curr = curr->next;
        } else {
            printf("cannot insert before nonextistent node");
        }
    }
    Node* new = (Node*) malloc(sizeof(Node));
    new->data = data;
    new->next = curr;
    prev->next = new;
}

void insert_after(Node* prev, int data) {
    if (prev == NULL)
    {
        printf("Previous node can't be a null!");
        return;
    }

    Node* next = (Node*) malloc(sizeof(Node));
    next->data = data;
    next->next = prev->next;
    prev->next = next;
}

void insert_last(Node* node, int data) {
    Node* last = (Node*) malloc(sizeof(Node));
    Node* temp = node;
    while (temp->next)
    {
        temp = temp->next;
    }
    last->data = data;
    temp->next = last;
}

void remove_node(Node **head, int key) {
    Node* curr = *head;
    Node* prev = *head;
    printf("head: %d | next: %d\n", (*head)->data, (*head)->next->data);
    if (key < 1) {
        printf("Pick a node higher than 1");
        return;
    } else if (key == 1) {
        if (!(*head)->next) {
            free(head);
            printf("List is empty");
        } else {
            *head = (*head)->next;
            free(curr);
            printf("head: %d | next: %d\n", (*head)->data, (*head)->next->data);
        }
        return;
    }


    for (int i = 1; i < key; i++) {
        prev = curr;
        curr = curr ->next;
    }
    prev->next = curr->next;
    free(curr);
    return;
}

int main(void) {
    Node* head = (Node*) malloc(sizeof(Node));
    head->data = 255;

    insert_last(head, 5);
    insert_after(head->next, 7);
    insert_first(&head, 100);
    insert_before(head, 3, 666);
    remove_node(&head, 1);

    printf("output should be [255 666 5 7]\n");

    printf("[");
    int elements = 0;
    Node* last = malloc(sizeof(Node));
    while (head)
    {
        elements++;
        printf("%d ", head->data);

        last = head;
        head = head->next;
        free(last);
    }
    printf("]");
    printf("\nlen: %d\n", elements);
    return 0;


}