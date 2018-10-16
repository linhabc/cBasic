#include <stdio.h>
#include <stdlib.h>
#include "search.h"
//#include "sort.h"


typedef int elementType;


void verify1(elementType list1[], elementType list2[], int n, int m);
void verify2(elementType list1[], elementType list2[], int n, int m);
void verify3(elementType list1[], elementType list2[], int n, int m);

int main(){
	elementType list1[10] = { 1, 4, 5, 6, 3, 7, 8, 12, 11, 13};
	elementType list2[10] = {10, 3, 5, 9, 5, 11, 6, 14, 15, 7};
	int n;
	do{
		printf("____MENU___\n");
		printf("1.All record found in list1 but not in list 2.\n");
		printf("2.All record found in list2 but not in list 1.\n");
		printf("3.All record that are in list1 and list 2 with the same key but have different value.\n");
		printf("4.Exit.\n");
		do{
			printf("Enter(1-4): ");
			scanf(" %d", &n);
		}while(n>4 || n<1);

		switch (n){
			case 1:
				verify1(list1, list2, 10, 10);
				break;
			case 2:
				verify2(list1, list2, 10, 10);
				break;
			case 3:
				verify3(list1, list2, 10, 10);
				break;


		}


	}while(n!=4);


	return 0;
}

void verify1(elementType list1[], elementType list2[], int n, int m){
	int i=0;
	for(i=0; i<n; i++){
		if(binarySearch(list2, list1[i], 0, m-1) == -1)
			printf("%d in list1, but isn't in list2\n", list1[i]);
	}
}

void verify2(elementType list1[], elementType list2[], int n, int m){
	int i=0;
	for(i=0; i<n; i++){
		if(binarySearch(list1, list2[i], 0, m-1) == -1)
			printf("%d in list2, but isn't in list1\n", list2[i]);
	}
}

void verify3(elementType list1[], elementType list2[], int n, int m){
	int i;
	for(i=0; i<n; i++){
		if(list1[i] != list2[i])
			printf("Key %d has different value in different field(list1: %d; list2: %d).\n", i, list1[i],list2[i]);
	}
}