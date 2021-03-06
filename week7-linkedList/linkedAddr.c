#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

//declaration of address list
typedef struct address{
  char name[20];
  char tel[11];
  char email[25];
}address_t;

struct list_el{
  address_t addr;
  struct list_el *next;
};//node_addr

typedef struct list_el node_addr;

node_addr *root, *cur;

//prototype function
node_addr *makeNewNode(address_t addr1);
address_t readNode();
void displayNode(node_addr *node);
void insertAtHead(address_t addr);
void traversingList();
void freeList();
void insertBeforeCur(address_t addr);
void insertAfterCur(address_t addr);
node_addr *insertAtPosition(address_t addr, int n);
void delete(int n);
void deleteAtHead();
void deleteCur();
node_addr* reverseList();

int main(){
  address_t tmp=readNode();
  root=makeNewNode(tmp);
  cur=root;
  printf("\nTraversing List:\n");
  traversingList();

  address_t tmp1 = readNode();
  root = makeNewNode(tmp1);
  
  address_t tmp2 = readNode();
  insertAtHead(tmp2);
  
  address_t tmp3 = readNode();
  insertAfterCur(tmp3);
  
  address_t tmp4 = readNode();
  insertBeforeCur(tmp4);
  
  traversingList();
  delete(1);
  traversingList();
  deleteCur();
  traversingList();
  deleteAtHead();
  traversingList();

  freeList();
  traversingList();
  return 0;
}

node_addr *makeNewNode(address_t addr1){
  node_addr* new=(node_addr*)malloc(sizeof(node_addr));
  new->addr = addr1;
  new->next = NULL;
  return new;
}

address_t readNode(){
  address_t addr;
  __fpurge(stdin);
  printf("Enter name: ");
  fgets(addr.name, 19, stdin);
  addr.name[strlen(addr.name)-1]='\0';
  printf("Enter tellephone: ");
  scanf(" %s", addr.tel);
  printf("Enter email: "); 
  scanf(" %s", addr.email);
  return addr;
}

void displayNode(node_addr *node){
  if(node==NULL){
    printf("Error NUll Pointer\n");
    return;
  }
  address_t tmp = node->addr;
  printf("%-20s\t%-15s\t%-30s %p\n", tmp.name, tmp.tel, tmp.email, node->next);

}

void insertAtHead(address_t addr){
  node_addr* new = makeNewNode(addr);
  new->next = root;
  root=new;
  cur=root;
}

void traversingList(){
  node_addr *p;
  for(p=root; p!=NULL; p=p->next){
    displayNode(p);
  }
}

void insertAfterCur(address_t addr){
  node_addr *new = makeNewNode(addr);
  
  if(root==NULL){
    root = new;
    cur = root;
  }else{
    new->next = cur->next;
    cur->next = new;
    //prev=cur;
    cur = cur->next;
  }
}

void insertBeforeCur(address_t addr){
  node_addr *new = makeNewNode(addr);
  node_addr *prev=(node_addr*)malloc(sizeof(node_addr));
  if(root==NULL){
    root=new;
    cur = root;
  }else{
    for(prev=root;prev!=NULL;prev=prev->next){
      if(prev->next == cur){
	break;
      }
    }
    new->next=cur;
    prev->next=new;
    cur=new;
  }
}

void freeList(){
  node_addr *to_free;
  to_free = root;
  while(to_free!=NULL){
    root = root->next;
    free(to_free);
    to_free=root;
  }
}

node_addr *insertAtPosition(address_t addr, int n){
  node_addr * new= makeNewNode(addr);
  node_addr* p=root;
  int count=0;
  for(p;p!=NULL;p=p->next){
    if(count==n){
      new->next = cur->next;
      cur->next = new;
      //prev=cur;
      cur = cur->next;
      break;
    }
    cur=p;
    count++;
  }
}

void delete(int n){
  node_addr* tmp = root;
  if(n==1){
    root = tmp->next;
    free(tmp);
    return;
  }
  for(int i=0;i<n-2;i++){
    tmp = tmp->next;
   }
  node_addr* tmp1 = tmp->next;
  tmp->next = tmp1->next;
  free(tmp1);
}

void deleteAtHead(){
  if(root==NULL) return;
  node_addr* p=root;
  root=root->next;
  free(p);
  cur=root;
}

void deleteCur(){
  node_addr* prev=root;
  if(cur==NULL) return;
  if(cur==root){
    deleteAtHead();
  }
  else{
    for(prev;prev!=NULL;prev=prev->next){
      if(prev->next==cur){
	break;
      }
    }
    prev->next=cur->next;
    free(cur);
    cur=prev->next;
  }
}

node_addr* reverseList(){
  node_addr *cur, *prev;
  cur = prev = NULL;
  while(root != NULL){
    cur = root;
    root = root->next;
    cur->next = prev;
    prev=cur;
  }
  return prev;
}
