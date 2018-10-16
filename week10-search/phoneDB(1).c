#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

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
void read_dat(char *fn , linked_list *ls){
	FILE *fp = fopen(fn,"rb");
	if (fp == NULL){
		printf("cannot open file %s \n", fn);
	}
	while (!feof(fp)) {
		elementtype *info = (elementtype *)malloc(sizeof(elementtype));
		fread(info, sizeof(elementtype), 1, fp);
		insert_head(ls,info);
	}
	printf("Imported successfully \n");
	fclose(fp);
}

void split_File(char *fn,char *f1,char *f2,int n){
	FILE *f = fopen(fn,"rb");
	int i;
	FILE *fo1 = fopen(f1,"wb+");
	FILE *fo2 = fopen(f2,"wb+");
	elementtype *info1 = (elementtype *)malloc(sizeof(elementtype));
	elementtype *info2 = (elementtype *)malloc(sizeof(elementtype));
	
	for (i = 0;i < n;i++){
		fread(info1,sizeof(elementtype),1 ,f);
		fwrite(info1,sizeof(elementtype), 1, fo1);
	}

	for (i = 0; i < 20 - n;i++){
		fread(info2,sizeof(elementtype), 1, f);
		fwrite(info2,sizeof(elementtype), 1, fo2);
	}
	

	fclose(f);
	fclose(fo1);
	fclose(fo2);
}
void write_dat(char *fn, linked_list *ls){
	FILE *fp = fopen(fn,"wb+");
	if (fp == NULL){
		printf("cannot open file %s\n", fn);
	}

	node *temp;
	temp = ls->root;
	while (temp != NULL){
		fwrite(temp->info, sizeof(phone), 1, fp);
		temp = temp->next;
	}
	printf("Exported successfully \n");
	fclose(fp);
}

node* search_node(linked_list *ls){
	char input[20];
	printf("Enter your name of phone you seek to \n");
	scanf("%s",input);
	clear();
	node *temp = ls->root;
	int ava = 0;
	while (temp != NULL){
		if (strcmp(temp->info->name, input) == 0){
			return (temp);
			ava = 1;
		}
		
		temp = temp->next;
	}
	if (ava == 0){
		printf("Cannot find the product \n");
		return NULL;
	}
}

void search_Name(linked_list *ls){
	elementtype *info;
	char input[20];
	char o;
	printf("Enter your name of phone you seek to \n");
	scanf("%s",input);
	clear();
	node *cur;
	node *temp = ls->root;
	int ava = 0;
	while (temp != NULL){
		if (strcmp(temp->info->name, input) == 0){
			cur = temp;
			printf("The infomation of this phone is: \n");
			displayNode(temp);
			ava = 1;

			printf(" \n\n Change the information Y/N ?\n");
			scanf("%c",&o);
			clear();
			if(o == 'Y'){
				read_node(temp->info);
			}
			else if (o == 'N')
				return;
			else
				printf("Syntax error!! You must enter Y/N \n");
		}
		temp = temp->next;
	}
	if ( ava == 0)
		printf("The product is not available \n");
}

void search_price(linked_list *ls){
	float input;
	int ava = 0;
	printf("Enter your price you want \n");
	scanf("%f",&input);
	clear();

	node *temp = ls->root;
	while (temp != NULL){
		if ((atof(temp->info->price)) < input){
			printf("These phones are what you need \n");
			displayNode(temp);
			ava = 1;
		}
		temp = temp->next;
	}
	if (ava == 0)
		printf("The product is not available \n");
}

void self_search_head(linked_list *ls){
	int i = 0;
	node *temp = ls->root;
	char input[20];
	elementtype *stored = (elementtype *)malloc(sizeof(elementtype));
	printf("Enter your name of phone you seek to \n");
	scanf("%s",input);
	clear();

	stored = temp->info;
	while (strcmp(temp->info->name,input) != 0){
		temp = temp->next;
		i++;
	}

	ls->root->info = temp->info;
	temp->info = stored;

	printf("Item found at position %d and be changed to head \n" , i);
}


