#include<stdio.h>
void insertionSort(int array[], int size){
   int key, j;
   for(int i = 1; i<size; i++) {
      key = array[i];
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key; 
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

    insertionSort(ar, eln);

    printf("Elements after Insertion Sorting: ");
    for(int i = 0; i < eln; i++){
        printf("%d ", ar[i]);
    }

    printf("\n");
}
