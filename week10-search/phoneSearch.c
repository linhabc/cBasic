#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinked.h"

void sentinalSearch(doubleL *list, int n, char m[]);
void readDat(FILE* fin, phone_t phone[], doubleL *list);

int main(){
  char *n;
  phone_t* phone;
  phone = (phone_t *)malloc(20*sizeof(phone_t));
  doubleL list;
  init_list(&list);
  FILE* fin = fopen("phone.dat", "rb");
  if(fin == NULL){
    printf("Cannot allocated memory.\n");
    return 1;
  }
  readDat(fin, phone, &list);
  transversingList(&list);
  
  char m[50];
  printf("Enter name of phone: ");
  scanf(" %s", m);
  sentinalSearch(&list, 20, m);
  
  fclose(fin);
  return 0;
}

void readDat(FILE* fin, phone_t phone[], doubleL *list){
  fread(phone, sizeof(phone_t), 20, fin);
  for(int i=0; i<20;i++){
    insertAfterCur(phone+i, list);
  }  
}

void sentinalSearch(doubleL *list, int n, char m[]){
  int i=0;
  phone_t key;
  strcpy(list->tail->phone.model, m);
  node* p = list->head;
  while(strcmp(p->phone.model, list->tail->phone.model)!=0){
    p = p->next;
    i += 1;
  }
  if(i<19){
    displayNode(p);
    return ;
  }
  printf("Not found.\n");
  return ;
}


