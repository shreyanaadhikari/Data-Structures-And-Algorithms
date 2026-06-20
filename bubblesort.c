#include<stdio.h>
#include<stdbool.h>
void bubbleSort(int arr[], int n){
	int i,j;
	bool swapped;
	for(i=0; i<n-1; i++){
		swapped=false;
		for (j=0; j<n-i-1;j++){
			if (arr [j]>arr[j+1]){
				int temp = arr [j];
				arr[j] = arr [j+1];
				arr [j+1]= temp;
			}
			swapped = true;
		}
	}
	if (swapped == false){
	}
}
int main () {
	int eln, ar[100];
	printf("Enter the number of elements: ");
	scanf ("%d", &eln);
	printf("Enter the elements: ");
	for (int i=0; i<eln; i++){
		scanf ("%d", &ar[i]);
	}
	bubbleSort (ar, eln);
	printf("Elements after Bubble Sorting: ");
   for(int i = 0; i<eln; i++)
      printf("%d ", ar[i]);
   printf("\n");
}
