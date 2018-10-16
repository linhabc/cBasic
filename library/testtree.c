#include "BST.h"

int main(){
  tree root,tmp;
  root = (nodeType*)malloc(sizeof(nodeType));
  root=NULL;
  tmp = (nodeType*)malloc(sizeof(nodeType));
  insertNode(3, &root);
  insertNode(6, &root);
  insertNode(2, &root);
  insertNode(9, &root);
  insertNode(1, &root);
  insertNode(5, &root);
  insertNode(7, &root);
  
  
  print2D(root);
  printInOrder(root);
  printf("\n");
  findGreater(3, root);
  printf("\n");
  deleteNode(9, &root);
  //printInOrder(root);
  print2D(root);
  //printf("\n");
  int n= numberNode(&root);
   printf("Number of Node: %d\n", n);
  tmp=findMin(root);
  printf("Min value: %d\n", tmp->key);
  tmp=findMax(root);
  printf("Max value: %d\n", tmp->key);
  return 0;
}
