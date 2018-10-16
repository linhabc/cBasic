#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio_ext.h>

typedef struct address_t{
  char name[20];
  char tel[11];
  char email[25];
} address;

struct list_el{
  address addr;
  struct list_el *next;
};

typedef struct list_el node_addr;

node_addr *root, *cur;

// in case you used prev

node_addr *prev;



node_addr* makeNewNode(address addr){
node_addr* new=(node_addr*)malloc(sizeof(node_addr));
new->addr=addr;
new->next=NULL;
return new;
}

address readNode(){
address read;
 __fpurge(stdin);
printf("Enter the name: "); fgets(read.name,20,stdin); read.name[strlen(read.name)-1]='\0';
printf("Enter the tel: "); scanf("%s",read.tel);
printf("Enter the email: "); scanf("%s",read.email);
return read;
}

void insertAtHead(address addr){
  node_addr* new = makeNewNode(addr);
  new->next=root;
  root=new;
  cur=root;
}

void displayNode(node_addr* p){
if (p==NULL) { printf("NULL pointer error!\n"); return;}
address tmp=p-> addr;
printf("%-20s\t%-15s\t%-30s  %p\n",tmp.name,tmp.tel,tmp.email,p->next);
}

void traversingList(){
  node_addr *p;
  for(p=root; p!=NULL; p=p->next)
    displayNode(p);
}


void main(){

address tmp=readNode();
root = makeNewNode(tmp);
displayNode(root);
address no1=readNode();
insertAtHead(no1); 
displayNode(root);
printf("\nTraversing List:\n");
traversingList();
}



