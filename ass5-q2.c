#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_LL(struct Node* head, int x) {
     struct Node* ptr = head;
     struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
     temp->data = x;
     if(head == NULL) {
          temp->next = NULL;
          return temp;
     }
     else {
          while(ptr->next != NULL) {
               ptr = ptr->next;
          }
          ptr->next = temp;
          temp->next = NULL;
     }
     return head;
}

void printList(struct Node* ptr) {
	while(ptr!=NULL) {
		printf("%d -> ",ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
};

int main() {
	int n, da, elem_no;
	printf("Enter number of lists: ");
	scanf("%d",&n);
	struct Node* head[n];
	struct Node* sing_head = (struct Node*)malloc(sizeof(struct Node));

	for(int i = 0; i < n; i++) {
		head[i] = NULL;
		printf("Enter number of elements of %d no. list: ",i+1);
		scanf("%d", &elem_no);
		for(int j = 0; j < elem_no; j++){
			printf("Enter %d no. element: ", j+1);
			scanf("%d", &da);
			head[i] = create_LL(head[i], da);
		}
	}

	printf("\nLinked List of Linked List created:\n");
	for(int i = 0; i < n; i++) {
		printList(head[i]);
		printf("\n");
		printf("|\n");
		printf("V\n");
	}
	printf("NULL\n");
	
	sing_head = head[0];
	for(int i=0; i<n; i++) {
		while((head[i]->next)!=NULL){
			head[i] = head[i]->next;
		}
		if(i < n-1){
		    head[i]->next = head[i+1];
		}
	}

	printf("\nThe converted singly linked_list is: ");
    printList(sing_head);
	return 0;
}