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

void quickSort(elementType list[], int left, int right){
  int pivot, i, j;
  if(left < right){
    i=left;
    j=right+1;
    pivot = list[left];
    do{
      do i++;
      while(list[i] < pivot);
      do j--;
      while(list[j] > pivot);
      if(i<j)
	swap(&list[i], &list[j]);
    }while(i<j);
    swap(&list[left], &list[j]);
    quickSort(list, left, j-1);
    quickSort(list, j+1, right);
  }
}

void merge(elementType list[], int l, int m, int r){
  int i,j,k;
  int n1= m-l+1;
  int n2=r-m;

  elementType L[n1], R[n2];

  for(i=0; i<n1; i++)
    L[i] = list[l+i];
  for(j=0; j<n2; j++)
    R[j] = list[m+1+j];

  i=0; j=0; k=l;
  
  while(i<n1 && j<n2){
    if(L[i] <= R[j]){
      list[k] = L[i];
      i++;
    }else{
      list[k] = R[j];
      j++;
    }
    k++;
  }

  while(i<n1){
    list[k] = L[i];
    i++;
    k++;
  }
  while(j<n2){
    list[k] = R[j];
    j++;
    k++;
  }
  
}

void mergeSort(elementType list[], int l, int r){
  if(l<r){
    int m = l + (r-l)/2;
    mergeSort(list, l, m);
    mergeSort(list, m+1, r);

    merge(list, l, m, r);
  }
}
