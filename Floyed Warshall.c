// Floyed Warshall Algorithm
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int V;
void printSolution(int d[][V]){
	int i,j;
	printf("Distance between all pair is\n");
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			printf("%d -> %d = %d\n",i+1,j+1,d[i][j]);
		}
	}
}
void floyedWarshall(int G[][V]){
	int d[V][V],p[V][V];
	int i,j,k;
	for(i=0;i<V;i++){
		for(j=0;j<V;j++){
			d[i][j]=G[i][j];
			p[i][j]=0;
		}
	}
	for(k=0;k<V;k++){
		for(i=0;i<V;i++){
			for(j=0;j<V;j++){
				if(d[i][k]!=INT_MAX && d[k][j]!=INT_MAX && d[i][j]>d[i][k]+d[k][j] ){
					d[i][j]=d[i][k]+d[k][j];
					p[i][j]=k;
				}
			}
		}
	}
	printSolution(d);
}
int main(){
FILE *file=fopen("matrix_floyed.txt","r");  
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
	floyedWarshall(cost);		
	return 0;
}
