#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
void process(int,int);
int input;
int arr[8][8]={0};
bool col[8];
bool slash1[15];
bool slash2[15];
vector<int> V;
int main(){
	scanf("%d",&input);
		for(int ha=0;ha<input;ha++){
			for(int a=0;a<8;a++){
				for(int b=0;b<8;b++)
					scanf("%d",&arr[a][b]);
			}
		memset(col,false,sizeof(col));
		memset(slash1,false,sizeof(slash1));
		memset(slash2,false,sizeof(slash2));
		process(0,0);
		sort(V.begin(),V.end());
		printf("%5d\n",V[V.size()-1]);
		while(!V.empty()) V.erase(V.begin());
		}
	return 0;
}
void process(int queen,int sum){                          //queen¦æ 
	if(queen==8){
		V.push_back(sum);
		return;
	}
	for(int i=0;i<8;i++){                                 //  ²Äi¦C 
		if(!col[i]&&!slash1[queen+i]&&!slash2[queen-i+7]){
			col[i]=true;
			slash1[queen+i]=true;
			slash2[queen-i+7]=true;
			sum+=arr[i][queen];
			process(queen+1,sum);
			col[i]=false;
			slash1[queen+i]=false;
			slash2[queen-i+7]=false;
			sum-=arr[i][queen];	
		}
	}
}


