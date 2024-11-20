#include <stdio.h>
#include <stdlib.h>

void createGraph();
void bfs(int v);
void dfs(int v);

int a[50][50], n, visited[50];
int q[20], front = -1, rear = -1; 
int s[20], top = -1; 

void createGraph() {
    int i, j;
    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix (0 or 1):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void bfs(int v) {
    int i, cur;
    visited[v] = 1;
    q[++rear] = v;
    printf("\nNodes reachable from starting vertex %d are: ", v);
    while (front != rear) {
        cur = q[++front];
        printf("%d ", cur);
        
        for (i = 1; i <= n; i++) {
            if (a[cur][i] == 1 && visited[i] == 0) {
                q[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int v) {
    int i;
    visited[v] = 1;
    s[++top] = v; 
    for (i = 1; i <= n; i++) 
    {
        if (a[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main() {
    int ch, start, i;
    createGraph();
    do {
        printf("\n\n~~~Menu~~~~");
        printf("\n==> 1. BFS: Print all nodes reachable from a given starting node");
        printf("\n==> 2. DFS: Print all nodes reachable from a given starting node");
        printf("\n==> 3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                for (i = 1; i <= n; i++) 
                    visited[i] = 0; 
                printf("\nEnter the starting vertex: ");
                scanf("%d", &start);
                bfs(start);
                
                for (i = 1; i <= n; i++) {
                    if (visited[i] == 0)
                        printf("\nThe vertex that is not reachable is %d", i);
                }
                break;

            case 2:
                for (i = 1; i <= n; i++) visited[i] = 0; 
                top = -1;
                printf("\nEnter the starting vertex: ");
                scanf("%d", &start);
                dfs(start);
                
                printf("\nNodes reachable from starting vertex %d are:\n", start);
                for (i = 0; i <= top; i++)
                    printf("%d\t", s[i]);

                for (i = 1; i <= n; i++) {
                    if (visited[i] == 0) 
                        printf("\nThe vertex that is not reachable is %d", i);
                }
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("\nPlease enter a valid choice:");
        }
    } while (ch != 3);
    return 0;
}