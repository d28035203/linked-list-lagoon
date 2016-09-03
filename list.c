/*
 * list.c — singly linked list drills (data structures)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *push_front(Node *head, int v) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) exit(1);
    n->val = v;
    n->next = head;
    return n;
}

Node *pop_front(Node *head) {
    if (!head) return NULL;
    Node *n = head->next;
    free(head);
    return n;
}

Node *reverse(Node *head) {
    Node *prev = NULL, *cur = head, *nxt;
    while (cur) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

void print_list(Node *head) {
    printf("[");
    for (Node *p = head; p; p = p->next)
        printf("%d%s", p->val, p->next ? " -> " : "");
    printf("]\n");
}

void free_list(Node *head) {
    while (head) head = pop_front(head);
}

int main(void) {
    Node *h = NULL;
    h = push_front(h, 3);
    h = push_front(h, 2);
    h = push_front(h, 1);
    printf("built: "); print_list(h);
    h = reverse(h);
    printf("rev:   "); print_list(h);
    h = pop_front(h);
    printf("pop:   "); print_list(h);
    free_list(h);
    return 0;
}
