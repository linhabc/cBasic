#include <stdio.h>
#include <stdlib.h>

void encodeFile(FILE *fin, int n);
void decodeFile(FILE *fin, int n);

int main(int argc, char* argv[]){
  if(argc!=3){
    printf("Enter 3 argument.\n");
    return 1;
  }
  
  FILE* fin = fopen(argv[1], "r");
  if(fin==NULL){
    printf("Cannot open");
    return -1;
  }
  
  int n;
  n=atoi(argv[2])%26;
  encodeFile(fin, n);
  fclose(fin);
  
  return 0;
}

void encodeFile(FILE *fin, int n){
  int buff;
  FILE *ftmp = fopen("tmp.txt","w");
  while((buff=fgetc(fin)) != EOF){
    if(buff != '\n'){
      buff += n;
    }
    fputc(buff, ftmp);
    putchar(buff);
  }
  fclose(ftmp);
}
void decodeFile(FILE *fin, int n){
  int buff;
  FILE *ftmp = fopen("tmp1.txt","w");
  while((buff=fgetc(fin)) != EOF){
    if(buff != '\n'){
      buff -= n;
    }
    fputc(buff, ftmp);
    putchar(buff);
  }
  fclose(ftmp);
}
