#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
void Union(int,int);
int Find(int);
int n,m;
int p[200010],cnt[200010],sum[200010],id[200010];
int main(){
	int a,b,c,P,Q,boss1,boss2;
	while(cin>>n>>m){
		for(int i=1;i<=n;i++){
			p[i]=i;
			cnt[i]=1;
			sum[i]=i;
			id[i]=i;
		}
		for(int i=0;i<m;i++){
			cin>>a;
			switch(a){
				case 1:
						cin>>P>>Q;
						boss1=Find(id[P]);
						boss2=Find(id[Q]);
						if(boss1==boss2) continue;
						Union(boss1,boss2);
						break;
				case 2:
						cin>>P>>Q;
						boss1=Find(id[P]);
						boss2=Find(id[Q]);
						if(boss1==boss2) continue;
						sum[boss1] -= P;
						cnt[boss1]--;
						id[P] = ++n;
						sum[n]=P;
						cnt[n]=1;
						p[n]=n;
						boss1=Find(id[P]);
						Union(boss1,boss2);
						break;
				case 3:
						cin>>P;
						boss1 = Find(id[P]);
						printf("%d %d\n",cnt[boss1],sum[boss1]);
						break;
			}
		}
	}
}
void Union(int X,int Y){
	p[X]=Y;
	cnt[Y]+=cnt[X];
	sum[Y]+=sum[X];
}

int Find(int x){

	if(p[x]==x) return x;
	return p[x]=Find(p[x]);

}

