#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define strcut_newline(str) ((str)[strlen(str) - 1] == '\n')? (str)[strlen(str) - 1] = '\0':0;

char* subStr(char*s1, int offset, int number);

int main(){
  char s1[100];
  char *p;
  int offset,number;
  printf("Enter string: ");
  fgets(s1,99,stdin);
  strcut_newline(s1);
  printf("Enter offset number: ");
  scanf(" %d", &offset);
  printf("Enter number of character: ");
  scanf(" %d", &number);
  p=subStr(s1,offset,number);
  printf("substr: %s\n", p);
  return 0;
}

char* subStr(char*s1, int offset, int number){
  int l;
  char* p;
  p=(char*)malloc((number+1)*sizeof(char));
  if(p==NULL){
    printf("Memory allocation failed!\n");
    return 0;
  }
  l=strlen(s1);
  if(l>=offset+number-1){
    for(int i=0, j=offset; j<offset+number;i++,j++){
      *(p+i)=*(s1+j);
    }
  }
  else{
   for(int i=0, j=offset; j<=l;i++,j++){
      *(p+i)=*(s1+j);
    }
  }  
  return p;
  free(p);
}
