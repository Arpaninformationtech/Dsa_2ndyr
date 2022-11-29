#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Stack type
struct stack
{
    int top;
    int size;
    int *array;
};
int isEmpty(struct stack *stack)
{
    return stack->top == -1;
}
int pop(struct stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct stack *stack, int op)
{
    stack->array[++stack->top] = op;
}
int Postfix_Evaluation(char* exp)
{
    struct stack* stack = (struct stack*) malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=strlen(exp);
    stack->array=(int*) malloc(stack->size*sizeof(int));

    for (int i = 0; i<strlen(exp); ++i)
    {
        
        if (exp[i] == ' ')
            continue;

        else if (isdigit(exp[i]))
        {
            int num = 0;

            
            
            while (isdigit(exp[i]))
            {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;

            
            push(stack, num);
        }
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);

            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val2 - val1);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack); 
}
int Prefix_Evaluation(char *exp)
{
    struct stack *stack = (struct stack *) malloc(sizeof(struct stack));
    stack->top = -1;
    stack->size = strlen(exp);
    stack->array = (int *)malloc(stack->size * sizeof(int));

    for (int i = strlen(exp)-1; i >= 0;i--)
    {
       
        if (exp[i] == ' ')
        {
            continue;
        }
        else if (isdigit(exp[i]))
        {
            int sum = 0;
            int n = 1;
            while (exp[i]!= ' ')
            {
                sum = sum + ((int)(exp[i]-'0')) * n;
                n = n * 10;
                i--;
            }
            
            i++;
            push(stack, sum);
        }
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, val2 + val1);
                break;
            case '-':
                push(stack, val1 - val2);
                break;
            case '*':
                push(stack, val2 * val1);
                break;
            case '/':
                push(stack, val2 / val1);
                break;
            }
        }
    }
    return pop(stack);
}
int main()
{
    char exp1[] = "112 34 5 * +";
    char exp2[]="+ * 5 34 112";
    printf("Answer after postfix evaluation is: %d\n", Postfix_Evaluation(exp1));
    printf("Answer of Prefix Evaluation is : %d\n",Prefix_Evaluation(exp2));
    return 0;
}