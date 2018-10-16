#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
  if(argc!=2){
    printf("Enter 2 argument.\n");
    return -1;
  }

  FILE*fFile=fopen(argv[1],"r");
  FILE*fFile1=fopen("temp.txt","w");

  if(fFile==NULL){
    printf("Cannot open");
    return -1;
  }
 
  int c;

  while((c=fgetc(fFile)) != EOF){
      if(islower(c)){
	c=toupper(c);
      }
      fputc(c,fFile1);
      putchar(c);
    }

  fclose(fFile);
  fclose(fFile1);
  FILE*ffFile=fopen(argv[1],"w");
  FILE*ffFile1=fopen("temp.txt","r");
  
  
  while((c=fgetc(ffFile1)) != EOF){
      fputc(c,ffFile);
    }

  fclose(ffFile);
  fclose(ffFile1);

  
  return 0;
}
