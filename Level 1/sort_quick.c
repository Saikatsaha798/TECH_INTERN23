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
        }   
            
        temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp; 

        quick(arr, l, i-1);
        quick(arr, i+1, r);
        

    return 0;
    }
}

int main(){
    int n,i;

    printf("Enter the Number of Elements : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the Elements : ");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting : ");
    for (i=0; i<n; i++){
        if (i == n-1){
            printf("%d", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }

    quick(arr, 0, n-1);

    printf("\nArray after sorting : ");
    for (i=0; i<n; i++){
        if (i == n-1){
            printf("%d", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
    return 0;
}