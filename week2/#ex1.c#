#include <stdio.h>
#include <string.h>

void ReadAndCopy(FILE*fin, FILE*fout);

int main(int argc, char*argv[]){
  if(argc!=3){
    printf("Enter 3 argument.\n");
    return -1;
  }
  
  FILE*fFile1=fopen(argv[1],"r");
  FILE*fFile2=fopen(argv[2],"w");

  if(fFile1==NULL){
    printf("Cannot open file1");
  }
  else if(fFile2==NULL){
    printf("Cannot opend file2");
  }
  else{
    ReadAndCopy(fFile1,fFile2);
    fclose(fFile1);
    fclose(fFile2);
  }
  
  return 0;
}

void ReadAndCopy(FILE*fin, FILE*fout){
  int c;
  while((c=fgetc(fin)) != EOF){
    fputc(c,fout);
    putchar(c);
  }
}
