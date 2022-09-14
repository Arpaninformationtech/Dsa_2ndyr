#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// linkdlist traversal
void linkdlisttraversal(struct Node *head)
{
    struct Node * ptr = head;
    do{
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;

    }while(ptr!=head);
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    // Allocate memory for nodes in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 24;
    third->next = NULL;
     
    linkdlisttraversal(head);
    return 0;
}

