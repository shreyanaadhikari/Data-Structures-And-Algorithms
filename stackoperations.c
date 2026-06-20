#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

/* Function Declarations */
void push();
void pop();
void peek();
void traverse();
int isFull();
int isEmpty();

int main() {
    int n, i;

    /* PUSH elements by user */
    printf("How many elements do you want to push? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        push();
    }

    /* TRAVERSE */
    printf("\nStack elements after push:\n");
    traverse();

    /* PEEK */
    peek();

    /* POP */
    pop();

    /* TRAVERSE after pop */
    printf("\nStack after pop operation:\n");
    traverse();

    /* isFull check */
    if (isFull())
        printf("\nStack is FULL\n");
    else
        printf("\nStack is NOT FULL\n");

    /* isEmpty check */
    if (isEmpty())
        printf("Stack is EMPTY\n");
    else
        printf("Stack is NOT EMPTY\n");

    return 0;
}

/* Push Operation */
void push() {
    int value;
    if (isFull()) {
        printf("Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &value);
        stack[++top] = value;
    }
}

/* Pop Operation */
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
    } else {
        printf("\nPopped element: %d\n", stack[top--]);
    }
}

/* Peek Operation */
void peek() {
    if (isEmpty()) {
        printf("\nStack is empty. No top element.\n");
    } else {
        printf("\nTop element is: %d\n", stack[top]);
    }
}

/* Traverse Operation */
void traverse() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

/* IsFull Operation */
int isFull() {
    return top == MAX - 1;
}

/* IsEmpty Operation */
int isEmpty() {
    return top == -1;
}
