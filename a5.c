#include<stdio.h>

int insertPos(int Arr[], int n, int x){ 
        int low = 0, high = n -1, mid;

        while(low <= high){
                mid = (low+high)/2;

                if (x < Arr[mid]){
                        high = mid - 1;
                }
                else {
                        low = mid + 1;
                }
        }
        return low;
}

int main(){
        int n, x;

        printf("Enter size of Array: ");
        scanf("%d", &n);

        int Arr[n];
        printf("Enter sorted array elements :\n");
        for(int i=0; i<n; i++){
                scanf("%d", &Arr[i]);
        }

        printf("Enter key value: ");
        scanf("%d", &x);

        int pos = insertPos(Arr, n, x);

        printf("Insert %d at index %d\n", x, pos);

        return 0;
}