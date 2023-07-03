#include <stdio.h>
#include <stdlib.h>

int n, c=0, vis[10], a[10][10];


void dfs(int s) {
    vis[s] = 1;
    //printf("%d\t", s);
    for (int j = 1; j <= n; j++) {
        if (a[s][j] == 1 && vis[j] == 0)
            dfs(j);
    }
}

void main(){
printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }
    
    for (int i = 1; i <= n; i++) {
                if (vis[i] == 0){
                    dfs(i);
                    c++;
                    }
            }
    printf("%d\n",c);
 }
