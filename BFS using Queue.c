// BFS using Queue
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int V,visited[MAX],queue[MAX],front=-1,rear=-1;
void enqueue(int value){
	if(rear==-1){
		front++;
	}
	queue[++rear]=value;
}
int dequeue(){
	int v;
	if(front==rear){
		v=queue[front];
		rear=front=-1;
	}
	else
		v=queue[front++];
	return v;
}
void bfs(int G[][V],int s){
	int i,u,j;
	enqueue(s);
	for(i=0;i<V;i++)
		visited[i]=0;
	visited[s]=1;
	printf("BFS traversal: ");
	while(front!=-1){
		u=dequeue();
		printf("%d\t",u+1);
		for(j=0;j<V;j++){
			if(G[u][j]==1 && visited[j]==0){
				enqueue(j);
				visited[j]=1;
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
	printf("Enter the source vertex:");
	scanf("%d",&s);
	bfs(cost,s);
	return 0;
}
