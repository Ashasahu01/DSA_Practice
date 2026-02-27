////Given a sorted array and a key x, find the number of occurrences of x using binary search (not linear scan).
#include<stdio.h>

int first_occ(int A[],int l,int r,int X){  // find first occurence of key value
        int res = -1;
        while(l <= r){

                int mid = (l+r)/2;

                if(X == A[mid]){
                        res = mid;
                        r = mid -1; // search from l to mid - 1, left of mid element
                }
                else if(X < A[mid]){
                        r = mid -1;
                }
                else{
                        l = mid +1;
                 }
                }
                return res;
        }

int last_occ(int A[], int l, int r, int X){  // find last occurence of key value
        int res = -1;
        while(l <= r){

                int mid = (l+r)/2;

                if(X == A[mid]){
                        res = mid;
                        l = mid + 1;
                }
                else if(X > A[mid]){
                        l = mid + 1;
                }
                else{
                        r = mid - 1;
                }
        }
        return res;
}

int main(){
        int n, X;
        printf("Size of Array: ");
        scanf("%d", &n);

        int A[n];
        printf("Enter sorted array of size %d :\n", n);
        for(int i=0; i<n; i++){
                scanf("%d", &A[i]);
        }
        printf("Key value : ");
        scanf("%d", &X);

        int first = first_occ(A, 0, n-1, X);
        int last = last_occ(A, 0, n-1, X);

        if(first == -1)
                printf("Element not found.");
        else{
                int count = last - first + 1;
                printf("Occ(%d) : %d", X, count);
        }

        return 0;

}