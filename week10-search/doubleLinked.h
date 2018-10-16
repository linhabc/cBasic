#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //using _fpurge(stdin);

typedef struct Ph{
  char model[10];
  int storage;
  float display;
  int prize;
}phone_t;
typedef phone_t elementtype;

typedef struct node node;
struct node{
  elementtype phone;
  node* prev;
  node* next;
};

typedef struct{
  node* head;
  node* tail;
  node* cur;
} doubleL;

// prototype functions
void init_list(doubleL *list);
node *makeNewNode(elementtype* addr);
elementtype* readNode();
void displayNode(node *node_addr);
void transversingList(doubleL *list);
void insertAtHead(elementtype *addr, doubleL *list);
void insertAfterCur(elementtype *addr, doubleL *list);
void insertAtPosition(elementtype *addr, int n, doubleL *list);
void deleteAtPosition(int n, doubleL *list);
void deleteAtHead(doubleL *list);


int isEmpty(doubleL *list){
  return (list->head==NULL);
}


void init_list(doubleL *list){
  list->head = NULL;
  list->tail= NULL;
  list->cur = NULL;
  return;
}

node *makeNewNode(elementtype* addr){
  node *new = (node*)malloc(sizeof(node));
  new->phone = *addr;
  new->next=NULL;
  new->prev=NULL;
  return new;
}
/*
elementtype* readNode(){
  elementtype *addr=(elementtype*)malloc(sizeof(elementtype));
  printf("Enter : ");
  scanf(" %d", addr);
  return addr;
}
*/
void displayNode(node *node_addr){
  if(node_addr==NULL){
    printf("Error NULL pointer.\n");
    return;
  }
  printf("%s %5d %5f %15d\n", node_addr->phone.model, node_addr->phone.storage, node_addr->phone.display, node_addr->phone.prize);
  return;
}

void transversingList(doubleL *list){
  if(list->head==NULL){
    printf("Empty list\n");
  }
  
  node *p;
  for(p=list->head;p!=NULL;p=p->next)
    displayNode(p);
  printf("\n");
  return;
}


void insertAtHead(elementtype *addr, doubleL *list){
  node* new = makeNewNode(addr);
  if(list->head==NULL){
    list->head = new;
    list->cur = list->head;
    list->tail = list->head;
    return;
  }else{
    new->next = list->head;
    list->head->prev = new;
    list->head = new;
    list->cur = list->head;
    return;
  }
}

void insertAfterCur(elementtype *addr, doubleL *list){
  node* new = makeNewNode(addr);
  if(list->head == NULL){
    list->head = new;
    list->cur = list->head;
    list->tail = list->head;
  }else if(list->cur->next == NULL){
    list->cur->next=new;
    new->prev=list->cur;
    list->cur=new;
  }else{
    new->next=list->cur->next;
    new->next->prev = new;
    list->cur->next = new;
    new->prev = list->cur;
    list->cur = list->cur->next;
  }
}

void insertAtPosition(elementtype *addr, int n, doubleL *list){
  if(n<0){
    printf("position cant be negative.\n");
    return;
  }
  node* new= makeNewNode(addr);
  node* h = list->head;
  node* c = h;
  int count=0;
  for(h;h!=NULL;h=h->next){
    if(n==0){
      insertAtHead(addr, list);
      break;
    }
    if((count)==n){
      new->next = c->next;
      new->next->prev = new;
      new->prev = c;
      c->next = new;
      c=c->next;
      break;
      break;
    }
    c=h;
    count++;
  }
}

void deleteAtHead(doubleL *list){
  if(list->head==NULL) return;
  node* tmp = list->head;
  list->head = list->head->next;
  free(tmp);
  list->cur = list->head;
  return;
}

void deleteAtPosition(int n, doubleL *list){
  node* tmp = list->head;
  if(n==0){
    list->head = tmp->next;
    free(tmp);
    return;
  }
  for(int i=1;i<n;i++){
    tmp = tmp->next;
  }
  node* tmp1 = tmp->prev;
  node* tmp2 = tmp->next;
  tmp1->next = tmp2;
  tmp2->prev = tmp1;
  free(tmp);
}

