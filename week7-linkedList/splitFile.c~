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

void readDat(FILE* fin, stu_t stu[]);
node_addr *makeNewNode(stu_t *stu);
void insertAfterCur();
void freeList();
  
int main(int argc, char* argv[]){
  if(argc != 5){
    printf("Enter 5 arg, including name\n");
    return 1;
  }

  int n=atoi(argv[2]);
  
  FILE* fin= fopen(argv[1], "rb");
  FILE* f1= fopen(argv[3], "w+b");
  FILE* f2= fopen(argv[4], "w+b");
  if(fin==NULL || f1==NULL || f2==NULL){
    printf("Cannot loaded file,\n");
    return 1;
  }

  stu_t *stu;
  stu=(stu_t *)malloc(20*sizeof(stu_t));
  if(stu==NULL){
    printf("Allocated memory failed\n");
    return 1;
  }

  readDat(fin,stu);

  
  node_addr *p=root;
  
  for(int i=0;i<20;i++){
    p=makeNewNode(stu+i);
    p=p->next;
  }

  fwrite(stu,sizeof(stu_t),n,f1);
  for(int i=n; i<20; i++){
    fwrite(stu+i,sizeof(stu_t),1,f2);
  }




  freeList();
  free(stu);
  fclose(fin);
  fclose(f1);
  fclose(f2);
  return 0;
}


void readDat(FILE* fin, stu_t stu[]){
  int i;
  fread(stu, sizeof(stu_t), 20, fin);
  for(i=0; i<20; i++){
    printf("%4d%11d%-30s%d\n", stu[i].num, stu[i].id, stu[i].name, stu[i].grade);
  }
}

node_addr *makeNewNode(stu_t *stu){
  node_addr* new=(node_addr*)malloc(sizeof(node_addr));
  new->student = *stu;
  new->next = NULL;
  return new;
}

void freeList(){
  node_addr *to_free;
  to_free = root;
  while(to_free!=NULL){
    root = root->next;
    free(to_free);
    to_free=root;
  }
}
/*
void insertAfterCur(){
  address_t addr=readNode();
  node_addr *new = makeNewNode(addr);
  
  if(root==NULL){
    root = new;
    cur = root;
  }else{
    new->next = cur->next;
    cur->next = new;
    //prev=cur;
    cur = cur->next;
  }
}
*/
