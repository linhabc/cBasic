#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int order;
	char id[10];
	char phone[15];
	char fullname[30];
	int grade;
} student;

int countLines(char *fn) {
	
	FILE *fp = fopen(fn, "r");
	if (fp == NULL) {
		printf("Can not open file %s\n", fn);
		return(0);
	}
	
	char ch;
	int nLines = 1;
	
	while ( !feof(fp) ) {
		ch = fgetc(fp);
		if (ch == '\n') {
			nLines ++;
		}
	}

	fclose(fp);
	return(nLines);
}

void getDataFromFileText(char *fn, student arr[], int n) {

	FILE *fp = fopen(fn, "r");
	if (fp == NULL) {
		printf("Can not open file %s\n", fn);
		return;
	}
	
	int i; /* counter */

	for (i = 0; i < n; i++) {
		fscanf(fp, "%d", &arr[i].order);
		fscanf(fp, "%s", arr[i].id);
		fscanf(fp, "%s", arr[i].phone);
		fseek(fp, 3, SEEK_CUR);
		fscanf(fp, "%[^\t]s", arr[i].fullname);
		fscanf(fp, "%d", &arr[i].grade);
	}
	
	fclose(fp);
	return;
}

void exportData(char *fn, student arr[], int n) {

	FILE *fp = fopen(fn, "wb");
	if (fp == NULL) {
		printf("Can not open file %s\n", fn);
		return;
	}

	fwrite(arr, sizeof(student), n, fp);

	fclose(fp);

	return;
}

void readDataFromFileDat(char *fn, student arr[], int n) {

	FILE *fp = fopen(fn, "rb");
	if (fp == NULL) {
		printf("Can not open file %s\n", fn);
		return;
	}

	fread(arr, sizeof(student), n, fp);

	int i; /* counter */
	for (i = 0; i < n; i++) {
		printf("Student   : %d \n", i + 1);
		printf("Full name : %s\n", arr[i].fullname);
		printf("Id        : %s\n", arr[i].id);
		printf("Phone     : %s\n", arr[i].phone);
		printf("Grade     : %d\n", arr[i].grade);
		printf("------------------------------------\n\n");
	}
	fclose(fp);
	return;
}

void searchAndUpdate(char *fn, student arr[], int n) {

	FILE *fp = fopen(fn, "rb");
	if (fp == NULL) {
		printf("Can not open file %s\n", fn);
		return;
	}

	fread(arr, sizeof(student), n, fp);

	char id[10];
	printf("\nId need to search and update : ");
	scanf(" %s", id);

	int i; /* counter */
	for (i = 0; i < n; i++) {
		if (strcmp(arr[i].id, id) == 0) {
			printf("New grade :  ");
			scanf(" %d", &arr[i].grade);
		}
	}
	
	fclose(fp);

	fp = fopen(fn, "wb");
	fwrite(arr, sizeof(student), n, fp);
	fclose(fp);
	return;
}

int main() {

	int n; /* number of line in file */
	int op;
	student *arr;

	n = countLines("grade_table.txt");
	/* allocate memory for student array */
	arr = (student *)malloc(n * sizeof(student));

	printf("There are 3 options : \n");
	printf("1: Text2Dat \n");
	printf("2: Display .dat file \n");
	printf("3. search and update \n");
	printf("Your option : ");
	scanf("%d", &op);

	switch (op) {
	case 1: {
		getDataFromFileText("grade_table.txt", arr, n);
		exportData("grade_table.dat", arr, n);
		break;
	}
	case 2: {
		readDataFromFileDat("grade_table.dat", arr, n);
		break;
	}
	case 3: {
		searchAndUpdate("grade_table.dat", arr, n);
		readDataFromFileDat("grade_table.dat", arr, n);
		break;
	}
	}
	

	
	return(0);
}
