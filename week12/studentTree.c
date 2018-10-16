#include "BST(STU).h"
#define strcut_newline(str) ((str)[strlen(str) - 1] == '\n')? (str)[strlen(str) - 1] = '\0':0;


void readTxt(char file[], keyType key[]);
//int compareName(char name1[], char name2[]);


int main(){
  tree root=NULL;
  keyType stu[10];
  printf("Before sort by tree\n-----\n");
  readTxt("studentlist.txt", stu);

  for(int i=0; i<10; i++){
    //printf("%s \n", stu[i].name);
    insertNode(stu+i, &root);
  }

  printf("------\nAfter sorted\n-------\n");
  printInOrder(root);

  char name[MAX];
  tree sname=(nodeType*)malloc(sizeof(nodeType));
  do{
    printf("Enter name to search: ");
    fgets(name, MAX-1, stdin);
    strcut_newline(name);
    sname = Search(root, name);
    if(sname == NULL){
      printf("Student isn't in list.\n");
    }
    else
      printf("Student in list.\n");
    //printInOrder(root);
  }while(1);
  
  return 0;
}

void readTxt(char file[], keyType key[]){
  FILE* f = fopen(file, "r");
  if(f==NULL){
    printf("cannot open file.\n");
    return;
  }
  for(int i=0; i<10; i++){
    fgets((key+i)->name, MAX, f);
    strcut_newline((key+i)->name);
    printf("%s\n", (key+i)->name);
  }
}


