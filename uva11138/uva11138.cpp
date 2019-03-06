#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool DFS(int);
int Bipartite(int,int);

vector<int> edge[502];
int arr[502][502];
int llink[502],rlink[502];
bool used[502];

int main(){
	int cases,cnt=1;
	cin >> cases;
	while(cases--){
		memset(arr,0,sizeof(arr));
		for(int i=0;i<502;i++) { while(!edge[i].empty()) edge[i].erase(edge[i].begin());}
		int a,b;
		cin >> a >> b;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				cin>>arr[i][j];
				if(arr[i][j]>0)
				edge[i].push_back(j);
			}
		}
		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",cnt++,Bipartite(a,b));
	}
}

int Bipartite(int nL,int nR){
	int ans=0;
	memset(llink,0,sizeof(llink));
	memset(rlink,0,sizeof(rlink));

	for(int i=1;i<=nL;i++){
		memset(used,false,sizeof(used));
		if(DFS(i)) ans++;
	}
	return ans;
}

bool DFS(int now){
	int next;
	for(int i=0;i<edge[now].size();i++){
		next = edge[now][i];
		if(!used[next]){
			used[next]=true;
			if(!rlink[next]||DFS(rlink[next])){
				llink[now]=next;
				rlink[next]=now;
				return true;
			}
		}
	}
	return false;
}
