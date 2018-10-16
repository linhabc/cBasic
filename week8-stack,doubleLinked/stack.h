#define MAX 50
typedef int Eltype;
typedef Eltype stacktype[MAX];
int top;

void initialize(stacktype stack){
  top=0;
}

int is_empty(stacktype stack){
  return (top==0);
}

int is_full(stacktype stack){
  return (top==MAX);
}

void push(Eltype el, stacktype stack){
  if(full(stack))
    printf("stack overflow\n");
  esle stack[top++]= el;
}

Eltype pop(stacktype stack){
  if(empty(stack))
    printf("stack empty\n");
  else return stack[--top];
}
