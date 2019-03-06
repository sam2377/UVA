#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int cases;
int dis[2500],len[2500],star1[2500],star2[2500];
void relax(int,int,int);
int main(){
	scanf("%d",&cases);
	for(int i=0;i<cases;i++){
		bool check=true;
		for(int j=0;j<2500;j++) dis[j]=9999999;
		dis[0]=0;
			int n,m;
			scanf("%d%d",&n,&m);
			for(int k=0;k<m;k++){
				scanf("%d%d%d",&star1[k],&star2[k],&len[k]);
			} 
			for(int x=0;x<n-1;x++){
				for(int b=0;b<m;b++)
					relax(star1[b],star2[b],len[b]);
			}
			for(int z=0;z<m;z++){
				if(dis[star1[z]]+len[z]<dis[star2[z]]){
					check=false;
					break;
				}
			}
			if(check) printf("not possible\n");
			else	printf("possible\n");
	}
} 
void relax(int a,int b,int c){
	if(dis[a]+c<dis[b])
		dis[b]=dis[a]+c;
}
