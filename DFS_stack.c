// DFS using stack
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int V,stack[MAX],top=-1;
void push(int value){
	stack[++top]=value;
}
int pop(){
	return stack[top--];
}
void dfs(int G[][V],int s){
	int visited[V],i,j;
	for(i=0;i<V;i++)
		visited[i]=0;
	push(s);
	visited[s]=1;
	printf("DFS traversal:  ");
	while(top!=-1){
		int u=pop();
		printf("%d\t",u+1);
		for(j=0;j<V;j++){
			if(G[u][j]==1 && visited[j]==0){
				push(j);
				visited[j]=1;
			}
		}
	} 												
}
int main(){
	FILE *file=fopen("matrix_dfs_2.txt","r");  
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
	printf("Enter the source vertex:");
	scanf("%d",&s);
	dfs(cost,s);
	return 0;
}
