#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //using _fpurge(stdin);

typedef struct {
  int hour;
  int minute;
  int client; //read nmber of client
  
}elementtype;

typedef struct node node;
struct node{
  elementtype *element;
  node* next;
};

typedef struct{
  node* head;
  node* rear;
} queue;


int isEmpty(queue *q){
  return (q->head==NULL);
}

void init_queue(queue *q){
  q->head = NULL;
  q->rear= NULL;
  return;
}

node *makeNewNode(elementtype* addr){
  node *new = (node*)malloc(sizeof(node));
  new->element = addr;
  new->next=NULL;
  return new;
}

elementtype* readNode(){
  elementtype *addr=(elementtype*)malloc(sizeof(elementtype));
  printf("Enter time (hh:mm): ");
  scanf(" %d:%d", &addr->hour,&addr->minute);
  printf("Enter number of client: ");
  scanf(" %d", &addr->client);
  return addr;
}
/*
void displayNode(node *addr){
  if(addr==NULL){
    printf("Error NULL pointer.\n");
    return;
  }
  printf("Time: %d:%d   Client: %d", addr->hour,addr->minute,addr->client);
  return;
}
*/
void enQueue(elementtype *addr, queue *q){
  node* new = makeNewNode(addr);
  if(q->rear!=NULL){
    q->rear->next = new;
    q->rear = q->rear->next;
  }else{
    q->rear = new;
    q->head = new;
  }
}

void deQueue(queue *q){
  if(isEmpty(q)){
    printf("Queue is empty.\n");
    exit(0);
  }
  node* tmp = q->head;
  q->head = q->head->next;
  free(tmp);
  return;
}

void freelist(queue *q){
  node *to_free;
  to_free = q->head;
  while(to_free!=NULL){
    q->head = q->head->next;
    free(to_free);
    to_free = q->head;
  }
}

elementtype seeHead(queue *q){
  elementtype value;
  value = *q->head->element;
  return value;
}
