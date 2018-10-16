#include "BST(topcare).h"

void readTxt(char fin[], keyType client[]);

int main(){
  int i;
  keyType client[10];
  tree root=NULL;
  readTxt("client.txt", client);

  for(i=0; i<10; i++){
    insertNode(client+i, &root);
  }
  printf("Order by money spent.\n");
  printInOrder(root);
  return 0;
}

void readTxt(char fin[], keyType client[]){

  FILE* f = fopen(fin, "r");
  
  for(int i=0;i<10;i++){
    fscanf(f, "%d %12s %d %d %d %d", &(client+i)->id, (client+i)->name, &(client+i)->money, &(client+i)->tp, &(client+i)->dt, &(client+i)->mm);
  }
}
