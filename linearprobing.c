#include <stdio.h>
#define SIZE 10
int main() {
    int hash[SIZE], i, n, key, index, j;
    for(i = 0; i < SIZE; i++)
        hash[i] = -1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter keys:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &key);
        index = key % SIZE;
        while(hash[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hash[index] = key;
    }
    printf("Hash Table (Linear Probing):\n");
    for(i = 0; i < SIZE; i++) {
        printf("%d -> %d\n", i, hash[i]);
    }
    return 0;
}
