#include <stdio.h>
#include <string.h>

void findAll(char *searchWord) {

  FILE *f = fopen("/usr/share/dict/words", "r");

  if (f == NULL) {
    printf("Can not open file /usr/share/dict/words \n");
    return;
  }
	
  char str[100];
  while ( !feof(f) ) {
    fgets(str, 100, f);

    if ( strstr(str, searchWord) == str ) {
      printf("%s", str);
    }
  }
	
  fclose(f);
  return;
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Syntac error !\n");
    return(1);
  }

  findAll(argv[1]);
	
  return(0);
}
