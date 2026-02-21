#include <stdio.h>
#include <stdlib.h>
#include <climits>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // self referential structure

} *first = NULL; // empty linkedList

void create(int A[], int n)
{
    int i;                                              // helps travesing the linkedList
    struct Node *t, *last;                              // last points to the last node help to add new elements at the end
    first = (struct Node *)malloc(sizeof(struct Node)); // here we create linked list using malloc function
    first->data = A[0];                                 // we assign first element of array
    first->next = NULL;                                 // element next ti the first is empty now
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//itereative version
int Max(struct Node *p){
    int max= INT_MIN;
    while(p){
        if(p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

//Recursive version
int RMax(){
    
}
int main()
{
    int A[] = {3, 5, 7, 10, 15,78,98,54,234};

    create(A, 9); // linkedList is created
    printf("Max is %d\n", Max(first));

    return 0;
}