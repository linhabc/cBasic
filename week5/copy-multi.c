#include <stdio.h>
#include <time.h>
#define MAX 100

void copybychar(FILE* fin, FILE* fout);
void copybyline(FILE* fin, FILE* fout);
void copybyblock(FILE* fin, FILE* fout);

int main(){
  clock_t starttime, finishtime, timetaken;
  double timeinsecond;
  int a;
  
  FILE* fin = fopen("text.txt", "r");
  FILE* fout = fopen("copytxt.txt", "w");
  if(fin==NULL || fout==NULL){
    printf("Can't open file\n");
    return 1;
  }

  do{
    printf("\nCOPY-MULTIMODE\n");
    printf("1. Copy by char\n");
    printf("2. Copy by line\n");
    printf("3. Copy by block\n");
    printf("4. Exit.\n");
    printf("Enter your selection: ");
    do{
      scanf(" %d", &a);
    }while(a<1 || a>4);

    switch(a) {
    case 1:
      starttime=clock();
      copybychar(fin,fout);
      finishtime=clock();
      timetaken=finishtime-starttime;
      timeinsecond=timetaken/(double)CLOCKS_PER_SEC;
      printf("TIME TAKEN: %lf", timeinsecond);
      break;	
    
    case 2:
      starttime=clock();
      copybyline(fin,fout);
      finishtime=clock();
      timetaken=finishtime-starttime;
      timeinsecond=timetaken/(double)CLOCKS_PER_SEC;
      printf("TIME TAKEN: %lf", timeinsecond);
      break;

    case 3:
      starttime=clock();
      copybyblock(fin,fout);
      finishtime=clock();
      timetaken=finishtime-starttime;
      timeinsecond=timetaken/(double)CLOCKS_PER_SEC;
      printf("TIME TAKEN: %lf", timeinsecond);
      break;

    
    }

  }while(a!=4);
  

  fclose(fin);
  fclose(fout);
  return 0;
}

void copybychar(FILE* fin, FILE* fout){
  int c;
  while((c=fgetc(fin))!=EOF){
    fputc(c,fout);
    //putchar(c);
  }
}

void copybyline(FILE* fin, FILE* fout){
  char buff[MAX];
  while(fgets(buff, MAX, fin)!=NULL){
    fputs(buff, fout);
    //printf("%s", buff);
  }
}

void copybyblock(FILE* fin, FILE* fout){
  int num;
  char buff[MAX+1];
  while(!feof(fin)){
    num=fread(buff, sizeof(char), MAX, fin);
    buff[num*sizeof(char)]='\0';
    //printf("%s",buff);
    fwrite(buff, sizeof(char), num, fout);
  }
}
