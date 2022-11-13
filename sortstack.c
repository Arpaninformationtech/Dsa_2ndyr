#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. It initializes size of stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    // printf("%d pushed to stack\n", item);
}

void push_user(struct Stack* stack)
{
    if (isFull(stack))
        return;
    int item;
    printf("Enter value for stack: ");
    scanf("%d", &item);
    stack->array[++stack->top] = item;
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

//Function to display in stack format
void disp(struct Stack* stack)
{
    if(stack->top==-1)
        printf("Stack is Empty.");
    else
        for(int i= stack->top; i>=0; i--)
            printf("\n| %d |", stack->array[i]);
}

void sortedInsert(struct Stack* s, int x)
{
    if (s->top==-1 || x > peek(s))
    {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}

// void sortStack(struct Stack* s)
// {
//     if (s->top != -1)
//     {
//         int x = pop(s); 
//         sortStack(s); 
//         sortedInsert(s, x);
//     }
// }
void sortStack(struct Stack* s)
{
    if (s->top == -1)
    return;

    int num = pop(s);
//  recursive approach 
    sortStack(s);

    sortedInsert(s,num);
    
}

void main()
{
    int sz1, sz2, sz3;
    printf("\nEnter size of stack 1: ");
    scanf("%d", &sz1);
    struct Stack* stack1= createStack(sz1);
    for(int i= 0; i<sz1; i++)
        push_user(stack1);

    printf("\nEnter size of stack 2: ");
    scanf("%d", &sz2);
    struct Stack* stack2= createStack(sz2);
    for(int i= 0; i<sz2; i++)
        push_user(stack2);

    printf("\nEnter size of stack 3: ");
    scanf("%d", &sz3);
    struct Stack* stack3= createStack(sz3);
    for(int i= 0; i<sz3; i++)
        push_user(stack3);

    int t_sz= sz1+sz2+sz3;
    struct Stack* t_stack= createStack(t_sz);
    for(int i= 0; i<t_sz; i++)
    {
        if(!isEmpty(stack1))
            push(t_stack, pop(stack1));
        else if(!isEmpty(stack2))
                push(t_stack, pop(stack2));
        else if(!isEmpty(stack3))
                push(t_stack, pop(stack3));
    }

    sortStack(t_stack);

    printf("\nSorted Stack is: \n");
    disp(t_stack);
}
