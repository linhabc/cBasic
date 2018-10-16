#include "BST(word).h"

void readTxt(char file[], char c[]);

int main(){
  tree root = NULL;
  char c[MAX], cut[MAX];
  int j=0;
  readTxt("word.txt", c);

  for(int i=0; i<MAX; i++){
    for(j=0;j<MAX;j++){
      if(c[i] != ' '){
	cut[j] = c[i];
	//printf("%s \n", cut);
	i++;
      }
      else if(c[i] == ' '){
	cut[j] = '\0';
	//printf("%s \n", cut);
	insertNode(cut, &root);
	break;
      }
    }
  }

  printInOrder(root);
  return 0;
}

void readTxt(char file[], char c[]){
  FILE* f = fopen(file, "r");
  if(f==NULL){
    printf("cannot open file.\n");
    return;
  }
  fgets(c, MAX, f);
  printf("%s\n", c);
}

