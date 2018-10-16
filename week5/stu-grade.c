#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct student{
  int num;
  int id;
  char name[30];
  int grade;
}stu_t;

void convertToDat(FILE* fin,FILE* fout, stu_t stu[]);
void readDat(FILE* fin, stu_t stu[]);
void searchAndUpdate(FILE* fin, stu_t stu[]);

int main(){
  int a;
  FILE* fin = fopen("grade-table.txt", "r");
  FILE* fout = fopen("grade-table.dat", "w+b");
  if(fin==NULL|| fout==NULL ){
    printf("Cannot opened the file.\n");
    return 1;
  }
  
  stu_t *stu;
  stu = (stu_t *)malloc(20*sizeof(stu_t));
  
  do{
    printf("\nMENU\n");
    printf("1.convert to dat\n");
    printf("2.display dat\n");
    printf("3.search and update\n");
    printf("4.exit\n");
    do{
      printf("Enter(1-3) : ");
      scanf(" %d", &a);
    }while(a>4 ||  a<1);

    switch(a){
    case 1:
      convertToDat(fin,fout,stu);
      printf("done\n");
      break;
    case 2:
      
      readDat(fout, stu);
      break;
    case 3:
      searchAndUpdate(fout, stu);
      break;
    }

  }while(a!=4);

  free(stu);
  fclose(fin);
  fclose(fout);
  return 0;
}


void convertToDat(FILE* fin,FILE* fout, stu_t stu[]){
  int i;
  for(i=0;i<20;i++){
    fscanf(fin, " %d", &stu[i].num);
    fscanf(fin, " %d", &stu[i].id);
    
    fgets(stu[i].name, 30, fin);
    fscanf(fin, " %d", &stu[i].grade);
  }
  fwrite(stu, sizeof(stu_t), 20, fout);
}


void readDat(FILE* fin, stu_t stu[]){
  int i;
  fread(stu, sizeof(stu_t), 20, fin);
  for(i=0; i<20; i++){
    printf("%4d%11d%-30s%d\n", stu[i].num, stu[i].id, stu[i].name, stu[i].grade);
  }
}

void searchAndUpdate(FILE* fin, stu_t stu[]){
  int c,g,i;
  printf("Enter student id: ");
  scanf(" %d", &c);
  printf("Enter grade to replace: ");
  scanf(" %d", &g);
  
  for (i = 0; i < 20; i++){
    if(stu[i].id==c){
      stu[i].grade=g;
      break;
    }
  }
  fwrite(stu, sizeof(stu_t), 20, fin);
  printf("%4d%11d%-30s%d", stu[i].num, stu[i].id, stu[i].name, stu[i].grade);
  
}
