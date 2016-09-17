/* linked-list-lagoon — singly linked list operations in C */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *node_new(int value) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) {
        perror("malloc");
        exit(1);
    }
    n->value = value;
    n->next = NULL;
    return n;
}

void list_push_front(Node **head, int value) {
    Node *n = node_new(value);
    n->next = *head;
    *head = n;
}

void list_push_back(Node **head, int value) {
    Node *n = node_new(value);
    if (!*head) {
        *head = n;
        return;
    }
    Node *cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

int list_delete(Node **head, int value) {
    Node *cur = *head, *prev = NULL;
    while (cur) {
        if (cur->value == value) {
            if (prev) prev->next = cur->next;
            else *head = cur->next;
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}

void list_reverse(Node **head) {
    Node *prev = NULL, *cur = *head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

int list_length(Node *head) {
    int n = 0;
    for (; head; head = head->next) n++;
    return n;
}

void list_print(Node *head) {
    printf("[");
    for (Node *c = head; c; c = c->next) {
        printf("%d", c->value);
        if (c->next) printf(" -> ");
    }
    printf("] (len=%d)\n", list_length(head));
}

void list_free(Node **head) {
    Node *cur = *head;
    while (cur) {
        Node *n = cur->next;
        free(cur);
        cur = n;
    }
    *head = NULL;
}

int main(void) {
    Node *head = NULL;
    list_push_back(&head, 10);
    list_push_back(&head, 20);
    list_push_back(&head, 30);
    list_push_front(&head, 5);
    printf("after inserts: ");
    list_print(head);

    list_delete(&head, 20);
    printf("after delete 20: ");
    list_print(head);

    list_reverse(&head);
    printf("after reverse: ");
    list_print(head);

    list_free(&head);
    return 0;
}
