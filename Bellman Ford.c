// Bellman Ford Algorithm
#include<stdio.h>
#include<stdlib.h>
int V;
int *d;
void display(){
	int i;
	d=(int*)malloc(V*sizeof(int));
	printf("Distance from the source vertex:\n");
	for(i=0;i<V;i++){
		printf("%d    %d",i,d[i]);
	}	
}
int bellmanFord(int G[][V],int s){
	int i,u,v;
	for(i=0;i<V;i++){
		d[i]=INT_MAX;
	}
	d[s]=0;
	for(i=0;i<V-1;i++){
		for(u=0;u<V;u++){
			for(v=0;v<V;v++){
				if(G[u][v]!=0 && d[u]!=INT_MAX && d[v]>d[u]+G[u][v])
					d[v]=d[u]+G[u][v];	
			}
		}
	}
	for(u=0;u<V;u++){
		for(v=0;v<V;v++){
			if(G[u][v]!=0 && d[u]!=INT_MAX && d[v]>d[u]+G[u][v])
				return 0;	
		}
	}
	return 1;
}
int main(){
FILE *file=fopen("matrix_2.txt","r");  
	int i,j,s,r;
	
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
	printf("Enter the source vertex");
	scanf("%d",&s);		
	r=bellmanFord(cost,s);
	if(!r)
		printf("There is a neg weight cycle!!");
	else
		display();	
	return 0;
}
