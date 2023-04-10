#include <stdio.h>

int shell_sort (int arr[], int n){
    int i,j,k,gap,anc;

    for (gap=n/2; gap>0; gap/=2){
        for (i=gap; i<n; i++){
            j = i-gap;
            anc = arr[i];
            
            while (j>=0 && anc<arr[j]){
                arr[j+gap] = arr[j];
                j-=gap;
                
            }

            arr[j+gap] = anc;

        }
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
            printf("%d\n", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }

    shell_sort(arr, n);

    printf("Array after sorting : ");
    for (i=0; i<n; i++){
        if (i == n-1){
            printf("%d", arr[i]);
            break;
        }
        printf("%d, ", arr[i]);
    }
    return 0;

}