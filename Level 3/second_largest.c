#include <stdio.h>

int second_largest (int arr[], int n){
    int max=0, sec_max=1, i;

    for (i=0; i<n; i++){
        if (arr[max]<arr[i]){
            sec_max = max;
            max = i;
        }
        else if (arr[sec_max]<arr[i] && arr[i]!=arr[max]){
            sec_max = i;
        }
        // printf("%d\t%d\n", max, sec_max);
    }

    return sec_max;
}

int main (){
    int n, i, sec_max;

    printf("Enter the number of ELEMENTS : ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter the ELEMENTS : ");
    for (i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    sec_max = second_largest(arr, n);

    printf("The SECOND LARGEST in array : %d\n", arr[sec_max]);
    return 0;
}