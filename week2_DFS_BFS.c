#include <stdio.h>
#include <stdlib.h>

int n, c, vis[10], a[10][10], q[10], f, r;

void dfs(int s) {
    vis[s] = 1;
    printf("%d\t", s);
    for (int j = 1; j <= n; j++) {
        if (a[s][j] == 1 && vis[j] == 0)
            dfs(j);
    }
}

void bfs(int s) {
    f = r = 0;
    vis[s] = 1;
    printf("%d\t", s);
    q[r++] = s;
    while (f != r) {
        int u = q[f++];
        for (int i = 1; i <= n; i++) {
            if (a[u][i] == 1 && vis[i] == 0) {
                q[r++] = i;
                vis[i] = 1;
                printf("%d\t", i);
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }
    printf("1. DFS\n2. BFS\n");
    scanf("%d", &c);
    switch (c) {
        case 1: {
            printf("DFS Traversal:\n");
            for (int i = 1; i <= n; i++) {
                if (vis[i] == 0)
                    dfs(i);
            }
            break;
        }
        case 2: {
            printf("BFS Traversal:\n");
            for (int i = 1; i <= n; i++) {
                if (vis[i] == 0)
                    bfs(i);
            }
            break;
        }
        default:
            printf("Invalid choice\n");
    }
    printf("\n");
    return 0;
}
