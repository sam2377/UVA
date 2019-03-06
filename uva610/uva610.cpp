#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
vector<int> path[1005];
int dfn[1005]={0},low[1005]={0},cases=1,dfs_cnt=1;
void dfs(int,int);
int main(){
	while((cin>>n>>m)&&n&&m){
		dfs_cnt=1;
		for(int i=1;i<=n;i++){
			path[i].clear();
			dfn[i]=0;
			low[i]=0;
		}
		for(int i=0;i<m;i++){
			int data1,data2;
			scanf("%d%d",&data1,&data2);
			path[data1].push_back(data2);
			path[data2].push_back(data1);
		}
		printf("%d\n\n",cases++);
		dfs(1,-1);
		printf("#\n");
	}
}
void dfs(int cur,int parent){
	int child=0;
	bool check=false;
	dfn[cur]=low[cur]=dfs_cnt++;
		for(int i=0;i<path[cur].size();i++){
			int next=path[cur][i];
			if(dfn[next]==0){
//				printf("cur:%d next:%d\n",cur,next);
				child++;
				dfs(next,cur);
				low[cur] = min(low[cur],low[next]);

				if(low[next]>=dfn[cur])
					check = true;
				if(low[next]>dfn[cur]){            
					printf("%d %d\n",cur,next);
					printf("%d %d\n",next,cur);
				}
				else
					printf("%d %d\n",cur,next);
			}
			else if(next!=parent){
				low[cur] = min(low[cur],dfn[next]);
				if(dfn[next]<dfn[cur])
				printf("%d %d\n",cur,next);      //print back edge
			}
		}
}
