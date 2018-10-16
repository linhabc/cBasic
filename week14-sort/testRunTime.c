#include "sort.h"
#include <time.h>

void gene(int n[]);

int main(){
  srand(time(NULL));
  int i,a, n[2000000];
  clock_t tic;
  clock_t toc;
  FILE* fout = fopen("200'000numbers(sorted).txt", "w");
  do{
    printf("MENU\n");
    printf("1.generate 2.10*6 number.\n");
    printf("2.insertion sort.\n");
    printf("3.selection sort.\n");
    printf("4.buble sort.\n");
    printf("5.heap sort.\n");
    printf("6.quick sort.\n");
    printf("7.merge sort.\n");
    printf("8.exit.\n");
    do{
      printf("ENTER: ");
      scanf(" %d", &a);
    }while(a>8 || a<1);


    switch(a){
    case 1:
      gene(n);
      break;

    case 2:
      fseek(fout, 0, SEEK_SET);
      tic = clock();
      insertionSort(n, 2000000);
      toc = clock();
      printf("Elapsed time of insertionSort: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);
      for(i=0; i<200000; i++){
	//printf("%d\n", n[i]);
	fprintf(fout, "%d ", n[i]);
      }
      break;
		     
    case 3:
      fseek(fout, 0, SEEK_SET);
      tic = clock();
      selectionSort(n, 2000000);
      toc = clock();
      printf("Elapsed time of selectionSort: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);
      for(i=0; i<200000; i++){
	//printf("%d\n", n[i]);
	fprintf(fout, "%d ", n[i]);
      }
      break;
		     
    case 4:
      fseek(fout, 0, SEEK_SET);
      tic = clock();
      bubbleSort(n, 2000000);
      toc = clock();
      printf("Elapsed time of bubbleSort: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);
      for(i=0; i<200000; i++){
	//printf("%d\n", n[i]);
	fprintf(fout, "%d ", n[i]);
      }
      break;

      		     
    case 5:
      fseek(fout, 0, SEEK_SET);
      tic = clock();
      heapSort(n, 2000000);
      toc = clock();
      printf("Elapsed time of heapSort: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);
      for(i=0; i<200000; i++){
	//printf("%d\n", n[i]);
	fprintf(fout, "%d ", n[i]);
      }
      break;

      case 6:
      fseek(fout, 0, SEEK_SET);
      tic = clock();
      quickSort(n, 0, 2000000);
      toc = clock();
      printf("Elapsed time of heapSort: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);
      for(i=0; i<200000; i++){
	//printf("%d\n", n[i]);
	fprintf(fout, "%d ", n[i]);
      }
      break;

      case 7:
      fseek(fout, 0, SEEK_SET);
      tic = clock();
      mergeSort(n, 0, 2000000);
      toc = clock();
      printf("Elapsed time of heapSort: %f second\n", (double)(toc-tic)/CLOCKS_PER_SEC);
      for(i=0; i<200000; i++){
	//printf("%d\n", n[i]);
	fprintf(fout, "%d ", n[i]);
      }
      break;
      
    }
  }while(a!=8);

  fclose(fout);
  return 0;
}

void gene(int n[]){
  FILE* f = fopen("200'000numbers.txt", "w");
  if(f==NULL){
    printf("Cannot allocate memmory.\n");
    return ;
  }
  for(int i=0; i<2000000; i++){
    n[i] = rand()%10000000;
    fprintf(f, "%d ", n[i]);
  }
  fclose(f);
  
  printf("DONE.\n");
}
