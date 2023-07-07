#include <stdio.h>

#define MAX_NODES 100

int visited[MAX_NODES];
int adjacencyMatrix[MAX_NODES][MAX_NODES];
int numNodes;

void initializeVisited() {
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = 0;
    }
}

void dfs(int source) {
    visited[source] = 1;
    for (int i = 0; i < numNodes; i++) {
        if (adjacencyMatrix[source][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int isNodeReachable(int source, int target) {
    initializeVisited();
    dfs(source);
    return visited[target];
}

int main() {
    int source, target;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("Enter the target node: ");
    scanf("%d", &target);

    if (isNodeReachable(source, target)) {
        printf("Node is accessible\n");
    } else {
        printf("Node is not accessible\n");
    }

    return 0;
}
