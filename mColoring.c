// mColoring problem
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n,m,x[MAX];
void nextValue(int G[][n],int k){
	int j;
	do{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		for(j=0;j<n;j++){
			if(G[k][j]!=0 && x[j]==x[k])
				break;
		}	
		if(j==n)
			return;
	}while(1);
}
void mColoring(int G[][n],int k){
	int i;
	do{
		nextValue(G,k);
		if(x[k]==0)
			return;
		if(k==n-1){
			for(i=0;i<n;i++)
				printf("%d\t",x[i]);
			printf("\n");
		}
		else
			mColoring(G,k+1);
			
	}while(1);
}
int main(){
	FILE *file=fopen("matrix_mCol.txt","r");  
	int i,j,s,r;
	
	if(file==NULL){
		printf("Error in opening file !!!");
		exit(0);
	}
	// Read the dimensions of the matrix
    fscanf(file, "%d", &n);
    
   // printf("V=%d\n",V);
    
	int cost[n][n];
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(fscanf(file,"%d",&cost[i][j])!=1){
				return 1;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",cost[i][j]);
		}
	printf("\n");
	}
	printf("Enter the no of colour: ");
	scanf("%d",&m);	
	if(m>=n)	
		mColoring(cost,0);
	else
		printf("Not possible");
	return 0;
}
