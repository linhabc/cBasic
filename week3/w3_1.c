#include <stdio.h>
#include <string.h>

void displayContentToEnd(char *fn) {

	FILE *f = fopen(fn, "r");

	if (f == NULL)
		printf("\nCan not open file!\n");
	else {
		char tempStr[100];

		while (fgets(tempStr, 100, f) != NULL) {
			printf("%s", tempStr);
		}
	}
	printf("\n");
	fclose(f);
	return;
}

void displayContentPageByPage(char *fn) {

	// a page == 25 lines
	
	FILE *f = fopen(fn, "r");

	if (f == NULL)
		printf("\nCan not open file!\n");
	else {
		char tempStr[100];
		int count = 0; // the number of lines printed in page

		while (fgets(tempStr, 100, f) != NULL) {
			count++;

			if (count < 25)
				printf("%s", tempStr);
			else if (count == 25) {
				printf("%s", tempStr);
				printf("\nPress enter to display more!\n");
				while (getchar() != '\n') // wait user press enter
					;
				
				count = 0; // reset to number of lines printed
			}
			
		}
	}
	printf("\n");
	fclose(f);
	return;
}

int main(int argc, char *argv[]) {

	if (argc == 2)
		displayContentToEnd(argv[1]);
	else if ((argc == 3) && (strcmp(argv[1], "-p") == 0))
		displayContentPageByPage(argv[2]);
	else
		printf("\nSystac error!\n");

	
	return(0);
}
