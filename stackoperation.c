#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("stack is full");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("stack is Empty");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
       
    }
}
// peak operation in stack..
int peak(struct stack *sp,int i){
  if(sp->top-i+1<0){
    printf("Not a valid pos for the stack");
    return -1;
  }
  else return sp->arr[sp->top-i+1];
}

int main()
{
    struct stack *sp;
    sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("%d\n", isEmpty(sp));
    push(sp, 8);
    push(sp, 4);
    push(sp, 10);
    printf("%d\n", isEmpty(sp));
    // printf("popped %d from the stack\n",pop(sp));
    
    for (int j = 1; j <= sp-> top+1; j++)
    {
       printf("the value at pos %d is %d\n",j,peak(sp,j));
    }
    


    return 0;
}