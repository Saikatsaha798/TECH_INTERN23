#include <stdio.h>

int heapify (int arr[], int n, int i){
    int num = i, l=2*i+1, r=2*i+2, temp;

    if (l<n && arr[num] < arr[l]){
        num = l;
    }
    if (r<n && arr[num] < arr[r]){
        num = r;
    }

    if (num == i){
        return 0;
    }
    else{
        temp = arr[num];
        arr[num] = arr[i];
        arr[i] = temp;

        heapify(arr, n, num);
    }
}

int heap_sort (int arr[], int n){
    int i, temp, k;

    for (i=0; i<5; i++){
        heapify(arr, 5, 0);
    }

    for (i=n-1; i>=1; i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify (arr, i, 0);

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

    heap_sort(arr, n);

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