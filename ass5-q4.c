#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->key = data;
    temp->left = temp->right = NULL;
    return (temp);
}

struct Node *createCBT(int *arr, int i, int n)
{
    struct Node *root = NULL;
    if (i < n)
    {
        root = newNode(arr[i]);
        root->left = createCBT(arr, 2 * i + 1, n);
        root->right = createCBT(arr, 2 * i + 2, n);
    }
    return root;
}

void sort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

struct Node *createBST(int *arr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    struct Node *root = newNode(arr[mid]);
    root->left = createBST(arr, start, mid - 1);
    root->right = createBST(arr, mid + 1, end);

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main()
{
    int n;
    printf("Enter the total number of integers: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // Creating the Complete Binary Tree
    struct Node *rootCBT = createCBT(arr, 0, n);

    // Creating the Binary Ssearch Tree
    // At first we sort the array in ascending order
    sort(arr, n);
    struct Node *rootBST = createBST(arr, 0, n - 1);

    printf("---------------COMPLETE BINARY TREE---------------\n");
    printf("Inorder Traversal: \n");
    inorder(rootCBT);
    printf("\nPreorder Traversal: \n");
    preorder(rootCBT);
    printf("\nPostorder Traversal: \n");
    postorder(rootCBT);

    printf("\n--------------BINARY SEARCH TREE-----------------\n");
    printf("Inorder Traversal: \n");
    inorder(rootBST);
    printf("\nPreorder Traversal: \n");
    preorder(rootBST);
    printf("\nPostorder Traversal: \n");
    postorder(rootBST);

    printf("\n");
    return 0;
}