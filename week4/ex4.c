#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100



int main(int argc, char* argv[]){
  if(argc!=3){
    printf("Enter 2 arg and name.");
    return 1;
  }
  
  FILE* fFile = fopen(argv[1], "r");
  if(fFile==NULL){
    printf("Cannot open the file");
    return 1;
  }


  char buff[MAX];
  int len,i;
  
  while(fgets(buff, MAX, fFile)!=NULL){
    len=strlen(buff);
    for(i=0;i<len;i++){
      if(buff[i]=='c' && buff[i+1]=='o' && buff[i+2]=='n'){
	printf("%s%s%s", argv[2],argv[2],argv[2]);
	i+=2;
      }
      else if(buff[i]=='c' && buff[i+1]=='o'){
	printf("%s%s", argv[2],argv[2]);
	i++;
      }
      else{
	printf("%c", buff[i]);
      }
    }
  }

  fclose(fFile);
  return 0;
}
