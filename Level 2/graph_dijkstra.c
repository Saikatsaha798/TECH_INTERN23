#include <stdio.h>
#include <limits.h>
#define v 9

int min (int ans[], int visited[]){
    int i, m=-1;
    for (i=0; i<v; i++){
        if (m == -1 && visited[i]){
            m = i;
        }
        else if ((ans[i] < ans[m]) && visited[i]){
            m=i;33
        }
    }
    return m;
}

int dijkstra (int g[v][v], int src, int des){
    int visited[v], target[v], ans[v], n=0, i, j=0;
    ans[src] = 0;
    for (i=0; i<v; i++){
        visited[i] = 1;
        ans[i] = INT_MAX;
    }
    j=src;
    while (n<v){
        // printf("%d -> ", j);
        for (i=0; i<v; i++){
            if (j == src){
                if (g[j][i] == -1){
                    ans[i] = INT_MAX;
                }
                else{
                    ans[i] = g[src][i];
                }
            }
            else{
                if (visited[i] && g[j][i]!=-1){
                    if (ans[i] > ans[j]+g[j][i]){
                        ans[i] = ans[j]+g[j][i];
                    } 
                }
            }

        }
        // for (i=0; i<v; i++){
        // printf("%d ", ans[i]);
        // }
        // printf("\n");
    
        visited[j]=0;
        j = min(ans, visited);
        
        n++;
    }
    return ans[des];

    
}

int main (){
    int i,j,src,des,path;
    
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

    // printf("\nEnter the WEIGHT between vertices (-1 for NO EDGE) : \n\n");
    // for (i=0; i<v; i++){
    //     printf("From Vertex %d : \n\n",i+1);
    //     for (j=i; j<v; j++){
    //         if (i==j){
    //             g[i][j] = 0;
    //         }
    //         else{
    //             printf("To %d : ", j+1);
    //             scanf("%d", &g[i][j]);
    //         }
    //     }
    //     printf("\n");
    // }
    // for (i=0; i<v; i++){
    //     for (j=i+1; j<v; j++){
    //         g[j][i] = g[i][j];
    //     }
    // }

    printf("Enter the Source Node in GRAPH : ");
    scanf("%d", &src);
    printf("Enter the Destination Node in GRAPH : ");
    scanf("%d", &des);
    

    path=dijkstra(g, src, des);
    printf("The Shortest Path between %d and %d : %d", src, des, path);

    return 0;
}