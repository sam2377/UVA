#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
void backtrack(int);
int input1,input2,cnt=0;
vector<int> V,ans;
map<vector<int>,bool>  M;
int sum=0,check=1;
int main(){
	while(1){
		check=1;
		sum=0;
		cnt=0;
		scanf("%d",&input1);
		scanf("%d",&input2);
		if(input1==0&&input2==0) break;
		for(int i=0;i<input2;i++){
			int temp;
			scanf("%d",&temp);
			V.push_back(temp);
		}
//		for(int i=0;i<V.size();i++)
//			printf("%d ",V[i]);
//		printf("\n");
//		printf("Sums of %d:\n",input1);
		printf("Sums of %d:\n",input1);
		backtrack(0);
		if(check==1) printf("NONE\n");
		while(!V.empty()) V.erase(V.begin());
		while(!ans.empty()) ans.erase(ans.begin());
	} 
}
void backtrack(int x){
	if(sum==input1){
		if(M[ans]==true) return;
		M[ans]=true;
		for(int i=0;i<ans.size();i++){
			if(i==0)
			printf("%d",ans[i]);
			else
			printf("+%d",ans[i]);
		}
		printf("\n");
		cnt++;
		check=0;
	}
	if(x==V.size())
		return;
	for(int i=x;i<V.size();i++){
		ans.push_back(V[i]);
		sum+=V[i];
		backtrack(i+1);
		sum-=V[i];
		ans.pop_back();
	}
	
}
