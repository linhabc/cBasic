#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
#define COUNT 10

typedef int keyType;

typedef struct node{
  keyType key;
  struct node *left, *right;
}nodeType;

typedef nodeType* tree;

void makeNull(tree *root){
  *root = NULL;
}

int emptyTree(tree *root){
  return *root==NULL;
}

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

void insertNode(keyType x, tree *root){
  if(*root == NULL){
    *root = (nodeType*)malloc(sizeof(nodeType));
    (*root)->key = x;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  else if(x < (*root)->key){
    insertNode(x,&(*root)->left);
  }
  else if(x > (*root)->key){
    insertNode(x,&(*root)->right);
  }
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

void printInOrder(tree root){
  if(root != NULL){
    printInOrder(root->left);
    printf("%d ", root->key);
    printInOrder(root->right);
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
  else findMax(root->right);
}

int numberNode(tree *T){
  if(emptyTree(T))
    return 0;
  else
    return 1 + numberNode(&(*T)->right) + numberNode(&(*T)->left);
}

void print2DUtil(tree root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
 
    // Process left child
    print2DUtil(root->left, space);
}

void print2D(tree root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}

void findLesser(int x, tree root){
  nodeType *p = root;
  if(x <= p->key){
    if(p->left != NULL)
      findLesser(x, root->left);
      
  }
  else if(x > p->key){
    printf("%d ", p->key);
    if(p->left != NULL)
      findLesser(x,p->left);

    if(p->right != NULL)
      findLesser(x,p->right);
  }
}

void findGreater(int x, tree root){
  nodeType *p = root;
  if(x >= p->key){
    if(p->right != NULL)
      findGreater(x, root->right);
      
  }
  else if(x < p->key){
    printf("%d ", p->key);
    if(p->left != NULL)
      findGreater(x,p->left);

    if(p->right != NULL)
      findGreater(x,p->right);
  }
}
