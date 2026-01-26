#include<stdio.h>
#include<stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("Elements of array are:- \n");
    for(i=0;i<arr.length;i++)
        printf("%d", arr.A[i]);
}

int main(){
    struct Array arr;
    int i,n;
    printf("Enter size of an array ");
    scanf("%d", &arr.size);         //size of array
    arr.A=(int *)malloc(arr.size*sizeof(int));     //create inside heap
    arr.length=0;

    printf("Enter no. of elements ");
    scanf("%d", &n);

    printf("Enter all the elements of array ");
    for(i=0;i<n;i++)
        scanf("%d", &arr.A[i]);
    arr.length=n;
    
    Display(arr);
    
    return 0;
}