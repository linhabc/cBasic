#include <stdio.h>
#include <stdlib.h>
#include "BST(US).h"
#include <time.h>

int main(){
  srand(time(NULL));
  char get[MAX];
  keyType team[16];
  int n1[8], n2[4], n3[2], n4;
  int i=0;
  FILE* f = fopen("USopen.txt", "r");
  while( !feof(f) ){
    fscanf(f, "%s ", team[i].name);
    printf("%s\n", team[i].name);
    i++;
  }

  n4 = rand()%15;

  tree root=(nodeType*)malloc(sizeof(nodeType));
  root->key = &team[n4];
  root->left = &team[
  return 0;
}

