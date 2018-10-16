#include <stdio.h>

typedef int elementType;

void swap(elementType *a, elementType *b){
	elementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort(elementType arr[], int n){
  int i, j, min_index;
  //find the min element in unsorted array
  for(i=0; i<n; i++){
    min_index = i;
    for(j=i+1; j<n; j++){
      if(arr[j]<arr[min_index])
	min_index=j;
    }
    //swap the founded min element with arr[i]
    swap(&arr[i], &arr[min_index]);
  }
}
