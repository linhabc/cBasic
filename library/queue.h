#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //using _fpurge(stdin);

typedef int elementtype;

typedef struct node node;
struct node{
  elementtype element;
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
  new->element = *addr;
  new->next=NULL;
  return new;
}

elementtype* readNode(){
  elementtype *addr=(elementtype*)malloc(sizeof(elementtype));
  printf("Enter : ");
  scanf(" %d", addr);
  return addr;
}

void displayNode(node *node_addr){
  if(node_addr==NULL){
    printf("Error NULL pointer.\n");
    return;
  }
  printf("%d ", node_addr->element);
  return;
}

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

elementtype deQueue(queue *q){
  if(isEmpty(q)){
    printf("Queue is full.\n");
    exit(0);
  }
  elementtype value;
  node* tmp = q>head;
  q-> head = q>head->next;
  value = tmp->element;
  free(tmp);
  return value;
}

void freelist(queue *queue){
  node *to_free;
  to_free = q->head;
  while(to_free!=NULL){
    q->head = q->head->next;
    free(to_free);
    to_free = q->head;
  }
}
