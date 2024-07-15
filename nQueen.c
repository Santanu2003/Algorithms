// N Queen Algorithm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *x;
void display(int n){
	int j;
	for(j=0;j<n;j++)
		printf("%d\t",x[j]+1);
	printf("\n");
}
int place(int k,int i){
	int j;
	for(j=0;j<k;j++){
		if(x[j]==i || (abs(x[j]-i)==abs(k-j)))
			return 0;
	}
	return 1;
}
void nQueen(int k,int n){
	int i;
	for(i=0;i<n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k+1==n){
				display(n);	
			}
			else
				nQueen(k+1,n);
		}
	}
}
int main(){
	int n;
	printf("Enter the no of queen:");
	scanf("%d",&n);
	x=(int *)malloc(n*sizeof(int));
	nQueen(0,n);
	return 0;
}
