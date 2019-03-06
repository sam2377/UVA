#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int input;
int coin[5]={1,5,10,25,50};	
int ans=0;
int dp[7490]={0};
int main(){
		memset(dp,0,7490);
		dp[0]=1;
		for(int j=0;j<5;j++){
			for(int i=0;i<7490;i++){		
				if(i-coin[j]>=0){
					if(dp[i-coin[j]]>0) 
					dp[i]+=dp[i-coin[j]]; 
				}
			}
		}
	while(scanf("%d",&input)!=EOF){
		printf("%d",dp[input]);
		printf("\n"); 
	}
	
} 
