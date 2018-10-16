#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct phone_t {
	char name[20];
	char size[5];
	char screen[5];
	char price[3];
} phone;

typedef phone elementtype;
typedef struct Node {
	elementtype *info;
	struct Node *next;
	struct Node *prev;
} node ;

typedef struct {
	node *root;
	node *last;
} linked_list;

void clear(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void init_list(linked_list *ls){
	ls->root = NULL;
	ls->last = NULL;
}

node *makeNode(elementtype *info){
	node *new_node = (node *)malloc( sizeof(node) );

	new_node->info = info;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void displayNode(node *node){

	printf("%-20s %-5s %-5s %-3s \n", \
		   node->info->name, \
		   node->info->size, \
		   node->info->screen, \
		   node->info->price);
}

void freeList(linked_list *ls){
	if (ls->root == NULL){
		printf("Free completed \n");
	}

	node *temp = ls->root;
	while (temp != NULL){
		free(temp);
		temp = temp->next;
	}
	printf("Free completed \n");
}

void traverse(linked_list *ls){
	if (ls->root == NULL){
		printf("The list is empty \n");
	}
	node *temp = ls->root;
	while (temp != NULL){
		displayNode(temp);
		temp = temp->next;
	}
}

void insert_head(linked_list *ls, elementtype *info){
	node *new_node = makeNode(info);

	if (ls->root == NULL && ls->last == NULL){
		ls->root = ls->last = new_node;
		new_node->next = NULL;
	}
	
	new_node->next = ls->root;
	ls->root = new_node;
}

 void insert_last(linked_list *ls,elementtype *info){
	 node *new_node = makeNode(info);
	 if (ls->last == NULL && ls->root == NULL){
		 ls->last = ls->root = new_node;
	 }
	 
	 ls->last->next = new_node;
	 new_node->prev = ls->last;
	 ls->last = new_node;
 }


void delete_head(linked_list *ls){
	node *temp = ls->root;
	ls->root = temp->next;
	free(temp);
}

void delete_cur(linked_list *ls,node * cur){
	node *prev = cur->prev;

	if (cur == NULL) return;
	if (cur == ls->root)
		delete_head(ls);

	prev->next = cur->next;
	cur->next = NULL;
	free(cur);
}

void reverse(linked_list *ls){
	node *prev = NULL;
	node *cur = ls->root;
	node *next = NULL;

	while ( cur != NULL){
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	ls->root = prev;
}

