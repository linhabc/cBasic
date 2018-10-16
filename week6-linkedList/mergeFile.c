#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int num;
  int id;
  char name[30];
  int grade;
}stu_t;

struct addr_node{
  stu_t student;
  struct addr_node *next;
};

typedef struct addr_node node_addr;

node_addr *root, *cur;

//void readDat(FILE* fin, stu_t stu[]);

int main(int argc, char* argv[]){
  if(argc != 4){
    printf("Enter 4 arg, including name\n");
    return 1;
  }

  FILE* fout= fopen(argv[3], "wb");
  FILE* f1= fopen(argv[1], "rb");
  FILE* f2= fopen(argv[2], "rb");
  if(fout==NULL || f1==NULL || f2==NULL){
    printf("Cannot loaded file,\n");
    return 1;
  }

  stu_t *stu;
  stu=(stu_t *)malloc(sizeof(stu_t));
  if(stu==NULL){
    printf("Allocated memory failed\n");
    return 1;
  }
  
  int num;
  while(!feof(f1)){
    num=fread(stu, sizeof(stu_t), 1, f1);
    fwrite(stu, sizeof(stu_t), 1, fout);
  }
  while(!feof(f2)){
    num=fread(stu, sizeof(stu_t), 1, f2);
    fwrite(stu, sizeof(stu_t), 1, fout);
  }



  free(stu);
  fclose(fout);
  fclose(f1);
  fclose(f2);
  return 0;
}


  /*
void readDat(FILE* fin, stu_t stu[]){
  int i;
  fread(stu, sizeof(stu_t), 20, fin);
  for(i=0; i<20; i++){
    printf("%4d%11d%-30s%d\n", stu[i].num, stu[i].id, stu[i].name, stu[i].grade);
  }
}
  */
