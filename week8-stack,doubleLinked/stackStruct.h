#define MAX 50
typedef int Eltype;
typedef struct stackRec{
  Eltype storage[MAX];
  int top;
};

typedef struct stackRec stackType;

void initialize(stackType *stack){
  (*stack).top=0;
}

int is_empty(stackType stack){
  return (stack.top== 0);
}

int is_full(stackType stack){
  return (stack.top == MAX);
}

void push(Eltype el, stackType* stack){
  if(full(*stack))
     printf("stack overflow\n");
  else ((*stack).storage[stack->top++] = el);
}

Eltype pop(stackType *stack){
  if(is_empty(*stack))
    printf("empty stack\n");
  else return (stack->storage[--(stack->top)]);
}
