#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

struct book{
  char name[MAX];
  int phone;
  char email[MAX];
};

typedef struct book keyType;

typedef struct node{
  keyType *key;
  struct node *left;
  struct node *right;
}nodeType;

typedef struct node* tree;

tree search(char email[], tree root){
  if(root == NULL)
     return NULL;
  else if (strcmp(root->key->email, email)==0)
    return root;
  else if (strcmp(root->key->email, email) < 0)
    return search(email, root->right);
  else
    return search(email, root->left);
}

tree insertNode(keyType *x, tree root){
  if(root == NULL){
    root = (nodeType*)malloc(sizeof(nodeType));
    root->key = x;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  if(strcmp(root->key->email, x->email) > 0){
   root->left = insertNode(x, root->left);
  }
  else if(strcmp(root->key->email, x->email) < 0){
    root->right = insertNode(x, root->right);
  }
  return root;
}

void printInOrder(tree root){
  if(root != NULL){
    printInOrder(root->left);
    printf("%-20s%23s%10d\n", root->key->email, root->key->name, root->key->phone);
    printInOrder(root->right);
  }
}
void printPostOrder(tree root){
  if(root != NULL){
    printPostOrder(root->left);
    printPostOrder(root->right);printPostOrder
    printf("%-20s%23s%10d\n", root->key->email, root->key->name, root->key->phone);
  }
}

void output(FILE* fout, tree root){
  if(root!=NULL){
    output(fout,root->left);
    fwrite(root->key, 1, sizeof(keyType), fout);
    output(fout,root->right);
  }
}


keyType *deleteMin(tree *root){
  keyType *k;
  if((*root)->left == NULL){
    k = (*root)->key;
    *root = (*root)->right;
    return k;
  }
  else return deleteMin(&(*root)->left);
}

void deleteNode(int x, tree *root){
  if(*root != NULL){
    if(x < (*root)->key->phone)
      deleteNode(x, &(*root)->left);
    else if(x > (*root)->key->phone)
      deleteNode(x, &(*root)->right);
    else if(x == (*root)->key->phone){
      if((*root)->left == NULL && (*root)->right == NULL)
	*root = NULL;
      else if((*root)->left == NULL)
	*root = (*root)->right;
      else if((*root)->right == NULL)
	*root = (*root)->left;
      else
	(*root)->key = deleteMin(&(*root)->right);
    }
  }
}

/*
nodeType makeNewNode(keyType x){
  nodeType new;
  new.key = x;
  new.left = NULL;
  new.right = NULL;
  return new;
}
*/
