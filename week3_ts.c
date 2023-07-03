//Topological sorting using DFS
#include <stdio.h>
int a[100][100], vis[100], n;
void dfs(int s){
	vis[s]=1;	
	for (int j = 0; j <n; j++) {
        if (a[s][j] == 1 && vis[j] == 0)
            dfs(j);
    }
    printf("%d\t", s+1);
    
}
void sr(){
int i, j;
	while(j<n){
	for(i=0; i<n;i++){
		if(a[i][j]==0){
			printf("%d\t",j+1);
		}
	j++;
}
}
}
int main(){
	int j,i, c;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	printf("Ener the adjacency matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &a[i][j]);
		}
		vis[i]=0;
	}
	printf("1.DFS\n2.Source removal\n");
	scanf("%d",&c);
	switch(c){
		case 1: {
		for(i=0;i<n;i++){
		if(vis[i]==0)
		dfs(i);
		}
		break;
		}
		
		case 2:{
		sr();
		}	
	}
	
	return 0;
}
