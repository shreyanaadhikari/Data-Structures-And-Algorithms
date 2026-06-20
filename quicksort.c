#include <stdio.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r){
    int pivot, x, y;

    pivot = a[l];
    x = l;
    y = r;

    while(x < y){
        while(a[x] <= pivot && x < r)
            x++;

        while(a[y] > pivot)
            y--;

        if(x < y)
            swap(&a[x], &a[y]);
    }

    a[l] = a[y];
    a[y] = pivot;

    return y;
}

void quickSort(int a[], int l, int r){
    int p;

    if(l < r){
        p = partition(a, l, r);
        quickSort(a, l, p-1);
        quickSort(a, p+1, r);
    }
}

int main(){
    int n;
    int ar[100];

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &ar[i]);
    }

    quickSort(ar, 0, n-1);

    printf("Sorted elements are (Quick Sort):\n");
    for(int i = 0; i < n; i++){
        printf("%d ", ar[i]);
    }

    return 0;
}

