#include<stdio.h>
#include<stdlib.h>

struct node {
    int coeff;    //coefficients
    int exp;   // exponent
    struct node *next;
};

typedef struct {
    struct node *front;
    struct node *rear;
}queue;

// Function to create a new node
struct node* createNode(int coeff, int exp) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Enqueue function (insert at rear)
void enqueue(queue *q, int coeff, int exp) {
    struct node* n = createNode(coeff, exp);
    if (q->rear == NULL) {
        q->front = q->rear = n;
        return;
    }
    q->rear->next = n;
    q->rear = n;
}

void addPolynomials(queue *P1, queue *P2, queue *Result) {

    struct node *t1 = P1->front;
    struct node *t2 = P2->front;

    while (t1 != NULL && t2 != NULL) {

        if (t1->exp == t2->exp) {
            int sum = t1->coeff + t2->coeff;

            if (sum != 0)   
                enqueue(Result, sum, t1->exp);

            t1 = t1->next;
            t2 = t2->next;
        }

        else if (t1->exp > t2->exp) {
            enqueue(Result, t1->coeff, t1->exp);
            t1 = t1->next;
        }

        else {  
            enqueue(Result, t2->coeff, t2->exp);
            t2 = t2->next;
        }
    }

    // If P1 still has terms
    while (t1 != NULL) {
        enqueue(Result, t1->coeff, t1->exp);
        t1 = t1->next;
    }

    // If P2 still has terms
    while (t2 != NULL) {
        enqueue(Result, t2->coeff, t2->exp);
        t2 = t2->next;
    }
}

// Display polynomial in mathematical format
void display(queue q) {
    struct node* temp = q.front;
    if (!temp) {
        printf("0\n");
        return;
    }

    while (temp) {
        if (temp->coeff != 0) {
            printf("%dx^%d", temp->coeff, temp->exp);
            if (temp->next && temp->next->coeff > 0)
                printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue P1 = {NULL, NULL};
    queue P2 = {NULL, NULL};
    queue Result = {NULL, NULL};

    // Add terms to P1
    enqueue(&P1, 5, 3); 
    enqueue(&P1, 4, 2); 
    enqueue(&P1, 2, 1);
    enqueue(&P1, 7, 0); 

    // Add terms to P2
    enqueue(&P2, 3, 3); 
    enqueue(&P2, 6, 1); 
    enqueue(&P2, 1, 0); 

    printf("P1 = ");
    display(P1);

    printf("P2 = ");
    display(P2);

    addPolynomials(&P1, &P2, &Result);

    printf("Sum is = ");
    display(Result);

    return 0;
}
