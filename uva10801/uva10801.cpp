#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<sstream>
#include<queue>
#include<algorithm>
using namespace std;
int n,k,destination,elavator_num;
int stopfloor[5][100]={0};
int speed[5]={0};
int mov;
int len[100][100]={0};
int dis[100]={0};
int main(){
	while(scanf("%d%d",&elavator_num,&destination)!=EOF){
		dis[0]=0;
		for(int i=0;i<100;i++) 
			for(int j=0;j<100;j++) 
				len[i][j]=999999;
		for(int i=1;i<100;i++)
			dis[i]=999999;
		string no_use;
		for(int i=0;i<elavator_num;i++) scanf("%d",&speed[i]);
		getline(cin,no_use);
		for(int i=0;i<elavator_num;i++){
			string temp;
			getline(cin,temp);
			stringstream haha;
			haha << temp;
			int ind=0;
			while(haha >> stopfloor[i][ind++]);
			ind--;
				for(int j=0;j<ind;j++){
					for(int k=j+1;k<ind;k++){
						int Floor1=stopfloor[i][j],Floor2=stopfloor[i][k];
						if((Floor2-Floor1)*speed[i]<len[Floor1][Floor2])
							len[Floor2][Floor1]=len[Floor1][Floor2]=(Floor2-Floor1)*speed[i];
					}
				}
		}
		
		queue<int> Q;
		bool inqueue[101];
		memset(inqueue,false,101);
		inqueue[0]=true;
		Q.push(0);
		while(!Q.empty()){
			int now = Q.front();
			inqueue[now]=false;
			Q.pop();
		
			for(int i=0;i<100;i++){
				if(dis[now]+len[now][i]+60<dis[i]){
					dis[i]=dis[now]+60+len[now][i];
					if(!inqueue[i]){
						Q.push(i);
						inqueue[i]=true;
					}
				}
			}
		} 
//		for(int j=0;j<ind;j++){
//			printf("%d\n",stopfloor[i][j]);
//		}

//		for(int i=0;i<elavator_num;i++){
//			for(int j=0;j<12;j++){
//				printf("%d ",stopfloor[i][j]);
//			}
//			printf("\n");
//		}
//		for(int i=0;i<100;i++){
//			printf("%d\n",dis[i]);
//		}
		if(destination==0) printf("0\n"); 
		else if(dis[destination]==999999) printf("IMPOSSIBLE\n");
		else printf("%d\n",dis[destination]-60);
	}

}

