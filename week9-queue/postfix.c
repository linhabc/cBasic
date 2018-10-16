#include <stdio.h>
#include <stdlib.h>
#include "stackLinked.h"
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

int main(){
  char exp[MAX];
  stack stack1;
  init_stack(&stack1);

  printf("Enter postfix expression: ");
  fgets(exp, 49, stdin);

  int i, c, c1, c2, c3;
  int n = strlen(exp)-1;
  char c4;

  for(i=0; i<n; i++){
    c4 = exp[i];
    if(c4!='+' && c4!='-' && c4!='*' && c4!='/' && isspace(c4)==0){
      c = exp[i] - '0';
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
  return 0;
}
