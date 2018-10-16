#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
  char name[MAX];
}keyType;

typedef struct node{
  keyType key;
  struct node *left, *right;
}nodeType;

typedef nodeType* tree;

int compareName(char name1[], char name2[]){
  int l1 = strlen(name1);
  int l2 = strlen(name2);
  int count1=0, count2=0;
  int check=0;
  int i,j=0;
  //count numbers of space->number of words
  for(i=0; i<l1; i++){
    if(name1[i] == ' '){
      count1++;
    }
  }
  for(i=0; i<l2; i++){
    if(name2[i] == ' '){
      count2++;
    }
  }
  //reverse name by words
  char r1[MAX];
  char r2[MAX];
  
  while(count1 >= 0){
    for(i=0; i<l1; i++){
      if(name1[i] == ' '){
        check++;
        i++;
      }
      if(check == count1){
	while(name1[i] != ' ' && name1[i] != '\0'){
	  //printf("%c \n", name[i]);
	  r1[j] = name1[i];
	  j++;
	  i++;
	}
	count1--;
	check = 0;
	//printf("%d \n", count);
	break;
      }
    }
  }
  check = 0,j=0;
  
  while(count2 >= 0){
    for(i=0; i<l2; i++){
      if(name2[i] == ' '){
        check++;
        i++;
      }
      if(check == count2){
	while(name2[i] != ' ' && name2[i] != '\0'){
	  //printf("%c \n", name[i]);
	  r2[j] = name2[i];
	  j++;
	  i++;
	}
	count2--;
	check = 0;
	//printf("%d \n", count);
	break;
      }
    }
  }
  return strcmp(r1, r2);
}

tree Search(tree root, char x[]){
  if(root != NULL){
    if (compareName(root->key.name, x) == 0)
    return root;
  else if (compareName(root->key.name, x) < 0)
    return Search(root->right, x);
  else if (compareName(root->key.name, x) > 0)
    return Search(root->left, x);
  }
  else
    printf("NULL\n");
    return NULL;
}

void insertNode(keyType *x, tree *root){
  if(*root == NULL){
    *root = (nodeType*)malloc(sizeof(nodeType));
    strcpy((*root)->key.name, x->name);
    (*root)->left = NULL;
    (*root)->right = NULL;
    //printf("%s \n", (*root)->key.name);
  }
  else if( compareName(x->name, (*root)->key.name) < 0){
    //printf("l\n");
    insertNode(x, &(*root)->left);
  }
  else if(compareName(x->name, (*root)->key.name) > 0){
    //printf("r\n");
    insertNode(x, &(*root)->right);
  }
}

void printInOrder(tree root){
  if(root != NULL){
    printInOrder(root->left);
    printf("%s\n", root->key.name);
    printInOrder(root->right);
  }
}

tree findMin(tree root){
  if(root==NULL){
    return NULL;
  }
  else if(root->left == NULL)
    return root;
  else findMin(root->left);
}
/*
tree findMax(tree root){
  if(root==NULL){
    return NULL;
  }
  else if(root->right == NULL)
    return root;
  else findMin(root->right);
}

keyType deleteMin(tree *root){
  keyType k;
  if((*root)->left == NULL){
    k = (*root)->key;
    *root = (*root)->right;
    return k;
  }
  else return deleteMin(&(*root)->left);
}

void deleteNode(keyType x, tree *root){
  if(root != NULL){
    if(x < (*root)->key)
      deleteNode(x, &(*root)->left);
    else if(x > (*root)->key)
      deleteNode(x, &(*root)->right);
    else if((*root)-> left == NULL && (*root)->right == NULL)
      *root = NULL;
    else if((*root)->left == NULL)
      *root = (*root)->right;
    else if((*root)->right == NULL)
      *root = (*root)->left;
    else
      (*root)->key = deleteMin(&(*root)->right);
  }
}

void printPostOrder(tree root){
  if(root != NULL){
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%s ", root->key.name);
  }
}
*/

/*
char *reverseName(char name[]){
  int l = strlen(name);
  int check=0,count=0;
  int i,j=0;
  //count numbers of space->number of words
  for(i=0; i<l; i++){
    if(name[i] == ' '){
      count++;
    }
    //printf("%c \n", name[i]);
  }

  static char r[MAX];
  while(count >= 0){
    for(i=0; i<l; i++){
      if(name[i] == ' '){
        check++;
        i++;
      }
      if(check == count){
	  while(name[i] != ' ' && name[i] != '\0'){
	  //printf("%c \n", name[i]);
	  r[j] = name[i];
	  j++;
      i++;
	}
	count--;
	check = 0;
	//printf("%d \n", count);
	break;
      }
    }
  }

  return r;
}

int compareName(char name1[], char name2[]){
  char *r1 = reverseName(name1);
  char *r2 = reverseName(name2);
  printf("%s %s\n", r1, r2);
  int i =  strcmp(r1, r2);
  printf("%d \n", i);
  return i;
}

*/