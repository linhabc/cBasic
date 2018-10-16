#include<stdio.h>
#include<string.h>
#include<stdio_ext.h> 
#define MAX 100

typedef struct PhoneAdress{
  char name[20];
  char tel[11];
  char email[25];
} PA;

int main()
{
  PA person[MAX];
  FILE *f;
  int i,n;

  printf("Enter the number of phone address: ");
  scanf("%d",&n);
  __fpurge(stdin);
  
  for(i=0;i<n;i++)
    {
      printf("The person number %d:\n",i+1);
      printf("\tname: "); fgets(person[i].name,20,stdin); person[i].name[strlen(person[i].name)]='\0';
      printf("\ttel: "); fgets(person[i].tel,11,stdin); person[i].tel[strlen(person[i].tel)]='\0';
      printf("\temail: "); fgets(person[i].email,25,stdin); person[i].email[strlen(person[i].email)]='\0';
    }
  
  if((f=fopen("PhoneAddress.txt","w+b"))==NULL)
    {
      printf("Cannot open file PhoneAddress.txt\n");
      return 1;
    }

  fwrite(person,sizeof(PA),n,f);
  fclose(f);
  printf("Completed!\n");

  return 0;
}
