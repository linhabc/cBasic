#include <stdio.h>

typedef struct phoneaddress{
  char name[20];
  char tel[10];
  char email[20];
}phoneaddress_t;

int main(){
  phoneaddress_t phone[100];
  
  for(int i=0; i<3; i++){
    printf("Enter number %d name: ", i+1);
    scanf(" %s", phone[i].name);
    printf("Enter number %d telephone number: ", i+1);
    scanf(" %s", phone[i].tel);
    printf("Enter number %d email: ", i+1);
    scanf(" %s", phone[i].email);
  }

  FILE *fout = fopen("directory.txt", "w+b");
  if(fout==NULL){
    printf("Cannot opened the file");
    return 0;
  }

  fwrite(phone, sizeof(phoneaddress_t), 10, fout);
  

  fclose(fout);
  return 0;
}
