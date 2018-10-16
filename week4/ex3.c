#include <stdio.h>
#define MAX 100

typedef struct student{
  int ID;
  char name[MAX];
  int phoneNum;
  float score;
}

int main(){
  FILE*fFile = fopen("class.txt", "r");
  


  return 0;
}

void LineRead(FILE* fin){
  char buff[MAX];
  while(fgets(buff,MAX,fin) != NULL){


  }

}
