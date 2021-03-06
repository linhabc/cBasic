#include <stdio.h>
 #include <stdlib.h>
#include "queue(OS).h"

int main(){
  queue queue1;
  init_queue(&queue1);
  node* node_addr = (node*)malloc(sizeof(node));
  
  int i, n, n1;
  int memoCap, memoUse=0, numPro=0; //numPro:number of process running
  int check=0;
  printf("Enter number of paralell processes: ");
  scanf(" %d", &n1);
  printf("Enter memory capacity(MB): ");
  scanf(" %d", &memoCap);
  do{
    printf("---------\n");
    printf("MENU\n");
    printf("1.Creat new program( with neccesary memory and ID).\n");
    printf("2.Kill a programe.\n");
    printf("3.Show the status of running and waitting programe.\n");
    do{
      printf("Enter(1->3): ");
      scanf(" %d", &n);
    }while(n>3 || n<1);

    elementtype *process;
    switch(n){
    case 1:
      process = readNode();
      if(numPro<n1 && check==0){
	memoUse += process->memory;
	if(memoUse>memoCap){
	  memoUse -= process->memory;
	  printf("Enqueue as there is not enough memory(%d vs %d).\n",(memoCap-memoUse),process->memory);
	  enQueue(process,&queue1);
	  check = 1;
	}
	else{
	  numPro += 1;
	  if(numPro == n1){
	    printf("Success, full paralell process.\n");
	    enQueue(process,&queue1);
	  }else{
	    printf("success, remaining memory: %d.\n", (memoCap-memoUse));
	    enQueue(process,&queue1);
	  }
	}
      }
      else{
	if(check==0)
	  printf("Enqueue as Full process in paralell.\n");
	if(check==1)
	  printf("Enqueue as full memory.\n");
	enQueue(process,&queue1);
      }
      break;
    case 2:
      process = deQueue(&queue1);
      node_addr = queue1.head;
      numPro=0;
      memoUse=0;
      for(node_addr;node_addr!=NULL;node_addr=node_addr->next){
	if(memoUse<=memoCap && numPro<=n1){
	  if((memoUse+node_addr->element->memory)<memoCap){
	    memoUse = memoUse+node_addr->element->memory;
	    numPro+=1;
	  }
	}else{
	  break;
	}
      }
	  
      break;
    case 3:
      printf("Running process:\n");
      node_addr = queue1.head;
      for(i=0;i<numPro;i++){
	printf("ID: %5d       Memory: %5d\n", node_addr->element->ID,node_addr->element->memory);
	node_addr = node_addr->next;
      }
      printf("\n");
      printf("Watting process:\n");
      for(node_addr;node_addr!=NULL;node_addr=node_addr->next){
	printf("ID: %5d       Memory: %5d\n", node_addr->element->ID,node_addr->element->memory);
      }
      printf("\n");
      break;
    }
  
  }while(n!=4);

  freelist(&queue1);
  return 0;
}
