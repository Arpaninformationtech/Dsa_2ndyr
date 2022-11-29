#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int IsEmptyStack(struct stack *ptr)
{
    if(ptr->top ==-1)
    return 1;
    else
    return 0;
}

int IsFullStack(struct stack *ptr)
{
    if(ptr->top == ptr->size -1)
    return 1;
    else
    return 0;
}

void push(struct stack *ptr, int val)
{
    if(IsFullStack(ptr)==1)
    printf("Stack Overflow\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;

    }
}

int pop(struct stack *ptr)
{
    if(IsEmptyStack(ptr)==1)
    {
       
        return -1;
    } 
    else
    {
        int ele = ptr->arr[ptr->top];
        ptr->top--;
        return ele;
    }
}
int peekStack(struct stack* ptr)
{
    if(IsEmptyStack(ptr)==1)
    {
        
        return -1;
    } 
    else
    {
        int ele = ptr->arr[ptr->top];
        return ele;
    }
}
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

struct queue* createQueue(int size)
{
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    q->size=size;
    q->f=-1;
    q->r=-1;
    q->arr=(int*) malloc(q->size*sizeof(int));

    return q;
}

int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
int peekQueue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
       
        return -1;
    }
    else{
        a = q->arr[q->f+1];
    }
    return a;
}
 

int main()
{
    int n;
    printf("Enter the size of the required permutation\n");
    scanf("%d",&n);

    struct queue* P = createQueue(n);
    struct queue* Q = createQueue(n);

    for(int i=1; i<=n;i++)
    {
        enqueue(P, i);
    }

    struct stack* stack = (struct stack*) malloc(sizeof(struct stack));
    stack->size=n;
    stack->top=-1;
    stack->arr= (int*) malloc(stack->size*sizeof(int));

    printf("Enter the required permutation (with space between two elements)\n");
    for(int i=0; i<n; i++)
    {
        int ele;
        scanf("%d",&ele);
        enqueue(Q, ele);
    }
    int val;
    int ans =0;
    int t=n;
    while(n--)
    {
        val = dequeue(Q);
        if(val>t)
        {
            printf("Invalid Permutation\n");
            return;
        }
        if(val == peekQueue(P))
        {
            dequeue(P);
        }
        else if(val==peekStack(stack))
        {
            pop(stack);
        }
        else if(val > peekQueue(P) && !isEmpty(P))
        {
            while(peekQueue(P)!= val)
            {
                push(stack, dequeue(P));
            }
            dequeue(P);
        }
        else
        {
            ans=1;
            break;
        }
    }

    if(ans==0)
    printf("This is a stack permutation\n");
    else
    printf("This is not a stack permutation\n");
}

