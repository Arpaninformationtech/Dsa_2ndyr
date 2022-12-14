#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100

// Queue data structure
struct queue {
    int data[MAX_N];
    int head;
    int tail;
};

// Stack data structure
struct stack {
    int data[MAX_N];
    int top;
};

// Initialize queue with given permutation
void init_queue(struct queue *q, int permutation[], int n) {
    for (int i = 0; i < n; i++) {
        q->data[i] = permutation[i];
    }
    q->head = 0;
    q->tail = n;
}

// Dequeue the first element from the queue
int dequeue(struct queue *q) {
    return q->data[q->head++];
}

// Enqueue an element at the end of the queue
void enqueue(struct queue *q, int element) {
    q->data[q->tail++] = element;
}

// Initialize stack to be empty
void init_stack(struct stack *s) {
    s->top = 0;
}

// Push an element onto the top of the stack
void push(struct stack *s, int element) {
    s->data[s->top++] = element;
}

// Pop the top element from the stack
int pop(struct stack *s) {
    return s->data[--s->top];
}

// Check if given permutation is a stack permutation
bool is_stack_permutation(int permutation[], int n) {
    struct queue q;
    struct stack s;
    init_queue(&q, permutation, n);
    init_stack(&s);

    int x = dequeue(&q);
    push(&s, x);

    while (s.top > 0) {
        int y = pop(&s);
        enqueue(&q, y);
        if (y != permutation[q.head]) {
            return false;
        }
        x = dequeue(&q);
        push(&s, x);
    }

    return q.tail == n && q.head == n;
}

int main() {
    int n;
    printf("Enter the length of the permutation: ");
    scanf("%d", &n);

    int permutation[MAX_N];
    printf("Enter the permutation: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &permutation[i]);
    }

    printf("The given permutation is a stack permutation: %d\n", is_stack_permutation(permutation, n));

    return 0;
}

