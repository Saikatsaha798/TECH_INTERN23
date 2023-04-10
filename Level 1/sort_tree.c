#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node * left;
    int num;
    struct node * right;
};

struct node * insert (struct node *root, int no){
    struct node * new_node = (struct node *) malloc (sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->num = no;
    
    

    if (root == NULL) {
        root = new_node;
    }
    else if (root->num >= no){
        if (root->left == NULL){
            root->left = new_node;
        }
        else{
            root = insert(root->left, no);
        }
    }
    else if (root->num < no){
        if (root->right == NULL){
            root->right = new_node;
        }
        else{
            root = insert(root->right, no);
        }
    }

    return root;
}

int inorder (struct node * root, int *arr, int *i){
    if (root != NULL){
        inorder(root->left, arr, i);
        arr[(*i)++] = root->num;
        inorder(root->right, arr, i);
    }

    return 0;
}

int tree_sort (int arr[], int n){
    int i, j=0;
    struct node * root = NULL;

    for (i=0; i<n; i++){
        if (root == NULL){
            root = insert(root, arr[i]);
        }
        else{
            insert(root, arr[i]);
        }
    }

    inorder(root, arr, &j);

    return 0;
}

int main (){
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

    tree_sort(arr, n);

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