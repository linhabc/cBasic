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
	return (new_node);
}

void displayNode(node *node){

	printf("%-20s %-5s %-5s %-3s \n", \
		   node->info->name, \
		   node->info->size, \
		   node->info->screen, \
		   node->info->price);
}

node *search_list(linked_list *ls,elementtype *info){
	node *temp = ls->root;
	if (temp == NULL)
		return (NULL);
	while (temp != NULL || temp->info != info)
		temp = temp->next;

	return (temp);
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
	else {
	new_node->next = ls->root;
	ls->last = ls->root;
	ls->root = new_node;
	}
}

 void insert_after(linked_list *ls,node *cur, elementtype *info ){
	 if (cur->next == NULL){
		 node *new_node = makeNode(info);
		 new_node->next = NULL;
		 cur->next = new_node;
	 }

	 node *new_node = makeNode(info);
	 new_node->next = cur->next;
	 cur->next = new_node;
}
/*
 node *previous_node(linked_list *ls , phone *info){
	 if ((ls->root == NULL) || (ls->root->next == NULL)){
		 printf("Empty list \n");
		 return (NULL);
	 }

	 if ((ls->root->next)->info == info)
		 return (ls->root);
	 else
		 return (previous_node((ls->root)->next,info));
 }
*/

node *previous_node(linked_list *ls,elementtype *info){
	node *temp = ls->root;
	if (ls->root == NULL || ls->root->next == NULL){
		return (NULL);
	}
	while (temp != NULL){
		if (temp->next->info == info)
			return (temp);

		temp = temp->next;
	}
}

 void insert_before(linked_list *ls, node *cur,elementtype *info){
	 if (ls->root == cur){
		 insert_head(ls,info);
	 }

	 node *prev = previous_node(ls,cur->info);
	 node *new_node = makeNode(info);
	 prev->next = new_node;
	 new_node->next = cur;
 }

 void insert_last(linked_list *ls,elementtype *info){
	 node *new_node = makeNode(info);
	 if (ls->last == NULL && ls->root == NULL){
		 ls->last = ls->root = new_node;
	 }
	 
	 ls->last->next = new_node;
	 new_node->next = NULL;
	 ls->last = new_node;
 }


 node *insert_position(linked_list *ls,int pos, elementtype *info){
	 if (pos < 0){
		 printf("The position must be larger than 0 \n");
		 return (NULL);
	 }
	 else if (pos == 0){
		 insert_head(ls,info);
		 return (ls->root);
	 }
	 else{
		 node *cur = ls->root;
		 int index = 1;

		 while (cur != NULL){
			 cur = cur->next;
			 index++;

			 if (index == pos){
				 insert_after(ls,cur,info);
				 return (cur->next);
			 }
		 }
		 if (pos > index){
			 insert_last(ls,info);
			 return (ls->last);
		 }
	 }
 }


node *delete_position(linked_list *ls,int n){
	if (ls->root == NULL)
		return NULL;

	node *temp = ls->root;
	if (n < 0){
		printf("The position must be larger than 0 \n");
		return NULL;
	}
	else if (n == 0){
		ls->root = temp->next;
		free(temp);
		return (ls->root);
	}
	else {
		node *cur = ls->root->next;
		int index = 1;

		while (cur != NULL){
			cur = cur->next;
			index++;

			if (n == index){
				node *prev = previous_node(ls,cur->info);
				prev->next = cur->next;
				free(cur);
			}
			
		}
		return (ls->root);
	}
}

void delete_head(linked_list *ls){
	node *temp = ls->root;
	ls->root = temp->next;
	free(temp);
}

void delete_cur(linked_list *ls,node * cur){
	node *prev = previous_node(ls,cur->info);

	if (cur == NULL) return;
	if (cur == ls->root)
		delete_head(ls);

	prev->next = cur->next;
	cur->next = NULL;
	free(cur);
}

void delete_element(linked_list *ls,elementtype *info){
	if (ls->root->info == info)
		delete_head(ls);
	else if (ls->last->info == info){
		node *prev = previous_node(ls,ls->last->info);
		prev->next = NULL;
		free(ls->last);
		ls->last = prev;
	}
	else {
		node *cur = ls->root;
		while (cur != NULL && cur->info == info){
			cur = cur->next;
		}
		if (cur == NULL)
			printf("The data is not on the list \n");
		else {
			delete_cur(ls,cur);
		}
	}
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

