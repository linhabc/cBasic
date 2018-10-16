#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void readFile(elementtype cl[]);
int countLines(char *fn);

int main(){
  queue queue1, queue2;
  init_queue(&queue1);
  init_queue(&queue2);
  int waittime1=0, waittime2=0, totalWait=0, time, co1=1, co2=1;
  elementtype cl[10], tmp;
  readFile(cl);
  
  int n,i,j,l=countLines("client.txt");
  int num=0;
  do{
    printf("--------------------------------------------------------\n");
    printf("MENU Stimulate 2 serving table, 15minServingTime/client .\n");
    printf("1.Add client.\n");
    printf("2.Divide client and check waitting time.\n");
    printf("3.Statistic(total client, total waitting time, avg waitting time).\n");
    printf("4.Exit.\n");
    do{
      printf("Enter (1->4): ");
      scanf(" %d", &n);
    }while(n>4 || n<1);

    switch(n){
    case 1:
       readFile(cl);
        for(i=0;i<l-1;i++){
	printf("TIME: %d:%d, client: %d\n", cl[i].hour, cl[i].minute,cl[i].client);
	}
      break;
    
    case 2:
 
      for(i=0;i<l-1;i++){
	printf("TIME: %d:%d, client: %d\n", cl[i].hour, cl[i].minute,cl[i].client);
      
	for(j=1;j<=cl[i].client;j+=2){
	  //if queue is empty
	  if(isEmpty(&queue1)){
	    if(j==1){
	      time = cl[i].hour*60 + cl[i].minute - cl[i-1].hour*60 - cl[i-1].minute - 15;
	      if(time>=0){
		waittime1 = 0;
	      }
	      else if(time<0){
		waittime1 += time*(-1);
		enQueue(cl+i, &queue1);
	      }
	    }
	    else if(j>=3){
	      waittime1 += 15;
	      enQueue(cl+i, &queue1);
	    }
	    else  waittime1 = 0;
	  }
	  
	  
	  //if queue is not empty
	  else if(isEmpty(&queue1)==0){
	    tmp = seeHead(&queue1);
	    time = cl[i].hour*60 + cl[i].minute - tmp.hour*60 - tmp.minute - 15*co1;
	    if( time >= 0 ){
	      deQueue(&queue1);
	      waittime1 = 0;
	      co1 += 1;
	    }
	    else if( time < 0 ){
	      waittime1 += time*(-1);
	      enQueue(cl+i, &queue1);
	    }
	  }
	  if(j+1 <= cl[i].client){
	    if(isEmpty(&queue2)==0){
	      tmp = seeHead(&queue2);
	      time = cl[i].hour*60 + cl[i].minute - tmp.hour*60 - tmp.minute - 15*co2;
	      if( time >= 0 ){
		deQueue(&queue2);
		waittime2 = 0;
		co2 += 1;
	      }else if( time < 0 ){
		waittime2 += time*(-1);
		enQueue(cl+i, &queue2);
	      }
	    }
	  }


	  if(isEmpty(&queue2)){
	    if(j+1==2){
	      time = cl[i].hour*60 + cl[i].minute - cl[i-2].hour*60 - cl[i-2].minute - 15;
	      if(time>=0){
		waittime2 = 0;
	      }
	      else if(time<0){
		waittime2 += time*(-1);
		enQueue(cl+i, &queue2);
	      }
	    }
	    else  waittime2 = 0;
	  }
	  //if queue is empty and on the <= second loop
	  if(j+1<=cl[i].client && j>=3){
	    if(isEmpty(&queue2)){
	      enQueue(cl+i, &queue2);
	      waittime2 += 15;
	    }
	  }

	  //print result
	  printf("client number %d in queue 1 wait: %d\n", j, waittime1);
	  if(j+1<=cl[i].client)
	    printf("client number %d in queue 2 wait: %d\n", j+1, waittime2);
	}
	totalWait = waittime1 + waittime2 + totalWait;
	waittime1 = 0;
	waittime2 = 0;
	co1=1;
	co2=1;
      }

    
    
      break;
    
    case 3:
      for(i=0;i<l;i++){
	num += cl[i].client;
	printf("%d\n", num);
      }
      
      printf("Total number of clients is: %d\n", num);
      printf("Total wait time: %d\n", totalWait);
      break;
    }

  }while(n!=4);
  return 0;
}

void readFile(elementtype cl[]){
  FILE* fin = fopen("client.txt", "r");
  if(fin==NULL){
    printf("Failed to load file.\n");
    return;
  }
  int i,l=countLines("client.txt");
  for(i=0;i<l;i++){
    fscanf(fin, "%d:%d  %d", &cl[i].hour, &cl[i].minute, &cl[i].client);
  }
  
  fclose(fin);
}

int countLines(char *fn){
  FILE *fp = fopen(fn, "r");
  if (fp == NULL) {
    printf("Can not open file %s\n", fn);
    return(0);
  }
  
  char ch;
  int nLines = 1;
  
  while ( !feof(fp) ) {
    ch = fgetc(fp);
    if (ch == '\n') {
      nLines ++;
    }
  }
  
  fclose(fp);
  return(nLines);
}
