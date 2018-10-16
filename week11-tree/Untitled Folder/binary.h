#include <string.h>

typedef struct {
  int id;
  char tel[10];
  char email[30];
  char name[30];
} contact;

typedef contact elementtype;

struct Node{
  elementtype *item;
  struct Node *left;
  struct Node *right;
};

typedef struct Node treeNode;

treeNode* makeNode(elementtype *item)
{
  treeNode* newNode = NULL;
  newNode = (treeNode*)malloc(sizeof(treeNode));

  if (newNode == NULL){
    printf("Allocated fail \n");
  }
  else {
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->item = item;
  }
  return newNode;
}

void freeTree(treeNode *tree){
  if (tree == NULL) return;
  freeTree(tree->left);
  freeTree(tree->right);
  free(tree);
  return;
}

treeNode *insert(treeNode *tree,elementtype *item){
  treeNode *newNode, *temp;

  newNode = makeNode(item);
  if (tree == NULL) return newNode;
  else {
    temp = tree;
    if (strcmp(item->email,temp->item->email) < 0){
      while (temp->left != NULL){
	temp = temp->left;
      }
      temp->left = newNode;
    }
    else if (strcmp(item->email,temp->item->email) > 0){
      while (temp->right != NULL){
	temp = temp->right;
      }
      temp->right = newNode;
    }
  }
  return tree;
}

void printNode(treeNode *node){
  printf("%d %-10s %-30s %-20s",node->item->id,node->item->tel,node->item->email,node->item->name);
}

void printInorder(treeNode *tree){
  if (tree != NULL){
    printInorder(tree->left);
    printNode(tree);
    printInorder(tree->right);
  }
}



	
