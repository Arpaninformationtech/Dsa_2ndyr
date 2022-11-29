#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned cap;
    int *array;
};

// function to create a stack of given cap. It initializes size of stack as 0
struct Stack *createStack(unsigned cap)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->cap = cap;
    stack->top = -1;
    stack->array = (int *)malloc(stack->cap * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->cap - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.
void push(struct Stack *stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// for taking user input
void push_user(struct Stack *stack)
{
    if (isFull(stack))
        return;
    int item;
    // printf("Enter value for stack: ");
    scanf("%d", &item);
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack.
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the top from stack
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// Function to display in stack format
void disp(struct Stack *stack)
{
    if (isEmpty(stack))
        printf("Stack is Empty.");
    else
        for (int i = stack->top; i >= 0; i--)
            printf("\n| %d |", stack->array[i]);
}

void sortedInsert(struct Stack *s, int x)
{
    if (s->top == -1 || x > peek(s))
    {
        push(s, x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s, temp);
}

void sortStack(struct Stack *s)
{
    if (s->top != -1)
    {
        int x = pop(s);
        sortStack(s);
        sortedInsert(s, x);
    }
}

void removeDuplicate(struct Stack *s)
{
    struct Stack *s1 = createStack(s->cap);
    push(s1, pop(s));
    int temp;
    while (!isEmpty(s))
        if (peek(s) != peek(s1))
            push(s1, pop(s));
        else
            temp = pop(s);

    struct Stack *s2 = createStack(s1->top + 1);
    while (!isEmpty(s1))
        push(s2, pop(s1));

    printf("\nStack with Duplicates removed:");
    disp(s2);
}

// To duplicate a stack from a given stack
struct Stack *duplicateStack(struct Stack *s)
{
    int temp = s->top;
    struct Stack *s1 = createStack(s->cap);
    struct Stack *s2 = createStack(s->cap);
    for (int i = 0; i < s->cap; i++)
        push(s1, pop(s));

    for (int i = 0; i < s->cap; i++)
        push(s2, pop(s1));
    s->top = temp;
    return s2;
}

int main()
{
    int n;
    printf("Enter size of the stack: ");
    scanf("%d", &n);
    struct Stack *stack1 = createStack(n);
    printf("Enter the elements of stack\n");
    for (int i = 0; i < n; i++)
        push_user(stack1);

    struct Stack *stack2 = duplicateStack(stack1);
    sortStack(stack1);
    removeDuplicate(stack1);
    // Displaying original stack
    printf("\nOriginal stack\n");
    disp(stack2);
    return 0;
}