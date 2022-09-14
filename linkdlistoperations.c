#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// linkdlist traversal
void linkdlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// insert at begining
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// insert at end;
struct Node * insertAtEnd(struct Node *head,int data){
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
     struct Node * p = head;
      while(p->next!=NULL){
        p=p->next;
      }
      p->next = ptr;
      ptr->next = NULL;
    return head;
}
//  insert after node
 struct Node * insertAfterNode(struct Node *head,int data,struct Node * prevNode){
    struct Node * ptr =(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next = prevNode->next ;
    prevNode->next = ptr;

     return head;
 }
//  deleting at first
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head=head->next;
    free(ptr);
    return head; 
}
// delete at index
struct Node * deleteAtIndex(struct Node * head,int index){
    struct Node * p = head;
    struct Node * q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    
    return head; 
}
// delete at last;
struct Node * deleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->next;

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

    third->data = 66;
    third->next = NULL;
     
    linkdlisttraversal(head);
    head = insertAtFirst(head,56);
    linkdlisttraversal(head);
    head = insertAtEnd(head,77);
    linkdlisttraversal(head);
    head = insertAfterNode(head,4,third);
    printf("....\n");
    linkdlisttraversal(head);
    head = deleteFirst(head);
    printf("After deleting first element\n");
    linkdlisttraversal(head);
    printf("After deleting indexed  element\n");
    head = deleteAtIndex(head,2);
    linkdlisttraversal(head);
    printf("After deleting last element\n");
    head = deleteAtEnd(head);
    linkdlisttraversal(head);

    return 0;
}

