#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node into a linked list at a prime position
void insertAtPrimePosition(struct Node **head, int data)
{
    // Create a new node
    struct Node *node = createNode(data);

    // If the linked list is empty, add the new node as the head
    if (*head == NULL)
    {
        *head = node;
        return;
    }

    // Check if the first element of the linked list is prime
    int count = 0;
    for (int i = 2; i <= (*head)->data / 2; i++)
    {
        if ((*head)->data % i == 0)
        {
            count++;
            break;
        }
    }

    // If the first element of the linked list is prime, add the new node before it
    if (count == 0)
    {
        node->next = *head;
        *head = node;
        return;
    }

    // Otherwise, find the first prime element in the linked list
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        count = 0;
        for (int i = 2; i <= temp->
