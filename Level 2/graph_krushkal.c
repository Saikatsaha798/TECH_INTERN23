#include <stdio.h>
#include <limits.h>
#define v 9

int min_weight(int graph[v][v], int used[v][v], int location[]){
    int i, j, min;
    min = INT_MAX;
    location[0] = 0;
    location[1] = 0;

    for (i=0; i<v; i++){
        for (j=0; j<i; j++){
            if (min>=graph[i][j] && used[i][j] && graph[i][j]!=-1){
                min = graph[i][j];
                location[0] = i;
                location[1] = j;
            }
        }
    }

    return 0;
}

int find_parent(int parent[], int i){
    while (i != parent[i]){
        i = parent[i];
    }
    return i;
}

int union_nodes(int graph[v][v], int parent[], int rank[], int a, int b, int* cost){
    int p_a, p_b;
    p_a = find_parent(parent, a);
    p_b = find_parent(parent, b);

    parent[a] = parent[p_a];
    parent[b] = parent[p_b];

    if (p_a == p_b){
        return 0;
    }

    printf("%d -- %d = %d\n", a, b, graph[a][b]);
    *cost += graph[a][b];
    

    if (rank[p_a] >= rank[p_b]){
        parent[p_b] = parent[p_a];
        rank[p_a]++;
    }
    else {
        parent[p_a] = parent[p_b];
        rank[p_b]++;
    }

    return 1;
}

int krushkal(int graph[v][v]){
    int parent[v], rank[v], used[v][v], location[2], i, p, j, n=0, c, cost=0;

    for (i=0; i<v; i++){
        for (j=0; j<v; j++){
            used[i][j] = 1;
        }
        parent[i] = i;
        rank[i] = 0;
    }

    // p = find_parent(parent, v, 4);
    // printf("%d", parent[p]);

    // union_nodes(parent, rank, 0, 1);
    // union_nodes(parent, rank, 1, 2);
    // union_nodes(parent, rank, 3, 4);
    // union_nodes(parent, rank, 4, 1);

    printf("The EDGES included in minimal spanning tree : \n");

    while (n < v-1){
        min_weight(graph, used, location);
        c = union_nodes(graph, parent, rank, location[0], location[1], &cost);
        used[location[0]][location[1]] = 0;
        if (c==1){
            n++;
        }
    }

    printf("The TOTAL Cost : %d", cost);

    // for (i=0; i<v; i++){
    //     printf("%d\t", parent[i]);
    // }

    // printf("\n");

    // for (i=0; i<v; i++){
    //     printf("%d\t", rank[i]);
    // }

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
    krushkal(g);
    return 0;
}