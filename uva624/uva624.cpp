#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
void backtrack(int);
void dfs(int);
int input,size,index=0;
vector<int> V,dp,ans,output[100];
int row=0,cnt=0,sum=0,input_adjust=0,len=0;
int main(){
	while(scanf("%d",&input)!=EOF&&scanf("%d",&size)!=EOF){
		int mx=0;
		row=0,cnt=0,sum=0,input_adjust=0,len=0,index=0;
		for(int i=0;i<size;i++){
			int temp;
			scanf("%d",&temp);
			V.push_back(temp);
			mx+=V[i];
		}
		for(int i=0;i<=mx;i++)
			dp.push_back(0);
		for(int i=mx;i<input;i++)
			dp.push_back(0);
		dp[0]=1;
		dfs(0);
		for(int i=input;i>=0;i--){
			if(dp[i]==1){
			input_adjust=i;
			break;
			}
		}
		backtrack(0);
		for(int i=0;i<100;i++){
			if(output[i].size()>len){
			len=output[i].size(); 
			row=i;
			}
		}
		for(int i=0;i<output[row].size();i++){
			printf("%d ",output[row][i]);
		}
		printf("sum:%d\n",input_adjust);
		while(!V.empty()) V.erase(V.begin());
		while(!dp.empty()) dp.erase(dp.begin());
		while(!ans.empty()) ans.erase(ans.begin());
		for(int i=0;i<100;i++){
		while(!output[i].empty()) output[i].erase(output[i].begin());
//		output[i].clear();
		}
	}
}
void backtrack(int x){
	if(sum==input_adjust){
		for(int i=0;i<ans.size();i++)
		output[cnt].push_back(ans[i]);
		cnt++;
		return;
	}
	if(x==size) return;
		for(int i=x;i<size;i++){
			ans.push_back(V[i]);
			sum+=V[i];
			backtrack(i+1);
			sum-=V[i];
			ans.pop_back();
		}
}
void dfs(int x){
	if(x==size) return;
	for(int i=x;i<size;i++){
		index+=V[i];
		dp[index]=1;
		dfs(i+1);
		index-=V[i];
	}
}
