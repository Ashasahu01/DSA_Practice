#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[5]={2,4,6,8,0};
    int *p;
    int i;

    p=(int *)malloc(5*sizeof(int));
    p[0]=1;
    p[1]=3;
    p[2]=5;
    p[3]=7;
    p[4]=9;
    
    printf("Array elements:- \n");
    for(i=0;i<5;i++)
        printf("%d ",A[i]);

    printf("\n");    
    printf("Elements after reassigning:- \n");
    for(i=0;i<5;i++)
        printf("%d ",p[i]);  //accessing new elements using pointer    
    return 0;

}