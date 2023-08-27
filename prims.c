# include<stdio.h>int G[50][50],select[50], i, j, k, n, min_dist,total=0,u, v;
void Prim(){
 printf("\n\n The Minimal Spanning Tree Is :\n");
 select[0] = 1;
 for (k=1 ; k<n ; k++) {
  min_dist = 32767;
  for (i=0 ; i<n ; i++)                       
    for (j=0 ; j<n ; j++) 
    if (G[i][j] && ((select[i] && !select[j]) || (!select[i] && select[j])))
      if (G[i][j] < min_dist)       {
       min_dist = G[i][j];
       u = i;
       v = j;          }
   printf("\n Edge (%d %d )and weight = %d",u,v,min_dist);
   select[u] = select[v] = 1;
   total =total+min_dist;  }
 printf("\n\nTotal Path Length Is = %d",total);}
int main(){
  printf("\n Enter Number of Nodes in The Graph\n");
  scanf("%d",&n);
  printf("Enter cost adjacency matrix\n");
  for(i=0;i<n;i++){
      for(j=0;j<n;j++){
       scanf("%d",&G[i][j]);}}
  Prim();
  return 0;}
