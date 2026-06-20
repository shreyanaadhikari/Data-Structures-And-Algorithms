#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = 0, rear = -1;
int isEmpty() {
    return (front == (rear + 1) % SIZE);
}
int isFull() {
    return (front == (rear + 2) % SIZE);
}
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is FULL\n");
    } else {
        rear = (rear + 1) % SIZE;  // Circular increment
        queue[rear] = data;
        printf("Enqueued: %d\n", data);
    }
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY, cannot dequeue\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % SIZE;  // Circular increment
    }
}
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is EMPTY\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != (rear + 1) % SIZE) {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}
int main() {
    int n, i, d;
    // Insert elements into the queue
    printf("Enter number of elements to insert (max %d): ", SIZE);
    scanf("%d", &n);
    if (n > SIZE) {
        printf("Cannot insert more than %d elements\n", SIZE);
        return 0;
    }
   printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
    scanf("%d", &d);
    enqueue(d);
}
    displayQueue();
    dequeue();
    enqueue(7);
    dequeue();
    enqueue(8);
    displayQueue();  
    return 0;
}
