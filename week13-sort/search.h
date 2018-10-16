#include <stdio.h>
#include <stdlib.h>

typedef int elementType;

void swap(elementType *x, elementType *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selectionSort(elementType list[], int n){
  int i, j, min_index;
  for(i=0; i<n; i++){
    min_index = i;
    
    for(j=i+1; j<n; j++){
      if(list[j] < list[min_index])
	min_index = j;
      
      swap(&list[min_index], &list[i]);
    }
  }
}

void insertionSort(elementType list[], int n){
  int i,key,j;
  for(i=0; i<n; i++){
    key = list[i];
    j = i - 1;

    while(j>=0 && list[j]>key){
      list[j+1] = list[j];
      j= j-1;
    }
    
    list[j+1] = key;
  }
}

//heapify a subtree rooted with node i which is an index in arr[], n is size of heap
void heapify(elementType arr[], int n, int i){
  int largest; // root
  int l = 2*i +1;
  int r = 2*i +2;

  if(l<n && arr[l] > arr[largest])
    largest = l;

  if(r<n && arr[r] > arr[largest])
    largest = r;

  if(largest != i){
    swap(arr[i], arr[largest]);

    heapify(arr, n, largest);
  }
}
