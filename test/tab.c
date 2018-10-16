#include <stdio.h>

int main(){
  int a,a1;
  char b[30],b1[30];
  FILE* fin = fopen("tab.txt", "r");

  fscanf(fin, "%d\t%[^\n]", &a,b);
  fscanf(fin, "%d\t%[^\n]", &a1,b1);
  printf("%d	%s\n", a,b);
  printf("%d	%s\n", a1,b1);

}
