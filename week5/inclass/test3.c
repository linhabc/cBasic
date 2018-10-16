#include <stdio.h>

typedef struct phoneaddress(){
  char name[20];
  char tel[10];
  char email[20];
}PA_t;


int main(){
  PA_t *phone;
  int i1,i2;
  FILE* fp=fopen("PhoneAddress.txt", "r+b"); 
  if(fp==NULL){
    printf("cannot opened file");
    return 1;
  }
  phone=(PA_t *)malloc(3*sizeof(PA_t));
  if(phone==NULL){
    printf("cannot allocated memory");
    return 1;
  }
  
  fseek(fp,3*sizeof(PA_t),SEEK_SET);
  i1=fread(phone,sizeof(PA_t),1,fp);
  fssek(fp,3*sizeof(PA_t),SEEK_CUR);
  i2=fread(phone+1,sizeof(PA_t),1,fp);

  
  
  return 0;
}(
