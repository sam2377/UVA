#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		int A[N],count=0,temp;
		for(int i=0;i<N;i++)
			scanf("%d",&A[i]);
		for(int i=N-1;i>0;i--){
			for(int j=0;j<i;j++){
				if(A[j]>A[j+1]){
					temp = A[j];
					A[j] = A[j+1];
					A[j+1] = temp;
					count++;
				}
			}
		}
		printf("Minimum exchange operations : %d\n",count);
	}
}
