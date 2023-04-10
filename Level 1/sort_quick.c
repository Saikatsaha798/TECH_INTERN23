#include <stdio.h>

int quick(int arr[], int l, int r){
    if (l<r){
        int i=l, j=r-1, p=r, temp, k;

        while (i<=j){

            if (arr[i] == arr[j]){
                break;
            }
            while (arr[i]<arr[p]){
                i++;
            }
            while (arr[j]>arr[p]){
                j--;
            }

            if (i<j) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
            
        temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp; 

        quick(arr, l, i-1);
        quick(arr, i+1, r);
    }

    return 0;
}

int main(){
    int arr[5] = {1,2,4,2,3}, i;

    quick(arr, 0, 4);

    for (i=0; i<5; i++){
        printf("%d\t", arr[i]);
    }

}