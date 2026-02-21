//Count and Sum  

#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int data;
    struct Node *list; // self referential structure

} *first = NULL; // empty linkedList

void create(int A[], int n)
{
    int i;                                              // helps travesing the linkedList
    struct Node *t, *last;                              // last points to the last node help to add new elements at the end
    first = (struct Node *)malloc(sizeof(struct Node)); // here we create linked list using malloc function
    first->data = A[0];                                 // we assign first element of array
    first->list = NULL;                                 // element list ti the first is empty now
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->list = NULL;
        last->list = t;
        last = t;
    }
}

// Iterative function
int count(struct Node *p){
    int c = 0;
    while(p != 0){
        c++;
        p = p->list;
    }
return c;
}

// Recursive function
int Rcount(struct Node *p){
    if(p == 0)
        return 0;
    else
        return Rcount(p->list)+1;
}

//Addition (Iterative function)
int Add(struct Node *p){
    int sum = 0;
    while(p){
        sum = sum + p->data;
        p = p->list;
    }
return sum;
}

// //Addition (Recursive function)
int RAdd(struct Node *p){
    if(p != 0){
        return RAdd(p->list) + p->data;
    }
    else{
        return 0;
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15,8,12,20};

    create(A, 8); // linkedList is created

    printf("Sum is %d\n\n",Add(first));
    printf("Sum is %d\n\n",RAdd(first));
    // RAdd(first);

    return 0;
}