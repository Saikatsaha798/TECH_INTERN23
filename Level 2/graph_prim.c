#include <stdio.h>
#include <limits.h>
#define v 9

int find_min(int value[], int visited[]){
    int i, min=-1;
    for (i=0; i<v; i++){
        if (min == -1 && visited[i]){
            min = i;
        }
        else if (value[min] > value[i] && visited[i]){
            min = i;
        }
    }

    return min;
}

int prim(int graph[v][v], int src){
    int visited[v], value[v], parent[v], i, ptr=src, n=0, cost=0;

    for (i=0; i<v; i++){
        visited[i] = 1;
        parent[i] = i;
        value[i] = INT_MAX;
    }

    value[src] = 0;

    while (n<v){
        for (i=0; i<v; i++){
            if (graph[ptr][i] < value[i] && graph[ptr][i] != -1 && i!=ptr && visited[i]){
                value[i] = graph[ptr][i];
                parent[i] = ptr;
            }
            
             
        }
        visited[ptr] = 0; 
        n++;

        // for (i=0; i<v; i++){
        // printf("%d\t", value[i]);
        // }

        ptr = find_min(value, visited);
        // printf("%d\n", ptr);
    }

    // printf("\n\n");
    // for (i=0; i<v; i++){
    //     printf("%d\t", parent[i]);
    // }


    printf("The EDGES to be included :\n");
    for (i=1; i<v; i++){
        printf("%d -- %d = %d\n", i, parent[i], value[i]);
        cost+=value[i];

    }

    printf("\nThe Total COST : %d", cost);

    return 0;
}

int main(){
    int g[v][v] = {
        {0, 4, -1, -1, -1, -1, -1, 8, -1},
        {4, 0, 8, -1, -1, -1, -1, 11, -1},
        {-1, 8, 0, 7, -1, 4, -1, -1, 2},
        {-1, -1, 7, 0, 9, 14, -1, -1, -1},
        {-1, -1, -1, 9, 0, 10, -1, -1, -1},
        {-1, -1, 4, 14, 10, 0, 2, -1, -1},
        {-1, -1, -1, -1, -1, 2, 0, 1, 6},
        {8, 11, -1, -1, -1, -1, 1, 0, 7},
        {-1, -1, 2, -1, -1, -1, 6, 7, 0}
    };
    prim(g, 0);
    return 0;
}