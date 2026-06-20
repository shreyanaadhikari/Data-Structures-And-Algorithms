#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

/* create node */
struct Node* makeNode(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

/* insert at head */
void insertHead(struct Node **head, int x) {
    struct Node *n = makeNode(x);

    if (*head == NULL) {
        n->next = n->prev = n;
        *head = n;
        return;
    }

    struct Node *tail = (*head)->prev;

    n->next = *head;
    n->prev = tail;
    tail->next = n;
    (*head)->prev = n;
    *head = n;
}

/* insert at tail */
void insertTail(struct Node **head, int x) {
    struct Node *n = makeNode(x);

    if (*head == NULL) {
        n->next = n->prev = n;
        *head = n;
        return;
    }

    struct Node *tail = (*head)->prev;

    n->next = *head;
    n->prev = tail;
    tail->next = n;
    (*head)->prev = n;
}

/* insert at given position */
void insertAtPos(struct Node **head, int x, int pos) {
    if (pos == 1) {
        insertHead(head, x);
        return;
    }

    struct Node *cur = *head;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->next;
        if (cur == *head) {
            printf("Invalid position\n");
            return;
        }
    }

    struct Node *n = makeNode(x);
    struct Node *nextNode = cur->next;

    n->next = nextNode;
    n->prev = cur;
    cur->next = n;
    nextNode->prev = n;
}

/* delete head */
void deleteHead(struct Node **head) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *tail = (*head)->prev;
    struct Node *temp = *head;

    *head = temp->next;
    (*head)->prev = tail;
    tail->next = *head;

    free(temp);
}

/* delete tail */
void deleteTail(struct Node **head) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *tail = (*head)->prev;

    if (tail == *head) {
        free(tail);
        *head = NULL;
        return;
    }

    struct Node *newTail = tail->prev;
    newTail->next = *head;
    (*head)->prev = newTail;

    free(tail);
}

/* delete at position */
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
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
        if (cur == *head) {
            printf("Invalid position\n");
            return;
        }
    }

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;

    free(cur);
}

/* search */
void searchNode(struct Node *head, int key) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *temp = head;
    int pos = 1;

    do {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);

    printf("Element %d not found\n", key);
}

/* display */
void showList(struct Node *head) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *temp = head;

    printf("HEAD -> ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("HEAD (circular)\n");
}

int main() {
    struct Node *head = NULL;
    int n, val, pos, key;

    printf("Enter number of elements to insert at head: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertHead(&head, val);
    }
    showList(head);

    printf("\nEnter number of elements to insert at tail: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertTail(&head, val);
    }
    showList(head);

    printf("\nEnter value and position to insert: ");
    scanf("%d %d", &val, &pos);
    insertAtPos(&head, val, pos);
    showList(head);

    printf("\nAfter deleting head:\n");
    deleteHead(&head);
    showList(head);

    printf("\nAfter deleting tail:\n");
    deleteTail(&head);
    showList(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);
    deleteAtPos(&head, pos);
    showList(head);

    printf("\nEnter element to search: ");
    scanf("%d", &key);
    searchNode(head, key);

    return 0;
}
