#include <stdio.h>


void ReadAndCopy(FILE*fin, FILE*fout){
  int c;
  while((c=fgetc(fin) != EOF)){
    fputc(c,fout);
    putchar(c);
  }
}

int main(){
  int c;
  FILE*fBacon =fopen("bacon.txt","r");
  FILE*fTuna =fopen("tuna.txt","w");

  ReadAndCopy(fBacon,fTuna);
  
  fclose(fBacon);
  fclose(fTuna);
  return 0;
}
