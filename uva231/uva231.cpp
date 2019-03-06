#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void find_LIS();
vector<int> arr,LIS;
int cases=1;
int flag=1;
int main(){
	
	for(;;cases++){
		int data;
		for(;;){
			scanf("%d",&data);
			if(data==-1) {
				flag--;
				if(flag<0) return 0;
				break;
			}
			else
				flag=1;
			arr.push_back(data);
			LIS.push_back(0);
		}
		arr.push_back(0);
		LIS.push_back(0);
		find_LIS();
//		for(int i=0;i<LIS.size();i++)
//			printf("%d ",LIS[i]);
//		printf("\n");
		sort(LIS.begin(),LIS.end());
		if(cases!=1) printf("\n");	
		printf("Test #%d:\n",cases);
		printf("  maximum possible interceptions: %d\n",LIS[LIS.size()-1]);
		while(!arr.empty()) arr.erase(arr.begin());
		while(!LIS.empty()) LIS.erase(LIS.begin());
	}
}
void find_LIS(){
	for(int i=LIS.size()-2;i>=0;i--){
		LIS[i]=1; 
		for(int j=arr.size()-2;j>i;j--){
			if(arr[i]>arr[j]&&LIS[j]+1>LIS[i])
			LIS[i]=LIS[j]+1;
		}
	}
}
