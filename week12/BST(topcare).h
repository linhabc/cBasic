#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
  int id;
  char name[MAX];
  int money;
  int tp;// thuc pham
  int dt;// dien tu
  int mm;// may mac
}keyType;

typedef struct node{
  keyType key;
  struct node *left, *right;
}nodeType;

typedef nodeType* tree;

tree search(char x[], tree root){
  if(root == NULL)
     return NULL;
  else if (strcmp(root->key.name, x) == 0)
    return root;
  else if (strcmp(root->key.name, x) < 0)
    return search(x, root->right);
  else
    return search(x, root->left);
}

void insertNode(keyType *x, tree *root){
  if(*root == NULL){
    *root = (nodeType*)malloc(sizeof(nodeType));
    (*root)->key.id = x->id;
    strcpy((*root)->key.name, x->name);
    (*root)->key.money = x->money;
    (*root)->key.tp=x->tp;
    (*root)->key.dt=x->dt;
    (*root)->key.mm=x->mm;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  else if(x->money < (*root)->key.money){
    insertNode(x,&(*root)->left);
  }
  else if(x->money > (*root)->key.money){
    insertNode(x,&(*root)->right);
  }
}

void printInOrder(tree root){
  if(root != NULL){
    printInOrder(root->left);
    printf("%d  %12s %d %d %d %d\n", root->key.id, root->key.name, root->key.tp, root->key.dt, root->key.mm);
    printInOrder(root->right);
  }
}
/*
void printPostOrder(tree root){
  if(root != NULL){
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d  %12s %d %d %d %d", root->key->id, root->key->name, root->key->tp, root->key->dt, root->key->mm);
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
*/
