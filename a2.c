//Resizing the array

#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p,*q;
    int i;
    p=(int *)malloc(5*sizeof(int));   // we declare an array of size 5 
    p[0]=3;p[1]=5;p[2]=7;p[3]=11;p[4]=13;

    q=(int *)malloc(10*sizeof(int));

    for(i=0;i<5;i++)
       q[i]=p[i];    //now p point to array q

    free(p);         
    p=q;
    q=NULL;
    
    for(i=0;i<5;i++)
    printf("%d \n",p[i]);

    return 0;
}