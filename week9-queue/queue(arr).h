#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int elementType;
typedef struct {
  elementType element[MAX];
  int front, rear;
}queue;

void init_queue(queue *q){
  q->front = 0;
  q->rear = 0;
}

int isEmpty(queue *q){
  return q->front==0;
}

int isFull(queue *q){
  return (q->rear - q->front +1) % MAX == 0;
}

void deQueue(queue *q){
  if(!isEmpty(q)){
    if(q-front == q->rear) init_queue(q);
    else q->front == (q->front+1) % MAX;
  }
  else printf("Queue is empty.\n"):
}

void enqueue(elementType x, queue *q){
  if(!isFull(q)){
    if(isEmpty(q)) q->front = 0;
    q->rear = (q->rear) % MAX;
    q->element[q->rear] = x;
  }
  else printf("Queue is full\n");
}
