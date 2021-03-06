#include "linkedAddr.h"

typedef struct{
  int t1;
  int t2;
  int result1;
  int result2;
}team_t;

typedef struct{
  char id[30];
  team_t team[100];
}round_t;

int readTxt(char file[], linkList *list, round_t *round);
void searchById(int value, int n, linkList *list);
void update(linkList *list,int l, round_t *round);
void statistic(linkList *list);

int main(){
  int n, l;
  linkList list;
  initList(&list);
  round_t round[100];
  
  do{
    printf("--------------------------------------\n");
    printf("MENU\n");
    printf("1.Read txt and print info of teams\n");
    printf("2.Print schedual \n");
    printf("3.Update info about tournament \n");
    printf("4.Statisic \n");
    printf("5.exit \n");
    do{
      printf("Enter: ");
      scanf(" %d", &n);
    }while(n>5 || n<1);

    switch(n){
    case 1:
      l = readTxt("bongda.txt", &list, round);
      printf("ID          TEAM SCORE GOAL CONCEDE\n");
      traversingList(&list);
      break;
      
    case 2:
      for(int i=0; i<l-1; i++){
	printf("%s\n", round[i].id);
	
	for(int j=0; j<l/2; j++){
	  searchById(round[i].team[j].t1, l, &list);
	  printf(" - ");
	  searchById(round[i].team[j].t2, l, &list);
	  printf("\n");
	}
      }

      break;

    case 3:
      update(&list, l, round);
      printf("ID          TEAM SCORE GOAL CONCEDE\n");
      traversingList(&list);

      break;

    case 4:
      statistic(&list);
      
      break;
      
    }

    
  }while(n != 5);


  freeList(&list);
  return 0;
}

int readTxt(char file[], linkList *list, round_t *round){
  FILE *f = fopen(file, "r");
  if(f == NULL){
    printf("Cannot opened file.\n");
    return 0;
  }
  
  int n;

  fscanf(f, "%d", &n);

  elType team[n];
  for(int i=0; i<n; i++){
    fscanf(f, "%d", &team[i].id);
    fscanf(f, "     %[^\n]s", team[i].name);
    team[i].score = 0;
    team[i].goal = 0;
    team[i].concede = 0;

    insertAtHead(team[i], list);
  }

  char tempStr[10];
  for(int i=0; i<n-1; i++){
    fgets(tempStr, 10, f);
    fscanf(f, "%[^\n]s", (round+i)->id);
    for(int j=0; j<n/2; j++){
      fscanf(f, "%d", &(round+i)->team[j].t1);
      fscanf(f, "%d",  &(round+i)->team[j].t2);
    }
  }

  fclose(f);
  return n;
}


node *search(int value, int n, linkList *list){
  node* p;
  for(p = list->root; p!= NULL; p=p->next){
    if(p->element.id == value)
      return p;
  }
}

void searchById(int value, int n, linkList *list){
  node* p;
  for(p = list->root; p!= NULL; p=p->next){
    if(p->element.id == value)
      printf("%-10s", p->element.name);
  }
}

void update(linkList *list,int l, round_t *round){
  int g1,g2;
  node *team1, *team2;
  for(int i=0; i<l-1; i++){
    printf("%s\n", round[i].id);
	
    for(int j=0; j<l/2; j++){
      searchById(round[i].team[j].t1, l, list);
      printf(" - ");
      searchById(round[i].team[j].t2, l, list);
      printf(": ");
      scanf("%d-%d", &g1, &g2);

      team1 = search(round[i].team[j].t1, l, list);
      team2 = search(round[i].team[j].t2, l, list);

      if(g1>g2)
	team1->element.score += 3;
      else if(g1<g2)
	team2->element.score += 3;
      else if(g1==g2){
	team1->element.score++;
	team2->element.score++;
      }

      team1->element.goal += g1;
      team1->element.concede += g2;

      team2->element.goal += g2;
      team2->element.concede += g1;
    }
  }
  
}

void statistic(linkList *list){
  int min=100;
  node* p;
  for(p = list->root; p!= NULL; p = p->next){
    if(p->element.score < min)
      min = p->element.score;
  }

  printf("Eliminate:\n");
  for(p = list->root; p!= NULL; p = p->next){
    if(p->element.score == min){
       printf("%d  %15s  %d    %d    %d\n", p->element.id, p->element.name, p->element.score, p->element.goal, p->element.concede);
       list->cur = p;
       deleteCur(list);
    }
  }
  traversingList(list);
}
