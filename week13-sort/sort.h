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
  for(i=0; i<n-1; i++){
    min_index = i;
    
    for(j=i+1; j<n; j++)
      if(list[j] < list[min_index])
	min_index = j;
      
    swap(&list[min_index], &list[i]);
    
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

void bubbleSort(elementType list[], int n){
  int check;
  int i;
  while(1){
    check = 0;
    for(i=0;i<n-1;i++){
      if(list[i] > list[i+1]){
	swap(list+i,list+i+1);
	check = 1;
      }
    }
    if(check == 0)
	break;
  }
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(elementType list[], int n, int i){
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if(l<n && list[l] > list[largest])
    largest = l;
  if (r<n && list[r] > list[largest])
    largest = r;

  if(largest != i){
    swap( list+i, list+largest);
    heapify(list, n, largest);
  }  
}

void heapSort(elementType list[], int n){
  for(int i= n/2 -1; i>=0; i--)
    heapify(list,n,i);// Build heap (rearrange array)
  for(int i= n-1; i>0; i--){// One by one extract an element from heap
    swap(list+0, list+i);// Move current root to end
    heapify(list, i, 0);// call max heapify on the reduced heap
  }
}
