#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int data[1000000];
int length[1000000];
int cnt=0;
vector<int>V,ans;
int LIS();
int main(){
	int temp,max_len=0;
	while(scanf("%d",&temp)!=EOF){
		data[cnt]=temp;
		cnt++;
	}
	max_len = LIS() ;
	printf("%d\n-\n",max_len);
//	for(int i=0;i<9;i++)
//		printf("%d ",length[i]);
//	printf("\n");
	for(int i=cnt-1;i>=0;i--){
		if(length[i]==max_len){
			ans.push_back(data[i]);
			max_len--;
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		printf("%d\n",ans[i]);		
	}
}
int LIS(){
	V.push_back(data[0]);
	length[0]=1;
	for(int i=1;i<cnt;i++){
		if(data[i]>V.back()){
			V.push_back(data[i]);
			length[i]=V.size();
		}
		else{
			length[i]=lower_bound(V.begin(),V.end(),data[i]) - V.begin() +1;
			*lower_bound(V.begin(),V.end(),data[i])=data[i]; 
		}
	}
	return V.size();
}

