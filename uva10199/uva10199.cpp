#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
int low[105]={0},dfn[105]={0},dfn_cnt=0,cases=1;
vector<int> V[105];
vector<string> ans;
map<string,int> M;
map<int,bool>check;
void dfs(int,int);
int main(){
	int N;
	while(scanf("%d",&N)&&N){
		
		while(!ans.empty()) ans.erase(ans.begin());
		M.clear();
		check.clear();
		dfn_cnt=0;
		for(int i=1;i<=N;i++){
			low[i]=0;
			dfn[i]=0;
			while(!V[i].empty()) V[i].erase(V[i].begin());
		}
			for(int j=1;j<=N;j++){
				string temp;
				cin>>temp;
				M[temp]=j;
			}
		int R;
		cin>>R;
		for(int i=0;i<R;i++){
			string a,b;
			cin>>a>>b;
			int A=M[a],B=M[b];
			V[A].push_back(B);
			V[B].push_back(A);
		}
		for(int i=1;i<=N;i++){
			if(dfn[i]==0) dfs(i,-1);
		}
//		dfs(1,-1);
		if(cases!=1) printf("\n");
		cout<<"City map #"<<cases++<<": "<<ans.size()<<" camera(s) found"<<endl;
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++) cout << ans[i] << endl;

	}
	return 0;

}

void dfs(int cur,int parent){
	int child=0;
	bool flag=false;
	low[cur]=dfn[cur]=++dfn_cnt;
	for(int i=0;i<V[cur].size();i++){
		int nxt=V[cur][i];
			if(dfn[nxt]==0){
				child++;
				dfs(nxt,cur);
				low[cur]=min(low[cur],low[nxt]);
				if((parent==-1&&child>1)||(low[nxt]>=dfn[cur]&&parent!=-1)){
					if(!check[cur]){
						for(map<string,int>::iterator iter=M.begin();iter!=M.end();iter++){
							if(iter->second==cur){
							ans.push_back(iter->first);
							check[cur]=true;
							break;
							}
						}
					}
				}
			}
			else if(nxt!=parent){
				low[cur]=min(low[cur],dfn[nxt]);
			}
	}
}
