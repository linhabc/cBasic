#include <stdio.h>
#include <ctype.h>

void statistic(FILE* fin);

int main(int argc, char * argv[]){
  if(argc!=2){
    printf("Enter 1 argument and name");
  }
  
  FILE* fin = fopen(argv[1], "r");
  statistic(fin);
 
  return 0;
}

void statistic(FILE* fin){
  FILE* fout = fopen("sourcestats.txt", "w");
  int count[27]={0};
  int c;
  while((c=fgetc(fin)) != EOF){
    if(isalpha(c)){
	if(isupper(c)){
	  tolower(c);
	}
	count[c-'a']++;
      }
    if(isspace(c)){
      count[26]++;
    } 
  }
  for(int i=0; i<26; i++){
    printf("%c: %d\n", i+'a', count[i]);
    fprintf(fout, "%c %d\n", i+'a', count[i]);
  }
  printf("space: %d\n", count[26]);
  fprintf(fout, "space %d\n", count[26]);
  
  fclose(fout);
}
