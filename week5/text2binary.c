#include <stdio.h>
#include <stdlib.h>

void text2binary(char *fnIn, char *fnOut) {

	FILE *fi = fopen(fnIn, "r");
	FILE *fo = fopen(fnOut, "w+b");

	if (fi == NULL) {
		printf("Can not open file %s \n", fnIn);
		return;
	}

	char *buff;

	buff = (char *)malloc( 1000 * sizeof(char));
	
	while ( !feof(fi) ) {
		fread(buff, sizeof(char), 1000, fi);
		fwrite(buff, sizeof(char), 1000, fo);
	}

	free(buff);
	fclose(fi);
	fclose(fo);
	return;
}

void printSecifyContent(char *fn, int start, int n) {

	FILE *f = fopen(fn, "r");

	if (f == NULL) {
		printf("Can not open file \n");
		return;
	}

	char buff[100];
	int i;
	
	for (i = 0; i < start; i++) {
		fgets(buff, 100, f);
	}

	int end = start + n;
	for (i = start; i < end; i++) {
		fgets(buff, 100, f);
		printf("%s", buff);
	}
	return;
}

int main() {
  int h,t; 
  text2binary("vnedict.txt", "vnedict_1.dat");
  do{
    printf("Enter head: ");
    scanf(" %d", &h);
    printf("Enter tail: ");
    scanf(" %d", &t);
  }while(h>t);
  printSecifyContent("vnedict.txt", h, t);
  return(0);
}
