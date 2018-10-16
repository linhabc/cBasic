#include <stdio.h>

void try(int i,int *a,int *b, int*c);
void print(int *x);

int main(){
  int a[8],b[15],c[15]; //b[i+j],c[i-j]is diagonal and a[i] is column
  int i;
  //2<=i+j<=16; -7<=i-j<=7
  //=1(true) means no queen on the diagonal or the column
  for(i=0;i<8;i++){
    a[1]=1;
  }
  for(i=0;i<15;i++){
    b[i]=1;
    c[i]=1;
  }

  try(1,a,b,c);

  return 0;
}

void try(int i,int *a, int *b, int *c){  
  int x[9];
  for(int j=1;j<=8;j++){
    if(a[i]==1 && b[i+j-1]==1 && c[i-j+8]==1){
      x[i]=j;
      a[j]=0;
      b[i+j-1]=0;
      c[i-j+7]=0;
      if(i==8){
	print(x);
      }
      else try(i+1,a,b,c);
      a[j]=1;
      b[i+j-1]=1;
      c[i-j+7]=1;

    }
    
  }
}

void print(int *x){
  for(int i=1;i<=8;i++){
    printf("%d ", *(x+i));
  }
  printf("\n");
}
