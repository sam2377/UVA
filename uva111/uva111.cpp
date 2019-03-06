#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int input;
int correct[25]={0},pos,arr[25]={0},LCS[25][25]={0},ans=0	; 
int main(){
	scanf("%d",&input);
	for(int i=1;i<=input;i++){
		scanf("%d",&pos);
		correct[pos]=i;
		}
		while(scanf("%d",&pos)!=EOF){
				arr[pos]=1;
				for(int i=2;i<=input;i++){
					scanf("%d",&pos);
					arr[pos]=i;
				}
			for(int i=0;i<=input;i++){
				LCS[0][i]=0;
				LCS[i][0]=0;
			}
			for(int i=1;i<=input;i++){
				for(int j=1;j<=input;j++){
					if(correct[i]==arr[j]){
						LCS[i][j]=LCS[i-1][j-1]+1;
					}
					else
						LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
				}
			}
			printf("%d\n",LCS[input][input]);
		}
}
