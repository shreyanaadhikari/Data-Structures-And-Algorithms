#include<stdio.h>
void SelectionSort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++){
        int min_ind = i;
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[min_ind]){
                min_ind = j;
            }
        }
        // Swap after finding minimum
        int temp = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
    }
}
int main(){
    int eln, ar[100];
    printf("Enter the number of elements: ");
    scanf("%d", &eln);
    printf("Enter the elements: ");
    for(int i = 0; i < eln; i++){
        scanf("%d", &ar[i]);
    }
    SelectionSort(ar, eln);
    printf("Elements after Selection Sorting: ");
    for(int i = 0; i < eln; i++){
        printf("%d ", ar[i]);
    }
    printf("\n");
}
