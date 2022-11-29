#include <stdio.h>
#include <stdlib.h>

/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;


/* 
 * Functions to create and display list
 */
void createList(int n);
void traverseList();

struct node * deleteAtEnd(struct node * head){
    struct node * p = head;
    struct node * q = head->next;

    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    // p->next=NULL;
    free(q);
    
    return head; 
}

int getCurrSize(struct node* ptr){
    int size=0;

    while(ptr !=NULL){
        ptr  = ptr ->next;
        size++;
    }
    return size;
}

//function to insert after nth node
void insertAfterNthNode(int n, int data, struct node* head)
{
    int size = getCurrSize(head);

    struct node* newNode = (struct node*) malloc(sizeof(struct node)); 
    newNode->data = data;
    newNode->next = NULL;
    
    // Can't insert if position to insert is greater than size of Linked List
    // can insert after negative pos
    if(n < 0 || n > size) 
        printf("Invalid position to insert\n"); 
        
    // inserting first node
    else if(n == 0){
        newNode->next = head; 
        head = newNode;
    }
    
    else 
    {
        // temp used to traverse the Linked List
        struct node* temp = head; 
        
        // traverse till the nth node
        while(--n)
            temp=temp->next;
        
        // assign newNode's next to nth node's next
        newNode->next= temp->next;
        // assign nth node's next to this new node
        temp->next = newNode;
        // newNode inserted b/w 3rd and 4th node
    }
}

int main()
{
    int n;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

    createList(n);

    printf("\nData in the list \n");
    traverseList();

    printf("\nafter inserting nth element\n");
     
    insertAfterNthNode(1,34,head);
    traverseList();
    printf("\nafter deleting last element \n");
    head = deleteAtEnd(head);
    traverseList();
   
    return 0;
}

/*
 * Create a list of n nodes
 */

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    // Terminate if memory not allocated
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }


    // Input data of node from the user
    printf("Enter the data of node 1: ");
    scanf("%d", &data);

    head->data = data; // Link data field with data
    head->next = NULL; // Link address field to NULL


    // Create n - 1 nodes and add to list
    temp = head;
    for(i=2; i<=n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));

        /* If memory is not allocated for newNode */
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }

        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; // Link data field of newNode
        newNode->next = NULL; // Make sure new node points to NULL 

        temp->next = newNode; // Link previous node with newNode
        temp = temp->next;    // Make current node as previous node
    }
    
}


/*
 * Display entire list
 */
void traverseList()
{
    struct node *temp;
    
    // Return if list is empty 
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    
    temp = head;
    while(temp != NULL)
    {
        printf("Data = %d\n", temp->data); // Print data of current node
        temp = temp->next;                 // Move to next node
    }
}

