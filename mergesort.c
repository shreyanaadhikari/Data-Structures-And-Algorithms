#include <stdio.h>

void Merge(int a[], int lb, int mid, int ub);

void MergeSort(int a[], int lb, int ub){
    if(lb < ub){
        int mid;
        mid = (lb + ub) / 2;

        MergeSort(a, lb, mid);
        MergeSort(a, mid + 1, ub);
        Merge(a, lb, mid, ub);
    }
}

void Merge(int a[], int lb, int mid, int ub){
    int i, j, k;
    int b[100];

    i = lb;
    j = mid + 1;
    k = lb;

    while(i <= mid && j <= ub){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        b[k] = a[i];
        i++;
        k++;
    }

    while(j <= ub){
        b[k] = a[j];
        j++;
        k++;
    }

    for(k = lb; k <= ub; k++){
        a[k] = b[k];
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

    MergeSort(ar, 0, n - 1);

    printf("Sorted elements are (Merge Sort):\n");
    for(int i = 0; i < n; i++){
        printf("%d ", ar[i]);
    }

    return 0;
}
