#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct KT{
  char name[MAX];
   int point;
}keyType;

typedef struct node{
  keyType *key;
  struct node *left, *right;
}nodeType;

typedef nodeType* tree;
/*
tree search(keyType x, tree root){
  if(root == NULL)
     return NULL;
  else if (root->key == x)
    return root;
  else if (root->key < x)
    return search(x, root->right);
  else
    return search(x, root->left);
}
*/
tree insertNode(keyType *x, tree root){
  if(root == NULL){
    root = (nodeType*)malloc(sizeof(nodeType));
    root->key = x;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  else if(x->point < root->key->point){
    root->left =  insertNode(x,root->left);
  }
  else if(x->point > root->key->point){
    root->right = insertNode(x,root->right);
  }
  return root;
}

void printInOrder(tree root){
  if(root != NULL){
    printInOrder(root->left);
    printf("%s ", root->key->name);
    printInOrder(root->right);
  }
}

/*
key deleteMin(tree root){
  key k;
  if(root->left == NULL){
    k = root->key;
    root = root->right;
    return k;
  }
  else return deleteMin(root->left);
}

void deleteNode(key x, tree root){
  if(root != NULL){
    if(x < root->key)
      deleteNode(x, root->left);
    else if(x > root->key)
      deleteNOde(x, root->right);
    else if(root-> left == NULL && root->right == NULL)
      root = NULL;
    else if(root->left == NULL)
      root = root->right;
    else if(root->right == NULL)
      root = root->left;
    else
      root->key = deleteMin(root->right);
  }
}
*/
