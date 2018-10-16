#include <stdio.h>
#include <stdlib.h>
#define notFound -1

typedef int elementType;

int binarySearch(elementType a[], elementType x, int lo, int hi){
  if (lo>hi) return notFound;
  int mid = (lo+hi)/2;
  if(a[mid]<x) return binarySearch(a,x,mid+1,hi);
  else if(a[mid]>x) return binarySearch(a,x,lo,mid-1);
  else return mid;
  
  return notFound; //usage: binarySearch(a,x,0,size-1);
}
