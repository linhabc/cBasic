#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef char elType;

typedef struct nodeType{
  elType element[MAX];
  struct nodeType *left, *right;
}node_type;

typedef node_type tree;

void makeNull(tree *T){
  T = NULL;
}

int EmptyTree(tree *T){
  return T==NULL;
}

tree *leftChild(tree *n){
  if(n != NULL)
    return n->left;
  else return NULL;
}

tree *rightChild(tree *n){
  if(n != NULL)
    return n->right;
  else return NULL;
}

node_type *create_node(elType Data[]){
  node_type *n;
  n = (node_type*)malloc(sizeof(node_type));
  if(n!=NULL){
    strcpy(n->element, Data);
    n->left = NULL;
    n->right = NULL;
  }
  return n;
}

int isLeaf(tree *n){
  if(n!=NULL)
    return (leftChild(n)==NULL) && (rightChild(n)==NULL);
  else return -1;
}

int numberNode(tree *T){
  if(EmptyTree(T)) return 0;
  else return 1 + numberNode(leftChild(T)) + numberNode(rightChild(T));
}

tree *createFrom2(elType *v, tree *l, tree *r){
  static tree *N;
  N = (tree*)malloc(sizeof(tree));
  strcpy(N->element, v);
  N->left = l;
  N->right = r;
  return N;
}

tree *addLeft(tree *T, elType *data){
  node_type *n = create_node(data);
  if(n == NULL) return NULL;
  if(T == NULL)
    T = n;
  else {
    node_type *l = T;
    while(l->left != NULL)
      l=l->left;
    l->left = n;
  }
  return n;
}

tree *addRight(tree *T, elType *data){
  node_type *n = create_node(data);
  if(n == NULL) return NULL;
  if(T == NULL)
    T = n;
  else {
    node_type *r = T;
    while(r->right != NULL)
      r=r->right;
    r->right = n;
  }
  return n;
}
