#include <stdio.h>
#include <stdlib.h>
#include "stackLinked.h"
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "queue(pf).h"
#define MAX 50

void getInfix(char exp[]);
int isOp(char op);
void convertInToPost(char exp[], queue *queue1);
int precedence(char op);
int claculate(queue *queue1);

int main(){
  int n;
  char exp[MAX],c;
  queue queue1;
  init_queue(&queue1);
  
  do{
    printf("\n- - - - -\n");
    printf("MENU\n");
    printf("1.Enter expression.\n");
    printf("2.Convert to postfix.\n");
    printf("3.Calculate.\n");
    printf("4.Exit.\n");
    do{
      printf("Enter(1->4): ");
      scanf(" %d", &n);
    }while(n>4 || n<1);

    switch(n){

    case 1:
      c = getchar();
      getInfix(exp);
      break;

    case 2:
      convertInToPost(exp,&queue1);
      break;

    case 3:
      claculate(&queue1);
      break;
    }

  }while(n!=4);

  freelistQ(&queue1);
  return 0;
}

void getInfix(char exp[]){
  printf("Enter infix expression: ");
  fgets(exp, 99, stdin);

}

int isOp(char op){
  if(op == '+' || op == '-' || op == '*' || op == '/')
    return 1;
  return 0;
}

void convertInToPost(char exp[], queue *queue1){
  printf("Postfix expression: ");
  stack stack2;
  init_stack(&stack2);
  int num=0; // get a number with more than 1 digit
  int co=1; // coefficient 10, 100, 1000
  int i, j, c;
  char c1;
  int l = strlen(exp)-1;
  
  for(i=0; i<l; i++){
    //get operand
    if( exp[i]!=' ' && isOp(exp[i]) == 0 && exp[i]!= '(' && exp[i] != ')'){
      while(exp[i]!=' ' && i<l){
        num = num*10 + (exp[i] -'0');
	i++;
      }
      enQueue(&num,queue1);
      printf("%d ", num); //printf when push to stack1
      num = 0;
    }
    
    // get operator
    else if(isOp(exp[i]) == 1){
      
      if(is_empty(&stack2)){
	c = exp[i] - '0';
	push(&c, &stack2);

      }
      //pop all operators have greater or equal precedence than exp[i] and then push exp[i] to stack2
      else if(precedence(exp[i]) <= precedence(top(&stack2)+'0') ){
        while(precedence(exp[i]) <= precedence(top(&stack2)+'0') ){
	  c = pop(&stack2);
	  enQueue(&c,queue1);
	  c1 = c + '0';
	  printf("%c ", c1); //printf when push to stack1
	}

	c = exp[i] - '0';
	push(&c, &stack2);
      }
      //push exp[i] to stack2 if it has higher precedence than top of stack2
      else if(precedence(exp[i]) > precedence(top(&stack2)+'0') ){
	c = exp[i] - '0';
	push(&c, &stack2);
      }
    }
    
    // get '('
    if(exp[i] == '('){
      c = exp[i] - '0';
      push(&c, &stack2);
    }
    
    //encounter ')'
    if(exp[i] == ')'){
      while((top(&stack2)+'0') !='('){
	c = pop(&stack2);
        enQueue(&c,queue1);
	c1 = c + '0';
	printf("%c ", c1);
      }

      c=pop(&stack2);
    }
  }
      
  //transverse all the expression
  while( is_empty(&stack2) == 0 ){
    c = pop(&stack2);
    enQueue(&c,queue1);
    c1 = c + '0';
    printf("%c ", c1);
  }
  
}

int precedence(char op){
  switch (op)
    {
    case '+':
    case '-':
      return 1;
 
    case '*':
    case '/':
      return 2;
 
    case '^':
      return 3;
    }
  return -1;
}

int claculate(queue *queue1){
  stack stack1;
  init_stack(&stack1);
  int i, c, c1, c2, c3;
  char c4;
  while((queue1->head) != NULL){
    c4 = deQueue(queue1) +'0';
    if(c4!='+' && c4!='-' && c4!='*' && c4!='/'){
      c = c4 - '0';
      push(&c, &stack1);
    }
    else if(c4=='+' || c4=='-' || c4=='*' || c4=='/'){
      c1 = pop(&stack1);
      c2 = pop(&stack1);
      
      if(c4 == '+') c3 = c1 + c2;
      if(c4 == '-') c3 = c1 - c2;
      if(c4 == '*') c3 = c1 * c2;
      if(c4 == '/') c3 = c1 / c2;
      push(&c3, &stack1);
      
    }
  }
  
  c3 = pop(&stack1);
  printf("result : %d\n", c3);
  freelist(&stack1);
}
