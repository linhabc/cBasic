#include "BST(STU).h"
#define strcut_newline(str) ((str)[strlen(str) - 1] == '\n')? (str)[strlen(str) - 1] = '\0':0;


void readTxt(char file[], keyType key[]);
//int compareName(char name1[], char name2[]);


int main(){
  keyType stu[10];
  printf("Before sort by heap\n-----\n");
  readTxt("studentlist.txt", stu);

  heapSort(stu, 10);

  printf("------\nAfter sorted\n-------\n");
  for(int i=0; i<10; i++){
    printf("%s\n", (stu+i)->name);
  }
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


