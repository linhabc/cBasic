#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Phone{
  char model[10];
  int storage;
  float display;
}phone_t;

void convertToDat(FILE* fin,FILE* fout, phone_t phone[]);
void readDat(FILE* fin, phone_t phone[]);
void printModel(phone_t phone[]);
void searchModel(phone_t phone[]);


int main(){
  int a;
  phone_t* phone;
  phone = (phone_t *)malloc(20*sizeof(phone_t));
  
  FILE* fin = fopen("phone.txt", "r");
  FILE* fout = fopen("phone.dat", "w+b");
  if(fin==NULL|| fout==NULL ){
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
    printf("6.store ind=for in linked list to phoneDB.dat\n");
    printf("7.exit\n");
    do{
      printf("Enter(1-7) : ");
      scanf(" %d", &a);
    }while(a>7 || a<1);

    switch(a){
    case 1:
      convertToDat(fin,fout,phone);
      printf("done\n");
      break;
    case 2:
      readDat(fout, phone);
      break;
    case 3:
      printModel(phone);
      break;
    case 4:
      searchModel(phone);
      break;
      
    }

  }while(a!=5);

  free(phone);
  fclose(fin);
  fclose(fout);

  return 0;
}

void convertToDat(FILE* fin,FILE* fout, phone_t phone[]){
  int i;
  for(i=0;i<20;i++){
    //fgets(phone[i].model, 10, fin);
    fscanf(fin, " %10s", phone[i].model);
    fscanf(fin, " %d", &phone[i].storage);
    fscanf(fin, " %f", &phone[i].display);
  }
  fwrite(phone, sizeof(phone_t), 20, fout);
}

void readDat(FILE* fin, phone_t phone[]){
  int c,i,h,t;
  fread(phone, sizeof(phone_t), 20, fin);
  do{
    printf("Read full or one part(1 for full, 2 for part): ");
    scanf(" %d", &c);
  }while(c>2 || c<1);
  
  switch(c){
  case 1:
    printf("Model     storage display\n");
    for(i=0;i<20;i++){
      printf("%10s%8d%5.1f\n", phone[i].model, phone[i].storage, phone[i].display);
    }
    break;
    
  case 2:
    printf("Enter head and tail(h/t): ");
    do{
       scanf(" %d/%d", &h,&t);
    }while(h>t);
    printf("Model     storage display\n");
    for(i=h;i<=t;i++){
      printf("%10s%8d%5.1f\n", phone[i].model, phone[i].storage, phone[i].display);
    }
  }

}

void printModel(phone_t phone[]){
  int i;
  printf("Model     storage display\n");
  for(i=0;i<20;i++){
      printf("%10s%8d%5.1f\n", phone[i].model, phone[i].storage, phone[i].display);
  }
}

void searchModel(phone_t phone[]){
  printf("Enter model: ");
  char model[10];
  scanf(" %s", model);
  int i;
  for(i=0;i<20;i++){
    if(!strcmp(model, phone[i].model)){
      printf("%10s%8d%5.1f\n", phone[i].model, phone[i].storage, phone[i].display);
      break;
    }
  }
}
