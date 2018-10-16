#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(){
  keyType book1[10];
  char e[MAX];
  FILE*fin = fopen("phone.txt", "r");
  FILE* fout = fopen("ADDRBOOK.dat", "wb");
  int i,n,x;
  
  do{
    printf("MENU\n");
    printf("1.sort address book by email.\n");
    printf("2.search email.\n");
    printf("3.delete node.\n");
    printf("4.output file and exit.\n");
    do{
      printf("ENTER: ");
      scanf(" %d", &n);
    }while(n<1 || n>4);

    switch(n){
    case 1:
      printf("BEFOR\n");
      for(i=0;i<10;i++){
	fscanf(fin, " %d", &book1[i].phone);
	fgets(book1[i].name, 23, fin);
	fscanf(fin, " %s", book1[i].email);
	printf("%14d %19s %s\n", book1[i].phone, book1[i].name, book1[i].email);
      }

      tree root = (nodeType*)malloc(sizeof(nodeType));
      root->key = book1+0;
      root->left = NULL;
      root->right = NULL;
      
      for(i=1;i<10;i++){
	insertNode(book1+i, root);
	//printf("%10d %23s %s\n", book1[i].phone, book1[i].name, book1[i].email);
	//printf("%20s%23s%10d\n", root->key->email, root->key->name, root->key->phone);
      }
      printf("AFTER.\n");
      printInOrder(root);
      break;

    case 2:
      printf("Enter email to search: ");
      scanf(" %s", e);
  
      tree p = (nodeType*)malloc(sizeof(nodeType));
      p = search(e, root);
      printf("%20s%23s%10d\n", p->key->email, p->key->name, p->key->phone);
      break;

    case 3:
      printf("Enter phone to delete: ");
      scanf(" %d", &x);
      deleteNode(x, &root);
      printInOrder(root);
      break;
      
    case 4:
      /*
      for(i=0;i<10;i++){
	fwrite(book1+i, 1, sizeof(keyType), fout);
      }
      */
      output(fout, root);
      printf("DONE\n");
      break;
    }
  }while(n!=4);
  fclose(fout);
  fclose(fin);
  return 0;
}
