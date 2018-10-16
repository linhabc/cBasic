#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ph{
  char model[10];
  int storage;
  float display;
  int prize;
}phone_t;

struct node1{
  phone_t ph;
  struct node1* next;
};

typedef struct node1 node;
node *root, *cur;
node *root1=NULL, *cur1;
node *root2=NULL, *cur2;

node* makeNewNode(phone_t* phone);
void insertAfterCurrent(node* roo, node* cur, phone_t* phone);
void printFile(node* roo, FILE* fout, int n);
void readText(FILE* fin, phone_t* phone, int n);
void freeList(node* roo);
void insertAtHead(node* roo, node* cur,phone_t *phone);
void insertAfterCur2(phone_t *phone);

int main(int argc, char* argv[]){
  int n1,n2;
  int i;
  n1=atoi(argv[1]);
  n2=atoi(argv[2]);

  
  if(argc!=3){
    printf("Enter 3 argument, including name.\n");
    return 1;
  }
  if(n1>n2 || n2>20){
    printf("Enter n1<n2<20\n");
    return 1;
  }

  FILE* fin = fopen("phone.dat", "rb");
  FILE* fout1 = fopen("phone1.txt", "w+");
  FILE* fout2 = fopen("phone2.txt", "w+");

  if(fin==NULL || fout1==NULL || fout2==NULL){
    printf("Cannot loaded file,\n");
    return 1;
  }

  phone_t* phone;
  phone = (phone_t*)malloc(20 *sizeof(phone_t));
  phone_t* phone1;
  phone1 = (phone_t*)malloc((20-(n2-n1+1))*sizeof(phone_t));
  phone_t* phone2;
  phone2 = (phone_t*)malloc((n2-n1+1)*sizeof(phone_t));
  if(phone==NULL|| phone1==NULL || phone2==NULL){
    printf("Allocated memory failed\n");
    return 1;
  }

  fread(phone, sizeof(phone_t), 20, fin);
  
  for(i=0;i<20;i++){
    insertAfterCur2(phone+i);
    //printf("%s\n", cur->ph.model);
  }
  node* p=root;
  node* p1=root1;
  node* p2=root2;
  
  for(i=0; i<=n1 ;i++){
    p1->ph=p->ph;
    p1->next=p->next;
    p=p->next;
    p1=p1->next;
    printf("%s\n", p1->ph.model);
  }
  for(i=n1+1;i<=n2;i++){
    p2->ph=p->ph;
    p2->next=p->next;
    p=p->next;
    p2=p2->next;
  }
  for(i=n2+1;i<20;i++){
    p1->ph=p->ph;
    p1->next=p->next;
    p=p->next;
    p1=p1->next;
  }
  
  printFile(root1, fout1, (20-(n2-n1+1)) );
  printFile(root2, fout2, (n2-n1+1) );
  
  readText(fout1, phone1,(20-(n2-n1+1)) );
  readText(fout2, phone2,(n2-n1+1) );

  freeList(root);
  freeList(root1);
  freeList(root2);
  free(phone);
  free(phone1);
  free(phone2);
  fclose(fin);
  fclose(fout1);
  fclose(fout2);
  
  return 0;
}

node* makeNewNode(phone_t* phone){
  node* new = (node*)malloc(sizeof(node));
  new->ph = *phone;
  new->next = NULL;
  return new;
}

void insertAtHead(node* root, node* cur,phone_t *phone){
  node* new = makeNewNode(phone);
  if(root==NULL){
    root = new;
    cur = root;
  }else{
    new->next = root;
    root=new;
    cur=root;
  }
}

void insertAfterCurrent(node* root, node* cur, phone_t* phone){
  node *new = makeNewNode(phone);
  
  if(root == NULL){
    root = new;
    cur = root;
  }else{
    new->next = cur->next;
    cur->next = new;
    cur = cur->next;
  }
}

void printFile(node* roo, FILE* fout, int n){
  int i;
  node* p = roo;
  for(i=0;i<n;i++){
    fprintf(fout, "%-10s%8d %-.1f  %20d\n", p->ph.model, p->ph.storage, p->ph.display, p->ph.prize);
    p = p->next;
  }
}

void readText(FILE* fin, phone_t* phone, int n){
  int i;
  fseek(fin,0,SEEK_SET);
  for(i=0;i<20;i++){
    fscanf(fin, " %10s", phone[i].model);
    fscanf(fin, " %d", &phone[i].storage);
    fscanf(fin, " %f", &phone[i].display);
    fscanf(fin, " %d", &phone[i].prize);
  }
  for(i=0; i<n;i++){
    printf("%-15s\t%8d Gb %-.1f Inch%20d VND\n", phone[i].model, phone[i].storage, phone[i].display, phone[i].prize);
  }
}

void freeList(node* roo){
  node *to_free;
  to_free = roo;
  while(to_free!=NULL){
    root = roo->next;
    free(to_free);
    to_free=roo;
  }
}

void insertAfterCur2(phone_t *phone){
  node *new = makeNewNode(phone);
  
  if(root==NULL){
    root = new;
    cur = root;
  }else{
    new->next = cur->next;
    cur->next = new;
    //prev=cur;
    cur = cur->next;
  }
}
