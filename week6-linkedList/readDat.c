#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num;
  int id;
  char name[30];
  int grade;
}stu_t;

void readDat(FILE* fin, stu_t stu[]);

int main(int argc, char* argv[]){
  if(argc != 2){
    printf("Enter 2 arg, including name\n");
    return 1;
  }

  FILE* fin= fopen(argv[1], "rb");
  if(fin==NULL){
    printf("Cannot loaded file,\n");
    return 1;
  }
  
  stu_t *stu;
  stu=(stu_t *)malloc(20*sizeof(stu_t));
  if(stu==NULL){
    printf("Allocated memory failed\n");
    return 1;
  }

  readDat(fin, stu);


  return 0;
}

void readDat(FILE* fin, stu_t stu[]){
  int i;
  fread(stu, sizeof(stu_t), 20, fin);
  for(i=0; i<20; i++){
    printf("%4d%11d%-30s%d\n", stu[i].num, stu[i].id, stu[i].name, stu[i].grade);
  }
}
