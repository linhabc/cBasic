#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h> //using _fpurge(stdin);

typedef int elementtype;

typedef struct nodeq nodeq;
struct nodeq{
  elementtype element;
  nodeq* next;
};

typedef struct{
  nodeq* head;
  nodeq* rear;
} queue;


int isEmpty(queue *q){
  return (q->head==NULL);
}

void init_queue(queue *q){
  q->head = NULL;
  q->rear = NULL;
  return;
}

nodeq *makeNewNodeq(elementtype* addr){
  nodeq *new = (nodeq*)malloc(sizeof(nodeq));
  new->element = *addr;
  new->next=NULL;
  return new;
}

void enQueue(elementtype *addr, queue *q){
  nodeq* new = makeNewNodeq(addr);
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
    //printf("Queue is empty.\n");
    return -1;
  }
  elementtype value;
  nodeq* tmp = q->head;
  q->head = q->head->next;
  value = tmp->element;
  free(tmp);
  return value;
}

void freelistQ(queue *q){
  nodeq *to_free;
  to_free = q->head;
  while(to_free!=NULL){
    q->head = q->head->next;
    free(to_free);
    to_free = q->head;
  }
}
