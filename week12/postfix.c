#include "BST.h"

int main(){

  return 0;
}

int eval(nodeType ptr){
  switch(ptr->key){
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 0:
    return ptr->key;
  }
  switch(ptr->key + '0'){
  case '+':
    return (eval(ptr->left) + eval(ptr->right));
  case '-':
    return (eval(ptr->left) - eval(ptr->right));
  case '*':
    return (eval(ptr->left) * eval(ptr->right));
  case '/':
    return (eval(ptr->left) / eval(ptr->right));
  }
}
