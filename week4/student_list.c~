#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readData(char *fn, char stuID[30][10], char stuName[30][100]) {

	FILE *f = fopen(fn , "r");
	int count = 0;

	while ( !feof(f)) {
		int temp;
		fscanf(f, "%d", &temp);
		fscanf(f, "%s", stuID[count]);
		fgets(stuName[count], 100, f);
		stuName[count][strlen(stuName[count]) - 1] = '\0';
		count++;
	}
	
	return(count - 1);
}

void getGrade(int grade[], char id[][10], char name[][100],int n) {

	printf("Input the grade of each student : \n");
	for (int i = 0; i < n; i++) {
		printf("%4d%11s%s : ", i + 1, id[i], name[i]);
		scanf("%d", &grade[i]);
	}
	return;
}

void printDataToFile(char *fn, \
					 int n, \
					 char id[30][10], \
					 char name[30][100], \
					 int grade[]) {

	FILE *f = fopen(fn, "w+");

	for (int i = 0; i < n; i++)
		fprintf(f, "%4d%11s%-30s%d\n", i + 1, id[i], name[i], grade[i]);

	return;
}

int main() {

	char (*id)[10] = (char (*)[10])calloc(100, 10 * sizeof(char));
	char (*name)[100] = (char (*)[100])calloc(100, 100 * sizeof(char));
	int *grade = (int *)calloc(100, sizeof(int));
	
	int n = readData("student_list.txt", id, name);

	getGrade(grade, id, name, n);
	printDataToFile("grade_table.txt", n, id, name, grade);
	return(0);
}

