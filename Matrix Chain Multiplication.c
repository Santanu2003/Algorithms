// Matrix Chain Multiplication
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void display(int n,int arr[][n]){
	int i,j,k;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(i<=j){
				printf("%d",arr[i][j]);
			}
			else
				printf(" ");		
		}
		printf("\n");
	}
}
int matMul(int p[],int n){
	int i,j,l,c,k;
	int m[n][n],s[n][n];
	for(i=0;i<n;i++){
			m[i][i]=0;
	}
	for(l=2;l<n;l++){
		for(i=1;i<n-l+1;i++){
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++){
				c=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(c<m[i][j]){
					m[i][j]=c;
					s[i][j]=k;
				}
			}
		}	
	}
	display(n,m);
	printf("\n");
	display(n,s);
	return m[1][n-1];
} 
int main(){
	int p[10],n,i,r;
	printf("Enter the size of the p array less than 10: ");
	scanf("%d",&n);
	printf("Enter the p array element:");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	r=matMul(p,n);
	printf("The min scaler multiplication is %d",r);
	return 0;
}
