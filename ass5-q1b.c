#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head;
void lastinsert()  
{  
    struct node *ptr,*temp;  
    int item;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        item=rand()%10000;  
        ptr->data = item;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;   
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL; 
          
        }  
    } 
} 
void swap(struct node *a, struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
void display()  
{  
    struct node *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nPrinting values after sorting . . . . .\n");   
        while (ptr!=NULL)  
        {  
            printf("%d---->",ptr->data);  
            ptr = ptr -> next;  
        }
        printf("\n");
    }  
}    
void bsort() 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *lptr = NULL; 
  
    if (head==NULL) return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = head; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->data > ptr1->next->data) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped);
    display(); 
} 

void main(int argc,char *argv[])
{
	clock_t start,end;
	start=clock();	
	int n=atoi(argv[1]);
	for(int i=1;i<n;i++)
		lastinsert();
	bsort();
	end=clock();
	double duration=((double)end-start)/CLOCKS_PER_SEC;
	printf("Time taken to execute in seconds:%f \n",duration);
}
