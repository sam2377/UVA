#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;
vector<int> depth,coin,ans1,ans2,output_coin[1000000],output_depth[1000000];
int second,constant,num,maximum=0,cnt=0,index,cases=0;
void backtrack(int);
int main(){
	while(scanf("%d%d%d",&second,&constant,&num)!=EOF){
		maximum=0,cnt=0;
		for(int i=0;i<num;i++){
			int temp,temp1;
			scanf("%d%d",&temp,&temp1);
			depth.push_back(temp);
			coin.push_back(temp1);
		}
		backtrack(0);	
//	for(int i=0;i<10;i++){
//		for(int j=0;j<output_coin[i].size();j++)
//			printf("%d ",output_coin[i][j]);
//		printf("\n");
//	}
		for(int i=0;i<1000000;i++){
			for(int j=0,sum=0;j<output_coin[i].size();j++){
				sum+=output_coin[i][j];			
				if(sum>maximum){
					maximum=sum;
					index=i;
				}
			}
		}
		if(cases++) printf("\n");
		printf("%d\n%d\n",maximum,output_coin[index].size());
		for(int i=0;i<output_coin[index].size();i++)
			printf("%d %d\n",output_depth[index][i],output_coin[index][i]);
		while(!depth.empty()) depth.erase(depth.begin());
		while(!coin.empty()) coin.erase(coin.begin());
		while(!ans1.empty()) ans1.erase(ans1.begin());
		while(!ans2.empty()) ans2.erase(ans2.begin());
		for(int i=0;i<1000000;i++){
			while(!output_coin[i].empty()) output_coin[i].erase(output_coin[i].begin());
			while(!output_depth[i].empty()) output_depth[i].erase(output_depth[i].begin());
		}
	}
	return 0;
}
void backtrack(int x){
	if(x==num){
		return;
	}
	for(int i=x;i<num;i++){
		if(second>=3*depth[i]*constant){
			second=second-3*depth[i]*constant;
			ans1.push_back(coin[i]);
			ans2.push_back(depth[i]);
			for(int K=0;K<ans1.size();K++){
			output_coin[cnt].push_back(ans1[K]);
			output_depth[cnt].push_back(ans2[K]);
			}
			cnt++;
			backtrack(i+1);
			second=second+3*depth[i]*constant;
			ans1.pop_back();
			ans2.pop_back();
		}
	}
}
