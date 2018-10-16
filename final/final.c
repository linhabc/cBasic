#include "BST.h"
#include <stdio_ext.h> //using _fpurge(stdin);
#define strcut_newline(str) ((str)[strlen(str) - 1] == '\n')? (str)[strlen(str) - 1] = '\0':0;

int countLines(char *fn);
void readTxt(char file[], tree *root);
void blockSite(char file[], tree *root2);

int main(){
  int op;
  tree root;
  makeNull(&root);
  tree root2;
  makeNull(&root2);
  
  char addr[MAX];
  tree addr_s = (nodeType*)malloc(sizeof(nodeType));

  char addr2[MAX];
  tree addr_s2 = (nodeType*)malloc(sizeof(nodeType));
  tree addr_s3 = (nodeType*)malloc(sizeof(nodeType));
  do{
    printf("\n----------------------\n");
    printf("MENU\n");
    printf("1. Reading data\n");
    printf("2. IP lookup\n");
    printf("3. Block website\n");
    printf("4. IP sort\n");
    printf("5. Exit\n");
    do{
      printf("Enter(1-5): ");
      scanf(" %d", &op);
      __fpurge(stdin);
    }while(op>5 || op<1);

    switch(op){
    case 1:
      readTxt("ip.txt", &root);
      printInOrder(root);
      break;
      
    case 2:
      printf("Enter domain name: ");
      fgets(addr, MAX-1, stdin);
      __fpurge(stdin);
      strcut_newline(addr);
      
      addr_s = search(addr, root);
      
      if(addr_s == NULL)
	printf("This site can't be reached.\n");
      else
	printf("IP: %s\n", addr_s->key.IP); 
      
      break;
	
    case 3:
      blockSite("blockedip.txt", &root2);
      printf("Enter domain name: ");
      fgets(addr2, MAX-1, stdin);
      __fpurge(stdin);
      strcut_newline(addr2);
      
      addr_s2 = search(addr2, root);
      if(addr_s2 == NULL)
	addr_s2 = search2(addr2, root);

      addr_s3 = search(addr2, root2);
      
      if(addr_s2 == NULL)
	printf("This site can't be reached.\n");
      else if(addr_s3 != NULL && addr_s2 != NULL)
	printf("This site has been blocked.\n");
      else if(addr_s3 == NULL && addr_s2 != NULL)
	printf("IP: %s\n", addr_s->key.IP); 

      break;

	/*
	case  :

	break;

      */
    }
        
  }while(op != 5);
    
  return 0;
  
}

void readTxt(char file[], tree *root){
  FILE *fin = fopen(file, "r");
  if(fin == NULL){
    printf("Cannot opened file.\n");
    return;
  }

  int n = countLines(file);

  keyType web[n];
  
  for(int i=0; i<n-1; i++){
    fscanf(fin, "%s", web[i].name);
    fscanf(fin, " %s", web[i].IP);
    //printf("%s %s\n", web[i].name, web[i].IP);
    insertNode(web[i], root);
  }

}

int countLines(char *fn){
  FILE *fp = fopen(fn, "r");
  if (fp == NULL) {
    printf("Can not open file %s\n", fn);
    return(0);
  }
  
  char ch;
  int nLines = 1;
  
  while ( !feof(fp) ) {
    ch = fgetc(fp);
    if (ch == '\n') {
      nLines ++;
    }
  }
  
  fclose(fp);
  return(nLines);
}

void blockSite(char file[], tree *root2){
  FILE* fin = fopen(file, "r");
  int n = countLines(file);

  keyType web2[n];
  
  for(int i=0; i<n-1; i++){
    fscanf(fin, "%s", web2[i].name);
    strcmp(web2[i].IP, "0");

    insertNode(web2[i], root2);
  }
  
}

