#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> con_num[100],V[100],ans[100];
int dfn[100]={0},low[100]={0},dfn_cnt=0,sum=0;
int num;
void dfs(int,int);
int main(){
	while(scanf("%d",&num)!=EOF){
		for(int i=0;i<100;i++){ while(!ans[i].empty()) ans[i].erase(ans[i].begin());}
		for(int i=0;i<num;i++) {
			V[i].clear();
			low[i]=0;
			dfn[i]=0;
		}
		dfn_cnt=0;
		sum=0;
			if(num!=0){
				for(int i=0;i<num;i++){
					int a,b;
					scanf("%d",&a);
					scanf(" (%d)",&b);
					for(int j=0;j<b;j++){
						int c;
						scanf("%d",&c);
						V[a].push_back(c);
						V[c].push_back(a);
					}
				}
				for(int i=0;i<num;i++)
					dfs(i,-1);
				printf("%d critical links\n",sum);
				for(int i=0;i<100;i++){
					if(!ans[i].empty()){
						sort(ans[i].begin(),ans[i].end());
						for(int j=0;j<ans[i].size();j++){
							printf("%d - %d\n",i,ans[i][j]);
						}
					}
				}
			}
			else printf("0 critical links\n");
		printf("\n");
	}
	return 0;
}
void dfs(int cur,int parent){
	int child=0;
	bool check=false;
	low[cur]=dfn[cur]=++dfn_cnt;
		for(int i=0;i<V[cur].size();i++){
			int nxt=V[cur][i];
			if(dfn[nxt]==0){
				child++;
				dfs(nxt,cur);
				low[cur]=min(low[cur],low[nxt]);
				if(low[nxt]>=dfn[cur])
					check=true;
				if(low[nxt]>dfn[cur]){
					if(nxt>cur) ans[cur].push_back(nxt);
					else	ans[nxt].push_back(cur);
					sum++;
				}
			}
			else if(nxt!=parent){
				low[cur]=min(low[cur],dfn[nxt]);	
			}
		}
}




