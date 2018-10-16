#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 150

typedef struct{
  char word[MAX];
  int count;
}keyType;

typedef struct node{
  keyType key;
  struct node *left, *right;
}nodeType;

typedef nodeType* tree;

void insertNode(char x[], tree *root){
  if(*root == NULL){
    *root = (nodeType*)malloc(sizeof(nodeType));

    (*root)->key.count = 1;
    strcpy((*root)->key.word, x);

    (*root)->left = NULL;
    (*root)->right = NULL;
    //printf("%s \n", (*root)->key.word);
  }
  else if(strcmp(x , (*root)->key.word) <0){
    insertNode(x,&(*root)->left);
  }
  else if(strcmp(x , (*root)->key.word) > 0){
    insertNode(x,&(*root)->right);
  }
  else if(strcmp(x , (*root)->key.word) == 0){
    (*root)->key.count++;
  }
}

void printInOrder(tree root){
  if(root != NULL){
    printInOrder(root->left);
    printf("%s %d \n", root->key.word, root->key.count);
    printInOrder(root->right);
  }
}
/*
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
    printf("%d ", root->key);
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

*/
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
