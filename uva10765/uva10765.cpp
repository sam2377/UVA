#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int dfn[10010]={0},low[10010]={0},dfn_cnt=0,maximum=-1;
vector<int> V[10010];
map<int,int> M;
void dfs(int,int);
int main(){
	int n,m;
	while(cin>>n>>m&&n&&m){
		M.clear();
		for(int i=0;i<n;i++){ 
				dfn[i]=0;
				low[i]=0;
				while(!V[i].empty()) V[i].erase(V[i].begin());
		}
			dfn_cnt=0;
			maximum=-1;
			int x,y;
			while(cin>>x>>y){
				if(x==-1&&y==-1) break;
				V[x].push_back(y);
				V[y].push_back(x);
			}	
			for(int i=0;i<n;i++){
				if(dfn[i]==0) dfs(i,-1);
			}
			for(int i=0;i<n;i++){
				map<int,int>::iterator iter=M.find(i);
				if(iter==M.end())	M[i]=1;
				else if(M[i]<=V[i].size()-1)M[i]++;
				if(M[i]>maximum) maximum=M[i];
			}
			bool flag=false;
			int count=0;
			for(map<int,int>::iterator iter=M.begin();;iter=M.begin()){
				while(iter!=M.end()){
					if(count==m){ flag=true; break;}
					if(iter->second==maximum){
						printf("%d %d\n",iter->first,maximum);
						count++;	
					}
					iter++;
				}
				if(flag) break;
				maximum--;
			}
		printf("\n");
	}
}
void dfs(int cur,int parent){
	bool flag=false;
	int child=0;
	low[cur]=dfn[cur]=++dfn_cnt;
		for(int i=0;i<V[cur].size();i++){
			int nxt=V[cur][i];
				if(dfn[nxt]==0){
					child++;
					dfs(nxt,cur);
					low[cur]=min(low[cur],low[nxt]);
					if(low[nxt]>dfn[cur]){
						M[cur]++;
						M[nxt]++;
					}
			//		if(low[nxt]==dfn[cur]){
			//			M[cur]++;
			//			if(M[cur]>maximum) maximum = M[cur];
			//		}
				}
				else if(nxt!=parent)
				low[cur]=min(low[cur],dfn[nxt]);
		}
}
