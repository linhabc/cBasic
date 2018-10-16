#include <stdio.h>
#include <stdlib.h>
#include "double_ll.h"

void read_dat(char *fn , linked_list *ls){
	FILE *fp = fopen(fn,"rb");
	if (fp == NULL){
		printf("cannot open file %s \n", fn);
	}
	while (!feof(fp)) {
		elementtype *info = (elementtype *)malloc(sizeof(elementtype));
		fread(info, sizeof(elementtype), 1, fp);
		insert_last(ls,info);
	}
	printf("Imported successfully \n");
	fclose(fp);
}

elementtype read_node(elementtype *info){
	printf("Enter Name \n");
	scanf("%s", info->name);
	printf("Enter size \n");
	scanf("%s", info->size);
	printf("Enter screen \n");
	scanf("%s", info->screen);
	printf("Enter price \n");
	scanf("%s", info->price);
}

void sentinelSearch(linked_list *ls){
	char input[20];
	printf("Enter phone you seek to: ");
	scanf("%s",input);
	clear();
	node *temp = ls->root;

	elementtype *last = (elementtype *)malloc(sizeof(elementtype));
	strcpy(last->name,ls->last->info->name);

	strcpy(ls->last->info->name,input);
	int i = 0;
	while (strcmp(temp->info->name,input) != 0){
		temp = temp->next;
		i++;
	}
	strcpy(ls->last->info->name,last->name);
	if (i < 19 || strcmp(ls->last->info->name,input) == 0){
		printf("Item found at position %d\n",i);
	}
	else
		printf("Not found \n");
}


int main(){
	linked_list ls;
	init_list(&ls);
	int option;
	elementtype info;
	int n;
	do {
		printf("Choose from 1 - 9 to execute \n");
		printf("1 Import from dat file \n");
		printf("2 Display \n");
		printf("3 Sentinel Search \n");
		printf("4 Exit \n");
		printf("Enter: ");
		scanf("%d", &option);
		clear();
		
		switch(option){
		case 1:
			read_dat("phoneDB.dat",&ls);
			break;
		case 2:
			traverse(&ls);
			break;
		case 3:
			sentinelSearch(&ls);
			break;
		}
	} while (option !=4);
	freeList(&ls);
	return 0;
}
