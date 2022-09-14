#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node * N1=(struct Node *)malloc(sizeof(struct Node));
    struct Node * N2=(struct Node *)malloc(sizeof(struct Node));
    struct Node * N3=(struct Node *)malloc(sizeof(struct Node));
    // linking nodes
    N1->next=N2;
    N1->prev=NULL;
    N1->data=3;
    // ..
      N2->next=N3;
    N2->prev=N1;
    N2->data=4;
    // 
     N3->next=NULL;
    N3->prev=N2;
    N3->data=7;

    return 0;
}
