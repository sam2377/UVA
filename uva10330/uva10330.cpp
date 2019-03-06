#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 999999
using namespace std;

bool DFS(int,int);
int FordFulkerson(int,int);
int Findflow(int,int);

int N,M,B,D;
int cap[205][205],flow[205][205];
int pa[205],visited[205];
int main(){

	while(cin>>N){
		memset(cap,0,sizeof(cap));
		memset(flow,0,sizeof(flow));
		for(int i=1;i<=N;i++){
			int value;
			cin >> value;
			cap[i][i+100]=value;
		}
		cin>>M;
		for(int i=1;i<=M;i++){
			int a,b,c;
			cin >> a >> b >> c;
			cap[a+100][b]=c;
		}
		cin>>B>>D;
		for(int i=1;i<=B;i++){
			int x;
			cin >> x;
			cap[0][x]=INF;
		}
		for(int i=1;i<=D;i++){
			int y;
			cin >> y;
			cap[y+100][N+1+100]=INF;
		}
		printf("%d\n",FordFulkerson(0,N+1+100));
	}
	
}

bool DFS(int k,int t){
	visited[k]=1;
	if(k==t) return true;
	for(int i=0;i<=t;i++){
		
		if(visited[i]) continue;
		
		if(cap[k][i]>flow[k][i]||flow[i][k]>0){
			pa[i]=k;
			if(DFS(i,t)) return true;
		}
	}
	return false;
}

int FordFulkerson(int s,int t){
	int ret = 0;
	while(1){
		memset(visited,0,sizeof(visited));
		if(!DFS(s,t)) break;
		ret+=Findflow(s,t);
	}

	return ret;
	
}

int Findflow(int s,int t){
	int pre,f=INF,i;
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
