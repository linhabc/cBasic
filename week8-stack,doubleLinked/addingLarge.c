#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackLinked.h"
#define  MAX 50


int main(){
  int i;
  
  stack stack1, stack2, stack3;
  init_stack(&stack1);
  init_stack(&stack2);
  init_stack(&stack3);
  
  char n1[MAX];
  char n2[MAX];
  printf("Enter first number: ");
  scanf(" %s", n1);
  printf("Enter second number: ");
  scanf(" %s", n2);
  int l1,l2;
  l1=strlen(n1);
  l2=strlen(n2);
  if(l1<l2){ // l1<l2 change n1->n2 and vice versa
    char n3[MAX];
    strcpy(n3,n1);
    strcpy(n1,n2);
    strcpy(n2,n3);
    int l3;
    l3=l1;
    l1=l2;
    l2=l3;
  }
  
  for(i=0; i<l1; i++){
    push((n1+i), &stack1);
    //printf("%c ", stack1.root->data);
  }

  for(i=0; i<l2; i++){
    push((n2+i), &stack2);
    //printf("%c ", stack2.root->data);
  }

  char a1,a2;
  char A3;
  int A1,A2; 
  int a3, spare=0;
  printf("sum of number1 and number 2 is: ");
  
  if(l1==l2){
    for(i=1; i<=l2; i++){
      a1=pop(&stack1);
      a2=pop(&stack2);
      A1 = a1 -'0'; // convert to int
      A2 = a2 - '0';
      a3=A1+A2+spare;
      if(a3>=10){
	a3=a3-10;
	spare=1;
      }else if(a3<10){
	spare=0;
      }
      A3 = a3 +'0'; // convert to char
      push(&A3, &stack3);
    }
    if(spare==1){
      l1 += 1; // length increase 1
      A3 = 1 +'0';
      push(&A3, &stack3);
    }
  }
   
  else if(l1>l2){
    for(i=1; i<=l2; i++){
      a1=pop(&stack1);
      a2=pop(&stack2);
      A1 = a1 -'0';
      A2 = a2 - '0';
      a3=A1+A2+spare;
      if(a3>=10){
	a3=a3-10;
	spare=1;
      }else if(a3<10){
	spare=0;
      }
      A3 = a3 +'0';
      push(&A3, &stack3);  
    }
    for(i=l2+1; i<=l1; i++){
      a1=pop(&stack1);
      A1 = a1 -'0';
      a3=A1+spare;
      if(a3>10){
	a3=a3-10;
	spare=1;
      }else if(a3<10){
	spare=0;
      }
      A3 = a3 +'0';
      push(&A3, &stack3);
    }
    if(spare==1){
      l1 += 1;
      A3 = 1 +'0';
      push(&A3, &stack3);
    }
  } 
 
  
  for(i=1;i<=l1;i++){
    A3 = pop(&stack3);
   printf("%c", A3);
  }
  printf("\n");

  freelist(&stack1);
  freelist(&stack2);
  freelist(&stack3);
  return 0;
}
