#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<fstream>
using namespace std;
vector<int> path[102];
int ans,dfn[102]={0},low[102]={0},dfs_cnt;
void dfs(int,int);
int main(){
	int N;
	string temp;
	while(cin>>N&&(N!=0)){
		dfs_cnt=0;
		ans=0;
//		memset(dfn,0,102);
//		memset(low,0,102);
		for(int i=0;i<=N;i++){ path[i].clear(); 
			dfn[i]=0,low[i]=0;
		}
		getline(cin,temp);
		while(getline(cin,temp)&&temp!="0"){
			int a,b;
			stringstream sst;
			sst<<temp;
			sst>>a;
			if(a==0) break;
			while(sst>>b){
				path[a].push_back(b);
				path[b].push_back(a);
			}
		}
		dfs(1,-1);
		printf("%d\n",ans);
	}
	return 0;
}
void dfs(int cur,int parent){
//	for(int i=1;i<=9;i++) {printf("low[%d]=%d ",i,low[i]);} printf("\n");
	int child=0;
	bool flag=false;
	dfn[cur]=low[cur]=++dfs_cnt;
	for(int i=0;i<path[cur].size();i++){
		int nxt = path[cur][i];
		if(dfn[nxt]==0){
			child++;
			dfs(nxt,cur);
			low[cur] = min(low[cur],low[nxt]);
//					for(int i=1;i<=9;i++) {printf("low[%d]=%d ",i,low[i]);} printf("\n");
			if(low[nxt]>=dfn[cur]){					//nxt connect to cur's ancestor  >= No,  <= Yes
//				printf("nxt:%d cur:%d low[nxt]:%d dfn[cur]:%d\n",nxt,cur,low[nxt],dfn[cur]);
				flag=true;
				}
		}
		else if(nxt!=parent){
			low[cur] = min(low[cur],dfn[nxt]);		// update back edge			
//		for(int i=1;i<=9;i++) {printf("low[%d]=%d ",i,low[i]);} printf("\n");
		}
	}
	if((parent==-1&&child>=2)||(parent!=-1&&flag))
		ans++;
}
