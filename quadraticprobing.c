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
        if(hash[index] == -1) {
            hash[index] = key;
        }
        else {
            for(j = 1; j < SIZE; j++) {
                int newIndex = (index + j * j) % SIZE;

                if(hash[newIndex] == -1) {
                    hash[newIndex] = key;
                    break;
                }
            }
        }
    }
    printf("Hash Table (Quadratic Probing):\n");
    for(i = 0; i < SIZE; i++) {
        printf("%d -> %d\n", i, hash[i]);
    }
    return 0;
}
