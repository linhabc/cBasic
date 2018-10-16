#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point{
  double x;
  double y;
}point_t;

typedef struct circle{
  point_t center;
  double radius;
}circle_t;

int is_intersec(circle_t* c1, circle_t* c2);
void auto_generate(circle_t* c1);
void manual_input(circle_t* c1);
void print_circle(int n, circle_t* c);
int max_count(int *count, int n);

int main(){
  srand(time(NULL));
  int i,n,a,*count,maxCountIndex;
  circle_t* c;
  
  printf("Enter the number of circle: ");
  scanf(" %d", &n);
  c=(circle_t*)malloc(n*sizeof(circle_t));
  count=(int*)malloc(n*sizeof(int));
  int intersecCircle[n][n];
  if(c==NULL){
    printf("Memory allocation failed.\n");
    return 1;
  }
  if(count==NULL){
    printf("Memory allocation failed.\n");
    return 1;
  }
  
  printf("Enter 1 for manual input,and 2 for auto generate circle: ");
  scanf(" %d", &a);
 
  if(a==1){
    for(i=0;i<n;i++){
      printf("Enter circle number %d: \n", i+1);
      manual_input((c+i));
    }
    print_circle(n, c);
    
  } else if(a==2){
    for(i=0;i<n;i++){
      auto_generate((c+i));
    }
    print_circle(n, c);
    
  }
  
  for(i=0;i<n;i++){
    *(count+i)=0;
    for(int j=0;j<n;j++){
      if(i!=j){
	if( is_intersec((c+i),(c+j)) ){
	  *(count+i)+=1;
	  intersecCircle[i][j]=1;
	}
      
	else{
	  intersecCircle[i][j]=0;
	}
      }else if(i==j){
	 intersecCircle[i][j]=0;
      }
    }
  }

  maxCountIndex = max_count(count,n);
  if(maxCountIndex!=0){
    printf("Circle has the most intersection is the circle number: %d\n", maxCountIndex+1);
    printf("And it intersecs with: \n");
    for(i=0;i<n;i++){
      if(intersecCircle[maxCountIndex][i]==1){
	printf("Circle %d\n", i+1);
      }
    }
  } else if(maxCountIndex==0){
    printf("No intersection.\n");
  }

  free(count);
  free(c);
  return 0;
}

int is_intersec(circle_t* c1, circle_t* c2){
  double x_dist, y_dist;
  x_dist = c1->center.x - c2->center.x;
  y_dist = c1->center.y - c2->center.y;
  return ( (c1->radius-c2->radius)*(c1->radius-c2->radius) < (x_dist*x_dist +y_dist*y_dist) &&  (x_dist*x_dist +y_dist*y_dist) < (c1->radius+c2->radius)*(c1->radius+c2->radius) );
}

void auto_generate(circle_t* c1){
  c1->center.x=rand()%100;
  c1->center.y=rand()%100;
  c1->radius=rand()%100+1;
}

void manual_input(circle_t* c1){
  printf("Enter x: ");
  scanf(" %lf", &c1->center.x);
  printf("Enter y: ");
  scanf(" %lf", &c1->center.y);
  printf("Enter radius: ");
  scanf(" %lf", &c1->radius);
}

void print_circle(int n, circle_t* c){
  for(int i=0;i<n;i++){
      printf("Circle number %d: \n", i+1);
      printf("x: %.2lf\n", (c+i)->center.x);
      printf("y: %.2lf\n", (c+i)->center.y);
      printf("radius: %.2lf\n", (c+i)->radius);
    }
}

int max_count(int *count, int n){
  int i,max=0,index=-1;
  for(i=0;i<n;i++){
    if(max<*(count+i)){
      max=*(count+i);
      index=i;
    }
  }
  return index;
}
