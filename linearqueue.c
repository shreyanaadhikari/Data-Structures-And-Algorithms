#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = 0, rear = -1;
int isEmpty() {
    return (rear < front);
}
int isFull() {
    return (rear == SIZE - 1);
}

int main() {
    int n, i, d;
    printf("Enter number of elements to insert (max %d): ", SIZE);
    scanf("%d", &n);

    if (n > SIZE) {
        printf("Queue is FULL\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        if (!isFull()) {
            rear++;
            scanf("%d", &queue[rear]);
        }
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");

    //Dequeue operation
    if (isEmpty())
        printf("Queue is EMPTY, cannot dequeue\n");
    else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
    if (isEmpty())
        printf("Queue is EMPTY after dequeue\n");
    else {
        printf("Queue after dequeue: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    return 0;
}