void self_search_prev(linked_list *ls){
	int i = 0;
	node *temp = ls->root;
	char input[20];
	elementtype *stored = (elementtype *)malloc(sizeof(elementtype));
	printf("Enter your name of phone you seek to \n");
	scanf("%s",input);
	clear();

	while (strcmp(temp->info->name,input) != 0){
		temp = temp->next;
		i++;
	}
	node *prev = previous_node(ls,temp->info);
	stored = prev->info;
	prev->info = temp->info;
	temp->info = stored;

	printf("Item found at position %d and be changed to previous \n" , i);
}
int main(){
	linked_list ls;
	init_list(&ls);
	int option;
	elementtype info;
	int n;
	do {
		printf("Choose from 1 - 7 to execute \n");
		printf("1 Import from dat file \n");
		printf("2 Display \n");
		printf("3 Add new phone (before/after) \n");
		printf("4 Insert at position \n");
		printf("5 Delete at position \n");
		printf("6 Delete current \n");
		printf("7 Delete first \n");
		printf("8 Search and update \n");
		printf("9 Divide and extract \n");
		printf("10 Reverse list \n");
		printf("11 Save to file \n");
		printf("12 Self organizing head search \n");
		printf("13 Self organizing previous search \n");
		printf("14 Quit \n");
		scanf("%d", &option);
		clear();
		
		switch(option){
		case 1:
			read_dat("phoneDB.dat", &ls);
			break;
		case 2:
			traverse(&ls);
			break;
		case 3:
			printf("Enter the information needed \n");
		    read_node(&info);
			clear();
			
			node *cur = search_node(&ls);
			printf("Choose a option to insert before or after \n");
			printf("1 for before, 2 for after \n");
			scanf("%d",&n);
			clear();
			if ( n == 1){
				insert_before(&ls,cur,&info);
				printf("Inserted completely \n");
			}
			else if (n == 2){
				insert_after(&ls,cur,&info);
				printf("Inserted completely \n");
			}
			else
				printf("Syntax error!!You must enter 1 or 2 \n");
			break;
		case 4:
			printf("Enter the information needed \n");
		    read_node(&info);
			clear();
			
			printf("Enter the position you want to insert (from 0 as root) \n");
			scanf("%d",&n);
			clear();

			insert_position(&ls,n,&info);
			printf("Inserted completely \n");
			break;
		case 5:
			printf("Enter the position you want to insert (from 0 as root) \n");
			scanf("%d",&n);
			clear();

			delete_position(&ls,n);
			printf("Deleted completely \n");
			break;
		case 6:
			printf("This is going to delete current node \n");
			node *curr = search_node(&ls);
			delete_cur(&ls,curr);
			printf("Deleted completely \n");
			break;
		case 7:
			printf("This is going to delete the first node \n");
			delete_head(&ls);
			printf("Deleted completely \n");
			break;
		case 8:
			search_Name(&ls);
			break;
		case 9:
			printf("Enter the number of lines you want to split \n");
			scanf("%d",&n);
			split_File("phoneDB.dat","phoneDB1.dat","phoneDB2.dat",n);
			FILE *f1 = fopen("phoneDB1.dat","rb");
			FILE *f2 = fopen("phoneDB2.dat","rb");
			printf("The first list after splitting \n");
				while (!feof(f1)) {
					elementtype *info = (elementtype *)malloc(sizeof(elementtype));
					fread(info, sizeof(elementtype), 1, f1);
					printf("%-20s %-5s %-5s %-3s \n", \
						   info->name,		  \
						   info->size,		  \
						   info->screen,		  \
						   info->price);
				}
			printf("The second list after splitting \n");
				while (!feof(f2)) {
					elementtype *info = (elementtype *)malloc(sizeof(elementtype));
					fread(info, sizeof(elementtype), 1, f2);
					printf("%-20s %-5s %-5s %-3s \n",	  \
							   info->name,		  \
							   info->size,	\
							   info->screen,	\
							   info->price);
				}

				fclose(f1);
				fclose(f2);
			break;
		case 10:
			reverse(&ls);
			traverse(&ls);
			break;
		case 11:
			write_dat("phoneDB.dat", &ls);
			break;
		case 12:
			self_search_head(&ls);
			break;
		case 13:
			self_search_prev(&ls);
			break;
		}
	} while (option !=14);
	freeList(&ls);
	return 0;
}
