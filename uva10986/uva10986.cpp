#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
struct Node{
	int next;
	int len;
}; 
int dis[20050]={0};
int	n,m,s,t;
int main(){
	int cases,i;
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		vector<Node> V[20050];
		scanf("%d%d%d%d",&n,&m,&s,&t);
		for(int j=0;j<20050;j++) dis[j]=999999;
		for(int k=0;k<m;k++){
			Node temp;
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			temp.next=b;
			temp.len=c;
			V[a].push_back(temp);
			temp.next=a;
			temp.len=c;
			V[b].push_back(temp);
		}
		dis[s]=0;
		queue<int> Q;
		bool inqueue[20000];
		memset(inqueue,false,20000);
		inqueue[s]=true;
		Q.push(s);
		while(!Q.empty()){
			int now = Q.front();
			inqueue[now] = false;
			Q.pop();
			
			for(int i=0;i<V[now].size();i++){
				if(dis[now]+V[now][i].len<dis[V[now][i].next]){
					dis[V[now][i].next]=dis[now]+V[now][i].len;
					if(!inqueue[V[now][i].next]){
						Q.push(V[now][i].next);
						inqueue[V[now][i].next]=true;
					} 
				} 
			}
		}			
		if(dis[t]!=999999)
		printf("Case #%d: %d\n",i,dis[t]);
		else
		printf("Case #%d: unreachable\n",i);
	}
}
