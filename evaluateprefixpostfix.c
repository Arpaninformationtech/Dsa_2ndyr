#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node* next;
}LL;

LL* createNode()
{
    LL* node= (LL*)malloc(sizeof(LL));
    node->val= 0;
    node->next= NULL;
    return node;
}

void push(LL** top, int value)
{
    LL* new_node= createNode();
    new_node->val= value;
    new_node->next= (*top);
    *top= new_node;
}

int pop(LL** top)
{
    LL* temp= *top;
    *top= (*top)->next;
    int value= temp->val;
    free(temp);
    return value;
}

void display(LL* ptr)
{

    while(ptr!=NULL)
    {
        printf("%d -> ", ptr->val);
        ptr= ptr->next;
    }
    printf("END\n");
}

void main()
{
    char* inp= malloc(100*sizeof(char)); int choice;
    printf("Enter 1 for postfix and 2 for prefix expression: ");
    scanf("%d", &choice);

    printf("Enter expression: \n");
    fflush(stdin);
    fgets(inp, 100, stdin);
    if(choice==2)
        inp= strrev(inp);
    inp[strlen(inp)]= '\0';

    LL* Head= NULL;
    char* token= strtok(inp, " ");
    while(token != NULL)
    {
        if(*token=='*' || *token=='+' || *token=='/' || *token=='-')
        {
            int num2= pop(&Head);
            int num1= pop(&Head);
            switch(token[0])
            {
                case '*':
                    push(&Head, num1*num2);
                    break;
                case '/':
                    push(&Head, num1/num2);
                    break;
                case '+':
                    push(&Head, num1+num2);
                    break;
                case '-':
                    push(&Head, num1-num2);
            }
        }
        else
            push(&Head, atoi(token));
        display(Head);
        token= strtok(NULL, " ");
    }
    printf("%d", Head->val);
}
