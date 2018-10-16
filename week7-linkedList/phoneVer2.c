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
// adding function
node_addr addPhone();
node_addr *insertAtPosition(int n);
void deleteAtPos(int n);
void deleteAtHead();
void deleteCur();
void reverseList();
void splitFile(phone_t *phone);

int main(){
  int a,n;
  phone_t* phone;
  phone = (phone_t *)malloc(20*sizeof(phone_t));
  if(phone==NULL){
    printf("allocated memory failed\n");
    return 1;
  }
  
  FILE* fin2 = fopen("phone.dat", "rb");
  
  if(fin2==NULL ){
    printf("Cannot opened the file.\n");
    return 1;
  }

  do{
    printf("\nMENU\n");
    printf("1.read data from .dat and build list\n");
    printf("2.Display all\n");
    printf("3.Add new phone\n");
    printf("4.Insert at position\n");
    printf("5.Delete at position\n");
    printf("6.Delete current\n");
    printf("7.Delete first\n");
    printf("8.Search by model.\n");
    printf("9.Divide and extract.\n");
    printf("10.Reverse list.\n");
    printf("11.Save to file.\n");
    printf("12.Quit.\n");
    do{
      printf("Enter(1-12) : ");
      scanf(" %d", &a);
    }while(a>12 || a<1);

    switch(a){
    case 1:
      readDat(fin2, phone);
      break;
    case 2:
      traversingList();
      break;
    case 3:
      addPhone();
      break;
    case 4:
      do{
      printf("Enter position: ");
      scanf(" %d", &n);
      }while(n<0);
      insertAtPosition(n);
      break;
    case 5:
      do{
      printf("Enter position: ");
      scanf(" %d", &n);
      }while(n<0);
      deleteAtPos(n);
      break;
    case 6:
      deleteCur();
      break;
    case 7:
      deleteAtHead();
      break;
    case 8:
      searchModel();
      break;
    case 9:
      splitFile(phone);
      break;
    case 10:
      reverseList();
      break;
    case 11:
      storeLinkedList();
      break;
    }
  }while(a!=12);

  freeList();
  free(phone);
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
  FILE* fout= fopen("phoneD.dat", "wb");
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


//improve function

node_addr addPhone(){
  phone_t newP;
  printf("Enter model: ");
  scanf("%10s", newP.model);

  printf("Enter storage: ");
  scanf("%d", &newP.storage);

  printf("Enter display: ");
  scanf("%f", &newP.display);

  printf("Enter prize: ");
  scanf("%20d", &newP.prize);

  insertAfterCur(&newP);
}


node_addr *insertAtPosition(int n){
  phone_t newP;
  printf("Enter model: ");
  scanf("%10s", newP.model);

  printf("Enter storage: ");
  scanf("%d", &newP.storage);

  printf("Enter display: ");
  scanf("%f", &newP.display);

  printf("Enter prize: ");
  scanf("%20d", &newP.prize);
  
  node_addr * new= makeNewNode(&newP);
  node_addr* p=root;
  int count=0;
  for(p;p!=NULL;p=p->next){
    if(count==n){
      new->next = cur->next;
      cur->next = new;
      //prev=cur;
      cur = cur->next;
      break;
    }
    cur=p;
    count++;
  }
}
void deleteAtPos(int n){
  node_addr* tmp = root;
  if(n==1){
    root = tmp->next;
    free(tmp);
    return;
  }
  for(int i=0;i<n-2;i++){
    tmp = tmp->next;
   }
  node_addr* tmp1 = tmp->next;
  tmp->next = tmp1->next;
  free(tmp1);
}

void deleteAtHead(){
  if(root==NULL) return;
  node_addr* p=root;
  root=root->next;
  free(p);
  cur=root;
}

void deleteCur(){
  node_addr* prev=root;
  if(cur==NULL) return;
  if(cur==root){
    deleteAtHead();
  }
  else{
    for(prev;prev!=NULL;prev=prev->next){
      if(prev->next==cur){
	break;
      }
    }
    prev->next=cur->next;
    free(cur);
    cur=prev->next;
  }
}

void reverseList() {
  cur = root;
  node_addr *next = NULL;
  node_addr *prev = NULL;

  while (cur != NULL) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  root = prev;
  return;
}


void splitFile(phone_t *phone){
  FILE* f1= fopen("file1.dat", "w+b");
  FILE* f2= fopen("file2.dat", "w+b");
  if(f1==NULL || f2==NULL){
    printf("Cannot loaded file,\n");
    return ;
  }
  int n;
  printf("Enter number to split: ");
  scanf(" %d", &n); 
  
  fwrite(phone,sizeof(phone_t),n,f1);
  for(int i=n; i<20; i++){
    fwrite(phone+i,sizeof(phone_t),1,f2);
  }
  fclose(f1);
  fclose(f2);
}
