#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* create node */
struct Node* makeNode(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

/* insert at head */
void insertHead(struct Node **head, int x) {
    struct Node *n = makeNode(x);
    n->next = *head;
    *head = n;
}

/* insert at tail */
void insertTail(struct Node **head, int x) {
    struct Node *n = makeNode(x);
    if (*head == NULL) {
        *head = n;
        return;
    }

    struct Node *cur = *head;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = n;
}

/* insert at given position */
void insertAtPos(struct Node **head, int x, int pos) {
    if (pos == 1) {
        insertHead(head, x);
        return;
    }

    struct Node *cur = *head;
    for (int i = 1; i < pos - 1 && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node *n = makeNode(x);
    n->next = cur->next;
    cur->next = n;
}

/* delete from head */
void deleteHead(struct Node **head) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *t = *head;
    *head = t->next;
    free(t);
}

/* delete from tail */
void deleteTail(struct Node **head) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *cur = *head;
    while (cur->next->next != NULL)
        cur = cur->next;

    free(cur->next);
    cur->next = NULL;
}

/* delete by position */
void deleteAtPos(struct Node **head, int pos) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }

    if (pos == 1) {
        deleteHead(head);
        return;
    }

    struct Node *cur = *head;
    struct Node *prev = NULL;

    for (int i = 1; i < pos && cur != NULL; i++) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = cur->next;
    free(cur);
}

/* search */
void searchNode(struct Node *head, int key) {
    int index = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d\n", key, index);
            return;
        }
        head = head->next;
        index++;
    }
    printf("Element %d not found\n", key);
}

/* display */
void showList(struct Node *head) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int n, val, pos, key;

    /* multiple insert at head */
    printf("Enter number of elements to insert at head: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertHead(&head, val);
    }
    showList(head);

    /* multiple insert at tail */
    printf("\nEnter number of elements to insert at tail: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertTail(&head, val);
    }
    showList(head);

    /* insert at position */
    printf("\nEnter value and position to insert: ");
    scanf("%d %d", &val, &pos);
    insertAtPos(&head, val, pos);
    showList(head);

    /* delete head */
    printf("\nAfter deleting head:\n");
    deleteHead(&head);
    showList(head);

    /* delete tail */
    printf("\nAfter deleting tail:\n");
    deleteTail(&head);
    showList(head);

    /* delete at position */
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    deleteAtPos(&head, pos);
    showList(head);

    /* search */
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    searchNode(head, key);

    return 0;
}
