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
}point[101];

struct edge{
	int point_a;
	int point_b;
	double length;
	bool operator<(const edge &a) const{ return length < a.length;}
};
vector<struct edge> V;
int p[101];
int main(){
	int input;
	scanf("%d",&input);
	for(int k=0;k<input;k++){
		if(k!=0) printf("\n");
		for(int i=0;i<101;i++) p[i]=i;
		double ans=0;
		int num,ind=0,cnt=0;
		scanf("%d",&num);
		for(int i=0;i<num;i++){
			cin>>point[i].x>>point[i].y;
		}
		for(int i=0;i<num;i++){
			for(int j=i+1;j<num;j++){
				struct edge temp;
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
			if(cnt==num-1) break;
			if(Find(V[i].point_a)!=Find(V[i].point_b)){
				Union(V[i].point_a,V[i].point_b);
				ans+=V[i].length;
				cnt++;
			}
		}
		printf("%.2lf\n",ans);
		while(!V.empty()) V.erase(V.begin());
	}
}

int Find(int x){
	if(x==p[x]) return x;
	return p[x]=Find(p[x]);
}

void Union(int x,int y){
	int X = Find(x);
	int Y = Find(y);

	p[X]=Y;
}


