// DFS
#include<stdio.h>
#include<stdlib.h>
int V;
void dfs(int visited[],int G[][V],int s){
	int u,v;
	visited[s]=1;
	for(u=0;u<V;u++){
		if(G[s][u]==1){
			if(visited[u]==1){
				printf("%d",u);
				dfs(visited,G,u);
			}
		}
	}
}
int main(){
	FILE *file=fopen("matrix_dfs.txt","r");  
	int i,j,s;
	
	if(file==NULL){
		printf("Error in opening file !!!");
		exit(0);
	}
	// Read the dimensions of the matrix
    fscanf(file, "%d", &V);
    
   // printf("V=%d\n",V);
    
	int cost[V][V];
	
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			if(fscanf(file,"%d",&cost[i][j])!=1){
				return 1;
			}
		}
	}
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			printf("%d\t",cost[i][j]);
		}
		printf("\n");
	}
	int* visited=(int*)malloc(V*sizeof(int));
	for(i=0;i<V;i++)
		visited[i]=0;
	printf("Enter the source vertex:");
	scanf("%d",&s);
	dfs(visited,cost,s);
	return 0;
}
