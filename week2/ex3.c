#include <stdio.h>
#include <string.h>

void replaceName(char* str, char* str1, char* str2);

int main(int argc, char* argv[]){
  if(argc!=4){
    printf("Enter 4 argument.\n");
    return -1;
  }

  replaceName(argv[1],argv[2],argv[3]);
  printf("%s\n",argv[1]);
  
  
  return 0;
}
void replaceName(char* str, char* str1, char* str2){
  int i,l;
  char* str3;
  l=strlen(str1);
   do{
    str3=strstr(str,str1);
    for(i=0;i<l;i++){
      *(str3+i)=*(str2+i);
    }
    }while(strstr(str,str1)!=NULL);
}
