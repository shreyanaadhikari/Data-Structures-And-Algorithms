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
    n->prev = NULL;
    n->next = NULL;
    return n;
}
/* insert at head */
void insertHead(struct Node **head, int x) {
    struct Node *n = makeNode(x);
    if (*head != NULL) {
        n->next = *head;
        (*head)->prev = n;
    }
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
    n->prev = cur;
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
    n->prev = cur;

    if (cur->next != NULL)
        cur->next->prev = n;
    cur->next = n;
}
/* delete from head */
void deleteHead(struct Node **head) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}
/* delete from tail */
void deleteTail(struct Node **head) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *cur = *head;
    while (cur->next != NULL)
        cur = cur->next;
    if (cur->prev != NULL)
        cur->prev->next = NULL;
    else
        *head = NULL;   // only one node
    free(cur);
}
/* delete by position */
void deleteAtPos(struct Node **head, int pos) {
    if (*head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *cur = *head;
    for (int i = 1; i < pos && cur != NULL; i++)
        cur = cur->next;
    if (cur == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (cur->prev != NULL)
        cur->prev->next = cur->next;
    else
        *head = cur->next;
    if (cur->next != NULL)
        cur->next->prev = cur->prev;
    free(cur);
}
/* search */
void searchNode(struct Node *head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}
/* display forward */
void showList(struct Node *head) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
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
