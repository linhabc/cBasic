#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ph{
  char model[10];
  int storage;
  float display;
  int prize;
}phone_t;

struct addr_node{
  phone_t ph;
  struct addr_node *next;
};

typedef struct addr_node node_addr;

node_addr *root, *cur;

node_addr *makeNewNode(phone_t *phone);
void insertAtHead(phone_t *phone);
void readText(FILE* fin, phone_t phone[]);
void readDat(FILE* fin, phone_t phone[]);
void displayNode(node_addr *node);
void traversingList();
void searchModel();
void searchPhoneUnderPrize();
void storeLinkedList();
void freeList();

int main(){
  int a;
  phone_t* phone;
  phone = (phone_t *)malloc(20*sizeof(phone_t));
  if(phone==NULL){
    printf("allocated memory failed\n");
    return 1;
  }
  
  FILE* fin1 = fopen("phone.txt", "r");
  FILE* fin2 = fopen("phone.dat", "rb");
  
  if(fin1==NULL|| fin2==NULL ){
    printf("Cannot opened the file.\n");
    return 1;
  }

  do{
    printf("\nMENU\n");
    printf("1.read data from text and build list\n");
    printf("2.read data from .dat file and build list\n");
    printf("3.display list\n");
    printf("4.search by model\n");
    printf("5.search phone under price input\n");
    printf("6.store infor in linked list to phoneDB.dat\n");
    printf("7.exit\n");
    do{
      printf("Enter(1-7) : ");
      scanf(" %d", &a);
    }while(a>7 || a<1);

    switch(a){
    case 1:
      readText(fin1, phone);
      break;
    case 2:
      readDat(fin2, phone);
      break;
    case 3:
      traversingList();
      break;
    case 4:
      searchModel();
      break;
    case 5:
      searchPhoneUnderPrize();
      break;
    case 6:
      storeLinkedList();
      break;
      
    }

  }while(a!=7);

  freeList();
  free(phone);
  fclose(fin1);
  fclose(fin2);
  return 0;
}

node_addr *makeNewNode(phone_t *phone){
  node_addr* new=(node_addr*)malloc(sizeof(node_addr));
  new->ph = *phone;
  new->next = NULL;
  return new;
}
  
void insertAtHead(phone_t *phone){
  node_addr* new = makeNewNode(phone);
  if(root==NULL){
    root = new;
    cur = root;
  }else{
    new->next = root;
    root=new;
    cur=root;
  }
}

void insertAfterCur(phone_t *phone){
  node_addr *new = makeNewNode(phone);
  
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
void readText(FILE* fin, phone_t phone[]){
  int i;
  for(i=0;i<20;i++){
    //fgets(phone[i].model, 10, fin);
    fscanf(fin, " %10s", phone[i].model);
    fscanf(fin, " %d", &phone[i].storage);
    fscanf(fin, " %f", &phone[i].display);
    fscanf(fin, " %d", &phone[i].prize);
  }
  
  node_addr *p;
  for(int i=0; i<20;i++){
    insertAtHead(phone+i);
  }
  
}

void readDat(FILE* fin, phone_t phone[]){
  fread(phone, sizeof(phone_t), 20, fin);
  node_addr *p;
  for(int i=0; i<20;i++){
    insertAfterCur(phone+i);
  }
  
}

void displayNode(node_addr *node){
  if(node==NULL){
    printf("Error NUll Pointer\n");
    return;
  }
  phone_t tmp = node->ph;
  printf("%-15s\t%8d Gb\t%-.1f Inch%20d VND    %p\n", tmp.model, tmp.storage, tmp.display, tmp.prize, node->next);

}

void traversingList(){
  node_addr *p;
  for(p=root; p!=NULL; p=p->next){
    displayNode(p);
  }
}

void searchModel(){
  printf("Enter model: ");
  char model[10];
  scanf(" %s", model);
  int i;
  node_addr *p=root;
  for(p;p!=NULL;p=p->next){
    if(!strcmp(model, p-> ph.model)){
      printf("________\n\n");
      printf("%-15s\t%8d Gb\t%-.1f Inch%20d VND\n", p->ph.model, p->ph.storage, p->ph.display, p->ph.prize);
      printf("________\n");
      break;
    }
  }
}

void searchPhoneUnderPrize(){
  int pr;
  printf("Enter prize: ");
  scanf(" %d", &pr);
  node_addr *p=root;
  for(p;p!=NULL;p=p->next){
    if(pr >= p->ph.prize){
      printf("%-15s\t%8d Gb\t%-.1f Inch%20d VND\n", p->ph.model, p->ph.storage, p->ph.display, p->ph.prize);
    }
  }

}

void storeLinkedList(){
  FILE* fout= fopen("phoneDB.dat", "wb");
  node_addr *p= root;
  for(p;p!=NULL;p=p->next){
    fwrite(p,sizeof(node_addr),1,fout);
  }
  fclose(fout);
}

void freeList(){
  node_addr *to_free;
  to_free = root;
  while(to_free!=NULL){
    root = root->next;
    free(to_free);
    to_free=root;
  }
}
