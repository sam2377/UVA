#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 999999

using namespace std;

int FordFulkerson(int,int);
bool DFS(int,int);
int Findflow(int,int);

int num,S,T,C;
int visited[101],pa[101];
int cap[101][101],flow[101][101];

int main(){
	int cases=1;
	while(cin>>num&&num){
		cin >> S >> T >> C;
//		memset(pa,0,sizeof(pa));
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		for(int i=0;i<C;i++){
			int q,w,e;
			cin >> q >> w >> e;
			cap[q][w]+=e;
			cap[w][q]=cap[q][w];
		}
		printf("Network %d\n",cases++);
		printf("The bandwidth is %d.\n\n",FordFulkerson(S,T));
	}
}

int FordFulkerson(int s,int t){
	int ret = 0;
	while(1){
		memset(visited,0,sizeof(visited));
		if(!DFS(s,t)) break;
		ret += Findflow(s,t);
//			printf("flow[1][2]=%d\n",flow[1][2]);
//			printf("flow[2][4]=%d\n",flow[2][4]);
//			printf("flow[2][3]=%d\n",flow[2][3]);
//			printf("flow[3][2]=%d\n",flow[3][2]);
//			printf("flow[1][3]=%d\n",flow[1][3]);
//			printf("flow[3][4]=%d\n\n",flow[3][4]);
		
	}
	return ret;
}

bool DFS(int k, int t){
	visited[k]=1;
	if (k==T) return true;
	for(int i=1;i<=num;i++){
		
		if(visited[i]) continue;
		
		if(cap[k][i]>flow[k][i] || flow[i][k]>0){
			pa[i]=k;
			if(DFS(i,t)) return true;
		}
	}
	return false;
}

int Findflow(int s,int t){
	int pre,i,f=INF;
	for(i=t;i!=s;i=pa[i]){
		pre = pa[i];

		if(cap[pre][i]>flow[pre][i])
			f = min(f,cap[pre][i]-flow[pre][i]);
		else 
			f = min(f,flow[i][pre]);
	}
	for(i=t;i!=s;i=pa[i]){
		pre = pa[i];

		if(cap[pre][i]>flow[pre][i])
			flow[pre][i]+=f;
		else
			flow[i][pre]-=f;

	}
	return f;


}

