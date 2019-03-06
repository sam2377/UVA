#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int Find(int);
void Union(int,int);

struct point{
	double x;
	double y;
}point[502];

struct edge{
	int point_a;
	int point_b;
	double length;
	bool operator<(const edge &a) const{ return length < a.length;}
};
vector<struct edge> V;
vector<double> ans;
int p[502];
int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		for(int i=0;i<502;i++) p[i]=i;
		int ind=0,cnt=0;
		int S,P;
		struct edge temp;
		scanf("%d%d",&S,&P);
		for(int i=0;i<P;i++){
			cin>>point[i].x>>point[i].y;
		}
		for(int i=0;i<P;i++){
			for(int j=i+1;j<P;j++){
				temp.point_a=i;
				temp.point_b=j;
				double X1=point[i].x,X2=point[j].x,Y1=point[i].y,Y2=point[j].y;
				temp.length=sqrt(pow(X1-X2,2)+pow(Y1-Y2,2));
				ind++;
				V.push_back(temp);
			}
		}
		sort(V.begin(),V.end());
		for(int i=0;i<ind;i++){
			if(cnt==P-1) break;
			if(Find(V[i].point_a)!=Find(V[i].point_b)){
				Union(V[i].point_a,V[i].point_b);
				ans.push_back(V[i].length);
				cnt++;
			}
		}
		sort(ans.begin(),ans.end());
		printf("%.2lf\n",ans[P-S-1]);
//		while(!ans.empty()) ans.erase(ans.begin());
//		while(!V.empty()) V.erase(V.begin());
		ans.clear();
		V.clear();
	}
}

int Find(int x){
	if(p[x]==x) return x;
	return p[x]=Find(p[x]);
}

void Union(int x,int y){
	int X = Find(x);
	int Y = Find(y);

	p[X]=Y;
}
