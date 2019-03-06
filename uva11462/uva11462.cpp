#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int main()
{
	while(1){
		vector<int> V;
		int input;
		scanf("%d",&input);
		if(input==0) return 0;
		for(int i=0;i<input;i++){
			V.push_back(1);
			scanf("%d",&V[i]);
		}
		sort (V.begin(),V.end());
		for(int i=0;i<V.size();i++){
			printf("%d",V[i]);
			if(i!=V.size()-1)
			printf(" ");
		}
		printf("\n");
	}
}
